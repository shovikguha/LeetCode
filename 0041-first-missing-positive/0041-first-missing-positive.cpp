class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[i] != i+1){
                int val = nums[i];
                int idx = i;
                while(val > 0 && val <= n && nums[idx] != idx+1){
                    int tmp = nums[val - 1];
                    nums[val - 1] = val;
                    val = tmp;
                    idx = tmp - 1;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        
        return n+1;
    }
};