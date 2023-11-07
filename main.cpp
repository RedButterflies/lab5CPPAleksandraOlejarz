#include <iostream>
#include <set>
#include<iterator>
#include <algorithm>
#include <map>
#include "Dictionary.h"

using namespace std;
void show( const set <int>& s)
{
    set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr<<" ";
    }
    cout<<endl;
}
void showMap( map<string, int> m)
{
    cout<<endl<<"m: "<<endl;
    map<string, int>::iterator it;
    for(it=m.begin(); it!=m.end(); ++it)
    {
        cout << it->first <<" "<<it->second<<endl;
    }
    cout<<endl;
}
map<string, int>::iterator
searchByValue(map<string, int>& m, int val)
{
map<string, int>::iterator it;
for(it=m.begin();it!=m.end();it++)
    if(it->second == val)
break;
return it;
}
std::pair<int,int>duplikat (const std::vector<int>&wektor)
{
    std:: set<int>zdupl;
    std::multiset<int>multiset;
    for(int i : wektor)
    {
        multiset.insert(i);

    }
    std::multiset<int>bez_duplikatow;
    unique_copy(multiset.begin(),multiset.end(),std::inserter(bez_duplikatow,bez_duplikatow.begin()));
    std::set_difference(multiset.begin(),multiset.end(),bez_duplikatow.begin(),bez_duplikatow.end(),std::insert_iterator(zdupl,zdupl.begin()));
    set<int>::iterator itr;
    int liczba;
    int sumaUnik=0;
    for (itr = zdupl.begin(); itr != zdupl.end(); itr++)
    {
        liczba=*itr;
    }
    for (itr =bez_duplikatow.begin(); itr !=bez_duplikatow.end(); itr++)
    {
        sumaUnik+=*itr;
    }
    pair <int,int> zwrot;
    zwrot.first=liczba;
    zwrot.second=sumaUnik;
    return zwrot;



}
template<typename T>
 void szablonowa(std::set<T> setA, std::set<T>setB)
{
    std::set <T> roznicaZbiorowA ;
    std::set <T> roznicaZbiorowB ;
    set_difference(setA.begin(),setA.end(),setB.begin(),setB.end(), insert_iterator(roznicaZbiorowA,roznicaZbiorowA.begin()));
    set_difference(setB.begin(),setB.end(),setA.begin(),setA.end(), insert_iterator(roznicaZbiorowB,roznicaZbiorowB.begin()));
    typename std::set<T>::iterator itr;
    cout<<"Elementy znajdujace sie tylko w pierwszym zbiorze: "<<endl;
    for (itr = roznicaZbiorowA.begin(); itr != roznicaZbiorowA.end(); itr++)
    {
        cout << *itr<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Elementy znajdujace sie tylko w drugim zbiorze: "<<endl;
    for (itr = roznicaZbiorowB.begin(); itr != roznicaZbiorowB.end(); itr++)
    {
        cout << *itr<<" ";
    }
}
char roznica(string stringA, string stringB)
{
    map<char,int> napisA;
    map<char,int>napisB;
    map<char, int> :: iterator it;
    for(int i=0;i<stringA.size();i++)
    {
        napisA[stringA.at(i)]=i;
    }
    for(int i=0;i<stringB.size();i++)
    {
        napisB[stringB.at(i)]=i;
    }
    char dod;
    for(it=napisB.begin(); it!=napisB.end(); ++it)
    {
       if(napisA.count(it->first)==0)
       {
           dod=it->first;
       }
    }
    return dod;

}
int main()
{
    set <int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(3);
    show(s);
    s.erase(s.begin(), s.find(2));
    show(s);
    s.erase(2);
    cout<<s.count(2)<<endl;
    set <int> s1={1,2,3,7};
    set<int>s2={-2,4,1,7,6};
    cout<<"s1: ";
    show(s1);
    cout<<"s2: ";
    show(s2);
    set<int>sUnion,sIntersec,sDiffer;
    set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator(sUnion,sUnion.begin()));
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator(sIntersec,sIntersec.begin()));
    set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator(sDiffer,sDiffer.begin()));
    cout<<"sUnion: ";
    show(sUnion);
    cout<<"sIntersec: ";
    show(sIntersec);
    cout<<"sDiffer: ";
    show(sDiffer);
    set<int> s3={3,8};
    pair <set<int>::iterator, bool> res;
    res=s3.insert(6);
    cout<<"Dodany element: "<<*(res.first)<<endl;
    cout<<"Czy element dodany? "<<res.second<<endl;
    show(s3);
    map<string,int> m;
    m.insert(pair<string,int>("Kowalski",4500));
    m.insert(make_pair("Nowak",2000));
    m["Adamek"]=3000;
    showMap(m);
    int salary=m.find("Kowalski")->second;
    cout<<"Zarobki Kowalskiego: "<<salary<<endl;
    m.erase("Adamek");
    showMap(m);
    cout<< "Czy jest Kowalski? "<<m.count("Kowalski")<<endl;
    pair<string,int> el=*m.begin();
    cout<<"Klucz: "<<el.first<<" "<<"war: "<<el.second<<endl;
    auto it = searchByValue(m, 2000);
    if(it != m.end())
        cout<<"Element znaleziony: "<<it->first<<" "<<
            it->second<<endl;
    else
        cout<<"Brak elementu"<<endl;

    //Przetestowanie dzialania Zad 5.1
   vector<int>liczby = {1,2,3,3,4,5,6};
   cout << "Powtarzajacy sie element:" << duplikat(liczby).first << endl;
   cout << "Suma unikatowych elementow:" << duplikat(liczby).second << endl;

   //Przetestowanie dzialania Zad 5.2
   std:: set <string> setA ={"Asia","Kasia","Basia","Tosia","Zosia","Misia","Fisia","Elzbieta","Fiona","Katarzyna"};
   std:: set <string> setB ={"Lucja","Nadia","Sara","Jola","Grenalda","Elzbieta","Fiona","Katarzyna"};
   szablonowa(setA,setB);

   cout<<endl;
   cout<<endl;
   cout<<endl;

   std:: set <int> setC={1,2,3,4,5,6,7,8,9};
   std:: set <int> setD={4,5,6,10,11,12,13};
    szablonowa(setC,setD);

    cout<<endl;
    cout<<endl;
    cout<<endl;

    std:: set <char> setE={'a','b','c','d','e','f','g'};
    std:: set <char> setF={'b','c','d','e','x','y','z'};
    szablonowa(setE,setF);

    cout<<endl;
    cout<<endl;
    cout<<endl;

   //Przetestowanie zadania Zad 5.3
    string stringA = "Tomato";
    string stringB ="maoYtTo";
    cout<<"Dodatkowy znak: "<<roznica(stringA,stringB)<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    //Przetestowanie zadania 5.4
    Dictionary dictionary;
    dictionary.words["slimak"]="snail";
    dictionary.words["mucha"]="fly";
    dictionary.words["biedronka"]="ladybug";
    dictionary.words["motyl"]="butterfly";
    cout<<"Wyswietlenie zawartosci slownika od z do a wzgledem tlumaczenia"<<endl;
    dictionary.wyswietlOdZdoA();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    dictionary.dodanieSlowa("rekin","shark");
    cout<<"Wyswietlenie slownika po dodaniu slowa - rekin "<<endl;
    dictionary.wyswietlSlownik();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    dictionary.usuniecieSlowa("biedronka");
    cout<<"Wyswietlenie slownika po usunieciu slowa - biedronka"<<endl;
    dictionary.wyswietlSlownik();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Wyswietlenie tlumaczenia slowa rekin"<<endl;
    dictionary.wyswietlTlumaczenie("rekin");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Wyswietlenie slownika od z do a wzgledem tlumaczenia"<<endl;
    dictionary.wyswietlOdZdoA();



    return 0;
}