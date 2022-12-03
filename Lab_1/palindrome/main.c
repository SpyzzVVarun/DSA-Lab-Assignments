#include "std_imports.h"
#include "functions.h"


int main()
{
    char c;
    char *str;
    int len;
    str = (char *) malloc(sizeof(char));
    len = sizeof(char);
    FILE *fp = fopen("input.txt","r");
    while((c = fgetc(fp)) != EOF)
    {
        str[len-1] = c;
        len ++;
        str = (char *)realloc(str,len);
    }
    str[len-1] = '\0';
    check_palindrome(str);
    return 0;
}
