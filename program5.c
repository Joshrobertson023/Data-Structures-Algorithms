/**********************************************************************/
/*                                                                    */
/* Program Name: program5 -                                           */
/* Author:       Josh Robertson                                       */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 20, 2023                                     */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* I pledge this assignment is my own first time work.                */
/* I pledge I did not copy or try to copy any code from the Internet. */
/* I pledge I did not copy or try to copy any code from anyone else.  */
/* I pledge I did not attempt to give code to anyone else on this.    */
/* I understand if I violate this pledge I will receive a 0 grade.    */
/*                                                                    */
/*                                                                    */
/*                      Signed: _____________________________________ */
/*                                          (signature)               */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <ctype.h>

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER   "CS227"     /* PCC assigned course number     */
#define PROGRAMMER_NAME "Robertson" /* The programmer's last name     */
#define PROGRAM_NUMBER  4           /* Teacher assigned program       */
                                    /* number                         */
#define MINIMUM_VALUE   -5000       /* */
#define MAXIMUM_VALUE   5000        /* */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* */
void print_instructions();
   /* */
char get_response();
   /* */
void get_range(int *p_first_number, int *p_last_number);
   /* */
void swap(int *p_first_number, int *p_second_number);
   /* */
int sum_evens(int first_number, int last_number, int sum);
   /* */
int is_even(int number);
   /* */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main() 
{
   int  first_number,  /* */
        last_number;   /* */
   char user_response; /* */
   int sum = 0; /* For debugging */

   /* Print the program heading and instructions */
   print_heading();
   print_instructions();

   
   /* Loop processing until the user quits */
   while ((user_response = get_response()) == 'y')
   {
      /* Get the range */
      get_range(&first_number, &last_number);

      /* Print the sum of the even whole numbers in the range, inclusively */
      if(first_number > last_number)
         swap(&first_number, &last_number);
      printf("\nProcessing the range %d to %d:", first_number, last_number);
      printf("\nThe sum of all even numbers in the range %d to %d is: %d",
         first_number, last_number, sum_evens(first_number, last_number, sum));
   }

   /* Print goodbye and terminate the program */
   printf("\nThanks for \"even summing\". Have a good day!");
   printf("\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                     Print the program heading                      */
/**********************************************************************/
void print_heading()
{
   printf("\n\n\n\n\n\n");
   printf("\n========================================================");
   printf("\n              Program Number: %d",    PROGRAM_NUMBER);
   printf("\n              Programmer: %s",        PROGRAMMER_NAME);
   printf("\n              PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   return;
}

/**********************************************************************/
/*                  Print the program instructions                    */
/**********************************************************************/
void print_instructions() 
{
   printf("\nThis program recursively calculates the sum of all");
   printf("\neven whole numbers between two numbers inclusively.");
   printf("\nYou are repeatedly asked to enter in the start and");
   printf("\nend of a range, and the sum of all even numbers in");
   printf("\nthat range is calculated and printed. Information");
   printf("\nabout the resursive action of the function is also");
   printf("\nprinted so the recursive nature of the calculation");
   printf("\n                 may be observed.");
   return;
}

/**********************************************************************/
/*               Get the response to continue or quit                 */
/**********************************************************************/
char get_response()
{
   char user_response[2]; /* */

   do
   {
      printf("\nDo you want to process another number? (Y = yes, N = no) ");
      scanf(" %1s", user_response);
      user_response[0] = tolower(user_response[0]);
   }
   while(user_response[0] != 'y' && user_response[0] != 'n');
   
   return user_response[0];
}

/**********************************************************************/
/*                  Get the range                    */
/**********************************************************************/
void get_range(int *p_first_number, int *p_last_number)
{
   do 
   {
      printf("\nEnter the first number (from %d to %d: ", 
         MINIMUM_VALUE, MAXIMUM_VALUE);
      scanf ("%d", p_first_number);
   }
   while (*p_first_number < MINIMUM_VALUE || *p_first_number > MAXIMUM_VALUE);

   do 
   {
      printf("\nEnter the last number (from %d to %d: ", 
         MINIMUM_VALUE, MAXIMUM_VALUE);
      scanf ("%d", p_last_number);
   }
   while (*p_first_number < MINIMUM_VALUE || *p_last_number > MAXIMUM_VALUE);

   return;
}

/**********************************************************************/
/*                         Swap two numbers                           */
/**********************************************************************/
void swap(int *first_number, int *second_number)
{
   *first_number += *second_number;
   *second_number = *first_number - *second_number;
   *first_number -= *second_number;
   return;
}

/**********************************************************************/
/*                                         */
/**********************************************************************/  /*Function only has one return statement */
int sum_evens(int first_number, int last_number, int sum) 
{
   printf("\n   Entering sum function for range %d to %d", 
      first_number, last_number);

   /* Recursive code to sum evens in a range*/

   if(first_number <= last_number)
   {
      if(is_even(first_number))
      {
         printf("\n      Adding: %d", first_number);
         sum += first_number;
         sum_evens(first_number + 1, last_number, sum);
      }
      else 
      {
         printf("\n      Skipping: %d", first_number);
         sum_evens(first_number + 1, last_number, sum);
      }
   }
   /* If current range < range end, enter sum function
       If even, print adding...
          Add current range to sum
       If not even, print skipping...
    Else if current range > range end, exit sum function */

    /* WORKS BUT GOES BACKWARDS WHEN EXITING SUM FUNCTION */


   printf("\n   Exiting sum function for range %d to %d with result: %d",
      first_number, last_number, sum);

   return sum; /* Only return statement in function */
}

/**********************************************************************/
/*                 Check to see if a number is even                   */
/**********************************************************************/
int is_even(int number) 
{
   return (number % 2 == 0) ? 1 : 0;
}