/*
Lab 8
CIS 231 / Cuesta College
Fall 2013 / R. Scovil
Heather Clements
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Prototypes of all functions (except main)*/
double getSide1 (void);
double getSide2 (void);
double hypo (double a, double b);
void printData (double a, double b, double c);

int main (void)
{
    /*Declare all local variables for the main fuction*/
    double a, b, c;
    
    /*Call getSide1 function and set return value to a*/
    a = getSide1();
    
    /*Call getSide2 function and set return value to b*/
    b = getSide2();
    
    /*Call hypo function and set return value to c*/
    c = hypo ( a , b);
    
    /*Call function to print out all Data*/
    printData(a, b, c);
    
    /*Ensure output stays on the screen for user*/
    system("pause");
    
    /*Exit Main*/
    return 0;
}

/*getSide1 function: Prompts user to input one side and returns the value*/
double getSide1 (void)
{
       double side1;
       printf("Enter one side of the trangle:\n");
       scanf("%lf", &side1);
       return side1;

}

/*getSide2 function: Prompts user to input second side and returns the value*/
double getSide2 (void)
{
       double side2;
       printf("\nEnter second side of the trangle:\n");
       scanf("%lf", &side2);
       return side2;
}

/* hypo function: returns the square root of the summation 
          for the two imputs squared, hypotenuse*/
double hypo (double a, double b)
{
       return sqrt(a*a + b*b);
}

/*printData function: Simply prints out the results to two decimal place,
                      no value returned*/
void printData (double a, double b, double c)
{
     printf("\nWhen the sides of the triangle are %.2lf & %.2lf" 
                  " the hypotenuse will be %.2lf\n", a,b,c);
}

/*
a	    b	     Projected    Program

2	    3	      3.61         3.61
3	    4	      5.00         5.00
4.5	    6	      7.50	       7.50 
5.555  7.89	      9.65         9.65
20	   8.5	      21.73	       21.73 */
