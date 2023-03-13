class UndergroundSystem {
public:
    unordered_map <string ,pair<int,int>> cost_map;
    unordered_map <int,pair <string,int>> mp;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(mp.count(id)){
            string startS = mp[id].first;
            int startT = mp[id].second;
            string hash = startS +">"+stationName;
            cost_map[hash].first += (t-startT);
            cost_map[hash].second++;
            mp.erase(id);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string hash = startStation + ">" + endStation;
        int total_time = cost_map[hash].first;
        int count = cost_map[hash].second;
        return (double)total_time/(double)count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

/*
// checkin
int id - > string station , time t
// checkout
int id, string station, time t

only direct connection is concerned

*/