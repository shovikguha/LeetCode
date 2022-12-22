class Solution {
public:
    int m;
    int n;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        
        vector<vector<int>> seen(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            fill(seen[i].begin(),seen[i].end(),-1);
        }
        
        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
                if(seen[i][j] == -1){
                    dfs(i,j,matrix,seen);
                }
            }
        }
        
        int ret = INT_MIN;
        for(int i = 0; i < m; i++){
            ret = max(ret, *max_element(seen[i].begin(),seen[i].end()));
        }
        
        return ret;
        
    }
    
    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& seen){
        if(seen[x][y] != -1){
            return seen[x][y];
        }
        else{
            int dx[4] = {1,-1,0,0};
            int dy[4] = {0,0,1,-1};
            int mx = 1; 

            for(int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if( 0 <= newx && newx < m && 0 <= newy && newy < n && matrix[newx][newy] > matrix[x][y]){
                    mx = max(mx,1 + dfs(newx,newy, matrix, seen));
                }
            }
            return seen[x][y] = mx;
        }
    }
};