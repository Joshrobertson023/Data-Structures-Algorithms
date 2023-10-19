/**********************************************************************/
/*                                                                    */
/* Program Name: program4 - Running an accounts receivable database   */
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
/* This program processes accounts receivable customer records. It    */
/* asks for the number of customers. Then for each customer it asks   */
/* for the last name, the amount owed, and the priority level. It     */
/* then prints the accounts receivable customer records in list form. */
/* The last names are printed in ascending order.                     */
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
#define DB_ALLOC_ERROR  1           /* Data memory allocation error   */
#define END_OF_STRING   '\0'        /* End-of-string character        */
#define MAX_CUSTOMERS   100         /* Max valid number of customers  */
#define MIN_CUSTOMERS   2           /* Min valid number of customrs   */
#define MAX_NAME_LENGTH 20          /* Max valid last name length     */
#define QUIT            0           /* Program exit value             */

/**********************************************************************/
/*                        Program structures                          */
/**********************************************************************/
/* A customer accounts receivable record                              */
struct customer
{
   char  last_name[MAX_NAME_LENGTH]; /* Last name                     */
   int   priority;                   /* Priority level                */
   float amount;                     /* Amount owed                   */
};

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_instructions();
   /* Print the program instructions                                  */
int get_num_customers();
   /* Get the number of customers                                     */
void get_customer_data(struct customer *p_customers_start, 
                       int num_customers);
   /* Get the accounts receivable customer database records           */
void clean_names(struct customer *p_customers_start, 
                 int num_customers);
   /* Remove non-letter characters from and title-case the last names */
void print_customer_data(struct customer *p_customers_start, 
                         int num_customers);
   /* Sort the last names into ascending order and print the records  */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int num_customers;           /* Number of customers                */
   struct customer *p_customer; /* Points to the database of accounts */
                                /* receivable customer records.       */
 
   /* Print the program heading                                       */
   printf("\n\n\n\n\n");
   print_heading();

   /* Loop processing accounts receivable customer records until the  */
   /* user quits                                                      */
   while (print_instructions(), (num_customers = get_num_customers()) 
                                                                != QUIT)
   {
      /* Allocate memory for the database of customer records and      */
      /* abort if memory is not available                              */
      if ((p_customer = malloc(sizeof(*p_customer) * num_customers)) 
                                                                 == NULL)
      {
         printf("\n\nError #%d occurred in main().", DB_ALLOC_ERROR);
         printf(  "\nA data allocation error occurred.");
         printf(  "\nThe program is aborting.\n");
         exit  (DB_ALLOC_ERROR);
         break;
      }

      /* Get the customer data, clean the names, and print the        */
      /* database of accounts receivable customer records             */
      get_customer_data  (p_customer, num_customers);
      clean_names        (p_customer, num_customers);
      print_customer_data(p_customer, num_customers);

      printf("\n\n******* End of Customer Database Processing *******");

      /* Release the memory allocated to the customer database        */
      free(p_customer);
   }

   /* Say goodbye and terminate the program                           */
   printf("\n\nThank you for processing accounts receivable customer");
   printf(  "\nrecords. Have a good day!");
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

   do 
   {
      printf(  "\nHow many customers do you have (%d to %d, %d=QUIT): ", 
         MIN_CUSTOMERS, MAX_CUSTOMERS, QUIT);
      scanf ("%d", &num_customers);
   }  while ((num_customers < MIN_CUSTOMERS || 
              num_customers > MAX_CUSTOMERS) && 
              num_customers != QUIT);

   return num_customers;
}

/**********************************************************************/
/*      Get the accounts receivable customer database records         */
/**********************************************************************/
void get_customer_data(struct customer *p_customers_start, 
                       int num_customers)
{
   struct customer *p_customer; /* Points to every customer           */
   
   /* Loop processing every accounts receivable customer              */
   for (p_customer = p_customers_start; 
       (p_customer - p_customers_start) < num_customers;
       p_customer++)
   {
      /* Print the customer's number                                  */
      printf("\n\nCustomer number %ld:", 
         ((p_customer - p_customers_start) + 1));

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
/*     Remove non-letter characters and title-case the last names     */
/**********************************************************************/
void clean_names(struct customer *p_customers_start, 
                 int num_customers)
{
   struct customer *p_customer; /* Points to every customer           */

   /* Loop processing every accounts receivable customer              */
   for(p_customer = p_customers_start; 
      (p_customer - p_customers_start) < num_customers; 
      p_customer++)
   {
      char *p_fast = p_customer->last_name, /* Points to every char   */
                                            /* in the last name       */
           *p_slow = p_customer->last_name; /* Points to all valid    */
                                            /* characters             */
           
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
/*   Sort the last names into ascending order and print the database  */
/**********************************************************************/
void print_customer_data(struct customer *p_customers_start, 
                         int num_customers)
{   
   struct customer *p_customer,   /* Points to every customer         */
                                  /* in the database                  */
                   temp_customer; /* Temporary customer               */
   int counter;                   /* Temporary counter                */

   for(counter = 1; counter < num_customers; counter++)
   {
      for(p_customer = p_customers_start; 
         (p_customer - p_customers_start) < (num_customers - counter); 
         p_customer++)
      {
         if(strcmp(p_customer->last_name, (p_customer+1)->last_name) > 0)
         {
            temp_customer = *p_customer;
            *p_customer = *(p_customer + 1);
            *(p_customer + 1) = temp_customer;
         }
      }
   }

   printf("\n\n  Here is the accounts receivable customer database");
   printf(  "\n=====================================================");
   printf(  "\n   Customer Name         Amount        Priority");
   printf(  "\n-------------------     ---------    -------------");

   /* Loop processing every accounts receivable customer              */
   for(p_customer = p_customers_start; 
      (p_customer - p_customers_start) < num_customers; 
      p_customer++)
   {
      printf(  "\n   %-20s  %-13.2f", 
         p_customer->last_name, p_customer->amount);

      /* Print the customer's priority level                          */
      switch(p_customer->priority)
      {
         /* Priority level 1                                          */
         case 1:
         printf(" 1 (VIP)");
         break;

         /* Priority level 2                                          */
         case 2:
         printf(" 2 (Important)");
         break;

         /* Priority level 3                                          */
         case 3:
         printf(" 3 (Regular)");
         break;
      }
   }

   return;
}