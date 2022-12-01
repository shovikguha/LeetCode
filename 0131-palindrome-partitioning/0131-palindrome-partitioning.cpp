class Solution {
public:
    vector<vector<string>> ret;
    
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        dfs(s, 0, curr);
        return ret;
    }
    
    void dfs(string s, int l, vector<string> curr){
        if(l == s.length()){
            ret.push_back(curr);
        }
        else{
            int n = s.length();
            string tmp  = "";
            for(int i = l; i < n; i++){
                tmp.push_back(s[i]);
                if(isPalindrome(tmp)){
                    curr.push_back(tmp);
                    dfs(s, i+1, curr);
                    curr.pop_back();
                }
            }
        }
    }
    
    bool isPalindrome(string s){
        int n = s.length();
        for(int i = 0; i < n-i-1; i++){
            if(s[i] != s[n-i-1]){
                return false;
            }
        }
        return true;
    }
};