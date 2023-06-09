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

int main() {
    int nCoins = N_COINS, n;
    int whoseTurn = HUMAN;
    cout << "Welcome to Nim. We start with " << nCoins << endl;
    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";

    while (nCoins > 1) {
		  cout << "\nWe have " << nCoins << ".\n";
		  cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
          switch (whoseTurn) {
              case HUMAN:
                 n = nCoins + 10;
                 while (n < 1 || n > 3 || n > nCoins) {
                    cout << "Pls pick 1 to 3 coins and <= remaining coins: ";
                    cin >> n;
                 }
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
    cout << "\n\nWinner is : " << (whoseTurn ? "Computer \n" : "Human \n");
}
