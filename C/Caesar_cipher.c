#include <stdio.h>

char m[] = {"gndk€rlqhmtkwwp}z}"};

void caesar(int turn)
{
    int i;
    char a;
    printf("For turn %d:", turn);
    for (i = 0; m[i] != '\0'; i++)
    {
        a = m[i];
        if ('a' <= a && a <= 'z')
        {
            printf("%c", (a - 'a' + turn) % 26 + 'a');
        }
        else if ('A' <= a && a <= 'Z')
        {
            printf("%c", (a - 'A' + turn) % 26 + 'A');
        }
        else
        {
            printf("%c", a);
        }
    }
    printf("\n");
}

int main()
{
    int i;
    for (i = 1; i < 26; i++)
    {
        caesar(i);
    }
    return 0;
}