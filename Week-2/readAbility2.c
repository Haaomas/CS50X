// * Libraries
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//* BreadCrumbs
string getText(void);
int countLetter(string text);
int countWord(string text);
int countSentence(string text);
int colemanLiauFormula(int numberOfLetters, int numberOfWords, int numberOfSentences);
string giveTheGradeOfAText(int colemanMath);

int main(void)
{
    //* Calling all of the function
    string text = getText();

    int numberOfLetters = countLetter(text);

    int numberOfWords = countWord(text);

    int numberOfSentences = countSentence(text);

    int colemanMath = colemanLiauFormula(numberOfLetters, numberOfWords, numberOfSentences);

    string gradeResult = giveTheGradeOfAText(colemanMath);

    // Print the final result
    printf("%s\n", gradeResult);
    // printf("%s %i\n", gradeResult, colemanMath);
}

//* Get a text from a User et check if it's a string
string getText(void)
{
    string text;
    return text = get_string("Enter your text here: ");
}

//* 3 function that return letter, words and sentence from a text
int countLetter(string text)
{
    int letters = 0;
    for (int i = 0, textLengh = strlen(text); i < textLengh; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int countWord(string text)
{
    int words = 1;
    for (int i = 0, textLengh = strlen(text); i < textLengh; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

int countSentence(string text)
{
    int sentences = 0;
    for (int i = 0, textLengh = strlen(text); i < textLengh; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}

//* Make the Coleman-Liau formula
int colemanLiauFormula(int numberOfLetters, int numberOfWords, int numberOfSentences)
{
    // Prepare the number for the Coleman formula
    float averageLetter = ((float)numberOfLetters / numberOfWords) * 100;
    float averageSentence = ((float)numberOfSentences / numberOfWords) * 100;

    // Coleman-Liau formula
    float colemanLiauFormula = 0.0588 * averageLetter - 0.296 * averageSentence - 15.8;

    // Rounded the result
    int roundColemanLiauFormula = round(colemanLiauFormula);

    return roundColemanLiauFormula;
}

string giveTheGradeOfAText(int colemanMath)
{
    string grade;
    if (colemanMath > 16)
    {
        grade = "Grade 16+\n";
    }
    else if (colemanMath < 1)
    {
        grade = "Before Grade 1\n";
    }
    else
    {
        grade = "Grade ";
        grade = grade + colemanMath;
    }
    return grade;
}
