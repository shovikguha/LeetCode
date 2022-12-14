class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long> pre(n);
        
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = nums[i] + pre[i-1];
        }
        
        long ret = INT_MAX;
        int idx = 0;
        
        for(int i = 0; i < n-1; i++){
            long avg1 = pre[i] / (i+1);
            long avg2 = (pre[n-1] - pre[i]) / (n-i-1);
            
            long diff = abs(avg1 - avg2);
            if(diff < ret){
                ret = diff;
                idx = i;
            }
        }
        
        if(pre[n-1] / n < ret){
            return n-1;
        }
        
        return idx;
    }
};