#include "global.h"
#include "functions.h"

void check_palindrome(char *p)
{
    char *temp;
    temp = (char *)malloc(sizeof(char)*strlen(p));
    strcpy(temp,p);
    strrev(p);
    if (strcmp(p,temp)==0)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
}

