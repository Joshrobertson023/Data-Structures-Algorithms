/**********************************************************************/
/*                                                                    */
/* Program Name: program6 - 
/* Author:       Josh Robertson                                       */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: November 22, 2023                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* 
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER     "CS227"      /* PCC assigned course number  */
#define PROGRAMMER_NAME   "Robertson"  /* The programmer's last name  */
#define PROGRAM_NUMBER    6            /* */
#define QUIT              0            /* */
#define MAXIMUM_ID        999999       /* */
#define MINIMUM_ID        1            /* */
#define LIST_HEADER       MINIMUM_ID-1 /* */
#define LIST_TRAILER      MAXIMUM_ID+1 /* */
#define HEADER_ALLOC_ERR  1            /* */
#define TRAILER_ALLOC_ERR 2            /* */
#define ID_ALLOC_ERR      3            /* */

/**********************************************************************/
/*                        Program structures                          */
/**********************************************************************/
/* A student record */
struct student
{
   int student_id;                 /* */
   struct student *p_next_student; /* */
};
typedef struct student STUDENT;

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_instructions();
   /* Print the program instructions                                  */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int *p_empty_student_id_list; /* */

   /* Print the program heading */
   print_heading();

   /* Loop processing ... until the user quits */
   while(print_instructions(), (get_response() == 'y'))
   {
      /* Create empty student id list */
      p_empty_student_id_list = create_list();

      /* */
      while(printf("Enter the next student id"))
   }
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
/*                Get the response to continue or quit                */
/**********************************************************************/
char get_response()
{
   char response[2]; /* Response to continue or quit */

   do
   {
      printf("\n\nDo you want to process another range? ");
      printf("(Y = yes, N = no): ");
      scanf ("%1s", response[0]);
      response[0] = tolower(response[0]);
   }
   while(response[0] != 'y' && response[0] != 'n');
   
   return response[0];
}

/**********************************************************************/
/* Create empty student ID list (linked list?) with header and trailer
/**********************************************************************/
STUDENT *create_list() /* TODO: Name them students or nodes since just header and trailer? */
{
   STUDENT *p_new_student; /* Points to the newly created list */

   /* Get a new node and make it the list header */
   if((p_new_student = (STUDENT *)malloc(sizeof(STUDENT))) == NULL)
   {
      printf("\nError #%d occurred in create_list().", HEADER_ALLOC_ERR);
      printf("\nCannot allocate memory for the list header.");
      printf("\nThe program is aborting.");
      exit  (HEADER_ALLOC_ERR);
   }
   p_new_student->student_id = LIST_HEADER;

   /* Get a new node and attach to end of list as the trailer */
   if((p_new_student->p_next_student = (STUDENT *) malloc(sizeof(STUDENT))) == NULL)
   {
      printf("\nError #%d occurred in create_list().", TRAILER_ALLOC_ERR);
      printf("\nCannot allocate memory for the list trailer.");
      printf("\nThe program is aborting.");
      exit  (TRAILER_ALLOC_ERR);
   }
   p_new_student->p_next_student->student_id = LIST_TRAILER;
   p_new_student->p_next_student->p_next_student = NULL;

   /* Return the pointer to the newly created linked list */
   return p_new_student;
}