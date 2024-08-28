// Javokhir Ganiboev
// Question9: Palindrome Number

#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    long int temp = x;
    long int rev=0, rem;

    if (x<0) return false;

    while(temp!=0){
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp /= 10;
    }

    if (rev == x) return true;
    else return false;
}