#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_TRIES = 6; // Maximum number of incorrect guesses

int main() {
    srand(time(0));

    vector<string> words = {"programming", "computer", "science", "data", "structures", "algorithms"};
    string chosenWord = words[rand() % words.size()];
    string guessedLetters;
    int tries = 0;

    cout << "Welcome to Hangman!" << endl;

    while (tries < MAX_TRIES) {
        string hiddenWord;
        for (char c : chosenWord) {
            if (guessedLetters.find(c) != string::npos) {
                hiddenWord += c;
            } else {
                hiddenWord += "_";
            }
        }

        cout << "Word: " << hiddenWord << endl;
        cout << "Guessed letters: " << guessedLetters << endl;
        cout << "Tries remaining: " << MAX_TRIES - tries << endl;

        char guess;
        cout << "Guess a letter: ";
        cin >> guess;
        guess = tolower(guess); 

        if (guessedLetters.find(guess) != string::npos) {
            cout << "You already guessed that letter." << endl;
            continue;
        }

        guessedLetters += guess;

        if (chosenWord.find(guess) == string::npos) {
            cout << "Incorrect guess." << endl;
            tries++;
        }

        if (hiddenWord == chosenWord) {
            cout << "Congratulations! You guessed the word: " << chosenWord << endl;
            return 0;
        }
    }

    cout << "You ran out of tries. The word was: " << chosenWord << endl;

    return 0;
}
