/**********************************************************************/
/*                                                                    */
/* Program Name: program7 - Demonstrating Various Search Algorithms   */
/* Author:       Josh Robertson                                       */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: November 4, 2023                                     */
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
/**********************************************************************/

#include <stdio.h>

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER   "CS227"       /* PCC assigned course number   */
#define PROGRAMMER_NAME "Robertson"   /* The programmer's last name   */
#define PROGRAM_NUMBER  7             /* Teacher assigned program num */
#define DATA_SIZE       15            /* */
#define LAST_INDEX      DATA_SIZE - 1 /* */
#define QUIT            0             /* */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_instructions();
   /* Print the program instructions                                  */
void get_data(int array[], int last_index); /* Rename array to something meaningful */
   /* Get the data for the array */


/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main() 
{
   int seq_data[DATA_SIZE], /* */
       prb_data[DATA_SIZE], /* */
       bin_data[DATA_SIZE]; /* */

   /* Print the program heading and instructions                      */
   printf("\n\n\n\n\n\n\n")
   print_heading();
   print_instructions();

   /* Get the data for each search algorithm */
   get_data(seq_data[], LAST_INDEX);
   get_data(prb_data[], LAST_INDEX);
   get_data(bin_data[], LAST_INDEX);

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
   printf("\nThis program demonstrates various search algorithms");
   printf("\nYou enter in any whole number, and the program will");
   printf("\nsearch for it in an ORDERED array of whole numbers");
   printf("\nusing each of the following search algorithms:");
   printf("\n     1. Ordered Sequentail Serach");
   printf("\n     2. Probability Search");
   printf("\n     3. Binary Search");
   printf("\nThe progress of each search is shown so the efficiency");
   printf("\nof the search algorithms can be compared.");
}

/**********************************************************************/
/*                                     */
/**********************************************************************/
void get_data(int array[], int last_index)
{
   
}