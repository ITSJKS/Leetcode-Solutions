class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for(int i = 1; i*i<=n; i++){
            if(n%i == 0 && i&1) count++;
            if(i*i != n && n%i == 0 && (n/i)&1) count++;
        }
        return count;
    }
};

/*
we need to form n  using consecutive numbers
so each number will be used only once
10 -> 
1+2+3+4
10
we can solve it in O(n) by using methods like checking sum - n and then if it exists
if it is divisible by 3
then we can divide it like n/3 - 1 n/3 n/3+1
if it is divisible by 5 and it is odd
n/5
so we can find number of odd factors of n
then we can divide our number based on that
to solve it in O(sqrt(n))
*/