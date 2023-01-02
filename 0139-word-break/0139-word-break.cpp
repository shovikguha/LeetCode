class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = s.size();
        
        vector<bool> brk(m+1);
        unordered_set<string> dict;
        
        for(string s : wordDict){
            dict.insert(s);
        }
        
        brk[m] = true;
        
        for(int i = m-1; i >= 0; i--){
            for(int j = i; j < m; j++){
                string tmp = s.substr(i,j-i+1);
                if(dict.find(tmp) != dict.end() && brk[j+1]){
                    brk[i] = true;
                    break;
                }        
            }
        }
        
        return brk[0];
    }
};