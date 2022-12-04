#include "functions.h"

int main()
{
    string num;
    ifstream fps;
    fps.open("input.txt");
    fps >> num;
    fps.close();
    checkPalindrome(num);
    return 0;
}