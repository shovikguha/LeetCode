class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<int> seen(n);
        
        for(int i =0; i < n; i++){
            fill(seen.begin(), seen.end(), 0);
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    if(seen[num] != 0){
                        return false;
                    }
                    seen[num] = 1;
                }
            }
        }
                        
        for(int j =0; j < n; j++){
            fill(seen.begin(), seen.end(), 0);
            for(int i = 0; i < n; i++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    if(seen[num] != 0){
                        return false;
                    }
                    seen[num] = 1;
                }
            }
        }
                
        vector<pair<int,int>> start;
        for(int i =0; i < n; i += 3){
            for(int j = 0; j < n; j+= 3){
                start.push_back(make_pair(i,j));
            }
        }
        
        for(int k = 0; k < start.size(); k++){
            auto& p = start[k];
            fill(seen.begin(), seen.end(), 0);
            for(int i = p.first; i < 3 + p.first; i++){
                for(int j = p.second; j < 3 + p.second; j++){
                    if(board[i][j] != '.'){
                        int num = board[i][j] - '1';
                        if(seen[num] != 0){
                            return false;
                        }
                        seen[num] = 1;
                    }
                }
            }
        }
        
        return true;

    }
};