class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        int sm = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            sm += nums[i];
            sm %= k;
            
            if(mp.find(sm)!=mp.end()){
                if(i - mp[sm] > 1){
                    return true;
                }
            }
            else{
                mp[sm] = i;                
            }
        }
        
        return false;
    }
};