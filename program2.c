/**********************************************************************/
/*                                                                    */
/* Program Name: program2 - Miscillaneous Operations on Two Whole     */
/*                          Numbers                                   */
/* Author:       Josh Robertson                                       */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: September 12, 2023                                   */
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
/* This program gives the user 5 menu options for miscellaneous       */
/* operations with two whole numbers. It then asks for those two      */
/* numbers, performs the desired calculation, then displays the       */
/* result.                                                            */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER   "CS227"         /* PCC assigned course number */
#define PROGRAMMER_NAME "Robertson"     /* The programmer's last name */
#define PROGRAM_NUMBER  2               /* Teacher assigned program   */
                                        /* number                     */
#define MIN_MENU_CHOICE 1               /* Minimum valid menu choice  */
#define MAX_MENU_CHOICE 5               /* Maximum valid menu choice  */
#define MENU_CHOICE_ERR 1               /* Menu choice error code     */
#define QUIT            MAX_MENU_CHOICE /* Menu choice number to quit */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_menu();
   /* Print the program menu                                          */
int get_menu_choice(int p_menu_choice);
   /* Get the menu choice                                             */
void get_whole_numbers(int *p_first_number, int *p_second_number);
   /* Get the first and second numbers                                */
int add_two_whole_numbers(int p_first_number, int p_second_number);
   /* Add the two numbers                                             */
float power_two_whole_numbers(int p_first_number, int p_second_number);
   /* Raise the first number to the power of the second               */
int sum_range(int p_range_start, int p_range_end);
   /* Sum the range of the two numbers                                */
void order_two_numbers(int *p_first_number, int *p_second_number);
   /* Order the numbers from smallest to largest                      */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int first_number,
       second_number,
       menu_choice;

   /* Print program heading                                           */
   print_heading();

   /* Loop processing pairs of whole numbers until the user quits     */
   while (print_menu(),(menu_choice = get_menu_choice(menu_choice)) != QUIT)
   {
      /* Get two whole numbers                                        */
      get_whole_numbers(&first_number, &second_number);

      /* Process the menu choice                                      */
      switch(menu_choice)
      {
         /* Add two whole numbers                                     */
         case 1 :
            printf("\nThe sum of %d and %d is %d", 
                   first_number, second_number, 
                   add_two_whole_numbers(first_number, second_number));
            break;

         /* Raise the first number to the power of the second number  */
         case 2 :
            printf("\n%d raised to the power of %d = %1.6e", 
                   first_number, second_number, 
                   power_two_whole_numbers(first_number, second_number));
            break;

         /* Sum the range of the two numbers                          */
         case 3 :
            printf("\nThe sum of all numbers between %d and %d ", 
                   first_number, second_number);
            printf("(inclusively) is %d",
                   sum_range(first_number, second_number));
            break; 

         /* Order the two numbers                                     */
         case 4 : 
         {
            int original_first_number  = first_number;
            int original_second_number = second_number;

            order_two_numbers(&first_number, &second_number);
            printf("\n%d and %d properly ordered are: %d and %d", 
                   original_first_number, original_second_number, 
                   first_number, second_number);
            break;
         }

         /* Print out error message                                   */
         default :
         {
            printf("\n\nError #%d occurred in main()", MENU_CHOICE_ERR);
            printf(  "\nAn impossible menu choice error occurred.");
            printf(  "\nThe program is aborting.\n");
            exit(MENU_CHOICE_ERR);
            break;
         }
      }
   }
   /* Print goodbye and terminate the program */
   printf("\nThanks for processing numbers. Have a nice day! ;-)\n");
   return 0;
}

/**********************************************************************/
/*                     Print the program heading                      */
/**********************************************************************/
void print_heading()
{
   printf("\n========================================================");
   printf("\n              Program Number: %d",    PROGRAM_NUMBER);
   printf("\n              Programmer: %s",        PROGRAMMER_NAME);
   printf("\n              PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   printf("\n   Miscellaneous operations on your two whole numbers   ");
   return;
}

/**********************************************************************/
/*                           Print the menu                           */
/**********************************************************************/
void print_menu()
{
   printf("\n\nMake a selection from the following menu:");
   printf(  "\n- - - - - - - - - - - - - - - - - - - - -");
   printf(  "\n   1 - Add two whole numbers");
   printf(  "\n   2 - Raise the 1st number to the power of the 2nd");
   printf(  "\n   3 - Sum all numbers between two whole numbers");
   printf(  "\n   4 - Put two whole numbers into ascending order");
   printf(  "\n   5 - Quit");
   return;
}

/**********************************************************************/
/*                        Get the menu choice                         */
/**********************************************************************/
int get_menu_choice(int p_menu_choice)
{
   do 
   {
      printf("\nEnter your menu selection (1-5): ");
      scanf ("%d", &p_menu_choice);
   }  while (p_menu_choice < 1 || p_menu_choice > 5);

   return p_menu_choice;
}

/**********************************************************************/
/*                       Get two whole numbers                        */
/**********************************************************************/
void get_whole_numbers(int *p_first_number, int *p_second_number)
{
   printf("\nType in any two whole numbers now:");
   printf("\n   What is your first number: ");
   scanf ("%d", p_first_number);

   printf(  "   Give me your second number: ");
   scanf (  "%d", p_second_number);
   return;
}

/**********************************************************************/
/*                          Add two numbers                           */
/**********************************************************************/
int add_two_whole_numbers(int p_first_number, int p_second_number)
{
   return p_first_number + p_second_number;
}

/**********************************************************************/
/*            Raise one number to the power of the second             */
/**********************************************************************/
float power_two_whole_numbers(int p_first_number, int p_second_number)
{
   double result = pow((double)p_first_number, (double)p_second_number);

   return (float)result;

   /* return (float)pow((double)p_first_number, (double)p_second_number); */
}

/**********************************************************************/
/*                     Calculate sum of the range                     */
/**********************************************************************/
int sum_range(int p_range_start, int p_range_end)
{
   int range_sum = 0, /* The value of every whole number in the       */
                      /* range                                        */
       range_value;   /* Inclusive sum of whole numbers in the range  */
   
   /* Put two values in order if they are out of order                */
   order_two_numbers(&p_range_start, &p_range_end);

   for (range_value = p_range_start; range_value <= p_range_end; 
                                                          range_value++)
      range_sum += range_value;

   return range_sum;
}

/**********************************************************************/
/*          Put two values in order if they are out of order          */
/**********************************************************************/
void order_two_numbers(int *p_first_number, int *p_second_number)
{
   /* If the first number is larger than the second, swap the numbers */
   if (*p_first_number > *p_second_number)
   {
      int temporary_variable = *p_first_number;
      *p_first_number        = *p_second_number;
      *p_second_number       = temporary_variable;
   }
   return;
}