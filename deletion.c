// demo code for deletion at the beginning, in between and end of nodes of a custom linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;

    struct node *next;

} node;

const int size = 10;

int main (void)
{
    node *list = NULL;

    for (int i = 0; i < size; i++)
    {
        node *n = malloc(sizeof(node));

        scanf("%i", &(n->num));

        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }

        else if (n->num <= list->num)
        {
            n->next = list;

            list = n;
        }

        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {

                if (ptr->next == NULL)
                {
                    ptr->next = n;

                    break;
                }

                else if (n->num < ptr->next->num)
                {
                    n->next = ptr->next;

                    ptr->next = n;

                    break;
                }
            }
        }
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->num);
    }

    printf("\n");


    // deletion at the beginning

    node *ptr = list->next;
    
    free(list);

    list = ptr;

    //deletion at the end

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->next->next == NULL)
        {
            ptr->next = NULL;
        }
    }

    //deletion in between nodes (random)

    node *temp = list->next;

    list->next = temp->next;

    free(temp);

    
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->num);
    }

    printf("\n");

}