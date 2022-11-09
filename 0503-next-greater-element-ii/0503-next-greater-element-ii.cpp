class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int,int>>st;
        
        int n = nums.size();
        vector<int> ret(n,-1);  
        
        for(int i =0; i < n; i++){
            while(!st.empty() && st.top().first < nums[i]){
                auto& p = st.top();
                ret[p.second] = nums[i];
                st.pop();
            }
            st.push(make_pair(nums[i],i));
        }
        
        for(int i =0; i < n; i++){
            while(!st.empty() && st.top().first < nums[i]){
                auto& p = st.top();
                if(ret[p.second] == -1){
                    ret[p.second] = nums[i];
                }
                st.pop();
            }
            st.push(make_pair(nums[i],i));
        }
        
        return ret;
    }
};