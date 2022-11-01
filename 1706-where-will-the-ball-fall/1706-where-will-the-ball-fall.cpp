class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> ret;
        
        for(int i = 0; i < m; i++){
            ret.push_back(dfs(0,i,n,m,grid));
        }
        
        return ret;
    }
    
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i < 0 || i >= n || j < 0 || j >= m){
            return -1;
        }
        else if(i == n-1){
            if(grid[i][j] == 1){
                if(j == m-1 || grid[i][j+1] == -1){
                    return -1;
                }
                else{
                    return j+1;
                }
            }
            else{
                if(j == 0 || grid[i][j-1] == 1){
                    return -1;
                }
                else{
                    return j-1;
                }
            }
        }
        else{
            if(grid[i][j] == 1){
                if(j == m-1 || grid[i][j+1] == -1){
                    return -1;
                }
                else{
                    return dfs(i+1, j+1, n, m, grid);
                }
            }
            else{
                if(j == 0 || grid[i][j-1] == 1){
                    return -1;
                }
                else{
                    return dfs(i+1, j-1, n, m, grid);
                }
            }
        }
    }
};