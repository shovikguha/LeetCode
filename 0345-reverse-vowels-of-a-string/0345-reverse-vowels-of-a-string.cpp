class Solution {
public:
    string reverseVowels(string s) {
        stack<char> st;
        for(int i = 0; i < (int)s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
               s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                st.push(s[i]);
            }       
        }
        
        string ret = "";
        
        for(int i = 0; i < (int)s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
               s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                ret += st.top();
                st.pop();
            }
            else{
                ret += s[i];
            }
        }
        
        return ret;
    }
};