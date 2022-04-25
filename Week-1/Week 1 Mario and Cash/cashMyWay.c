#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents, int quarterAmount);
int calculate_dimes(int cents, int dimesAmount);
int calculate_nickels(int cents, int nickelAmount);
int calculate_pennies(int cents);

int main(void)
{
    const int quarterAmount = 25;
    const int dimesAmount = 10;
    const int nickelAmount = 5;
    const int pennyAmount = 1;

    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents, quarterAmount);
    cents = cents - (quarters * quarterAmount);

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents, dimesAmount);
    cents = cents - (dimes * dimesAmount);

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents, nickelAmount);
    cents = cents - (nickels * nickelAmount);

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - (pennies * pennyAmount);

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("Here's you'r change, %i coins, %i quarters, %i dimes, %i nickels and %i pennies. Have a good day :)\n", coins, quarters, dimes, nickels, pennies);
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

int calculate_quarters(int cents, int quarterAmount)
{
    int quartersNumber = 0;
    if (cents >= quarterAmount)
    {
        do
        {
            cents = cents - quarterAmount;
            quartersNumber++;
        } while (cents >= quarterAmount);
    }

    return quartersNumber;
}

int calculate_dimes(int cents, int dimesAmount)
{
    int dimesNumber = 0;
    if (cents >= dimesAmount)
    {
        do
        {
            cents = cents - dimesAmount;
            dimesNumber++;
        } while (cents >= dimesAmount);
    }
    return dimesNumber;
}

int calculate_nickels(int cents, int nickelAmount)
{
    int nickelsNumber = 0;
    if (cents >= nickelAmount)
    {
        do
        {
            cents = cents - nickelAmount;
            nickelsNumber++;
        } while (cents >= nickelAmount);
    }
    return nickelsNumber;
}

int calculate_pennies(int cents)
{
    int penniesNumber = cents;
    return penniesNumber;
}