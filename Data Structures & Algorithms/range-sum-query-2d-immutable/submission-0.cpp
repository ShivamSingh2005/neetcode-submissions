class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        pre = vector<vector<int>>(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for(int r = 0 ; r<matrix.size() ; r++){
            int prefix = 0 ;
            for(int c = 0; c<matrix[0].size() ; c++){
                prefix+=matrix[r][c];
                pre[r+1][c+1] = pre[r][c+1]+prefix;
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return pre[r2+1][c2+1] + pre[r1][c1]-pre[r1][c2+1]-pre[r2+1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */