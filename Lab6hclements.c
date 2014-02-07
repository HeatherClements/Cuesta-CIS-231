/*
Lab 6
CIS 231 / Cuesta College
Fall 2013 / R. Scovil
Heather Clements
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (void)
{
    /* Declare all variables*/
    int a , b, c;

/*Part 1*/

    /*Get user input of sides from keyboard*/
    printf("Please enter two integers seperated by a space only:\n");
    scanf("%i %i", &a, &b);
    
    /*Determine which input is larger and print the results*/
    if ( a > b )
       printf("The first number, %i, is greater than the second number, %i.\n\n", a,b);
    else if ( a < b )
        printf("The second number, %i, is greater than the first number, %i.\n\n", b,a);
    else
        printf("The two number, %i & %i, are the same.\n\n", a,b);
 
/*Part 2*/
 
    /*Get another integer from user input*/   
    printf("Please enter another integer:\n");
    scanf("%i", &c);
    
    /*Determine wether or not the input is divisble by both 2 and 3 and print results*/
    if( c%3==0 && c%2==0)
        printf("The number entered, %i, is evenly divisible by 2 and 3.\n", c);
    else
        printf("The number entered, %i, is NOT evenly divisible by 2 and 3. \n", c);
         
    /*Ensure that the solutions stays on the screen for viewing-- until the user decides to exit*/
    system("pause");
    
    /*Exit Program*/
    return 0;
}
