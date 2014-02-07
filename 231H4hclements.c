/*
Heather Clements
CIS 231 /Assignment 4
Analyze a data set and generate a set
of results based on the data
Open and read a file before evaluating it
and printing out the required results.
Cuesta College / R. Scovil
Due: Sunday, November 17, 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Constants*/
#define ARRAYSIZE     2500

/*Files*/
#define DATAFILE      "F:/231A4binData.dat"
#define REPORTFILE    "F:/231HA4HCleReport.txt"

/*Prototypes of all functions (except main)*/
void dynamicCreate(double data[]);
int getArray (double data[], int numValues);
void reallocateArray(double data[], int numValues);
void sortArray(double data[], int numValues);
FILE* openFile(void);
void printName(FILE* output);
void printNumValues(FILE* output, int numValues);
void printAllValues(FILE* output, double data[], int numValues);
void printHighLow(FILE* output, double data[], int numValues);
double printAverage(FILE* output, double data[], int numValues);
void printAveValues(FILE* output, double data[], double average, int numValues);
void printStdDev(FILE* output, double data[], double average, int numValues);
void printMedian(FILE* output, double data[], int numValues);
void printMode(FILE* output, double data[], int numValues);
void closeFile(FILE* output);

int main(void)
{
    /*Initialize variables*/
    double someArray[ARRAYSIZE], average;
    int i, numPoints;
    FILE * output;
    
    /*Call all functions to get data*/
    dynamicCreate(someArray);
    numPoints = getArray(someArray, ARRAYSIZE);
    reallocateArray(someArray, numPoints);
    sortArray(someArray, numPoints);
    
    /*Call all functions to compute and output data*/
    output = openFile( );
    printName(output);
    printNumValues(output, numPoints);
    printAllValues(output, someArray, numPoints);
    printHighLow(output, someArray, numPoints);
    average = printAverage(output, someArray, numPoints);
    printAveValues(output, someArray, average, numPoints);
    printStdDev(output, someArray, average, numPoints);
    printMedian(output, someArray, numPoints);
    printMode(output, someArray, numPoints);
    closeFile(output);
    
    /*Ensure output stays on screen for user to view*/
    system("pause");    
    
    /*Exit*/
    return 0;
}

void dynamicCreate(double data[])
{
     /*Declare variables*/
     int doubleSize = sizeof(double); 
     double *array;
     
     /*Dynamically allocate memory*/
     array = (double *) malloc(ARRAYSIZE*doubleSize);
}


int getArray (double data[], int numValues)    
{
    /*Declare variables*/
     int doubleSize = sizeof(double), numItems, i;
     
     /*Declare file pointer*/
     FILE * input;
     
     /*Open file to read information "rb"*/
     input = fopen (DATAFILE, "rb");
     
     /*If unable to find file, print error*/
	 if (!input)
		printf("Error opening input file!");

 	 else
		{
            /*If file is empty, print error*/
			if(data == NULL)
               printf("Not enough memory available. \n");
            
            /*Else, read in the data, retrieving array & the
              number of items before closing the file*/   
            else
            {
                numItems = fread(data, doubleSize , ARRAYSIZE , input);
                fclose(input);

             }
         }
         
    /*Keep the numItems in Main for future functions*/     
    return numItems;
}
     
void reallocateArray(double data[], int numValues)
{
     int doubleSize = sizeof(double);
     
     /*Reallocate the array to the number of items*/
     data = (double *)realloc(data, numValues * doubleSize);
}

void sortArray(double data[], int numValues)
{
     /*Declare variable*/
     int i, j, k;
     double hold;
     
     /*Begin for loop to sort data*/
     for (i=0; i< numValues; i++)
     {
         /*Exchange maximum with next array value*/
         k = i;
         
         /*Search remaining values for a max*/
         for (j = i +1; j < numValues; j++)
             /*If larger value is found- swap*/
             if(data[j] > data[k])
                k = j;
         /*Update array with the swap*/       
         hold = data[k];
         data[k]= data[i];
         data[i] = hold;
     }
}

FILE* openFile(void)
{
      /*Open file to write data into*/
      return fopen(REPORTFILE, "w");
}


void printName(FILE* output)
{
     /*Print name into file*/     
     fprintf(output, "a. Heather Clements\n\n");
     
     /*Print name to screen*/
     printf("a. Heather Clements\n\n");
     
}     


void printNumValues(FILE* output, int numValues)
{
     /*Print numValues into file*/
     fprintf(output, "b. Number of Values: %i\n\n", numValues);
     
     /*Print numValues to screen*/
     printf("b. Number of Values: %i\n\n", numValues);
}


void printAllValues(FILE* output, double data[], int numValues)
{
     /*Declare variables*/
     int i;
     
     /*Print header to file and screen*/
     fprintf(output, "c. All Values: \n");
     printf("c. All Values: \n");
     
     
     /*Starting at i=1 to ensure first value is on first line*/
     for(i=1; i < numValues+1; i++)
     {
              /*Use if statement to place values in rows of 5*/
              if((i % 5))
              {
                  fprintf(output, "%10.2lf ", data[i-1]);
                  printf("%10.2lf ", data[i-1]);
              }
              else
              {
                  fprintf(output, "%10.2lf\n", data[i-1]);
                  printf("%10.2lf\n", data[i-1]);
              }
     }
     
     printf("\n\n");
     fprintf(output, "\n\n");
         
}


void printHighLow(FILE* output, double data[], int numValues)
{
     
     /*Print high and low into file*/
     fprintf(output, "d. The highest value: %19.2lf\n\n", data[0]);
     fprintf(output, "e. The lowest value: %20.2lf\n\n", data[numValues-1]);
     
     /*Print high and low to screen*/
     printf("d. The highest value: %19.2lf\n\n", data[0]);
     printf("e. The lowest value: %20.2lf\n\n", data[numValues-1]);
}


double printAverage(FILE* output, double data[], int numValues)
{
    /*Declare variables*/
    int i;
    double total = 0.0;
    
    /*Total all values*/
    for(i=0; i < numValues; i++)
    {
             total = total + data[i];
    }
    
    /*Print out the average to screen and file*/
    fprintf(output, "f. The average: %25.2lf\n\n", total/((double) numValues));
    printf("f. The average: %25.2lf\n\n", total/((double) numValues));
    
    /*Return average to main to use for future functions*/
    return total/((double) numValues);
    
}
    
    
void printAveValues(FILE* output, double data[], double average, int numValues)
{
     /*Declare variables*/
     int above = 0, equal = 0, below = 0,i;
     
     /*Test each number in the array and determine which category
      it applies to, then add one to that category*/
     for(i = 0; i < numValues; i++)
     {
           if(data[i] < average)
               below++;
           else if(data[i] > average)
               above++;
           else 
               equal++;
       }
       
       /*Print values to file*/
       fprintf(output, "g. Number of values above average: %3i\n", above);
       fprintf(output, "   Number of values below average: %3i\n", below);
       fprintf(output, "   Number of values equal average: %3i\n\n", equal);
       
       /*Print values to screen*/
       printf("g. Number of values above average: %3i\n", above);
       printf("   Number of values below average: %3i\n", below);
       printf("   Number of values equal average: %3i\n\n", equal);                
     
}


void printStdDev(FILE* output, double data[], double average, int numValues)
{
     /*Declare variables*/
     int i;
     double meanSD;
     
     /*Compute difference of each number with average and square the differences*/
     for(i=0; i < numValues; i++)
     {
         meanSD = (data[i] - average)*(data[i] - average);
     }
     
     /*Output standard deviation on screen and in file*/
     fprintf(output, "h. The Standard Deviation: %14.2lf\n\n", sqrt(meanSD/average));
     printf("h. The Standard Deviation: %14.2lf\n\n", sqrt(meanSD/average));     
     
}


void printMedian(FILE* output, double data[], int numValues)
{
     /*If the number of values is odd, print the value in the middle*/
     /*Taking into account that arrays start at zero for both cases*/
     if(numValues%2)
     {
         fprintf(output, "i. The median value: %20.2lf\n\n", data[(numValues-1)/2]);
         printf("i. The median value: %20.2lf\n\n", data[(numValues-1)/2]);
     }
     /*If the number is even print the value to the left of the middle*/
     else
     {
         fprintf(output, "i. The median value: %20.2lf\n\n", data[(numValues/2)-1]);
         printf("i. The median value: %20.2lf\n\n", data[(numValues/2)-1]);
     }
}


void printMode(FILE* output, double data[], int numValues)
{
     /*Declare variable*/
    int i, j, maxCount = 0, count; 
    double modeValue = 0;
    
    /*Outer loop to ensure all data is checked*/
    for (i = 0; i < numValues; i++) 
    {   
        /*Since if you get here there is at least one value*/
        count=1;
        
        /*Check if two consecutive values are within two decimal places*/     
        if((data[i] - data[i+1]) < 0.01 ) 
            count++;
            
        
       /*If the count is larger than any other value, mark as Mode*/ 
       if(count > maxCount)
       {
          maxCount = count;
          modeValue = data[i];
       } 
         
    }
    
    /*Print value to file and screen*/
    fprintf(output, "j. The mode: %28.2lf\n", modeValue);
    fprintf(output, "   Number of occurrences: %12i\n\n", maxCount);
    printf("j. The mode: %28.2lf\n", modeValue);
    printf("   Number of occurrences: %12i\n\n", maxCount);         
}


void closeFile(FILE* output)
{
     /*Close file*/
     fclose(output);
}
