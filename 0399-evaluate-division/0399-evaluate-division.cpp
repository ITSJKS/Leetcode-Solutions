#define psd pair<string, double> 
#define str string 

class DSU{
public:
    // to store parents of each Disjoint set
    map<str, psd> parent; 
    
    psd find(str source){
        
        if (parent.find(source)==parent.end()){
            // Initially parent of each variable is itself. 
            parent[source]={source, 1};
        } 
        
        if (source == parent[source].first) return parent[source];
         
        psd par = find(parent[source].first);
        parent[source].first = par.first;
        parent[source].second *= par.second;
        
        return {par.first, parent[source].second};
    }
        
    void unifyEquations(str u, str v, double val){
        psd pu = find(u);
        psd pv = find(v);
        
        if(pu.first == pv.first) return;
    
        parent[pv.first].first = pu.first;
        parent[pv.first].second = pu.second * val/pv.second;
    }
};





class Solution {
public:    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        DSU solver;
        int n = equations.size();
        int q = queries.size();
        
        for (int i=0; i<n; i++){
            str num = equations[i][0];
            str den = equations[i][1];
            solver.unifyEquations(num, den, values[i]);
        }
        
        vector<double> ans;
        
        for (auto q: queries){
            string num = q[0];
            string den = q[1];
            double eval = -1.0;
            
            if (solver.parent.find(num) != solver.parent.end() && 
                solver.parent.find(den) != solver.parent.end() ){ 
        
                psd pu = solver.find(num);
                psd pv = solver.find(den);

                if (pu.first == pv.first){ 
                    eval = pv.second * 1.0/pu.second;
                }
                //  else case => both variables don't have same parent => variables not related even though present
            } 
            // else case => either of the two variables not present
            
            ans.push_back(eval);
        }
        
        return ans;
    }
};