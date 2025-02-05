#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 10
#define SEARCH_VALUE -4

size_t search(const int *array, const int expected_value)
{
    int *left = (int *)array;

    int *right = (int *)array + (ARRAY_SIZE - 1);

    int *choice;

    while (right >= left)
    {
        choice = left + ((right - left) / 2);

        if (*choice == expected_value)
        {
            return choice - array;
        }

        if (*choice < expected_value)
        {
            left = choice + 1;
        }
        else
        {
            right = choice - 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    int *array = (int *)malloc(sizeof(int) * ARRAY_SIZE);

    if (array == NULL)
    {
        fprintf(stderr, "erro ao alocar memória\n");
        return 1;
    }

    printf("valor a ser buscado: %d\n", SEARCH_VALUE);
    printf("array: ");

    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        int value = (i - 5) * 2;
        array[i] = value;

        printf("%d ", value);
    }

    printf("\n");

    const size_t array_index = search(array, SEARCH_VALUE);

    if (array_index != -1)
    {
        printf("\narray[%d] = %d\n", array_index, SEARCH_VALUE);
    }
    else
    {
        printf("\nvalor não encontrado\n");
    }

    free(array);

    return 0;
}
