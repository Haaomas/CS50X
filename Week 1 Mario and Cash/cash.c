// Librairies
#include <cs50.h>
#include <stdio.h>

// BreadCrumbs
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - (pennies * 1);

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int change;
    do
    {
        change = get_int("How many cents do I own you? ");
    } while (change < 0);

    return change;
}

int calculate_quarters(int cents)
{
    int quartersNumber = 0;
    if (cents >= 25)
    {
        do
        {
            cents = cents - 25;
            quartersNumber++;
        } while (cents >= 25);
    }

    return quartersNumber;
}

int calculate_dimes(int cents)
{
    int dimesNumber = 0;
    if (cents >= 10)
    {
        do
        {
            cents = cents - 10;
            dimesNumber++;
        } while (cents >= 10);
    }
    return dimesNumber;
}

int calculate_nickels(int cents)
{
    int nickelsNumber = 0;
    if (cents >= 5)
    {
        do
        {
            cents = cents - 5;
            nickelsNumber++;
        } while (cents >= 5);
    }
    return nickelsNumber;
}

int calculate_pennies(int cents)
{
    int penniesNumber = cents;
    return penniesNumber;
}