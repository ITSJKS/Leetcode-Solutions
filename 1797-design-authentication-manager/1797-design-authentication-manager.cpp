class AuthenticationManager {
public:
    unordered_map <string,int> mp;
    int life_time;
    AuthenticationManager(int timeToLive) {
        life_time = timeToLive; 
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.count(tokenId)){
            if(mp[tokenId]+life_time<=currentTime){
                mp.erase(tokenId);
            }
            else mp[tokenId] = currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        vector <string> c;
        for(auto x:mp){
            if(x.second+life_time>currentTime){
                count++;
            }
            else c.push_back(x.first);
        }
        for(auto x:c) mp.erase(x);
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */