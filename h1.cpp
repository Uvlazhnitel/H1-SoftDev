// Create program in C++ using STD map or binary file. For details see Lab requirements.

// H1. Read text from given text file. Find most frequent words in input file starting on each English alphabet letter. Print in another text file for each English alphabet letter the most frequent word. Word is string containing only English alphabet letters. All other symbols in text file are interpreted as word separators.


// СКОЛЬКО РАЗ ВСТРЕЧАЕТСЯ КАЖДЫЙ СИМВОЛ //
    // list<string> names = {"Apple","apple" "aardvark", "banana" ,"Bandana" ,"circus","Cirrus","Dog", "dogma" ,"effort", "Effort" ,"Gamma" ,"gamma" ,"hat", "Iota" ,"iota" ,"Joke" ,"joke","Kite", "kite" ,"Lima" ,"lima" ,"moma", "moma" ,"nectar" ,"Nectar", "Opera", "opera"};

    // std::map<char , int> st;

    // for (auto &n : names) {
    //     for(char &c:n){
    //         c = tolower(c);
    //         st[c]++;
    //     }

    // }

    // for (const auto &pair : st) {
    //     std::cout << pair.first << ": " << pair.second << std::endl;
    // }

#include<iostream>
#include <fstream>
#include <list>
#include <map>



using namespace std;
int main(){
    ifstream file("examples.txt");
    string word;
    list<char> alphabet;
    map<string,int> mf;
    int num = 0;
    string word1;

    if(file.is_open()){
        while(file>>word){
            for(char &c:word){
                c=tolower(c);   
            }
            mf[word]++;
        }
        for (auto it=mf.begin(); it!=mf.end(); ++it)
            cout << it->first << " => " << it->second << '\n';
        }else{
                cout<<"Error to open a file!";
            }
            file.close();
}

//найти сколько раз повторяются слова
//найти самое частое для каждой букв
//собрать в один список
//отсортировать
//присвоить значения мэпу с алфавитом  