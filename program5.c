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


/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main() 
{
   int first_number = 0, /* */
       last_number = 0;   /* */
   char user_response;  /* */

   /* Print the program heading and instructions */
   print_heading();
   print_instructions();

   
   /* Loop processing until the user quits */
   while ((user_response = get_response()) == 'y')
   {
      /* */
      get_range(&first_number, &last_number);
   }

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
      printf("\nDo you want to process another number? (Y = yes, N = no)");
      scanf(" %1s", user_response);
      /*response = tolower(response);*/
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
   while (p_first_number < MINIMUM_VALUE || p_first_number > MAXIMUM_VALUE);

   do 
   {
      printf("\nEnter the last number (from %d to %d: ", 
         MINIMUM_VALUE, MAXIMUM_VALUE);
      scanf ("%d", p_last_number);
   }
   while (p_last_number < MINIMUM_VALUE || p_last_number > MAXIMUM_VALUE);

   return;
}