class Solution {
public:
    vector<string> ret;
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0){
            return {};
        }
        
        unordered_map<int,vector<char>> mp = {{2, {'a','b','c'}}, {3, {'d','e','f'}},{4, {'g','h','i'}},{5, {'j','k','l'}},{6, {'m','n','o'}},{7, {'p','q','r','s'}},{8, {'t','u','v'}},{9, {'w','x','y', 'z'}}};
        
        dfs(0,digits,mp,"");
        return ret;
    }
    
    void dfs(int i, string& digits, unordered_map<int,vector<char>>& mp, string curr){
        if(i == digits.size()){
            ret.push_back(curr);
        }
        else{
            for(char c : mp[digits[i] - '0']){
                dfs(i+1, digits, mp, curr + c);
            }
        }
    }
};