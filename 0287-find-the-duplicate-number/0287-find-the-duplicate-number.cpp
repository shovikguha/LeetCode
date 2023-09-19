class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int len = nums.size();
        
        while(lo < hi){
            int mid = (lo + hi) / 2;
            
            int cnt = 0;
            for(int i = 0; i < len; i++){
                if(nums[i] <= mid){
                    cnt++;
                }
            }
            
            if(cnt <= mid){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        
        return lo;
        
    }
};