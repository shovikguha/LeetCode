class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3);
        vector<int> ret;
        
        for(int i: nums){
            cnt[i]++;
        }
        
        int idx = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < cnt[i]; j++){
                nums[idx] = i;
                idx++;
            }
        }
        
    }
};