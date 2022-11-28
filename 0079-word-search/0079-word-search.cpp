class Solution {
public:
    int m;
    int n;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        bool ret = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>> seen(m, vector<bool>(n));
                    seen[i][j] = true;
                    ret = dfs(i,j,1,board, seen, word);
                    if(ret){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool dfs(int i, int j, int l, vector<vector<char>>& board,vector<vector<bool>>& seen, string word){
        if(l == word.size()){
            return true;
        }
        bool ret = false;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        for(int k = 0 ; k < 4; k++){
            int newx = i + dx[k];
            int newy = j + dy[k];
            
            if(0 <= newx && newx < m && 0 <= newy && newy < n && seen[newx][newy] == false && word[l] == board[newx][newy]){
                seen[newx][newy] = true;
                ret = ret || dfs(newx, newy, l + 1, board, seen, word);
                seen[newx][newy] = false;
            }
        }
        return ret;
    }
};