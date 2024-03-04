class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int score = 0;
        int i = 0, j = n-1;
        int count = 0;
        while(i<=j && count<n){
            // cout<<power<<" ";
            if(power >= tokens[i]){
                power-=tokens[i];
                score++;
                i++;
            }
            else if(score>=1 && count!=n-1){
                power += tokens[j];
                score--;
                j--;
            }
            count++;
            
        }
        return score;
    }
};