/*
Heather Clements
CIS 231 /Assignment 1
Input a series of five Fahrenheit temps
and convert to Celsius, print total and average
Cuesta College / R. Scovil
Due: Friday, September 13, 2013
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (void)
{
    /* Declare variables*/
    int fahren1, fahren2, fahren3, fahren4, fahren5;
    double cels1, cels2, cels3, cels4, cels5;
    double averageFahren, averageCelsius;
    
    /*Get user input of Fahrenheit temperatures from keyboard*/
    printf("Please enter five Fahrenheit Temperatures:\n"
            "(All on one line, seperated only be a space)\n\n");
    scanf("%i %i %i %i %i", &fahren1, &fahren2, &fahren3, &fahren4, &fahren5);
    
    /*Output the five Fahrenheit Temperatures on the same line of the screen
      First taking up three spaces to align with ones column of Celsius.
      Then using 5 going forward to take into account the decimal and tenths*/
    printf("\nInputed Fahrenheit Temperatures:\n\n%3i %5i %5i %5i %5i\n\n", 
              fahren1, fahren2, fahren3, fahren4, fahren5);
    
    /*Total the Fahrenheit Temperatures and figure out the average*/
    averageFahren = (fahren1 + fahren2 + fahren3 + fahren4 + fahren5) / 5;
    
    /*Print the Average Fahrenheit*/
    printf("The average of the Fahrenheit Temperatures: ");
    printf("%4.1lf\n\n", averageFahren);
    
    /*Convert each individual temperature to Celsius*/
    cels1 = (fahren1 - 32) * 5/9;
    cels2 = (fahren2 - 32) * 5/9;
    cels3 = (fahren3 - 32) * 5/9;
    cels4 = (fahren4 - 32) * 5/9;
    cels5 = (fahren5 - 32) * 5/9;
    
    /*Output the five Celsius Temperatures on the same line of the screen
      Taking us 5 spaces on the screen for each output*/
    printf("Converted Celsius Temperatures:\n\n"
           "%5.1lf %5.1lf %5.1lf %5.1lf %5.1lf",
           cels1, cels2, cels3, cels4, cels5);
    
    /*Total the Celsius Temperatures and figure out the average*/
    averageCelsius = (cels1 + cels2 + cels3 + cels4 + cels5) / 5;
    
    /*Print the Average Celsius*/
    printf("\n\nThe average  of  the  Celsius Temperatures: ");
    printf("%4.1lf\n\n", averageCelsius);
     
    /*Ensure that the solutions stays on the screen for viewing-- 
             until the user decides to exit*/
    system("pause");
    
    /*Exit Program*/
    return 0;
}
     
