#include <iostream>

#define NO_GOOD_MOVE  0
#define MAX_MOVE 3
#define N_COINS 23
#define HUMAN 1
#define COMPUTER 0

using namespace std;

bool isBadPosition(int nCoins);

int findGoodMove(int nCoins) {
	for (int n = 1; n <= MAX_MOVE; n++)
		if (isBadPosition(nCoins - n))
			return n;
	return NO_GOOD_MOVE;
}

bool isBadPosition(int nCoins) {
    if (nCoins == 1)
        return true;
    return
        findGoodMove(nCoins) == NO_GOOD_MOVE;
}

void variant_one()
{
    int nCoins = N_COINS, n, evy;
    int whoseTurn = HUMAN;
    cout << "Welcome to Nim. We start with " << nCoins << endl;
    cout << "The player whose pileis even will win\n";
    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";

    while (nCoins > 1) {
		  cout << "\nWe have " << nCoins << ".\n";
		  cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
          switch (whoseTurn) {
              case HUMAN:
                 n = nCoins;
                 while (n < 1 || n > 3 || n > nCoins) {
                    cout << "Pls pick 1 to 3 coins and <= remaining coins: ";
                    cin >> n;
                 }
                 evy += n;
                 break;
              case COMPUTER:
              	n = findGoodMove(nCoins);
              	if (!n)
                    n = 1;
				cout << "Computer takes " << n << " coins.\n" ;
           }
           nCoins -= n;
           whoseTurn = (whoseTurn + 1) % 2;
    }
    if (evy % 2 == 0){
        cout << "\n\nWinner is : Human \n";
    }
    else {
        cout << "\n\nWinner is : Computer \n";
    }
}

bool pile_empty(int pile)
{
    if (pile == 0){
        return false;
    }
    else{
        return true;
    }
}

bool coin_pile(int n,int pile)
{
    if (n > pile){
        return false;
    }
    else{
        return true;
    }
}

int bigger_pile(int pile1, int pile2, int pile3)
{
    int big_pile;
    if (pile1 >= pile2){
        if (pile1 >= pile3){
            return 1;
        }
        else{
            return 3;
        }
    }
    else{
        if (pile2 >= pile3){
            return 2;
        }
        else{
            return 3;
        }
    }
}

void variant_two()
{
    int nCoins = N_COINS, n;
    int pile_1 = 6, pile_2 = 8, pile_3 = 9, user_pile, check = 0;
    int whoseTurn = HUMAN;
    cout << "Welcome to Nim. We have 3 piles.\n";
    cout << "Pile 1 have " << pile_1 << "coins\n";
    cout << "Pile 2 have " << pile_2 << "coins\n";
    cout << "Pile 3 have " << pile_3 << "coins\n";
    cout << "Each one picks 1 to " << MAX_MOVE << " coins from piles.\n";

    while ((pile_1 + pile_2 + pile_3) > 1) {
        cout << "\nWe have 3 piles.\n";
        cout << "Pile 1 have " << pile_1 << "coins\n";
        cout << "Pile 2 have " << pile_2 << "coins\n";
        cout << "Pile 3 have " << pile_3 << "coins\n";
        cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
        switch (whoseTurn) {
            case HUMAN:
                n = pile_1 + pile_2 + pile_3;
                //|| n > (pile_1 + pile_2 + pile_3)
                while (n < 1 || n > 3 || user_pile < 1 || user_pile > 3 || check == 0) {
                    cout << "Don't choose empty pile\n";
                    cout << "Please pick pile: ";
                    cin >> user_pile;
                    if (user_pile == 1){
                        check = pile_empty(pile_1);
                    }
                    else if (user_pile == 2){
                        check = pile_empty(pile_2);
                    }
                    else if (user_pile == 3){
                        check = pile_empty(pile_3);
                    }
                    cout << "\nPlease pick 1 to 3 coins and <= remaining coins: ";
                    cin >> n;
                    if (user_pile == 1){
                        check = coin_pile(n, pile_1);
                    }
                    else if (user_pile == 2){
                        check = coin_pile(n, pile_2);
                    }
                    else if (user_pile == 3){
                        check = coin_pile(n, pile_3);
                    }
                }
                break;
            case COMPUTER:
                user_pile = bigger_pile(pile_1, pile_2, pile_3);
                if (user_pile == 1){
                    n = findGoodMove(pile_1);
                }
                else if (user_pile == 2){
                    n = findGoodMove(pile_2);
                }
                else if (user_pile == 3){
                    n = findGoodMove(pile_3);
                }
              	if (!n)
                    n = 1;
				cout << "Computer takes " << n << " coins from pile " << user_pile <<"\n";
        }
        if (user_pile == 1){
            pile_1 -= n;
        }
        else if (user_pile == 2){
            pile_2 -= n;
        }
        else if (user_pile == 3){
            pile_3 -= n;
        }
        whoseTurn = (whoseTurn + 1) % 2;
    }
    cout << "\n\nWinner is : " << (whoseTurn ? "Computer \n" : "Human \n");
}

int main() {
    int choice;
    cout << "Welcome to Nim Game. Choose which variant you want\n";
    cout << "1-Variant One\n2_Variant Two\n";
    cout << "Please Enter your choice: ";
    cin >> choice;
    cout << "\n";

    if (choice == 1){
        variant_one();
    }
    else if (choice == 2){
        variant_two();
    }
}
