class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        for(char c : s){
            if(st.empty() || abs(st.top() - c) != 32){
                st.push(c);
            }
            else{
                st.pop();
            }
        }
        
        string ret = "";
        while(!st.empty()){
            ret += st.top();
            st.pop();
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};