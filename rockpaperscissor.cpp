#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    srand(time(0));

    string choices[] = {"rock", "paper", "scissors"};
    int playerChoice, computerChoice;
    char playAgain;

    do {
        cout << "Enter your choice (1 for rock, 2 for paper, 3 for scissors): ";
        cin >> playerChoice;

        if (playerChoice < 1 || playerChoice > 3) {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
            continue;
        }

        computerChoice = rand() % 3; // Computer's random choice

        cout << "You chose: " << choices[playerChoice - 1] << endl;
        cout << "Computer chose: " << choices[computerChoice] << endl;

        if (playerChoice == computerChoice) {
            cout << "It's a tie!" << endl;
        } else if ((playerChoice == 1 && computerChoice == 2) ||
                  (playerChoice == 2 && computerChoice == 0) ||
                  (playerChoice == 0 && computerChoice == 1)) {
            cout << "Computer wins!" << endl;
        } else {
            cout << "You win!" << endl;
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
