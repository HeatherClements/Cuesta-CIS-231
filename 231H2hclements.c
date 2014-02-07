/*
Heather Clements
CIS 231 /Assignment 2
Breakdown a given dollar amount into
$20, $10, $5, $1, .25, .10, .05 and
0.01 increments.
Cuesta College / R. Scovil
Due: Tuesday, September 24, 2013
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (void)
{
    /*Print initial headline of name and assignment*/
    printf("Heather Clements - Assignment 2 - Change-O-Matic\n\n");
    
    /* Declare variables. Penny is declared as double to ensure math is accurate*/
    double amountEntered, amountUse, penny;
    int twenty, ten, five, one, quarter, dime, nickel;
    
    /* Declare x for outer loop. 
       Initial value of 1 to ensure it runs through at least one*/
    int x=1;
 
 /*Outer while loop begins*/       
 while (x>0)
 {
       /*Get dollar input from user*/
       printf("\nEnter a dollar amount from $0.00 and $200.00:\n\n");
       scanf("%lf", &amountEntered);
       
       /*Check to ensure that the entered number is within the range of:
               $0.00 to $200.00*/
       while ((amountEntered < 0) || (amountEntered > 200))
       {
             /*If input is not in range have the user re-enter a number*/
             printf("\nThe number entered is out of range, please re-enter:\n\n");
             scanf("%lf", &amountEntered);
       }
      
       /*Ensure that the input is only two decimal points
              and take out any extra decimals.*/
       amountUse = ((int)(amountEntered * 100)) / 100.00;
       
       /*Print back amount entered, but only to two decimal places*/
       printf("\nAmount entered: %.2lf\n\n", amountUse);
    
       /*Determine the number of $20 bills needed:
        Continue subtracting $20 from amount until price is less than 20*/
       for(twenty = 0; amountUse >= 20; twenty ++)
       {
                   amountUse = amountUse - 20;
       }
       
       /*If any twenties are necessary to make change, print out how many*/
       if(twenty != 0)
                 printf("%i  $20.00\n", twenty);
       
       /*From the now adjusted price determine the number of $10 bills needed:
        Continue subtracting $10 from amount until price is less than 10*/
       for(ten = 0; amountUse >= 10; ten ++)
       {
                amountUse = amountUse - 10;
       }
       
       /*If any tens are necessary to make change, print out how many*/
       if (ten != 0)
                printf("%i  $10.00\n", ten);
     
       /*From the now adjusted price determine the number of $5 bills needed:
        Continue subtracting $5 from amount until price is less than 5*/
       for(five = 0; amountUse >= 5; five ++)
       {
                 amountUse = amountUse - 5;
       }     
       
       /*If any fives are necessary to make change, print out how many*/
       if (five != 0)
                printf("%i   $5.00\n", five);
      
      /*From the now adjusted price determine the number of $1 bills needed:
        Continue subtracting $1 from amount until price is less than 1*/
      for(one = 0; amountUse >= 1; one ++)
      {
                amountUse = amountUse - 1;
      }   
      
      /*If any ones are necessary to make change, print out how many*/
      if (one >= 1)
              printf("%i   $1.00\n", one);

      /*From the now adjusted price determine the number of quarters needed:
        Continue subtracting 0.25 from amount until price is less than 0.25*/   
      for(quarter = 0; amountUse >= 0.25; quarter ++)
      {
                   amountUse = amountUse - 0.25;
      }  
      
      /*If any quarters are needed to make change, print out how many*/  
      if (quarter != 0)
                  printf("%i   $0.25\n", quarter);
    
      /*From the now adjusted price determine the number of dimes needed:
        Continue subtracting 0.10 from amount until price is less than 0.10*/
      for(dime = 0; amountUse >= 0.10; dime ++)
      {
                   amountUse = amountUse - 0.10;
      } 
      
      /*If any dimes are necessary to make change, print out how many*/
      if (dime != 0)
               printf("%i   $0.10\n", dime);
      
      /*From the now adjusted price determine the number of nickels needed:
        Continue subtracting 0.05 from amount until price is less than 0.05*/
      for(nickel = 0; amountUse >= 0.05; nickel ++)
      {
                  amountUse = amountUse - 0.05;
      } 
      
      /*If any nickels are necessary to make change, print out how many*/
      if (nickel != 0)
                 printf("%i   $0.05\n", nickel);
       
      /*Determine number of pennies by dividing remaining amount by 0.01.
         Remember this is why we had to make penny a double*/   
      penny = amountUse / 0.01;
    
      /*If any pennies are necessary to make change, print out how many
        Since penny is a double the value may not equal exactly 0, 
        thus need >0.01 . Also, want it to look like an int, so we request
        one character (can only be 1-4) and no decimal place*/
      if (penny > 0.01)
                printf("%1.0lf   $0.01\n", penny);

      /*Once the change has successfully been printed
        Ask the user is they want to play again. Store the answer (0 or 1) for x
        Therefore, if the answer is x=0 the user will exit the loop*/
      printf("\nWould you like to enter another number: "
              " (Please enter 0 for No or 1 for Yes)\n");
      scanf("%i", &x);
}

 /*Pause the system so the results are visible by the user*/
 system("pause");
  
 /*Exit*/  
 return 0;
}
