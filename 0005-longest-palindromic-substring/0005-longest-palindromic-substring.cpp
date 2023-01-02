class Solution {
public:
    string longestPalindrome(string s) {
        string ret = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            string tmp = longest(i,i,s);
            if(tmp.size() > ret.size()){
                ret = tmp;
            }
        }
        
        for(int i = 0; i < n-1; i++){
            string tmp =  "";
            if(s[i] == s[i+1]){
                tmp = longest(i,i+1,s);
            }
            if(tmp.size() > ret.size()){
                ret = tmp;
            }
        }
        
        return ret;
    }
    
    string longest(int i, int j, string& s){
        int n = s.size();
        
        while(i > 0 && j < n-1 && s[i-1] == s[j+1]){
            i--;
            j++;
        }
        
        return s.substr(i,j-i+1);
    }
};