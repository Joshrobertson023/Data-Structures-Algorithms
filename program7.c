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

/* TO-DO */
/* Rename array[] to something meaningful throught program */

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
void show_data(int array[], int last_index, int search_target);
   /* */
void search_result(char result, int target_location);
   /* */
int sequential_search(int array[], int last_index, int search_target, int *p_target_location);
   /* */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main() 
{
   int seq_data[DATA_SIZE], /* */
       prb_data[DATA_SIZE], /* */
       bin_data[DATA_SIZE], /* */
       search_target,       /* */
       target_location;     /* */

   /* Print the program heading and instructions                      */
   printf("\n\n\n\n\n\n\n");
   print_heading();
   print_instructions();

   /* Get the data for each search algorithm */
   get_data(seq_data, LAST_INDEX);
   get_data(prb_data, LAST_INDEX);
   get_data(bin_data, LAST_INDEX);

   /* For debugging */
   /*int index;
   for(index = 0; index <= LAST_INDEX; index++) {
      printf("\n%d\n", seq_data[index]);
   }*/

   /* Loop processing ... until user quits */
   while(printf("\n\n\nEnter an integer search target (0 to quit): "), 
      scanf("%d", &search_target), (search_target != QUIT))
   {
      /* Ordered Sequential Search */
      printf("\n\n\nOrdered Sequential Search:");
      show_data(seq_data, LAST_INDEX, search_target);
      if(sequential_search(seq_data, LAST_INDEX, search_target, &target_location))
         search_result('S', target_location);
      else 
         search_result('U', target_location);
   }

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
   return;
}

/**********************************************************************/
/*                                     */
/**********************************************************************/
void get_data(int array[], int last_index)
{
   int array_index; /* */

   for(array_index = 0; array_index <= last_index; array_index++)
      array[array_index] = (array_index * 5) + 10;

   return;
}

/**********************************************************************/
/*                                     */
/**********************************************************************/
void show_data(int array[], int last_index, int search_target)
{
   int array_index; /* */

   printf("\n   Array Index: ");
   for(array_index = 0; array_index <= last_index; array_index++)
      printf("[%2d]", array_index);

   printf("\n    Array Data: ");
   for(array_index = 0; array_index <= last_index; array_index++)
      printf(" %2d ", array[array_index]);

   printf("\n   User Target:  %d", search_target);

   return;
}

/**********************************************************************/
/*                                     */
/**********************************************************************/
void search_result(char result, int target_location)
{
   printf("\nSearch outcome: ");

   if(result == 'S')
      printf("Successful - target found at index [%2d]", target_location);
   else
      if(result == 'U')
         printf("Unsuccessful - target not found");
      else
         printf("Undetermined");

   return;
}

/**********************************************************************/
/*                                     */
/**********************************************************************/
int sequential_search(int array[], int last_index, int search_target, int *p_target_location)
{
   int search_index = 0; /* */

   printf("\n   Search Path: ");

   if(search_target < array[last_index])
   {
      /* Find first element greater than or equal to target */
      while(search_index <= last_index && search_target > array[search_index])
      {
         printf("[%2d]", search_index);
         search_index++;
      }
      *p_target_location = search_index;
   }
   else
      *p_target_location = last_index;

   return(search_target == array[*p_target_location]);
}

/**********************************************************************/
/*                                     */
/**********************************************************************/
   /* No found variable, return (expression evaluating true or false) */
   /* Print statements that add index every time index value is looked at (search path) */
      /* Should be able to remove without breaking code */
   /* Has swap code */

/**********************************************************************/
/*                                     */
/**********************************************************************/
   /* No found variable, return (expression evaluating true or false) */
   /* Print statements that add index every time index value is looked at (search path) */
      /* Should be able to remove without breaking code */