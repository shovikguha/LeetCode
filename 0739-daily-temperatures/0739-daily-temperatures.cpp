class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ret(n);
        
        stack<int> st;
        for(int i =0; i < n; i++){
            if(st.empty() || temperatures[i] <= temperatures[st.top()]){
                st.push(i);     
            }
            else{
                while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                    int tmp = st.top();
                    st.pop();
                    ret[tmp] = i - tmp;
                }
                st.push(i);
            }
        }
        
        return ret;
    }
};