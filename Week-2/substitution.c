#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Ask for a key, a text and cipher it
int main(int argc, string argv[])
{
    // Check if the Key is good
    // Check for only one argument
    if (argc == 1)
    {
        printf("Need to put a key\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("To many argument\n");
        return 1;
    }

    // Store the key and it's length
    string keyCode = argv[1];
    int lengthKey = strlen(keyCode);

    // Check if the key is 26 letters long
    if (lengthKey > 26 || lengthKey < 26)
    {
        printf("The key is not 26 letters long\n");
        return 1;
    }

    // Check if the key is only letters
    for (int i = 0; i < lengthKey; i++)
    {
        if (isdigit(keyCode[i]))
        {
            printf("Only letter allow\n");
            return 1;
        }
    }

    // Check if any letter is unique
    for (int k = 0; k < lengthKey; k++)
    {
        for (int j = k + 1; j < lengthKey; j++)
        {
            if (keyCode[j] == keyCode[k])
            {
                printf("Only unique letter\n");
                return 1;
            }
        }
    }

    // Get the text to cipher
    string text = get_string("Text to cipher: ");
    int lengthText = strlen(text);

    // Cipher the Text
    // Print the beginning of the output
    printf("ciphertext: ");

    // Take every character of the text and cipher it with the key
    for (int m = 0; m < lengthText; m++)
    {
        // Get the number of the letter of the text
        int textNumber = (int)text[m];

        // If the text is lower
        if (islower(text[m]))
        {
            // Get the position of the letter to replace it by the new alphabet (the key)
            int positionLetterInAlphabeatLower = textNumber - 97;
            textNumber = keyCode[positionLetterInAlphabeatLower];
            textNumber = (char)textNumber;

            // Turn the key in lower case
            textNumber = tolower(textNumber);

            // Output the cipher letter
            printf("%c", textNumber);
        }
        else if (isupper(text[m]))
        {
            // Get the position of the letter to replace it by the new alphabet (the key)
            int positionLetterInAlphabeatUpper = textNumber - 65;
            textNumber = keyCode[positionLetterInAlphabeatUpper];
            textNumber = (char)textNumber;

            // Turn the key in upper case
            textNumber = toupper(textNumber);

            // Output the cipher letter
            printf("%c", textNumber);
        }
        // If it's not a letter
        else
        {
            // Just print the character
            printf("%c", text[m]);
        }
    }

    // Back to line to avoid the $ after the cipher text
    printf("\n");
}