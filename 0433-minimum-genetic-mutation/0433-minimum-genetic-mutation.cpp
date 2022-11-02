class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue <string> q;
        unordered_set <string > seen;
        q.push(start);
        seen.insert(start);
        int steps = 0;
        while(q.size()){
            int q_size = q.size();
            for(int j = 0; j <q_size; j++){
                string node = q.front();
                q.pop();
                if(node == end) return steps;
                for(char c:"ACGT"){
                    for(int i = 0; i <node.size(); i++){
                        string neighbour = node;
                        neighbour[i] = c;
                        if(!seen.count(neighbour) && find(bank.begin(),bank.end(),neighbour)!=bank.end()){
                            q.push(neighbour);
                            seen.insert(neighbour);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};