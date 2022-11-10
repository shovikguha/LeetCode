class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ret = 0;
        
        int i = 0;
        int j = 0;
        int n = s.size();
        
        while(i < n && j < n){
            if(mp[s[j]] == 0){
                mp[s[j]] = j + 1;
            }
            else{
                ret = max(ret, j - i);
                i = max(mp[s[j]], i);
                mp[s[j]] = j + 1;
            }
            j++;
        }
                
        ret = max(ret, j-i);
        
        return ret;
    }
};