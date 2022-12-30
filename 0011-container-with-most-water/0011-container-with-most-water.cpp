class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int mx = INT_MIN;
        
        while(i < j){
            int curr = min(height[i],height[j]) * (j-i);
            mx = max(mx, curr);
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        
        return mx;
    }
};