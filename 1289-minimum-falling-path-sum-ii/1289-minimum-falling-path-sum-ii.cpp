class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int j = 0; j < n; j++){
            dp[n-1][j] = grid[n-1][j];
        }
        
        for(int i = n-2; i >=0; i--){
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
            for(int j = 0; j < n; j++){
                q.push(make_pair(dp[i+1][j], j));
            }
            pair<int,int> mn = q.top();
            q.pop();
            pair<int,int> smn = q.top();
            for(int j = 0; j < n; j++){
                if(j == mn.second){
                    dp[i][j] = smn.first + grid[i][j];
                }
                else{
                    dp[i][j] = mn.first + grid[i][j];
                }
            }
        }
        return *min_element(dp[0], dp[0]+n);
    }
};