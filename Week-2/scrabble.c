#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word, int lengthWord);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Get the length of each word
    int lengthWord1 = strlen(word1);
    int lengthWord2 = strlen(word2);

    // Score both words
    int score1 = compute_score(word1, lengthWord1);
    int score2 = compute_score(word2, lengthWord2);

    // Give the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

// Compute and return score
int compute_score(string word, int lengthWord)
{
    // Set the result to 0
    int result = 0;

    // Check every letters one by one
    for (int i = 0; i < lengthWord; i++)
    {
        // Get the number of the letter in the word
        int wordNumber = (int)word[i];

        // Check if the character is a letter lower or upper
        if (islower(word[i]) && isalpha(word[i]))
        {
            // Get the position of the letter in the alphabet
            int positionLetterInAlphabeatLower = wordNumber - 97;

            // New result = curentResult + new POINTS letter
            result = result + POINTS[positionLetterInAlphabeatLower];
        }
        else if (isupper(word[i]) && isalpha(word[i]))
        {
            // Get the position of the letter in the alphabet
            int positionLetterInAlphabeatUpper = wordNumber - 65;

            // New result = curentResult + new POINTS letter
            result = result + POINTS[positionLetterInAlphabeatUpper];
        }
        // Meaning if it's not a letter
        else
        {
            // Don't add any point
            result = result + 0;
        }
    }
    return result;
}
