/*
Lab 9
CIS 231 / Cuesta College
Fall 2013 / R. Scovil
Heather Clements
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*Declare array and variables*/
    double myArray[25], total=0, average;
    int i, below=0, above=0, equal=0;
    double highest, lowest;
    
    /*Enter 25 doubles into the array*/
	printf("Please enter the 25 values for myArray:\n");
	for(i = 0; i < 25; i++)
	{
        printf("Please enter myArray[%i]: ",i);
		scanf("%lf", &myArray[i]);
	}

    printf("\n\n");
 
    /*Output the 25 number in their order in the array*/
    printf("The array you entered looks like the following:\n {");
    for(i = 0; i < 25; i++)
	{
		printf("%.1lf  ", myArray[i]);
	}
    printf("}\n\n");

    /*Output the 25 number in the array in reverse order*/    
    printf("The array you entered in reverse order is the following:\n {");
    for(i = 24; i >= 0; i--)
	{
		printf("%.1lf  ", myArray[i]);
	}
    printf("}\n\n");
    
    /*Find the average of the numbers in the array*/
    /*Find total first*/
    for(i = 0; i < 25; i++)
	{
		total = total + myArray[i];
	}
	
	/*Now find average*/
	average = total / 25;
	
	/*Output the average*/
	printf("The average of the array is: %.1lf\n\n", average);
	
	/*Determine the amount of values above, below and equal to the average*/
    for(i = 0; i < 25; i++)
	{
		if (myArray[i] < average)
           below++;
        else if (myArray[i] > average)
           above++;
        else
           equal++;
     }

     /*Output the amount of values above, below, and equal to the average*/
     printf("The amount of values in the array that are above the average are: %i\n"
              "The amount of values below the average are: %i\n"
              "The amount of values equal to the average are: %i\n\n", 
              above, below, equal);
     
     /*Determine highest number in array*/
     highest = myArray[0];
     for(i = 1; i < 25; i++)
	 {
		if ( myArray[i] > highest)
		  highest = myArray[i];
     }

     /*Determine lowest number in array*/     
     lowest = myArray[0];
     for(i = 1; i < 25; i++)
	 {
		if ( myArray[i] < lowest)
		  lowest = myArray[i];
     }     	
          
     /*Output the highest abd lowest numbers in the array*/
     printf("The lowest number in the array is %.1lf \n"
               "The highest number in the array is %.1lf\n\n", lowest, highest);
               
     /*Allow output to stay on screen for user to view*/
     system("pause");
     
     /*Exit program^*/
     return 0;
}    

/*The biggest advantage to using arrays that I have seen so far is that you are
  able to evaluate and return several values at once without having to enter them 
  individually*/
