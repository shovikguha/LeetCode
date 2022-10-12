class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
        for(int i = 0; i < n-2; ++i){
            if(verify(nums[i], nums[i+1], nums[i+2])){
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
        
        return 0;
    }
    
    bool verify(int a, int b, int c){
        return (a < b + c && b < a + c && c < a + b);
    }
};