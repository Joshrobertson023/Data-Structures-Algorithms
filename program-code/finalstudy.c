#include <stdio.h>

int main()
{
   int data[]  = {7, 3, 1, 21, 76},
       *p_data = &data[0];

   printf("\n*p_data = %d", *p_data);
   printf("\n(*p_data)++ = %d", (*p_data)++);
   printf("\n*(p_data++) = %d", *(p_data++));
   printf("\n*p_data++ = %d", *p_data++);

   return 0;
}

void insert_node(NODE *p_list, char *p_insert_key)
{
   NODE *p_new,
        *p_previous = p_list,
        *p_current = p_list->p_next_node;

   while(strcpm(p_insert_key, p_current->node_key) > 0)
   {
      p_previous = p_current;
      p_current = p_current->p_next_node;
   }

   p_new = (NODE *) malloc(sizeof(NODE));

   strcpy(p_new->node_key, p_insert_key);
   p_new->p_next_node = p_current;
   p_previous->p_next_node = p_new;

   return;
}

void delete_node(NODE *p_list, char *p_delete_key)
{
   NODE *p_current = p_list->p_next_node,
        *p_previous = p_list;

   while(strcmp(p_delete_key, p_current->node_key) > 0)
   {
      p_previous = p_current;
      p_current = p_current->p_next_node;
   }

   if(strcmp(p_delete_key, p_current->node_key) == 0)
   {
      p_previous->p_next_node = p_current->p_next_node;
      free(p_current);
   }

   return;
}