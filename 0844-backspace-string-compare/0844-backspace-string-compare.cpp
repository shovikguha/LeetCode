class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;
        
        for(auto& c : s){
            if(c == '#'){
                if(!s1.empty()){
                    s1.pop();
                }
            }
            else{
                s1.push(c);
            }
        }
        
        for(auto& c : t){
            if(c == '#'){
                if(!s2.empty()){
                    s2.pop();
                }
            }
            else{
                s2.push(c);
            }
        }
        
        return s1 == s2;
    }
};