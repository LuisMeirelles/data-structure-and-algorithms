#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 10

typedef struct Node
{
    struct Node *next;
    int value;
} Node;

int push(Node *head, const int value)
{
    Node *pointer = head;

    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;

    pointer->next = new_node;
}

void print_list(Node *head)
{
    Node *pointer = head;

    while (1)
    {
        printf("%d", pointer->value);

        if (pointer->next == NULL)
        {
            break;
        }

        printf(" -> ");

        pointer = pointer->next;
    }

    printf("\n");
}

int main()
{
    Node *linked_list = malloc(sizeof(Node) * ARRAY_SIZE);

    Node *current = linked_list;

    size_t count = 0;

    while (1)
    {
        current->value = count;
        count++;

        if (count == ARRAY_SIZE)
        {
            break;
        }

        Node *next = malloc(sizeof(Node) * ARRAY_SIZE);

        current->next = next;

        current = next;
    }

    print_list(linked_list);

    int success = push(linked_list, 1234);

    if (!success)
    {
        fprintf(stderr, "An error occurred while trying to add a node to a linked list\n");
        return 1;
    }

    print_list(linked_list);

    return 0;
}
