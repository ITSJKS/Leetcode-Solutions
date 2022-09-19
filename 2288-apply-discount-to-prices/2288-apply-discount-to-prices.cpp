class Solution {
public:
    string check_string(string word,int discount){
        int n = word.size();
        if(word[0]!='$' || n == 1 ) return word;
        long long price = 0;
        for(int i = 1; i <n; i++){
            if(!isdigit(word[i])) return word;
            price = price*10 + (word[i]-'0');
        }
        stringstream ss2;
        double dis_per = (100 - discount)/100.0;
        ss2<<fixed<<setprecision(2)<<(price*dis_per);
        return '$' + ss2.str();
    }
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string word;
        string ans;
        while(ss>>word){
           ans += check_string(word,discount)+" ";
        }
        ans.pop_back();
        return ans;
    }
};