/**********************************************************************/
/*                                                                    */
/* Program Name: program6 - */
/* Author:       Josh Robertson                                       */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: November 22, 2023                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* */
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

void print_instructions();

char get_response();

STUDENT *create_list();

void insert_student(STUDENT *p_student_list, int student_id);

void print_list(STUDENT *p_student);

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int     student_id;      /* */
   STUDENT *p_student_list; /* */

   /* Print the program heading */
   print_heading();

   /* Loop processing ... until the user quits */
   while(print_instructions(), (get_response() == 'y'))
   {
      /* Create empty student id list */
      p_student_list = create_list();

      /* */
      while(printf("\nEnter the next student id (0 = quit): "), 
            scanf("%d", &student_id),
            student_id != QUIT)
      {
         if(student_id > MAXIMUM_ID)
            printf("    Id rejected - it cannot exceed 999999");
         else
            insert_student(p_student_list, student_id);
      }

      /* Print unsorted list id */
      print_list(p_student_list);
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
   printf("\n\n\n");
   printf("\n    This program maintains a list of students by their");
   printf("\n    id number. After entry of all id's, it sorts them");
   printf("\n    into ascending order, then removes all duplicates.");
   return;
}

/**********************************************************************/
/*                Get the response to continue or quit                */
/**********************************************************************/
char get_response()
{
   char response[2]; /* Response to continue or quit */

   printf("\n\n");

   do
   {
      printf("\nDo you want to enter another student id list? ");
      printf("(Y = yes, N = no): ");
      scanf ("%1c", &response[0]);
      response[0] = tolower(response[0]);
   }
   while(response[0] != 'y' && response[0] != 'n');
   
   return response[0];
}

/**********************************************************************/
/* Create empty student id list (linked list?) with header and trailer */
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

/**********************************************************************/
/* Insert student in list */
/**********************************************************************/
void insert_student(STUDENT *p_student_list, int student_id) /* TODO: change to p_next_student? My notes say so... */
{
   STUDENT *p_new_student,                                       /* Points to newly created student */
           *p_current_student  = p_student_list->p_next_student, /* Points to each data node ???????? */
           *p_previous_student = p_student_list;                 /* Points to previous data node */

   if((p_new_student = (STUDENT *) malloc(sizeof(STUDENT))) == NULL)
   {
      printf("\nError #%d occurred in insert_student().", ID_ALLOC_ERR);
      printf("\nCannot allocate memory for the student node."); /* Re-write? */
      printf("\nThe program is aborting.");
      exit  (ID_ALLOC_ERR);
   }

   p_new_student->student_id          = student_id;
   p_new_student->p_next_student      = p_current_student;
   p_previous_student->p_next_student = p_new_student;

   return;
}

/**********************************************************************/
/* Print the student ids from list */
/**********************************************************************/
void print_list(STUDENT *p_student)
{
   printf("The unsorted student id list, as entered, is: ");

   while(p_student->p_next_student != NULL)
   {
      if(p_student->student_id != QUIT)
         printf("\n                      %6d", p_student->student_id);
      p_student = p_student->p_next_student;
   }

   return;
}