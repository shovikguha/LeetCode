class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ret = 0;
        
        for(string s : words){
            string rev = s;
            reverse(rev.begin(),rev.end());
            if(mp[rev] > 0){
                ret += 4;
                mp[rev] -= 1;
            }
            else{
                mp[s] += 1;
            }
        }
        
        for(string s : words){
            if(s[0] == s[1] && mp[s] == 1){
                ret += 2;
                break;
            }
        }
        
        return ret;
    }
};