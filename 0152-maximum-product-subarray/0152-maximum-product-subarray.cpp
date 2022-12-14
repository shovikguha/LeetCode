class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx(n+1);
        vector<int> mn(n+1);
        
        mx[n] = 1;
        mn[n] =1;
        
        int ret = INT_MIN;
        
        for(int i = n-1; i >= 0; i--){
            vector<int> tmp = {nums[i], mx[i+1]*nums[i], mn[i+1]*nums[i]};
            mx[i] = *max_element(tmp.begin(), tmp.begin() + 3);
            mn[i] = *min_element(tmp.begin(), tmp.begin() + 3);
            
            ret = max(ret, mx[i]);
        }
        
        return ret;
    }
};