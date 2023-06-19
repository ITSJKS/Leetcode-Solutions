// I m gonna learn how to write modular code
class NumMatrix {
private:
    int rows , cols;
    vector <vector <int>> bit;
    int lsb(int n){
        return n &(-n);
    }
    void updateBit(int r, int c, int val){
        for(int i =r; i<=rows; i+=lsb(i)){
            for(int j = c; j <=cols; j+=lsb(j)){
                this->bit[i][j] += val;
            }
        }
    }
    int queryBit(int r, int c){
        int sum = 0;
        for(int i = r; i>0; i-=lsb(i)){
            for(int j = c; j>0; j-=lsb(j)){
                sum += this->bit[i][j];
            }
        }
        return sum;
    }
    void build(vector <vector <int>>&matrix){
        for(int i =1; i <=rows; i++){
            for(int j = 1; j <=cols; j++){
                updateBit(i,j,matrix[i-1][j-1]);
            }
        }
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        bit.resize(rows+1);
        for(int i = 1; i <=rows; i++){
            bit[i].resize(cols+1,0);
        }
        build(matrix);
    }
    
    void update(int row, int col, int val) {
        int old_val = sumRegion(row,col,row,col);
        row++,col++;
        int  diff = val - old_val;
        updateBit(row,col,diff);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++,col1++,row2++,col2++;
        int sum1 = queryBit(row2,col2);
        int sum2 = queryBit(row1-1,col1-1);
        int sum3 = queryBit(row1-1,col2);
        int sum4 = queryBit(row2,col1-1);
        return sum1 - sum3 -sum4 + sum2;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */