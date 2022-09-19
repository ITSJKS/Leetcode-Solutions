class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map <string,vector <string>>mp;
        for(auto path:paths){
            string path_name;
            int n = path.size();
            int i = 0;
            while(path[i]!=' '){
                path_name.push_back(path[i]);
                i++;
            }
            string file_c;
            while(i<n+1){
                if(i == n || path[i] == ' '){
                    int c = file_c.find('(');
                    string file_name = file_c.substr(0,c);
                    string content = file_c.substr(c+1);
                    if(content.size() != 0 || file_name.size() != 0 )
                        mp[content].push_back(path_name + '/' + file_name);
                    file_c = "";
                    
                }
                else{
                    file_c.push_back(path[i]);
                }
                i++;
                
            }
            
        }
        vector <vector <string>> ans;
        for(auto x:mp){
            if(x.second.size()>1)
                ans.push_back(x.second);
        }
        return ans;
    }
};