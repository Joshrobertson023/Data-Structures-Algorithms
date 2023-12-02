/**********************************************************************/
/*                                                                    */
/* Program Name: program7 - Demonstrate Various Search Algorithms     */
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
/* This program asks for a whole number, then searches through three  */
/* whole number arrays with three different searching algorithms:     */
/*    1. Sequential Search                                            */
/*    2. Probability Search                                           */
/*    3. Binary Search                                                */
/* For each searching algorithm, the program displays the whole       */
/* numbers with their corresponding index, the number the user        */
/* searched for, the search path taken by the algorithm, and whether  */
/* or not the search was successful.                                  */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER   "CS227"       /* PCC assigned course number   */
#define PROGRAMMER_NAME "Robertson"   /* The programmer's last name   */
#define PROGRAM_NUMBER  7             /* Teacher assigned program num */
#define DATA_SIZE       15            /* Size of the integer arrays   */
#define LAST_INDEX      DATA_SIZE - 1 /* Last index of the arrays     */
#define QUIT            0             /* Program exit value           */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_instructions();
   /* Print the program instructions                                  */
void get_data(int whole_number_data[], int last_index);
   /* Get the whole number data for the array                         */
void show_data(int whole_number_data[], int last_index,
               int search_target);
   /* Print the array indexes, array data, and user search target     */
void search_result(char result, int target_location);
   /* Print the search result                                         */
int sequential_search(int seq_data[], int last_index, int search_target,
                      int *p_target_location);
   /* Search whole numbers using a sequential search algorithm        */
int probability_search(int prb_data[], int last_index, int search_target,
                       int *p_target_location);
   /* Search whole numbers using a probability  search algorithm      */
int binary_search(int bin_data[], int last_index, int search_target,
                  int *p_target_location);
   /* Search whole numbers using a binary search algorithm            */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main() 
{
   int seq_data[DATA_SIZE], /* Whole number data for the sequential   */
                            /* search                                 */
       prb_data[DATA_SIZE], /* Whole number data for the probability  */
                            /* search                                 */
       bin_data[DATA_SIZE], /* Whole number data for the binary       */
                            /* search                                 */
       search_target,       /* User's whole number search target      */
       target_location;     /* Search target's location in the data   */

   /* Print the program heading and instructions                      */
   print_heading();
   print_instructions();

   /* Get the whole number data for each search algorithm             */
   get_data(seq_data, LAST_INDEX);
   get_data(prb_data, LAST_INDEX);
   get_data(bin_data, LAST_INDEX);
   
   /* Loop processing searching for whole numbers until user quits    */
   while(printf("\n\n\nEnter an integer search target (0 to quit): "),
      scanf("%d", &search_target), (search_target != QUIT))
   {
      /* Show the whole number data, search for the target using an   */
      /* Ordered Sequential Search, and print the search outcome      */
      printf("\n\nOrdered Sequential Search:");
      show_data(seq_data, LAST_INDEX, search_target);
      if(sequential_search(seq_data, LAST_INDEX, 
                           search_target, &target_location))
         search_result('S', target_location);
      else 
         search_result('U', target_location);

      /* Show the whole number data, search for the target using a    */
      /* Probability Search, and print the search outcome             */
      printf("\n\nProbability Search:");
      show_data(prb_data, LAST_INDEX, search_target);
      if(probability_search(prb_data, LAST_INDEX, 
                            search_target, &target_location))
         search_result('S', target_location);
      else 
         search_result('U', target_location);

      /* Show the whole number data, search for the target using a    */
      /* Binary Search, and print the search outcome                  */
      printf("\n\nBinary Search:");
      show_data(bin_data, LAST_INDEX, search_target);
      if(binary_search(bin_data, LAST_INDEX, 
                       search_target, &target_location))
         search_result('S', target_location);
      else
         search_result('U', target_location);
   }

   /* Say goodbye and terminate the program                           */
   printf("\nThanks for searching.  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                     Print the program heading                      */
/**********************************************************************/
void print_heading()
{
   printf("\n\n\n\n\n\n");
   printf("\n======================================================");
   printf("\n               Program Number: %d",    PROGRAM_NUMBER);
   printf("\n               Programmer: %s",        PROGRAMMER_NAME);
   printf("\n               PCC Course Number: %s", COURSE_NUMBER);
   printf("\n======================================================");
   return;
}

/**********************************************************************/
/*                  Print the program instructions                    */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program demonstrates various search algorithms.");
   printf("\nYou enter in any whole number, and the program will");
   printf("\nsearch for it in an ORDERED array of whole numbers");
   printf("\nusing each of the following search algorithms:");
   printf("\n     1. Ordered Sequential Search");
   printf("\n     2. Probability Search");
   printf("\n     3. Binary Search");
   printf("\nThe progress of each search is shown so the efficiency");
   printf("\nof the search algorithms can be compared.");
   return;
}

/**********************************************************************/
/*               Get the whole number data for the array              */
/**********************************************************************/
void get_data(int whole_number_data[], int last_index)
{
   int array_index; /* Index of every whole number                    */

   for(array_index = 0; array_index <= last_index; array_index++)
      whole_number_data[array_index] = (array_index * 5) + 10;

   return;
}

/**********************************************************************/
/*     Print the array indexes, array data, and user search target    */
/**********************************************************************/
void show_data(int whole_number_data[], int last_index,
               int search_target)
{
   int array_index; /* Index of every whole number                    */

   printf      ("\n   Array Index: ");
   for(array_index = 0; array_index <= last_index; array_index++)
      printf   ("[%2d]", array_index);

   printf      ("\n    Array Data: ");
   for(array_index = 0; array_index <= last_index; array_index++)
   {
      printf   (" %2d", whole_number_data[array_index]);
      if(array_index < last_index)
         printf(" ");
   }

   printf      ("\n   User Target:  %2d", search_target);

   return;
}

/**********************************************************************/
/*                       Print the search result                      */
/**********************************************************************/
void search_result(char result, int target_location)
{
   printf("\nSearch Outcome: ");

   if(result == 'S')
      printf   ("Successful - target found at index [%2d]",
         target_location);
   else
      if(result == 'U')
         printf("Unsuccessful - target not found");
      else
         printf("Undetermined");

   return;
}

/**********************************************************************/
/*    Search for a whole number using a sequential search algorithm   */
/**********************************************************************/
int sequential_search(int seq_data[], int last_index,
                      int search_target, int *p_target_location)
{
   int search_index = 0; /* Index searching through every whole number */

   printf("\n   Search Path: ");

   if(search_target <= seq_data[last_index])
   {
      while(search_index <= last_index && 
            search_target > seq_data[search_index])
      {
         printf("[%2d]", search_index);
         search_index++;
      }
      printf   ("[%2d]", search_index);
      *p_target_location = search_index;
   }
   else
   {
      printf   ("[%2d]", last_index);
      *p_target_location = last_index;
   }

   return(search_target == seq_data[*p_target_location]);
}

/**********************************************************************/
/*    Search for a whole number using a probability search algorithm  */
/**********************************************************************/
int probability_search(int prb_data[], int last_index, 
                       int search_target, int *p_target_location)
{
   int search_index = 0, /* Index searching through every whole number */
       temporary_number; /* Temporary number used to swap two numbers  */

   printf("\n   Search Path: ");

   while(search_index < last_index && 
         search_target != prb_data[search_index])
   {
      printf("[%2d]", search_index);
      search_index++;
   }
   printf   ("[%2d]", search_index);
   *p_target_location = search_index;

   if(search_index > 0 && search_index < LAST_INDEX)
   {
      temporary_number = prb_data[search_index];
      prb_data[search_index] = prb_data[search_index - 1];
      prb_data[search_index - 1] = temporary_number;
      *p_target_location -= 1;
   }

   return(search_target == prb_data[*p_target_location]);
}

/**********************************************************************/
/*      Search for a whole number using a binary search algorithm     */
/**********************************************************************/
int binary_search(int bin_data[], int last_index,
                  int search_target, int *p_target_location)
{
   int beginning_index = 0,    /* Start of the data being searched    */
       middle_index = 0,       /* Middle of the data being searched   */
       end_index = last_index; /* End of the data being searched      */

   printf("\n   Search Path: ");

   while(beginning_index <= end_index)
   {
      middle_index = (beginning_index + end_index) / 2;
      printf("[%2d]", middle_index);

      if(search_target > bin_data[middle_index])
         beginning_index = (middle_index + 1);
      else
         if(search_target < bin_data[middle_index])
            end_index = middle_index - 1;
         else
            beginning_index = (end_index + 1);
   }
   *p_target_location = middle_index;

   return (search_target == bin_data[*p_target_location]);
}