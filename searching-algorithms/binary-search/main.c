#include <stdlib.h>

#define ARRAY_SIZE 10
#define SEARCH_VALUE -4

int search(int *array, int expected_value)
{
    int *left = array;

    int last_element_index = ARRAY_SIZE - 1;

    int *right = array + last_element_index;

    int *choice;

    while (1)
    {
        choice = left + ((right - left) / 2);

        int actual_value = *choice;

        if (actual_value == expected_value)
        {
            return choice - array;
        }

        if (actual_value < expected_value)
        {
            left = choice + 1;
        }
        else
        {
            right = choice - 1;
        }

        if (right < left)
        {
            return -1;
        }
    }
}

int main(int argc, char *argv[])
{
    printf("valor a ser buscado: %d\n", SEARCH_VALUE);

    int *array = (int *)malloc(sizeof(int) * ARRAY_SIZE);

    if (array == NULL)
    {
        printf("erro ao alocar memória\n");
        return 1;
    }

    printf("array: ");

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        int value = (i - 5) * 2;
        array[i] = value;

        printf("%d ", value);
    }

    printf("\n");

    int array_index = search(array, SEARCH_VALUE);

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
