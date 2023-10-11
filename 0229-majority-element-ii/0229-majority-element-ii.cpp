class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int can1 = -1;
        int can2 = -1;
        
        int c1 = 0;
        int c2 = 0;
        
        for(auto& x : nums){
            if(x == can1){
                c1++;
            }
            else if(x == can2){
                c2++;
            }
            else if(c1 ==0 ){
                can1 = x;
                c1++;
            }
            else if(c2 == 0){
                can2 = x;
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        c1 = 0;
        c2 = 0;
        
        for(auto&x: nums){
            if(x == can1){
                c1++;
            }
            if(x == can2){
                c2++;
            }
        }
        
        vector<int>ret;
        int sz = (nums.size() /3); 
        if(c1 > sz){
            ret.push_back(can1);
        }
        if(can1 != can2 && c2 > sz){
            ret.push_back(can2);
        }
        
        return ret;
    }
};