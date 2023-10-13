class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        vector<int> dp(sz + 1);
        dp[sz-1] = cost[sz - 1];
        
        for(int i = sz - 2; i >= 0; i--){
            dp[i] = min(dp[i+1] + cost[i], dp[i+2] + cost[i]);
        }
        
        return min(dp[0], dp[1]);
    }
};