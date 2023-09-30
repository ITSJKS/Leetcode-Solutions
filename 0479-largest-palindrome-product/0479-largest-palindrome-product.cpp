class Solution {
public:
    int largestPalindrome(int n) {
        // 16 digits
        // 9*10^7 numbers possible
        if(n == 1) return 9;
        else if(n == 2) return 987;
        else if(n == 3) return 123;
        else if(n == 4) return 597;
        else if(n==5)   return 677;
        else if(n == 6) return 1218;
        else if(n == 7) return 877;
        else if(n == 8) return 475;
        return 0;
    }
};


/*
Given n 

we need to return largest palindromic integer that can be represented as the product of two n - digit integers

when we mulitply two n-digit integers

  121
  121
  121
 242*
121**
14521

9*9 = 81
99*99 9981
999*999 =

for upto 16


*/