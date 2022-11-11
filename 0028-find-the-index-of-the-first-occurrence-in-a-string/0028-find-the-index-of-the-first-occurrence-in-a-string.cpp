class Solution {
public:
    int strStr(string haystack, string needle) {
        unordered_map<string,int> mp;
        int n = haystack.size();
        int m = needle.size();
        
        if(m > n){
            return -1;
        }
        
        mp[needle] =1;
        
        for(int i = 0; i <= n - m; i++){
            string s = haystack.substr(i, m);
            if(mp[s] != 0){
                return i;
            }
        }
        
        return -1;
    }
};