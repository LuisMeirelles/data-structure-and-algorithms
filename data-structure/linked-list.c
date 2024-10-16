#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 10

typedef struct Node
{
    struct Node *next;
    int value;
} Node;

void populate_list(Node *head)
{
    Node *current = head;

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

int push(Node *head, const int value)
{
    Node *pointer = head;

    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    }

    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Failed to allocate memory for new node.\n");
        return -1;
    }
    
    new_node->value = value;

    pointer->next = new_node;
}

int main()
{
    Node *linked_list = malloc(sizeof(Node) * ARRAY_SIZE);

    populate_list(linked_list);

    print_list(linked_list);

    push(linked_list, 1234);

    print_list(linked_list);

    return 0;
}
