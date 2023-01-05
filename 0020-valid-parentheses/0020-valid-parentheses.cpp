class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> comp;
        comp[')'] = '(';
        comp['}'] = '{';
        comp[']'] = '[';

        
        for(char c : s){
            if(c == ')' || c == '}' || c == ']'){
                if(st.empty() || st.top() != comp[c]){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else{
                st.push(c);
            }
        }
        
        return st.empty();
    }
};