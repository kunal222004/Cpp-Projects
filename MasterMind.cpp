#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int CODE_LENGTH = 4; // Length of the secret code
const int MAX_GUESSES = 10; // Maximum number of guesses allowed

// Function to generate a random secret code
vector<int> generateCode() {
    vector<int> code;
    srand(time(0));
    for (int i = 0; i < CODE_LENGTH; ++i) {
        code.push_back(rand() % 6 + 1); // Generate a number between 1 and 6
    }
    return code;
}

// Function to evaluate a guess
pair<int, int> evaluateGuess(const vector<int>& secretCode, const vector<int>& guess) {
    int blackPegs = 0;
    int whitePegs = 0;

    vector<bool> usedInSecret(CODE_LENGTH, false); 

    // Check for black pegs (correct number in correct position)
    for (int i = 0; i < CODE_LENGTH; ++i) {
        if (secretCode[i] == guess[i]) {
            blackPegs++;
            usedInSecret[i] = true;
        }
    }

    // Check for white pegs (correct number in wrong position)
    for (int i = 0; i < CODE_LENGTH; ++i) {
        if (secretCode[i] != guess[i]) {
            for (int j = 0; j < CODE_LENGTH; ++j) {
                if (secretCode[i] == guess[j] && !usedInSecret[j]) {
                    whitePegs++;
                    usedInSecret[j] = true;
                    break;
                }
            }
        }
    }

    return make_pair(blackPegs, whitePegs);
}

int main() {
    vector<int> secretCode = generateCode();

    cout << "Welcome to Mastermind!" << endl;
    cout << "I have generated a secret code of " << CODE_LENGTH << " numbers between 1 and 6." << endl;

    for (int i = 0; i < MAX_GUESSES; ++i) {
        cout << "Enter your guess (" << CODE_LENGTH << " numbers separated by spaces): ";
        vector<int> guess;
        for (int j = 0; j < CODE_LENGTH; ++j) {
            int num;
            cin >> num;
            guess.push_back(num);
        }

        pair<int, int> result = evaluateGuess(secretCode, guess);

        cout << "Black pegs: " << result.first << ", White pegs: " << result.second << endl;

        if (result.first == CODE_LENGTH) {
            cout << "Congratulations! You cracked the code!" << endl;
            return 0;
        }
    }

    cout << "You ran out of guesses. The secret code was: ";
    for (int num : secretCode) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}f
