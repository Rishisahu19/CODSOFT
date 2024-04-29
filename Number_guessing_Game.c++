#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(nullptr));
    
    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    
    // Initialize variables
    int guess;
    bool guessed = false;
    int attempts = 0;
    
    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "I have chosen a number between 1 and 100. Can you guess it?" << endl;
    
    while (!guessed) {
        // Ask the user for input
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        
        // Check if the guess is correct
        if (guess == secretNumber) {
            cout << "Congratulations! You've guessed the number " << secretNumber << " correctly in " << attempts << " attempts." << endl;
            guessed = true;
        }
        // Provide feedback if the guess is too high
        else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        }
        // Provide feedback if the guess is too low
        else {
            cout << "Too low! Try again." << endl;
        }
    }

    return 0;
}
