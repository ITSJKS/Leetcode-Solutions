class Solution {
public:
    string predictPartyVictory(string senate) {
        queue <int> r,d;
        int n = senate.size();
        for(int i = 0; i <n; i++){
            if(senate[i] == 'R') r.push(i);
            else d.push(i);
        }
        while(!r.empty()&& !d.empty()){
            int ridx = r.front();
            int didx = d.front();
            r.pop();
            d.pop();
            if(ridx < didx){
                r.push(ridx+n);
            }
            else d.push(didx+n);
        }
        if(r.size() == 0) return "Dire";
        else return "Radiant";
    }
};
//1000 round max
// in each round atleast one of the senate will be eliminated for sure
