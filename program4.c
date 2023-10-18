/**********************************************************************/
/*                                                                    */
/* Program Name: program4 - Processing a database of experimental     */
/*                          scientific data                           */
/* Author:       Josh Robertson                                       */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 7, 2023                                      */
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
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER   "CS227"     /* PCC assigned course number     */
#define PROGRAMMER_NAME "Robertson" /* The programmer's last name     */
#define PROGRAM_NUMBER  4           /* Teacher assigned program       */
                                    /* number                         */
#define DB_ALLOC_ERROR  1           /* */
#define END_OF_STRING   '\0'        /* */
#define MAX_CUSTOMERS   100         /* */
#define MIN_CUSTOMERS   2           /* */
#define MAX_NAME_LENGTH 20          /* */
#define QUIT            0           /* */

/**********************************************************************/
/*                        Program structures                          */
/**********************************************************************/
/* A customer accounts receivable record                              */
struct customer
{
   char  last_name[MAX_NAME_LENGTH]; /* */
   int   priority;                   /* */
   float amount;                     /* */
};

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* */
void print_instructions();
   /* */
int get_num_customers();
   /* */
void get_customer_data(struct customer *p_customers_start, int num_customers);
   /* */
void clean_names(struct customer *p_customers_start, int num_customers);
   /* */
void print_customers(struct customer *p_customers_start, int num_customers);
   /* */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int num_customers;           /* Amount of customers                */
   struct customer *p_customer; /* Points to the database of accounts */
                                /* receivable customer records.       */
 
   /* Print the program heading                                       */
   printf("\n\n\n\n\n");
   print_heading();

   /* Loop processing accounts receivable customer records until the  */
   /* user quits                                                      */
   while (print_instructions(), (num_customers = get_num_customers()) != QUIT)
   {
      /* Allocate memory the for customer records and abort if memory  */
      /* is not available                                              */
      if ((p_customer = malloc(sizeof(*p_customer) * num_customers)) == NULL)
      {
         printf("\n\nError #%d occurred in main().", DB_ALLOC_ERROR);
         printf(  "\nA data allocation error occurred.");
         printf(  "\nThe program is aborting.\n");
         exit  (DB_ALLOC_ERROR);
         break;
      }
      /* Get customers, clean names, sort customers, print customers  */
      get_customer_data(p_customer, num_customers);
      clean_names      (p_customer, num_customers);
      print_customers  (p_customer, num_customers);
      printf("\n\n******* End of Customer Database Processing *******");

      /* Release the memory allocated to the customer database        */
      free(p_customer);
   }

   /* Say goodbye and terminate the program                           */
   printf("\n\nThank you for processing customer databases. Have a");
   printf(  "\ngood day!");
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
   return;
}

/**********************************************************************/
/*                  Print the program instructions                    */
/**********************************************************************/
void print_instructions()
{
   printf("\n\nThis program allows you to input customers which owe");
   printf(  "\nyou money (your accounts receivable), and manage these");
   printf(  "\naccounts in a database. You will enter the following:");
   printf(  "\n   Customer last name (1-%d characters)", MAX_NAME_LENGTH);
   printf(  "\n   Amount the customer owes (to the exact cent)");
   printf(  "\n   Customer priority (1=VIP, 2=Important, 3=Regular)");
   printf(  "\nFrom %d to %d customers may be processed.", MIN_CUSTOMERS, 
      MAX_CUSTOMERS);
   printf(  "\n-------------------------------------------------------");
   return;
}

/**********************************************************************/
/*                     Get the number of customers                    */
/**********************************************************************/
int get_num_customers()
{
   int num_customers; /* Amount of customers                          */

   printf("\n\nGet the customers for the database");
   printf(  "\n-----------------------------------------------");
   printf(  "\nHow many customers do you have (%d to %d, %d=QUIT): ", 
      MIN_CUSTOMERS, MAX_CUSTOMERS, QUIT);
   scanf ("%d", &num_customers);
   return num_customers;
}

/**********************************************************************/
/*      Get the accounts receivable customer database records         */
/**********************************************************************/
void get_customer_data(struct customer *p_customers_start, int num_customers)
{
   struct customer *p_customer; /* */
   
   /* Loop processing every accounts receivable customer              */
   for (p_customer = p_customers_start; 
       (p_customer - p_customers_start) < num_customers;
       p_customer++)
   {
      /* Print the customer number */
      printf("\n\nCustomer number %ld:", ((p_customer - p_customers_start) 
         + 1));

      /* Get the customer's last name                                 */
      printf(  "\n   Enter the customer's last name: ");
      scanf ("%s", p_customer->last_name);
      
      /* Get the customer's amount owed                               */
      printf(    "   Enter the amount owed: ");
      scanf ("%f", &p_customer->amount);

      /* Get the customer's priority level                            */
      do 
      {
         printf( "   Enter the customer's priority (1-3): ");
         scanf ("%d", &p_customer->priority);
      }  while (p_customer->priority < 1 || p_customer->priority > 3);
   }

   return;
}

/**********************************************************************/
/*             Remove non-letter characters and title-case            */
/**********************************************************************/
void clean_names(struct customer *p_customers_start, int num_customers)
{
   struct customer *p_customer; /* Points to every customer           */

   for(p_customer = p_customers_start; (p_customer - p_customers_start) 
      < num_customers; p_customer++)
   {
      char *p_fast = p_customer->last_name, /* Points to every char in word */
           *p_slow = p_customer->last_name; /* Points to all valid chars */
           
      while(*p_fast != END_OF_STRING)
      {
         if(isalpha(*p_fast))
            *p_slow++ = tolower(*p_fast);
         p_fast++;
      }
      *p_slow = END_OF_STRING;

      *p_customer->last_name = toupper(*p_customer->last_name);
   }
   return;
}

/**********************************************************************/
/*          Sort into ascending order and print the customers         */
/**********************************************************************/
void print_customers(struct customer *p_customers_start, int num_customers)
{   
   struct customer *p_customer;

      /* Bubble sort algorithm currently not working                  */
      for(p_customer = p_customers_start; (p_customer - p_customers_start) 
         < num_customers - 1; p_customer++)
      {
         if(strcmp(p_customer->last_name, (p_customer->last_name) + 1) > 0)
         {
            struct customer temp;
            temp = *p_customer;
            *p_customer = *(p_customer + 1);
            *(p_customer + 1) = temp;
         }
      }


   printf("\n\n  Here is the accounts receivable customer database");
   printf(  "\n=====================================================");
   printf(  "\n   Customer Name         Amount        Priority");
   printf(  "\n-------------------     ---------    -------------");

   for(p_customer = p_customers_start; (p_customer - p_customers_start) 
      < num_customers; p_customer++)
   {
      printf(  "\n   %-20s  %-13.2f %d", p_customer->last_name, 
      p_customer->amount, p_customer->priority);
   }

   return;
}