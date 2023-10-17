/**********************************************************************/
/*                                                                    */
/* Program Name: program3 - Processing experimental scientific data   */
/* Author:       Josh Robertson                                       */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: September 30, 2023                                   */
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
/* This program handles experimental scientific data. It asks for the */
/* experimental scientific data, sorts it into descneding order, then */
/* prints it in that order. It also sums the data and prints the      */
/* total.                                                             */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <stdlib.h>

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER    "CS227"     /* PCC assigned course number    */
#define PROGRAMMER_NAME  "Robertson" /* The programmer's last name    */
#define PROGRAM_NUMBER   3           /* Teacher assigned program num  */
#define MINIMUM_QUANTITY 2           /* Minimum valid amount          */
#define MAXIMUM_QUANTITY 100         /* Maximum valid amount          */
#define QUIT             0           /* Program exit value            */
#define DATA_ALLOC_ERR   1           /* Data memory allocation error  */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_instructions();
   /* Print the program instructions                                  */
int get_quantity();
   /* Get the quantity of experimental scientific data values         */
void get_experimental_data(float *p_data_start, int quantity);
   /* Get the experimental data converting negatives to positives     */
void sort_data(float *p_data_start, int quantity);
   /* Sort the experimental scientific data into descending order     */
void print_data(float *p_data_start, int quantity);
   /* Print the exprimental scientific data with duplicates noted     */
float sum_data(float *p_data_start, int quantity);
   /* Sum the experimental scientific data                            */
void print_total(float *p_data_start, int quantity);
   /* Print the total sum of the experimental scientific data         */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int   quantity; /* Number of experimental scientific data          */
   float *p_data;  /* Points to the database of experimental          */
                   /* scientific data                                 */

   /* Print the program heading                                       */
   printf("\n\n\n\n\n");
   print_heading();

   /* Loop processing experimental scientific data until the user     */
   /* quits                                                           */
   while(print_instructions(), (quantity = get_quantity()) != QUIT)
   {
      /* Allocate memory the for scientific data and abort if memory   */
      /* is not available                                              */
      if ((*p_data = (float*)malloc(sizeof(*p_data) * quantity)) == NULL)
      {
         printf("\n\nError #%d occurred in main().", DATA_ALLOC_ERR);
         printf(  "\nA data allocation error occurred.");
         printf(  "\nThe program is aborting.\n");
         exit  (DATA_ALLOC_ERR);
         break;
      }

      /* Get, sort, and print the experimental scientific data and    */
      /* its sum                                                      */
      get_experimental_data(&p_data, quantity);
      sort_data(&p_data, quantity);
      print_data(&p_data, quantity);
      print_total(&p_data, quantity);
      /* Release the memory allocated to the experimental scientific  */
      /* data                                                         */
      free(p_data);
   }

   /* Say goodbye and terminate the program                           */
   printf("\n\nThanks for processing data. Have a nice day! ;-)");
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
   printf("\n   Miscellaneous operations on your two whole numbers   ");
   return;
}

/**********************************************************************/
/*                  Print the program instructions                    */
/**********************************************************************/
void print_instructions()
{
   printf("\n\n\nThis program processes experimental scientific data");
   printf(    "\n- - - - - - - - - - - - - - - - - - - - - - - - - -");
   return;
}

/**********************************************************************/
/*          Get the quantity of experimental scientific data          */
/**********************************************************************/
int get_quantity()
{
   int quantity; /* Amount of experimental scientific data           */

   do 
   {
      printf("\nHow many data values are there (%d to %d, %d=quit): ", 
         MINIMUM_QUANTITY, MAXIMUM_QUANTITY, QUIT);
      scanf ("%d", &quantity);
   } while((quantity < MINIMUM_QUANTITY || quantity > 
                            MAXIMUM_QUANTITY) && quantity != QUIT);

   return quantity;
}

/**********************************************************************/
/*     Get the experimental data converting negatives to positives    */
/**********************************************************************/
void get_experimental_data(float *p_data_start, int quantity)
{
   int   counter; /* Count the data values being entered              */
   float *p_data; /* Points to the experimental scientific data       */

   for (p_data = p_data_start, counter = 1; (p_data - p_data_start) 
                                        < quantity; p_data++, counter++)
   {
      printf("\n   Enter data value %d: ", counter);
      scanf ("%f", p_data);

      /* If the experimental scientific data is negative, negate it   */
      if (*p_data < 0)
         *p_data = -*p_data;
   }

   return;
}

/**********************************************************************/
/*     Sort the experimental scientific data into descending order    */
/**********************************************************************/
void sort_data(float *p_data_start, int quantity)
{
   float *p_inner, /* Second value being compared                     */
         *p_outer; /* First value being compared                      */

   /* Place the largest value on top                                  */
   for (p_outer = p_data_start; (p_outer - p_data_start) < quantity - 1; 
                                                              p_outer++)
   {
      for (p_inner = p_outer + 1; (p_inner - p_data_start) < quantity; 
                                                              p_inner++)
      {
         if (*p_inner > *p_outer)
         {
            float temp; /* Temporary                                  */
            temp = *p_inner;
            *p_inner = *p_outer;
            *p_outer = temp;
         }
      }
   }

   return;
}

/**********************************************************************/
/*     Print the exprimental scientific data with duplicates noted    */
/**********************************************************************/
void print_data(float *p_data_start, int quantity)
{
   /* Use one pointer and pointer arithmetic */

   float *p_data; /* Points to the experimental scintific data        */
   
   printf("\n\nThe data in descending order (with duplicates noted):");
   printf(  "\n- - - - - - - - - - - - - - - - - - - - - - - - - - -");

   for (p_data = p_data_start; (p_data - p_data_start) < quantity; 
                                                               p_data++)
   {
      printf("\n                      %0.2f", *p_data);
   }

   return;
}

/**********************************************************************/
/*                 Sum the experimental scientific data               */
/**********************************************************************/
float sum_data(float *p_data_start, int quantity)
{
   float *p_data, /* Points to the experimental scientific data       */
         sum;     /* Sum of the experimental scientific data          */

   for (p_data = p_data_start; (p_data - p_data_start) < quantity; 
                                                               p_data++)
      sum += *p_data;

   return sum;
}

/**********************************************************************/
/*       Print the total sum of the experimental scientific data      */
/**********************************************************************/
void print_total(float *p_data_start, int quantity)
{
   printf("\n                 - - - - -");
   printf("\n                      %0.2f total", sum_data(&p_data_start, 
                                                             quantity));
   return;
}