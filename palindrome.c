#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define FINAL_CARACTER '\0'

void clearString(char *str);
char* isPalindrome(char *str);

int main()
{
    char input[100];

    printf("Digite a palavra ou frase: ");
    scanf("%[^\n]", input); // 1

    clearString(input);

    // convertToLowcase()
    for(int i = 0; input[i] != FINAL_CARACTER; i++)
    {
        input[i] = tolower(input[i]);
    }

    char *str = isPalindrome(input);

    printf("\n%s", str);

    return 0;
}

// MARCIO -> 10
// [M][A][R][C][I][O][\0][][][]
// \0 -> Significa que chegou no final da linha

void clearString(char *str)
{
    int j = 0;

    for(int i = 0; str[i] != FINAL_CARACTER; i++)
    {
        if (isalnum(str[i])) // 2, 3
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = FINAL_CARACTER;
}

char* isPalindrome(char *str)
{
    int ZERO = 0, START_LOWCASE = 32;
    int lastPosition = (strlen(str) - 1);
    int left = ZERO, right = lastPosition;

    while(left < right)
    {
        /*
        if(str[left] != str[right] &&
           (int)str[left]+START_LOWCASE != (int)str[right] &&
           (int)str[right]+START_LOWCASE != (int)str[left]
           )
        {
        */
        if(str[left] != str[right])
        {
            return "NÃO";
        }
        left++;
        right--;
    }

    return "SIM";
}
