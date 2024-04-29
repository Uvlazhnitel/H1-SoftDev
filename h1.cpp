// Create program in C++ using STD map or binary file. For details see Lab requirements.

// H1. Read text from given text file. Find most frequent words in input file starting on each English alphabet letter. Print in another text file for each English alphabet letter the most frequent word. Word is string containing only English alphabet letters. All other symbols in text file are interpreted as word separators.


#include<iostream>
#include <fstream>
#include <list>
#include <map>

using namespace std;
int main(){
    ifstream file("examples.txt");
    ofstream outputFile("output.txt");


    string word;


    map<string,int> mf;
    map<char,int>mf2;
    map<char,string>mf3;


    int maxValue = 0;

    string thatWord = "";
    char prevLet='\0';
    

    if(file.is_open()){
        char c;
        string word;
        while(file.get(c)){
            if(isalpha(c)){
                word += tolower(c);
            }else if(!word.empty()) {
                mf[word]++;
                word.clear();
            }
        }

        if (!word.empty()) {
            mf[word]++;
        }

        for (char letter = 'a'; letter <= 'z'; ++letter) {
            mf3[letter];
        }

        for(auto &v:mf){
            if(prevLet!=v.first[0]){
                maxValue = 0;
            }
            if(v.second>=maxValue){
                thatWord = v.first;
                maxValue=v.second;
                prevLet = v.first[0];
            }
            mf2[prevLet]=maxValue;
        }

        for(auto &n:mf2){
            for(auto &i:mf){
                if(n.second == i.second && n.first == i.first[0]){
                    mf3[n.first] = i.first;
                }
            }
        }

        for (auto it=mf3.begin(); it!=mf3.end(); ++it){
            outputFile<< it->first << " => " << it->second << '\n';
         }

        cout<<"\n";

    }else {
        cerr<<"Error opening file!";
    }

    file.close();
    }
