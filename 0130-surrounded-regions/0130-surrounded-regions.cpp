class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i <n; i++){
            if(board[0][i] == 'O'){
                q.push(make_pair(0,i));
                board[0][i] = '.';
            }
        }
        
        for(int i = 0; i <n; i++){
            if(board[m-1][i] == 'O'){
                q.push(make_pair(m-1,i));
                board[m-1][i] = '.';
            }
        }
        
        for(int i = 1; i < m-1; i++){
            if(board[i][0] == 'O'){
                q.push(make_pair(i,0));
                board[i][0] = '.';
            }
        }
        
        for(int i = 1; i < m-1; i++){
            if(board[i][n-1] == 'O'){
                q.push(make_pair(i,n-1));
                board[i][n-1] = '.';
            }
        }
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            
            int dx[4] = {1,-1,0,0};
            int dy[4] = {0,0,1,-1};
            
            for(int i = 0; i < 4; i++){
                int newx = p.first + dx[i];
                int newy = p.second + dy[i];
                
                if(0 <= newx && newx < m && 0 <= newy && newy < n && board[newx][newy] == 'O'){
                    board[newx][newy] = '.';
                    q.push(make_pair(newx,newy));
                }
            }
        }
        
        for(int i =0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '.'){
                    board[i][j] = 'O';
                }
            }
        }
        
    }

};