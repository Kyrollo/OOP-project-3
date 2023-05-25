#include <bits/stdc++.h>
using namespace std;
ifstream file;
char name[100];
map <int, string> words;
map <int, string>::iterator itr;


void read_file()
{
    char char_file;
    string word;
    file.open(name, ios::in);
    if (file.is_open()){
        while(!file.eof()){
            file.get(char_file);

            if(char_file == '\n' || char_file == ' '){
                cout << word << "\n";
                for (itr = words.begin(); itr != words.end(); itr++){
                    if(itr->second == word){
                        cout << "Found\n";
                        cout << itr->second << "\n";
                        //(itr->second)++;
                    }
                    else{
                        words.insert({1, word});
                        cout << "Not Found\n";
                    }
                }
                word.clear();
            }
            else{
                word += tolower(char_file);
            }

        }
    }
}


int main(){
    cout << "Enter the file name: ";
    cin.getline(name, 100);
    strcat(name, ".txt");
    string cc = "sd";
    words.insert(pair<int, string> (5, cc));
    read_file();

    words.insert(pair<int, string> (1, cc));
    cout << "\tKey\tValue\n";
    for (itr = words.begin(); itr != words.end(); itr++){
        cout << "\t " << itr->first << "\t " << itr->second << "\n";
    }
}
