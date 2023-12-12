/**********************************************************************/
/*                                                                    */
/* Program Name: program6 - Maintain a student linked list by id      */
/* Author:       Josh Robertson                                       */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: November 22, 2023                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program creates an empty linked list. It asks for each        */
/* student id and adds that id into the linked list in an unordered   */
/* fashion. The unsorted list is printed along with it's length. The  */
/* list is sorted into ascending order by id, then printed. The       */
/* duplicate ids are deleted then the list is printed again.          */
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
#define PROGRAM_NUMBER    6            /* Teacher assigned program num*/
#define QUIT              0            /* Program exit value          */
#define MAXIMUM_ID        999999       /* Maximum student id number   */
#define MINIMUM_ID        1            /* Minimum student id number   */
#define LIST_HEADER       MINIMUM_ID-1 /* Student list header value   */
#define LIST_TRAILER      MAXIMUM_ID+1 /* Student list trailer value  */
#define HEADER_ALLOC_ERR  1            /* Header memory alloc error   */
#define TRAILER_ALLOC_ERR 2            /* Trailer memory alloc error  */
#define ID_ALLOC_ERR      3            /* Student id memory alloc err */

/**********************************************************************/
/*                        Program structures                          */
/**********************************************************************/
/* Student id linked list node                                        */
struct student
{
   int            student_id;      /* Student id number               */
   struct student *p_next_student; /* Points to next student id node  */
};
typedef struct student STUDENT;

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_instructions();
   /* Print the program instructions                                  */
char get_response();
   /* Get the response to continue or quit                            */
STUDENT *create_list();
   /* Create empty student id linked list with header and trailer     */
   /* nodes                                                           */
void insert_student(STUDENT *p_student_list, int student_id);
   /* Insert new student node into the student id linked list         */
void print_list(STUDENT *p_student);
   /* Print the student ids from the student id linked list           */
int get_number_ids(STUDENT *p_student);
   /* Get the number of student ids in the student id linked list     */
void sort_list(STUDENT *p_student_list, int quantity);
   /* Sort the student id linked list into ascending order by id num  */
void remove_duplicate_ids(STUDENT *p_student_list);
   /* Remove duplicate student ids from the student id linked list    */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   STUDENT *p_student_id_list, /* Points to the student linked list   */
           *p_student;         /* Points to each student              */
   int     student_id;         /* The id number of the student        */

   /* Print the program heading                                       */
   print_heading();

   /* Loop processing student id linked lists until the user quits    */
   while(print_instructions(), (get_response() == 'y'))
   {
      /* Create a new unordered student id linked list with header    */
      /* and trailer                                                  */
      p_student_id_list = create_list();

      /* Loop processing entering student ids until the user quits    */
      while(printf("Enter the next student id (0 = quit): "), 
            scanf("%d", &student_id),
            student_id != QUIT)
      {
         if(student_id > MAXIMUM_ID)
            printf("   Id rejected - it cannot exceed %d\n", MAXIMUM_ID);
         else
            insert_student(p_student_id_list, student_id);
      }

      /* Print the unsorted student id linked list                    */
      printf("\n\nThe unsorted student id list, as entered, is:");
      print_list(p_student_id_list);
      printf("\nThe length of the unsorted student id list is: %d", 
         get_number_ids(p_student_id_list));

      /* Sort the student id linked list and print the student ids    */
      sort_list(p_student_id_list, get_number_ids(p_student_id_list));
      printf("\n\nThe student id list, sorted by ascending id, is:");
      print_list(p_student_id_list);
      printf("\nThe length of the sorted student id list is: %d",
         get_number_ids(p_student_id_list));

      /* Remove duplicate student ids from the student id linked list */
      if(p_student_id_list->p_next_student->student_id != LIST_TRAILER)
         remove_duplicate_ids(p_student_id_list);
      printf("\nThe student id list, with duplicate id's removed, ");
      printf(  "sorted ascending by id, is:");
      print_list(p_student_id_list);
      printf("\nThe length of the cleaned and sorted student id list ");
      printf(  "is: %d", get_number_ids(p_student_id_list));

      /* Free the memory of the header, trailer, and student nodes    */
      p_student = p_student_id_list;
      while(p_student->student_id != LIST_TRAILER)
      {
         p_student_id_list = p_student_id_list->p_next_student;
         free(p_student);
         p_student = p_student_id_list;
      }
      free(p_student);
   }

   /* Say goodbye and terminate the program                           */
   printf("\n\nThanks for managing student ids. Have a nice day :)");
   printf("\n\n\n\n\n");
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
   char response[2]; /* Response to continue or quit                  */

   printf("\n\n");

   do
   {
      printf("Do you want to enter another student id list? ");
      printf("(Y = yes, N = no): ");
      scanf (" %1c", &response[0]);
      response[0] = tolower(response[0]);
   }
   while(response[0] != 'y' && response[0] != 'n');
   
   return response[0];
}

/**********************************************************************/
/* Create empty student id linked list with header and trailer nodes  */
/**********************************************************************/
STUDENT *create_list()
{
   STUDENT *p_new_student_list; /* Points to the newly created list   */

   if((p_new_student_list = (STUDENT *)malloc(sizeof(STUDENT))) == NULL)
   {
      printf("\nError #%d occurred in create_list().", HEADER_ALLOC_ERR);
      printf("\nCannot allocate memory for the student id list header.");
      printf("\nThe program is aborting.");
      exit  (HEADER_ALLOC_ERR);
   }
   p_new_student_list->student_id = LIST_HEADER;

   if((p_new_student_list->p_next_student = (STUDENT *) 
       malloc(sizeof(STUDENT))) == NULL)
   {
      printf("\nError #%d occurred in create_list().", TRAILER_ALLOC_ERR);
      printf("\nCannot allocate memory for the student id list trailer.");
      printf("\nThe program is aborting.");
      exit  (TRAILER_ALLOC_ERR);
   }
   p_new_student_list->p_next_student->student_id = LIST_TRAILER;
   p_new_student_list->p_next_student->p_next_student = NULL;

   return p_new_student_list;
}

/**********************************************************************/
/*       Insert new student node into the student id linked list      */
/**********************************************************************/
void insert_student(STUDENT *p_student_id_list, int student_id)
{
   STUDENT *p_new_student; /* Points to newly created student node    */

   if((p_new_student = (STUDENT *) malloc(sizeof(STUDENT))) == NULL)
   {
      printf("\nError #%d occurred in insert_student().", ID_ALLOC_ERR);
      printf("\nCannot allocate memory for a new student id node.");
      printf("\nThe program is aborting.");
      exit  (ID_ALLOC_ERR);
   }

   p_new_student->student_id = student_id;
   p_new_student->p_next_student = p_student_id_list->p_next_student;
   p_student_id_list->p_next_student = p_new_student;

   return;
}

/**********************************************************************/
/*       Print the student ids from the student id linked list        */
/**********************************************************************/
void print_list(STUDENT *p_student)
{
   if(p_student->p_next_student->student_id == LIST_TRAILER)
      printf("\n   The student id list is empty.");
   else
      while(p_student = p_student->p_next_student,
            p_student->student_id != LIST_TRAILER)
         printf("\n                      %6d", p_student->student_id);

   return;
}

/**********************************************************************/
/*     Get the number of student ids in the student id linked list    */
/**********************************************************************/
int get_number_ids(STUDENT *p_student_list)
{
   int     number_student_ids = 0;      /* Number of student ids      */
   STUDENT *p_student = p_student_list; 
                                    /* Points to each student node    */

   while(p_student->p_next_student->student_id != LIST_TRAILER)
   {
      number_student_ids += 1;
      p_student = p_student->p_next_student;
   }

   return number_student_ids;
}

/**********************************************************************/
/* Sort the student id linked list into ascending order by id number  */
/**********************************************************************/
void sort_list(STUDENT *p_student_list, int quantity)
{
   int     student_counter; /* Counts every student node              */
   STUDENT *p_student = p_student_list, 
                            /* Points to each student node            */
           *p_temporary_student; 
                     /* Points to temporary student node for the swap */

   for(student_counter = 0; student_counter < 
       quantity-student_counter; student_counter++)
   {
      while(p_student->p_next_student->p_next_student->student_id 
                                                        != LIST_TRAILER)
      {
         if(p_student->p_next_student->student_id > 
            p_student->p_next_student->p_next_student->student_id)
         {
            p_temporary_student = p_student->
                                         p_next_student->p_next_student;
            p_student->p_next_student->p_next_student 
                                  = p_temporary_student->p_next_student;
            p_temporary_student->p_next_student 
                                            = p_student->p_next_student;
            p_student->p_next_student = p_temporary_student;
         }
         p_student = p_student->p_next_student;
      }
      p_student = p_student_list;
   }
   
   return;
}

/**********************************************************************/
/*    Remove duplicate student ids from the student id linked list    */
/**********************************************************************/
void remove_duplicate_ids(STUDENT *p_student_list)
{
   STUDENT *p_current_student = p_student_list->
                                         p_next_student->p_next_student,
                                   /* Points to each student node     */
           *p_previous_student = p_student_list->p_next_student;
                                   /* Points to previous student node */

   while(p_current_student->student_id != LIST_TRAILER)
   {
      if(p_previous_student->student_id == p_current_student->student_id)
      {
         printf("\nDeleting the duplicate student id: %d",
            p_current_student->student_id);
         p_previous_student->p_next_student 
                                     = p_current_student->p_next_student;
         free(p_current_student);
         p_current_student = p_previous_student->p_next_student;
      }
      else 
      {
         p_previous_student = p_current_student;
         p_current_student = p_current_student->p_next_student;
      }
   }

   return;
}