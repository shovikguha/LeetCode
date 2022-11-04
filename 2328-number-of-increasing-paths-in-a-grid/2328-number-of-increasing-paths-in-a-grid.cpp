class Solution {
public:
    long dp[1000][1000];
    int m;
    int n;
    int mod;
    
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        mod = pow(10,9) + 7;
        
        for(int i = 0; i < 1000; i++){
            for(int j = 0; j < 1000; j++){
                dp[i][j] = -1;
            }
        }
        
        int ret = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ret = (ret + dfs(i,j,grid)) % mod;
            }
        }
        
        return ret;
        
    }
    
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        else{
            int ret = 1;
            int dx[4] = {-1,1,0,0}; 
            int dy[4] = {0,0,-1,1}; 
            
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                
                if(0 <= x && x < grid.size() && 0 <= y && y < grid[x].size() && grid[x][y] > grid[i][j]){
                    ret = (ret + dfs(x,y,grid)) % mod;
                }
            }
            
            return dp[i][j] = ret;
        }
    }
};