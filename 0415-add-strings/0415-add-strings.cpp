class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int n = num1.size(), m = num2.size();
        int i = 0, j = 0;
        int carry = 0;
        while(i < n && j < m){
            int a = num1[i]-'0';
            a = a + (num2[j]-'0')+carry;
            carry = a/10;
            num1[i] = (a%10)+'0';
            i++;
            j++;
        }
        while(i < n && carry){
            int a = (num1[i] -'0') + carry;
            carry = a/10;
            num1[i] = a%10+'0';
            i++;
        }
        while(j < m){
            int a = (num2[j] -'0') + carry;
            carry = a/10;
            num1.push_back(a%10 + '0');
            j++;
        }
        if(carry){
            num1.push_back(carry+'0');
        }
        reverse(num1.begin(),num1.end());
        return num1;
    }
};