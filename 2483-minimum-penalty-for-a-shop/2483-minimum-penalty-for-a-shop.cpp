class Solution {
public:
    int bestClosingTime(string customers) {
        int count_yes = 0;
        for(auto x:customers){
            count_yes += x == 'Y';
        }
        int n = customers.size();
        int ans = n;
        int hour = n;
        int count_no = 0;
        for(int i = 0; i <n; i++){
            int x = count_no + count_yes;
            if(ans  > count_no + count_yes){
                ans = count_no + count_yes;
                hour = i;
            }
            count_no += (customers[i] == 'N');
            count_yes -= (customers[i] == 'Y');
        }
        if(ans  > count_no + count_yes){
                ans = count_no + count_yes;
                hour = n;
            }
        return hour;
    }
};