/**********************************************************************/
/*                                                                    */
/* Program Name: program5 - Recursive Summing of Even Numbers Between */
/*                          Two Whole Numbers                         */
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
/* This program asks the user if they would like to process a range   */
/* of numbers, then asks for the start and the end of the range. It   */
/* swaps the two numbers if they are not in ascending order. It then  */
/* prints out the sum of all the even numbers in the range            */
/* inclusively, then asks the user if they would like to process      */
/* another range.                                                     */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <ctype.h>

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER   "CS227"     /* PCC assigned course number     */
#define PROGRAMMER_NAME "Robertson" /* The programmer's last name     */
#define PROGRAM_NUMBER  4           /* Teacher assigned program num   */
#define MINIMUM_VALUE   -5000       /* Minimum valid start of range   */
#define MAXIMUM_VALUE   5000        /* Maximum valid end of range     */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_instructions();
   /* Print the program instructions                                  */
char get_response();
   /* Get the response to continue or quit                            */
void get_range(int *p_first_number, int *p_last_number);
   /* Get the start and end of the range                              */
void swap_numbers(int *p_first_number, int *p_second_number);
   /* Swap two numbers                                                */
int sum_evens(int first_number, int last_number);
   /* Recursively sum all even numbers in the range inclusively       */
int is_even(int number);
   /* Check if the number is even                                     */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main() 
{
   int  range_end,   /* End of the whole number range                 */
        range_start; /* Start of the whole number range               */

   /* Print the program heading and instructions                      */
   print_heading();
   print_instructions();

   /* Loop processing until the user quits                            */
   while(get_response() == 'y')
   {
      /* Get the start and end of the range                           */
      get_range(&range_start, &range_end);

      /* Print the sum of the even whole numbers in the range,        */
      /* inclusively                                                  */
      if(range_start > range_end)
         swap_numbers(&range_start, &range_end);
      printf("\nProcessing the range %d to %d:", range_start, range_end);
      printf("\nThe sum of all even numbers in the range %d to %d is: %d",
         range_start, range_end, sum_evens(range_start, range_end));
   }

   /* Say goodbye and terminate the program                           */
   printf("\nThanks for \"even summing\". Have a good day!");
   printf("\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                     Print the program heading                      */
/**********************************************************************/
void print_heading()
{
   printf("\n\n\n\n\n");
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
/*                Get the response to continue or quit                */
/**********************************************************************/
char get_response()
{
   char response[2]; /* The user's response                           */

   do
   {
      printf("\n\nDo you want to process another range? ");
      printf("(Y = yes, N = no) ");
      scanf ("%1s", response);
      response[0] = tolower(response[0]);
   }
   while(response[0] != 'y' && response[0] != 'n');
   
   return response[0];
}

/**********************************************************************/
/*                 Get the start and end of the range                 */
/**********************************************************************/
void get_range(int *p_range_start, int *p_range_end)
{
   do 
   {
      printf("\nEnter the first number (from %d to %d: ", 
         MINIMUM_VALUE, MAXIMUM_VALUE);
      scanf ("%d", p_range_start);
   }
   while (*p_range_start < MINIMUM_VALUE || 
          *p_range_start > MAXIMUM_VALUE);

   do 
   {
      printf("\nEnter the last number (from %d to %d: ", 
         MINIMUM_VALUE, MAXIMUM_VALUE);
      scanf ("%d", p_range_end);
   }
   while (*p_range_end < MINIMUM_VALUE || 
          *p_range_end > MAXIMUM_VALUE);

   return;
}

/**********************************************************************/
/*                          Swap two numbers                          */
/**********************************************************************/
void swap_numbers(int *p_first_number, int *p_second_number)
{
   *p_first_number += *p_second_number;
   *p_second_number = *p_first_number - *p_second_number;
   *p_first_number -= *p_second_number;
   return;
}

/**********************************************************************/
/*      Recursively sum all even numbers in the range inclusively     */
/**********************************************************************/
int sum_evens(int range_start, int range_end) 
{
   int range_sum = 0; /* Sum of the even numbers in the range         */

   printf("\n   Entering sum function for range %d to %d", 
      range_start, range_end);

   if(range_start <= range_end)
   {
      if(is_even(range_start))
      {
         printf("\n      Adding: %d", range_start);
         range_sum = range_start + sum_evens(range_start + 1, range_end);
      }
      else 
      {
         printf("\n      Skipping: %d", range_start);
         range_sum = sum_evens(range_start + 1, range_end);
      }
   }

   printf("\n   Exiting sum function for range %d to %d with result: %d",
      range_start, range_end, range_sum);

   return range_sum;
}

/**********************************************************************/
/*                     Check if the number is even                    */
/**********************************************************************/
int is_even(int number) 
{
   return (number % 2 == 0) ? 1 : 0;
}