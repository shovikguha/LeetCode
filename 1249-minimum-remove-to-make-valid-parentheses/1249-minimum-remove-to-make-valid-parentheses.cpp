class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == ')'){
                if(s[i] == ')' && !st.empty() && s[st.top()] == '('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        
        if(st.empty()){
            return s;
        }
        
        string ret = "";
        for(int i = n - 1; i >= 0; i--){
            if(!st.empty() && st.top() == i){
                st.pop();
            }
            else{
                ret.push_back(s[i]);
            }
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};