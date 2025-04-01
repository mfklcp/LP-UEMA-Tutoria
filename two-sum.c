#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// https://leetcode.com/problems/two-sum/description/?envType=problem-list-v2&envId=array

int main()
{
    int size = 4;
    int input[size];
    int target = 0;;

    for(int i = 0; i < size; i++)
    {
        scanf("%i", &input[i]);
    }
    scanf("%i", &target);

    for(int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (input[i]+input[j] == target)
            {

                printf("[%i,%i]", i, j);
                return 0;
            }
        }
    }
    printf("Não encontrou dois numeros que somam dá alvo");
    return 0;
}
