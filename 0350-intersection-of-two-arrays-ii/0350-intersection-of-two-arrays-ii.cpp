class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> count(1001);
        vector<int> count1(1001);
        
        for(int i: nums1){
            count[i]++;
        }
        
        for(int i: nums2){
            count1[i]++;
        }
        
        vector<int> ret;
        for(int i = 0; i < 1001; i++){
            if(count[i] && count1[i]){
                for(int j = 0; j < min(count[i],count1[i]); j++){
                    ret.push_back(i);
                }
            }
        }
        
        return ret;
    }
};