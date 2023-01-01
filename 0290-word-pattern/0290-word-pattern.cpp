class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_set<char> seen;
        unordered_map<string,int> mp;
        
        istringstream str(s);
        string tmp;
        vector<string> sent;
        
        while(str >> tmp){
            sent.push_back(tmp);
        }
        
        int n = sent.size();
        
        if(n != pattern.length()){
            return false;
        }
        
        for(int i = 0; i < n; i++){
            if(seen.find(pattern[i]) != seen.end()){
                if(mp[sent[i]] != pattern[i]){
                    return false;
                }
            }
            else if(mp.find(sent[i]) != mp.end()){
                if(mp[sent[i]] != pattern[i]){
                    return false;
                }
            }
            else{
                mp[sent[i]] = pattern[i];
                seen.insert(pattern[i]);
            }
        }
        
        return true;
    }
};