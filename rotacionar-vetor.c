#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int size = 5;
    int k = INT_MIN;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        printf("Inputa o vetor: ");
        scanf("%i", &array[i]);
    }

    printf("Digite um K: ");
    scanf("%i", &k);


    for (int i = 0; i < k; i++)
    {
        int lastItem = array[size-1];

        for (int j = size-1; j > 0; j--){
            array[j] = array[j-1];
        }

        array[0] = lastItem;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }
}
