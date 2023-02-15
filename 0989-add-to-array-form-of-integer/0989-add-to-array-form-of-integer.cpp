class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(),num.end());
        string s = to_string(k);
        reverse(s.begin(),s.end());
        int n = num.size();
        int m = s.size();
        int i = 0, j = 0;
        int carry = 0;
        while(i < n && j < m){
            int a = 0;
            a += num[i];
            a += (s[j]-'0');
            a += carry;
            num[i] = a%10;
            carry = a/10;
            i++;
            j++;
        }
        while(i < n && carry){
            int a = num[i];
            a += carry;
            num[i] = a%10;
            carry = a/10;
            i++;
        }
        while(j<m){
            int a = s[j]-'0';
            a += carry;
            carry = a/10;
            num.push_back(a%10);
            j++;
        }
        if(carry){
            num.push_back(carry);
        }
        reverse(num.begin(),num.end());
        return num;
    }
};