class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int  i = 0; int j = 0;
        int ret = -1;
        
        while(i < n && j < n){
            if(mp.find(s[j]) != mp.end()){
                int len = j-i;
                ret = max(ret, len);
                i = max(i, mp[s[j]]+1);
                mp[s[j]] = j;
            }
            mp[s[j]] = j;
            j++;
        }
        
        int len = j-i;
        ret = max(ret, len);
        
        return ret;
    }
};