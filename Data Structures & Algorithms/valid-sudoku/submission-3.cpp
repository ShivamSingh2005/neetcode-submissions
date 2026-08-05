class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0 ;  row< 9 ; row++){
            unordered_set<char> seen;
            for(int col = 0 ; col<9 ; col++){
                if(board[row][col] == '.') continue;
                if(seen.count(board[row][col])) return false;
                seen.insert(board[row][col]);
            }
        }
        for(int col = 0 ;  col< 9 ; col++){
            unordered_set<char> seen;
            for(int row = 0 ; row<9 ; row++){
                if(board[row][col] == '.') continue;
                if(seen.count(board[row][col])) return false;
                seen.insert(board[row][col]);
            }
        }
        for(int sq = 0 ;  sq< 9 ; sq++){
            unordered_set<char> seen;
            for(int i = 0 ; i<3 ; i++){
                for(int j= 0 ; j<3 ; j++){
                    int row = sq/3*3+i;
                    int col = sq%3*3+j;
                    if(board[row][col] == '.') continue;
                    if(seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
