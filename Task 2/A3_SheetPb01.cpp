#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
ifstream file;
vector<string> result;

bool is_found(string word){
    string word_2;
    char character_of_file;
    int check = 0;
	file.open("dictionary.txt", ios::in);
	while(!file.eof())
	{
		file.get(character_of_file);
        if(character_of_file == '\n' || character_of_file == ' '){
            if (strcasecmp(word_2.c_str(), word.c_str()) == 0) {
                check = 1;
                break;
            }
            word_2.clear();
        }
        else{
            word_2.push_back(character_of_file);
        }

	}
	file.close();
	return check;
}

int i = 0;
void backtrack(string message, string &s, int &end_message)
{
    if (i >= message.size())
    {
        i = 0;
        result.push_back("\n");
        return ;
    }

    for (int j = i; j < end_message; j++)
    {
        s += message[j];
    }
    if (is_found(s) == 1)
    {
        result.insert(result.end(), s);
        i += s.size();
        s.clear();
        end_message = message.size();
        backtrack(message, s, end_message);
    }

    else if(is_found(s) == 0)
    {
        s.clear();
        end_message--;
        if (i >= end_message)
        {
            i++;
            end_message = message.size();
            backtrack(message, s, end_message);
        }
        backtrack(message, s, end_message);
    }
}
void fronttrack(string message, string &s, int &end_message)
{
    if (i >= message.size()){return ;}

    for (int j = i; j < end_message; j++)
    {
        s += message[j];
    }
    if (is_found(s) == 1)
    {
        result.insert(result.end(), s);
        i += s.size();
        s.clear();
        end_message = i + 1;
        fronttrack(message, s, end_message);
    }
    else if(is_found(s) == 0)
    {
        s.clear();
        end_message++;
        if (end_message > message.size())
        {
            end_message = i + 1;
            i--;
            result.pop_back();
            fronttrack(message, s, end_message);
        }
        fronttrack(message, s, end_message);
    }
}

int main()
{
    string message = "wearmyshoes", ty;
    int n = message.size();
    backtrack(message, ty, n);
    n = 1;
    fronttrack(message, ty, n);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}
