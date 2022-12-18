class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n);
        dp[n-1] = true;
        
        for(int i = n-2; i >=0; i--){
            for(int dx = 1; dx <= nums[i]; dx++){
                int tmp = min(i + dx, n-1);
                dp[i] = dp[i] || dp[tmp];
                if(dp[i] || tmp == n-1){
                    break;
                }
            }
        }
        
        return dp[0];
    }
};