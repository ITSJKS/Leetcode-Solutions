class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map <char, int > table;
        for(auto x:p) table[x]++;
        int start = 0,end = 0;
        vector <int> index;
        int n = s.length();
        int m = p.length();
        int counter = table.size();
        if(m>n || m==0) return index;
        while(end<n){
            char ec = s[end];
            if(table.find(ec)!=table.end()){
                table[ec]--;
                if(table[ec] == 0) counter--;
            }
            end++;
            while(counter == 0){
                if(end - start == m){
                    index.push_back(start);
                }
                char bc = s[start];
                if(table.find(bc)!=table.end()){
                    table[bc]++;
                    if(table[bc]>0) counter++;
                }
                start++;
            }
        }
        return index;
    }
};