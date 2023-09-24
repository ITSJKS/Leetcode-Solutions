const int level = 16;
struct Node{
    Node* links[2];
    int cnt;
    Node(){
        links[0] = links[1] = NULL;
        cnt = 0;
    }
};
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Node* root = new Node();
        auto insert =[&](int num){
            auto temp = root;
            for(int i = level-1; i>=0; i--){
                bool set = num&(1<<i);
                if(!temp->links[set]) temp->links[set] = new Node();
                temp->links[set]->cnt++;
                temp = temp->links[set];
            }
        };
        auto find_cnt=[&](int N,int K){
            auto temp = root;
            int cnt = 0;
            for(int i = level-1; i>=0&&temp; i--){
                bool bit1 = N&(1<<i);
                bool bit2 = K&(1<<i);
                if(bit2 == 0){
                    temp = temp->links[bit1];
                    continue;
                }
                if(temp->links[bit1]){
                    cnt += temp->links[bit1]->cnt;
                }
                temp = temp->links[1-bit1];
            }
            return cnt;
        };
        int count = 0;
        for(auto &x:nums){
            count += find_cnt(x,high+1) - find_cnt(x,low);
            insert(x);
        }
        return count;
        
    }
};

/*
high 
[1,4,2,7] 
less than high
6 -> 110
1 -> 001

how trie works 
to get values less than K
we will traverse in bits
31th bit
if it is 0 or 1
if our element is 1 we will have to check if high has that bit set 


*/