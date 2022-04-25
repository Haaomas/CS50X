#include <cs50.h>
#include <stdio.h>
// Breadcrumb
void makePyramid(int userInput, string gap);
void oneSide(int incrementation);

int main(void)
{
    int n;
    string space = "  ";

    // Ask for the height of the pyramid, while the answer is not between 0 && 9
    do
    {
        n = get_int("Height: ");
    } while (n < 1 || n > 8);

    // Call for the pyramid function
    makePyramid(n, space);
}

// Create a pyramid of # the height of the user input
void makePyramid(int userInput, string gap)
{
    // Create the column
    for (int i = 0; i < userInput; i++)
    {
        // Create the rows
        for (int l = (userInput - 2); l >= i; l--)
        {
            printf(" ");
        };

        // Create the left side of the pyramid
        oneSide(i);

        // Create the Gap
        printf("%s", gap);

        // Create the right side of the pyramid
        oneSide(i);

        // End of one line
        printf("\n");
    }
}

// Create one side of a pyramid
void oneSide(int incrementation)
{
    for (int k = 0; k <= incrementation; k++)
    {
        printf("#");
    };
}