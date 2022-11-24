class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0) return false;
        int n = board.size();
        int m = board[0].size();
        for(int i =0; i < n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0] && DFS(board,word,i,j,0)  ){
                    return true;
                }
                }
            }
        return false;
        }
    
    
     bool DFS(vector<vector<char>>& board, string &word,int i,int j,int n){
        if(n==word.size()){
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j >= board[0].size() || board[i][j]!=word[n] ){
            return false;
        }
            
            board[i][j] = '0';
            bool status = DFS(board,word,i+1,j,n+1) || DFS(board,word,i-1,j,n+1) || DFS(board,word,i,j-1,n+1) || DFS(board,word,i,j+1,n+1);
            board[i][j] = word[n];
            return status;
            
        
    }
    
   
};