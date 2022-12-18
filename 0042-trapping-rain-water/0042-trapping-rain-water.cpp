class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> mxLeft(n);
        vector<int> mxRight(n);
        
        fill(mxLeft.begin(), mxLeft.end(), -1);
        fill(mxRight.begin(), mxRight.end(), -1);
        
        int currMx = height[0];
        for(int i = 1; i < n; i++){
            if(height[i] > currMx){
                currMx = height[i];
            }
            else{
                mxLeft[i] = currMx;
            }
        }
        
        currMx = height[n-1];
        for(int i = n-2; i >= 0; i--){
            if(height[i] > currMx){
                currMx = height[i];
            }
            else{
                mxRight[i] = currMx;
            }
        }
        
        int ret = 0;
        for(int i = 0; i < n; i++){
            int mn = min(mxLeft[i], mxRight[i]);
            if(mn != -1){
                ret += mn - height[i];
            }
        }
        
        return ret;
    }
};