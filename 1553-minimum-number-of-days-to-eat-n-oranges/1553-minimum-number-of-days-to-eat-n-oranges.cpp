class Solution {
public:
    int minDays(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return 1 + min(n%2 + minDays(n/2),n%3 + minDays(n/3));
    }
};

// if divisible by 2 , then we can just take two more turn and then do this third opertion

/*
 x -> 3 operation me -> (x-2)/3 
24 -> 1 opeation me 8 -> 2 + op

*/