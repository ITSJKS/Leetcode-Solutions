class Solution {
public:
    struct Person{
        int qual;
        int wage;
        double rate;
        Person(int _qual ,int _wage){
            qual = _qual;
            wage = _wage;
            rate = (double)wage/qual;
        }
    };
    struct cmp{
        bool operator()(const Person &a, const Person &b){
            return a.rate < b.rate;
        }
    };
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector <Person> workers;
        int n = quality.size();
        for(int i = 0; i <n; i++){
            Person p(quality[i],wage[i]);
            workers.push_back(p);
        }
        sort(workers.begin(),workers.end(),cmp());
        priority_queue <int> pq;
        double minCost = 1e12;
        int totalQ = 0;
        for(auto &x:workers){
            double rate = x.rate;
            pq.push(x.qual);
            totalQ += x.qual;
            if(pq.size() > k){
                totalQ -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                minCost = min(minCost, rate*totalQ);
            }
        }
        return minCost;
    }
};