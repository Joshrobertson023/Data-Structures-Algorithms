/**********************************************************************/
/*                                                                    */
/* Program Name: program1                                             */
/* Author: Josh Robertson                                             */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course: cs227, Data Structures and Algorithms                      */
/* Date Written: September 2, 2023                                    */
/*                                                                    */
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
/*                                        Josh Robertson              */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program asks the user to enter two numbers, then prints out   */
/* the sum of the range of those two numbers.                         */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>

/**********************************************************************/
/*                       Symbolic Constants                           */
/**********************************************************************/
#define COURSE_NUMBER     "CS227"       /* PCC assigned course number */
#define PROGRAMMER_NAME   "Robertson"   /* The programmer's last name */
#define PROGRAM_NUMBER    1             /* Teacher assigned program   */
                                        /* number                     */

/**********************************************************************/
/*                       Function Prototypes                          */
/**********************************************************************/
void print_heading();
   /* Print the program heading.                                      */
int get_range(int *range_start, int *range_end);
   /* Get the two range values.                                       */
int sum_range(int range_start, int range_end);
   /* Sum the range of the two values.                                */

/**********************************************************************/
/*                         Main Function                              */
/**********************************************************************/
int main()
{
   int range_start,    /* The first value the user will enter         */
       range_end,      /* The second value the user will enter        */
       range_sum;      /* The sum of the range of the two values      */

   /* Print the program heading.                                      */
   printf("\n\n\n\n\n");
   print_heading();
   printf("\n");
   printf("\nI'll sum whole numbers in a number range (inclusively).");
   printf("\n-------------------------------------------------------");
   
   /* Get the range values.                                           */
   printf("\nEnter a range of whole numbers now, lower number first: ");
   get_range(&range_start, &range_end);
   
   /* Calculate and print the sum of the range.                       */
   range_sum = sum_range(range_start, range_end);
   printf("The sum of all numbers between %d and %d (inclusively) is %d"
           , range_start, range_end, range_sum);

   /* Print goodbye and terminate the program.                        */
   printf("\n\nThanks for your range summing. Have a nice day! ;-)");
   printf("\n\n\n\n");

   return 0;
}

/**********************************************************************/
/*                    Print the program heading                       */
/**********************************************************************/
void print_heading()
{
   printf("\n========================================================");
   printf("\n              Program Number: %d",      PROGRAM_NUMBER   );
   printf("\n              Programmer: %s",          PROGRAMMER_NAME  );
   printf("\n              PCC Course Number: %s",   COURSE_NUMBER    );
   printf("\n========================================================");
}

/**********************************************************************/
/*                    Get the values for the range                    */
/**********************************************************************/
int get_range(int *p_range_start, int *p_range_end)
{
   printf("\n   What is your small number: ");
   scanf("%d", p_range_start);

   printf("   Give me your large number: ");
   scanf("%d", p_range_end);

   return 0;
}

/**********************************************************************/
/*                    Calculate the sum of the range                  */
/**********************************************************************/
int sum_range(int range_start, int range_end)
{
   int range_sum = 0, /* The value of every whole number in the       */
                      /* range                                        */
       range_value;   /* Inclusive sum of whole numbers in the range  */
   
   for (range_value = range_start; range_value <= range_end; range_value++)
      range_sum += range_value;

   
   return range_sum;
}