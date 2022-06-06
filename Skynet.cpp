/*
Xenia DeNoyer
Skynet (This assignment took too long)
6.5.2022
*/

// iostream is file header
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
// std for standard
using namespace std;

// Variables for array
const int EIGHT = 8;
const int EMPTY = 0;

// Runs random number generator to get the enemy's position
int enemyPosition()
{
    int enemy = rand() % 64 + 1; // The random number to place the enemy

    return enemy; // Returns the enemy position
}

// Initialize program
int main()
{
    // Seed the random number 
    srand(time(0));


    // The funky fresh code to make the grid, yes I had to google this
    int gameboard[EIGHT][EIGHT];

    for (int row = 0; row < EIGHT; row++)
    {
        for (int col = 1; col < EIGHT + 1; col++) 
        {
            cout << setw(2) << (row * EIGHT) + col;
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Bringing in the enemy position function
    int enemyPlace = enemyPosition();

    // Displays where the enemy is located
    cout << "The enemy is located at square " << enemyPlace << endl;
    cout << endl;

    // Automatically sets the correct guess to false as there has been no attempts
    bool correctGuess = false;

    // Keeps tracks of the number of guesses
    int numberOfGuesses = 0;

    // Loops the function if allies guess incorrectly
    while (correctGuess == false) 
    {
        int guess = rand() % 64 + 1; // Random guess
        //cout << "The random guess is " << rand() % 64 + 1 << "!" << endl;
        cout << "The allies are guessing the enemy is at " << guess << endl;
        numberOfGuesses++;
        system("pause"); // Pauses the system
        cout << endl;
        // Loads once the allies guess correctly
        if (guess == enemyPlace)
        {
            correctGuess = true;
        }
    }

    // States where the allies found the enemy and the number of guesses it took
    cout << "The allies correctly guessed the enemy was at square " << enemyPlace << "!" << endl;
    cout << "It took the allies " << numberOfGuesses << " guesses." << endl;

    system("pause"); // Pauses the system
    return 0; // Return 0
}

