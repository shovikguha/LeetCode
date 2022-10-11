class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mn1 = INT_MAX;
        int mn2 = INT_MAX;
        
        for(int i : nums){
            if(i <= mn1){
                mn1 = i;
            }
            else if (i <= mn2){
                mn2 = i;
            }
            else{
                return true;
            }
        }
        return false;
    }
};