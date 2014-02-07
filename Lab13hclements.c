//
//  Heather Clements
//  Lab 13 - November 5, 2013

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LENGTH 81
#define MAX_TOKENS 40

void strInput(char str[], int maxChars);

int main(void)
{

   /* create string to tokenize */
   char test [STR_LENGTH];

   strInput(test, STR_LENGTH);

   /* pointer array to mark the start of each token */
   char * results[MAX_TOKENS];

    int count, i, total;
    double average;

    /* repeat as long as test string isn't empty */
    while (strlen(test))
    { 
        count = 0;
        total = 0;
        average = 0;

         /* first call to strtok() with string uses a pointer
         to the start of the string being tokenized
         the second argument is a string w/all delimiters       
         count first token, if legit (non-NULL) */
         if ((results[0] = strtok(test, " \t")))
         count++;        

         /* subsequent tokenizing of the same string is done by
         passing NULL as the first argument        
         results[count] is assigned NULL (logical 0, false)
         if there are no more tokens in the string*/
         while ( results[count] = strtok(NULL, " \t") )
         count++;

        /* create a block of STR_LENGTH ints and assign to data */
        int intSize = sizeof(int);
        int * data = (int *) malloc(count*intSize);
        
        /*Convert each token into an integer array*/
        for(i=0; i < count; i++)
        {
            data[i] = atoi(results[i]);
        }
        
        /*Declare variable for output*/
        int j, t, total = 0;
        double average = 0;

        printf("The number of variable: %i\n", count);
        
        printf("The numbers inputed: ");
        for(j=0; j<count; j++)
        {
             printf("%i ", data[j]);
        }
         /*Find the average of the numbers in the array*/
         /*Find total first*/
        total=0;
        
        printf("%i", total);
        
        for(t = 0; t < count; t++)
	    {
		    total = total + data[t];
	    } 
	    
	    average = ((double) total)/count;
	    
	    printf("\nThe sum is: %i\nThe average is: %.1lf\n", total, average);
	    
        /*Determine highest and lowest number in array*/
        int highest = data[0], lowest = data[0];
        for(j = 1; j < count; j++)
	    {
		    if ( data[j] > highest)
		    highest = data[j];
		    if ( data[j] < lowest)
		    lowest = data[j];
        }
          
         /*Output the highest abd lowest numbers in the array*/
         printf("The lowest number in the array is %i \n"
                  "The highest number in the array is %i\n\n", lowest, highest);
               
        strInput(test, STR_LENGTH);

    }
    puts("");

    return 0;
}


void strInput(char str[], int maxChars)
{
    int k=0;
    
    printf("\nInput string or integers to breakdown:  ");

    while ((str[k] =getchar()) != '\n' && k< maxChars)
          k++;
    str[k] = '\0';
}
