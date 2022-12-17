class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        int curr = 0;
        
        for(string s : tokens){
            if(s != "+" && s != "-" && s != "/" && s != "*"){
                st.push(stoi(s));
            }    
            else{
                long op1 = st.top();st.pop();
                long op2 = st.top();st.pop();
                
                if(s == "+"){
                    st.push(op1 + op2);
                }
                else if(s == "-"){
                    st.push(op2 - op1);
                }
                else if(s == "*"){
                    st.push(op1 * op2);
                }
                else{
                    st.push(op2 / op1);
                }
            }
        }
        
        return st.top();
    }
};