class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n+2);
        
        for(int i = n-1; i >= 0; i--){
            ret[i] = max(nums[i] + ret[i+2], ret[i+1]);
        }
        
        return ret[0];
    }
};