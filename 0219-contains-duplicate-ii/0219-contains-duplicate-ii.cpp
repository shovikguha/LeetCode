class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(int i = 0; i < (int)nums.size(); i++){
            if(i != 0){
                int idx = mp[nums[i]];
                if(idx != 0){
                    if(i - idx <= k){
                        return true;
                    }
                }
                else{
                    if(nums[i] == nums[0]){
                        if(i <= k){
                            return true;
                        }
                    }
                }
                mp[nums[i]] = i;
            }
        }
        
        return false;
    }
};