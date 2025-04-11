#include <stdio.h>
#include <stdlib.h>

/*
Date           :    2024-03-25
Filename       :    pop
Author's name  :    Jay Patel
Student ID     :    501223346

Assignment #1 - Vending Machine
CPS 393 Section 1J0
Instructor: L. Hiraki
Purpose: Create a program to run a Vending Machine

I certify that the program and code are my own work.

Comprehensive section:

1. The assignment helped me gain a better understanding on C language in general, use of functions and their implementations.
2. My two difficulties were taking out duplication code and use functions as well as usinf command line arguments and creating a condition around it.
*/

// Define Constants that wouldn't change during the program
#define MIN_CENTIMES 30
#define MAX_CENTIMES 115
#define NICKEL 5
#define DIME 10
#define PENTE 20
#define CENTIMES_MULTIPLE 5

// Defining Functions
void welcomeMessage();
void usageInfoMessage(int amount);
void customerCalculation(int amount);
void refund(int total);

// Main fnction
int main(int argc, char *argv[]) {

// If command line arguments doesn't meet the following condition display the following message
    if (argc != 2) {
        printf("Please specify the selling price as a command line argument.\n");
        printf("Usage: %s [price]\n", argv[0]);
// Returning a different code in case I get an error for the first IF block.
        return 11;
    }

//  Including the command line argument into the code
    int amount = atoi(argv[1]);

// Check if the amount entered is within the defined range
    if (amount < MIN_CENTIMES || amount > MAX_CENTIMES) {
        printf("Price must be from %d to %d centimes inclusive.\n", MIN_CENTIMES, MAX_CENTIMES);
// Returning a different code in case I get an error for the above IF block.
        return 12;
    }

// Check if the amount enetered is in multiple of 5.
    if (amount % CENTIMES_MULTIPLE != 0) {
        printf("Price must be a multiple of %d.\n", CENTIMES_MULTIPLE);
// Returning a different code in case I get an error for the above IF block.
        return 13;
    }

// After all of the above conditions are met, the following functions will be called out.
    welcomeMessage();
    usageInfoMessage(amount);
    customerCalculation(amount);
    return 0;
}

//Welcome Message.
void welcomeMessage(){
    printf("Welcome to my C Pop Machine!\n");
}

//Information on pop prices and coin information.
void usageInfoMessage(int amount){
    printf("Pop is %d centimes. Please insert any combination of nickels [N or n], dimes [D or d] or Pentes [P or p]. You can also press R or r for coin return.\n", amount);
}

//Refund calculation
void refund(int total){
    int coin_dimes = total / DIME;
    int coin_nickels = (total % DIME) / NICKEL;
    printf("Change given: %d centimes as %d dime(s) and %d nickel(s).\n", total, coin_dimes, coin_nickels);
}

//calculation on total coins added, refund etc.
void customerCalculation(int amount){
    char coin;
    int total = 0;

// Using a while loop to trigger an infinite loop to ask for the coin infinitely
    while (1) {
        printf("Enter coin (NDPR): ");
        scanf(" %c", &coin);

        if (coin == 'n' || coin == 'N'){
            printf("Nickel detected.\n");
            total += NICKEL;
        }
        else if (coin == 'd' || coin == 'D'){
            printf("Dime detected.\n");
            total += DIME;
        }
        else if (coin == 'p' || coin == 'P'){
            printf("Pente detected.\n");
            total += PENTE;
        }
        else if (coin == 'r' || coin == 'R'){
            refund(total);
            total = 0;
            usageInfoMessage(amount);
            continue;
        }
        else if (coin == 'k' || coin == 'K'){
            refund(total);
            printf("Shutting Down. Goodbye.\n");
            break;
        }
        else {
//Unknown coin should be rejected.
            printf("Unknown coin rejected.\n");
            continue;
        }
//The following statements would print after adding every coin.
        printf("You have inserted a total of %d centimes.\n", total);

        if (total >= amount){
            printf("Pop is dispensed. Thank you for your business! Please come again.\n");
            int refund_change = total - amount;
            refund(refund_change);
            total = 0;
            usageInfoMessage(amount);
        }
        else {
//Until the above condition is met, the machine would display the following message after adding every coin.
            printf("Please insert %d more centimes.\n", amount - total);
        }
    }
}
