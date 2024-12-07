#include "tictactoe.h"
#include <stdio.h>
#include <string.h>

//print options for selection
void outputSelectOpt(){
    printf("Select from options:\n"
    "[1] Rock\n"
    "[2] Paper\n"
    "[3] Scissors\n");
}

//get user input:
    // char name[50];
    // printf("Enter your name: ");
    // fgets(name, sizeof name, stdin); // <-- Crisis averted!
    // name[strcspn(name, "\n")] = 0; // <-- Necessary step.
    // printf("Hello, %s! Welcome!\n", name);
void getUserName(){
    char name[50];
    printf("Enter your name: ");
    //safe user input with bufer
    fgets(name, sizeof name, stdin);
    //remove newline char and replace with null
    name[strcspn(name,"\n")] = 0;
    printf("Hello, %s! Welcome!\n", name);
}

//randomly select from 3 options

//compare user selection to generated option