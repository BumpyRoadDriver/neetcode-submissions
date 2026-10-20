class Solution {
public:

    bool checkBox(vector<vector<char>>  &board, int x, int y){
        vector<int> cnt(9); 
        for(int i = x; i < x + 3; i++){
            for(int j = y ; j < y+3; j++){
                if(board[i][j] == '.')continue;
                int num = board[i][j] -'1'; 
                
                if (++cnt[num] == 2){
                    return false;
                }
            }
        }
        return true;

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> cnt(9); 

        bool ans = true; 
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                ans &= (checkBox(board, i, j));
                if (not ans) return false;
            }
        }

        for(int i = 0; i < 9; i++){
            fill(cnt.begin(), cnt.end(), 0);
            for(int j  =0 ;j < 9; j++){
                if(board[i][j] == '.')continue;
                int num = board[i][j] - '1'; 
                
                if (++cnt[num]== 2){
                    return false;
                }
            }
        }
        for(int i = 0; i < 9; i++){
            fill(cnt.begin(), cnt.end(), 0); 
            for(int j  =0 ;j < 9; j++){
                if(board[j][i] == '.')continue;
                int num = board[j][i] - '1'; 
                
                if (++cnt[num]== 2){
                    return false;
                }
            }
        }
        return true;

    }
};