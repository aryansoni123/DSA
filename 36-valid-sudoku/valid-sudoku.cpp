class Solution {
public:

    bool isValid(char val, int x, int y, vector<vector<char>>& board){
        for(int i = 0; i<9; i++){
            if(i!= x && board[i][y] == val ) return false;
            if(i!= y && board[x][i] == val ) return false;
            
            int nr = 3 * (x/3) + (i/3);
            int nc = 3 * (y/3) + (i%3);

            if((nr!=x || nc!=y) && board[nr][nc] == val ) return false;
        }

        return true;
    }
    
    bool f(vector<vector<char>>& board){
        for (int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] != '.'){
                //     for(int val = 1; val<=9; val++){
                    if(isValid(board[i][j], i, j , board) == false) return false;
                    // {
            //             board[i][j] = val + '0';
            //             if(f(board)) return true;
            //             board[i][j] = '.';
            //         } 
            //     }
            //     return false;
                }


            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return f(board);
    }
};