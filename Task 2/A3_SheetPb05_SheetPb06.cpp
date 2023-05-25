#include <iostream>
#include <string>
using namespace std;

int The_index = 0;
class Cell {
    private :
     int index;
     bool stat;
     char player_stat;

    public:
    Cell() {
        index = The_index++;
        stat = 0;
        if (The_index == 25) {
            The_index = 0;
        }
        if (index == 1 || index == 2 || index == 3) {
            player_stat = 25;
            stat = 1;
        }
        else if (index == 5 || index == 10 || index == 15) {
            player_stat = 26;
            stat = 1;
        }
        else if (index == 0 || index == 4 || index == 20 || index == 24) {
            player_stat = 2;

        }
        else {
            player_stat = ' ';
        }

    }

    void set_index(int ind)
    {
        index = ind;
    }

    int get_index()
    {
        return index;
    }

    void set_stat(bool sta)
    {
        stat = sta;
    }

    bool get_stat()
    {
        return stat;
    }

    void set_player_stat(char m)
    {
        player_stat = m;
    }

    char get_player_stat()
    {
        return player_stat;
    }

};

class uni {
private : 
    Cell gird[5][5];
    string message = "You cannot take this step \n";
public :
    void show() {
        for (int i = 0; i < 5; i++) {
            if (i > 0 && i < 4) {
                cout << i << ' ';
            }
            else {
                cout << "  ";
            }
            for (int j = 0; j < 5; j++)
            {
                cout << gird[i][j].get_player_stat() << ' ';
            }
            cout << endl;
        }
    }
    void take_step(bool player, int choice)
    {
        if (player == 0) {
            for (int k = 0; k < 4; k++) {
                if (gird[choice][k].get_stat() == 1 && gird[choice][k].get_player_stat() == char(26)) {
                    if (gird[choice][k + 1].get_stat() == 0) {
                        gird[choice][k].set_stat(0);
                        gird[choice][k].set_player_stat(' ');
                        gird[choice][k+1].set_stat(1);
                        gird[choice][k + 1].set_player_stat(26);
                    }
                    else if (gird[choice][k + 1].get_stat() == 1 && gird[choice][k + 2].get_stat() == 0)
                    {
                        gird[choice][k].set_stat(0);
                        gird[choice][k].set_player_stat(' ');
                        gird[choice][k + 2].set_stat(1);
                        gird[choice][k + 2].set_player_stat(26);
                    }
                    else if (gird[choice][k + 1].get_stat() == 1 && gird[choice][k + 2].get_stat() == 1)
                    {
                        throw message;
                    }
                }
            }
        }
        else{
            for (int f = 0; f < 4; f++)
            {
                if (gird[f][choice].get_stat() == 1 && gird[f][choice].get_player_stat() == char(25))
                {
                    if (gird[f + 1][choice].get_stat() == 0)
                    {
                        gird[f][choice].set_stat(0);
                        gird[f][choice].set_player_stat(' ');
                        gird[f+1][choice].set_stat(1);
                        gird[f+1][choice].set_player_stat(25);
                    }
                    else if (gird[f + 1][choice].get_stat() == 1 && gird[f + 2][choice].get_stat() == 0)
                    {
                        gird[f][choice].set_stat(0);
                        gird[f][choice].set_player_stat(' ');
                        gird[f + 2][choice].set_stat(1);
                        gird[f + 2][choice].set_player_stat(25);
                    }
                    else if (gird[f + 1][choice].get_stat() == 1 && gird[f + 2][choice].get_stat() == 1)
                    {
                        throw message;
                    }

                }

            }
      
        }
    
    }


    void check_the_winner(string player_one, string player_two)
    {
        if (gird[1][4].get_stat() == 1 && gird[2][4].get_stat() == 1 && gird[3][4].get_stat() == 1) {
            cout << player_one << " wons" << char(2) << endl;
            exit;
        }
        else if (gird[4][1].get_stat() == 1 && gird[4][2].get_stat() == 1 && gird[4][3].get_stat() == 1) {
            cout << player_two << " wons" << char(2) << endl;
            exit;
        }
    }
};

int main()
{
    int choice_of_the_gamemode;
    cout << "please choose 1 if you want to play against player and 2 if you want to play against AI :";
    cin >> choice_of_the_gamemode;
    if (choice_of_the_gamemode == 1)
    {
        string player_one;
        string player_two;
        uni mina;
        int The_choice;
        cout << "player 1 please enter your name : ";
        cin >> player_one;
        cout << "player 2 please enter your name : ";
        cin >> player_two;
        mina.show();
        while (true) {
            cout << player_one << " enter your choice:";
            cin >> The_choice;
            try { mina.take_step(0, The_choice); }
            catch (const string message) { cerr << message; cout << player_one << "enter your choice :";  cin >> The_choice; }
        }

    }

}

   