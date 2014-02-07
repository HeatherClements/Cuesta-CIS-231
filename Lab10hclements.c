/*Lab 10
CIS 231 / Cuesta College
Fall 2013 / R. Scovil
Heather Clements
*/

#include <stdio.h>
#include <stdlib.h>

/*Prototypes of all functions (except main)*/
double input_nums (double theArray[], int numElem);
void in_order( double theArray[], int numElem);
void rev_order( double theArray[], int numElem);
void abo_bel_equ( double theArray[], int numElem);
void hi_lo( double theArray[], int numElem);

int main(void)
{
    /*Declare array and variables*/
    double myArray[20];
    int numValues, i;
    
    /*Get number of double input from user*/
    printf("How many doubles would you like to enter for an array (1-20):\n");
    scanf("%i", &numValues);
    
    /*Check to ensure that the entered number is within the range of: 1 to 20*/
    while ((numValues < 1) || (numValues > 20))
    {
       /*If input is not in range have the user re-enter a number*/
       printf("\nThe number entered is out of range, please re-enter:\n");
       scanf("%i", &numValues);
    }
    
    /*Get the values in the array*/
    myArray[20] = input_nums(myArray, numValues);
    
    /*Call the function to print out array in order*/
    in_order(myArray, numValues);
    
    /*Call the function to print out in reverse rder*/
    rev_order(myArray, numValues);
    
    /*Call the function to print out average and how all values relate*/
    abo_bel_equ(myArray, numValues);
    
    /*Call the function to print out highest and lowest*/
    hi_lo(myArray, numValues);
    
    /*Allow output to stay on screen for user to view*/
    system("pause");
    
    /*Exit program*/
    return 0;
    
}

double input_nums (double theArray[], int numElem)
{
    /*Enter the doubles into the array*/
    int i;
    
	printf("\nPlease enter the %i values for myArray:\n", numElem);
	for(i = 0; i < numElem; i++)
	{
        printf("Please enter myArray[%i]: ",i);
		scanf("%lf", &theArray[i]);
	}
	
	printf("\n\n");
	
	return theArray[numElem];
}

void in_order( double theArray[], int numElem)
{
    /*Output the numbers in their order in the array*/
    int i;
     
    printf("The array you entered in order is the following:\n {");
    for(i = 0; i < numElem; i++)
	{
		printf("%.1lf  ", theArray[i]);
	}
    printf("}\n\n");
    
    return;
}

void rev_order( double theArray[], int numElem)
{
    /*Output the 25 number in the array in reverse order*/ 
    int i;
    
    printf("The array you entered in reverse order is the following:\n {");
    for(i = (numElem-1); i >= 0; i--)
	{
		printf("%.1lf  ", theArray[i]);
	}
    printf("}\n\n");
    
    return;
}

void abo_bel_equ( double theArray[], int numElem)
{
     double total=0, average=0;
     int i, below=0, above=0, equal=0;
     
    /*Find the average of the numbers in the array*/
    /*Find total first*/
    for(i = 0; i < numElem; i++)
	{
		total = total + theArray[i];
	}
	
	/*Now find average*/
	average = total / numElem;
	
	/*Output the average*/
	printf("The average of the array is: %.1lf\n\n", average);
	
	/*Determine the amount of values above, below and equal to the average*/
    for(i = 0; i < numElem; i++)
	{
		if (theArray[i] < average)
           below++;
        else if (theArray[i] > average)
           above++;
        else
           equal++;
     }

     /*Output the amount of values above, below, and equal to the average*/
     printf("The amount of values in the array that are:\n");
     printf("Above average: %i\nBelow average: %i\nEqual to average: %i\n\n",
              above, below, equal);
     
     return;
}

void hi_lo( double theArray[], int numElem)
{
     double highest = theArray[0], lowest = theArray[0];
     int i;
     
     /*Determine highest and lowest number in array*/
          for(i = 1; i < numElem; i++)
	 {
		if ( theArray[i] > highest)
		  highest = theArray[i];
		if ( theArray[i] < lowest)
		  lowest = theArray[i];
     }
          
     /*Output the highest abd lowest numbers in the array*/
     printf("The lowest number in the array is %.1lf \n"
               "The highest number in the array is %.1lf\n\n", lowest, highest);
     
     return;
}
