//
// Created by szyns on 06.11.2023.
//

#ifndef UNTITLEDPP_DICTIONARY_H
#define UNTITLEDPP_DICTIONARY_H
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

class Dictionary {

public:
    std::map<string,string>words;
    Dictionary();
    void dodanieSlowa(const string& slowo, string tlumaczenie);
    void usuniecieSlowa(const string& slowo);
    void wyswietlSlownik();
    void wyswietlTlumaczenie(const string& slowo);
    void wyswietlOdZdoA();
};


#endif //UNTITLEDPP_DICTIONARY_H
