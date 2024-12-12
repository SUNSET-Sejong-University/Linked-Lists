// demo code for insertion at the beginning, in between and end of nodes of a custom linked list

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

        // prepend

        else if (n->num <= list->num)
        {
            n->next = list;

            list = n;
        }

        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // append

                if (ptr->next == NULL)
                {
                    ptr->next = n;

                    break;
                }

                // in between nodes

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
    
    // freeing the nodes

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        node *nxt = ptr->next;

        free(ptr);

        ptr = nxt;
    }
}