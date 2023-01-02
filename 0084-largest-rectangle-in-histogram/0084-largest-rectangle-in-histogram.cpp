class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
                
        int n = heights.size();
        int mx = 0;
        for(int i =0; i < n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                
                int w = i - (st.empty() ? -1 : st.top())  - 1;
                
                mx = max(mx, h * w);
            }
            st.push(i);
        }
        
        return mx;
    }
};