/*
Heather Clements
CIS 231 /Assignment 3
Input 1 to 25 Fahrenheit values,
Display Fahrenheit and Celsius in 
ascending order, the averages, and the 
highest and lowest values
Cuesta College / R. Scovil
Due: Sunday, October 27, 2013
*/

#include <stdio.h>
#include <stdlib.h>

/*Prototypes of all functions (except main)*/
void inputFahrs (double data[], int numFahrs);
double fahrtoCels (double fahr);
void selectionSort (double data[], int numFahrs);
void outputFahrs (double data[], int numFahrs);
void outputAverage (double data[], int numFahrs);
void outputHighLows (double data[], int numFahrs);
void outputGrads (double data[], int numFahrs);

int main(void)
{
    /*Declare array and variables*/
    double myFahrs[25];
    int numValues, i;
    
    /*Get number of double input from user*/
    printf("How many Fahrenheit values will you be typing?(1-25):\n");
    scanf("%i", &numValues);
    
    /*Check to ensure that the entered number is within the range of: 1 to 20*/
    while ((numValues < 1) || (numValues > 25))
    {
       /*If input is not in range have the user re-enter a number*/
       printf("\nThe number entered is out of range, please re-enter:\n");
       scanf("%i", &numValues);
    }
    
    /*Get the values in the array*/
    inputFahrs(myFahrs, numValues);
    
    /*Print header*/
    printf("CIS 231 - Assignment 3 - Heather Clements\n\n");
        
    /*Sort the values in the array in ascending order*/  
    selectionSort(myFahrs, numValues);
    
    /*Output Fahrenheit and Celsius Temperatures*/
    outputFahrs (myFahrs, numValues);
    
    /*Output the average of all the values (Fahrenheit and Celsius Temps)*/
    outputAverage (myFahrs, numValues);
    
    /*Output the high and low values of both Fahrenheit and Celsius*/
    outputHighLows (myFahrs, numValues);
    
    /*Output the gradient information*/
    outputGrads (myFahrs, numValues);
    
    /*Allow output to stay on screen for user to view*/
    system("pause");
    
    /*Exit program*/
    return 0;
    
}


void inputFahrs (double data[], int numFahrs)
{
    int i;
    
    /*Enter the doubles into the array*/
	printf("Please enter the %i Fahrenheit values:\n", numFahrs);
	for(i = 0; i < numFahrs; i++)
	{
        printf("Please enter the temperature in the %i place: ",i);
		scanf("%lf", &data[i]);
		while ((data[i] < -175.0) || (data[i] > 175.0))
       {
          /*If input is not in range have the user re-enter a number*/
          printf("\nThe number entered is out of range, please re-enter:\n");
          scanf("%lf", &data[i]);
       }
	}

	printf("\n\n");
}


double fahrtoCels (double fahr)
{
    return ((fahr - 32) * 5/9);
}

    
void selectionSort (double data[], int numFahrs)
{
     int fill, i, minIndex, lastIndex = numFahrs - 1;
     double temp;
     
     /*Sort the values in the array*/
     for(fill = 0; fill < lastIndex; fill++)
     {
            /*Find the smallest item from the fill index to the end of array*/
            minIndex = fill;
            
            for(i = fill + 1; i <= lastIndex; i++)
            {
                  /*If it's the new low value, save its index, not value*/
                  if(data[i] < data[minIndex])
                         minIndex = i;
            }
            
            /*If the item is not where it needs to be, swap it*/
            if (minIndex != fill)
            {
                   temp = data[fill];
                   data[fill] = data[minIndex];
                   data[minIndex] = temp;
            }
     }
}

                   
void outputFahrs (double data[], int numFahrs)
{
    int i;
    char space = ' ';
     
    /*Label the output accordingly*/ 
    printf("%31cFahr%11cCels\n%31c====%11c====\n", space, space, space, space);

    /*Output the numbers in ascending order in the array*/
    for(i = 0; i < numFahrs; i++)
	{
		printf("%35.1lf", data[i]);
        printf("%15.1lf\n", fahrtoCels(data[i]));
	}
	
	/*Print footer*/
    printf("%31c====%11c====\n", space, space);
}


void outputAverage (double data[], int numFahrs)
{
     double total = 0.0;
     int i;
     
    /*Find the average of the numbers in the array*/
    /*Find total first*/
    for(i = 0; i < numFahrs; i++)
	{
		total = total + data[i];
	}
	
	/*Print out the average for Fahrenheit and convert to Celsius*/
	printf("Average: %26.1lf%15.1lf\n\n", total / numFahrs, 
            fahrtoCels(total/numFahrs));
}


void outputHighLows (double data[], int numFahrs)
{
     double highest = data[0], lowest = data[0];
     int i;
     
     /*Determine highest and lowest number in array*/
     for(i = 1; i < numFahrs; i++)
	 {
		if ( data[i] > highest)
		    highest = data[i];
		if ( data[i] < lowest)
            lowest = data[i];	  
     }
          
     /*Output the highest and lowest numbers in the array
       With corresponding Celsius values*/
     printf("High: %29.1lf%15.1lf\nLow: %30.1lf%15.1lf\n\n", 
            highest, fahrtoCels(highest), lowest, fahrtoCels(lowest));
     
}


void outputGrads (double data[], int numFahrs)
{
     /*Initialize all variables to 0 (except i) and declare*/
     int below = 0, zero3Two = 0, thirty26Eight = 0, sixty81Hundred = 0;
     int above = 0, i;
         
     /*Test each number in the array and determine which gradation
       it applies to, then add one to that gradation*/
     for(i = 0; i < numFahrs; i++)
     {
           if(data[i] < 0.0)
                  below++;
           else if(data[i] >= 0.0 && data[i] <= 32.0)
                     zero3Two++;
           else if(data[i] > 32.0 && data[i] < 68.0)
                     thirty26Eight++;
           else if(data[i] >= 68.0 && data[i] <= 100.0)
                     sixty81Hundred++;
           else
                  above++;
     }
     
     /*Print the results, one on each line*/
     printf("Below 0.0F:%23i\nBetween 0.0 and 32.0F:%12i\n"
     "Above 32.0F & below 68.0F:%8i\nAt least 68.0 & below 100.0F:%5i\n"
     "Above 100.0F:%21i\n", below, zero3Two, thirty26Eight, sixty81Hundred, above);
}
