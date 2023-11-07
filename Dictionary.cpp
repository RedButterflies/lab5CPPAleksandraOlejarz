//
// Created by szyns on 06.11.2023.
//

#include "Dictionary.h"

#include <utility>

Dictionary::Dictionary() = default;

void Dictionary::dodanieSlowa(const string& slowo, string tlumaczenie) {
    if(words.count(slowo))
    {
        cout<<"Slowo juz jest w slowniku"<<endl;
    }
    else
    {
        words[slowo]=std::move(tlumaczenie);
    }

}

void Dictionary::usuniecieSlowa(const string& slowo) {

        if(words.count(slowo))
        {
            words.erase(slowo);
        }
        else
        {
            cout<<"Podane słowo nie znajduje się slowniku"<<endl;
        }
}

void Dictionary::wyswietlSlownik() {
    map<string, string>::iterator it;
    for(it=words.begin(); it!=words.end(); ++it)
    {
        cout <<"Slowo: " <<it->first <<" Tlumaczenie: "<<it->second<<endl;
    }

}

void Dictionary::wyswietlTlumaczenie(const string& slowo) {
    string tlumaczenie = words.find(slowo)->second;
    cout<<"Tlumaczenie: "<<tlumaczenie<<endl;
}

void Dictionary::wyswietlOdZdoA() {
    vector<string>tlumaczenia;
    vector<string>::iterator it;
    map<string,string>::iterator im;
   for(im=words.begin(); im!=words.end(); ++im)
   {
        tlumaczenia.insert(tlumaczenia.begin(),im->second);
    }

    std::sort(tlumaczenia.begin(), tlumaczenia.end());
    std::reverse(tlumaczenia.begin(), tlumaczenia.end());

    for(auto & i : tlumaczenia)
    {

        for(im=words.begin(); im!=words.end(); ++im)
        {
            if(im->second==i)
            {
                cout<<"Slowo: "<<im->first<<" Tlumaczenie: "<<im->second<<endl;
            }
        }
    }
}
