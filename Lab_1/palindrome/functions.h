#include "global.h"

void checkPalindrome(string num)
{
    string straight = num;
    reverse(num.begin(), num.end());
    if (num == straight) cout << "Palindrome" << endl;
    else cout << "Not Palindrome" << endl;
}