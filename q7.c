// Javokhir Ganiboev
// Question7: Reverse Integer

#include <limits.h>

int reverse(int x){
    long int temp = x;
    long int rev=0, rem; 

    while(temp != 0){
        rem = temp % 10;

        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && rem > 7)) return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && rem < -8)) return
        0;

        rev = rev * 10 + rem;
        temp /= 10;
    } 

    return rev;
}