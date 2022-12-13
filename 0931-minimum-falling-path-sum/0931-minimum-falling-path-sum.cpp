class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < n; i++){
            dp[n-1][i] = matrix[n-1][i];
        }
        
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(j == 0){
                    dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + matrix[i][j];
                }
                else if(j == n-1){
                    dp[i][j] = min(dp[i+1][j], dp[i+1][j-1]) + matrix[i][j];
                }
                else{
                    dp[i][j] = min(dp[i+1][j], min(dp[i+1][j+1], dp[i+1][j-1])) + matrix[i][j];
                }
            }
        }
        
        return *min_element(dp[0], dp[0] + n);
    }
};