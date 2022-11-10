class Solution {
public:
    string removeDuplicates(string s) {
        string ret = "";
        for(int i = 0 ; i < (int)s.size(); i++){
            if(!ret.empty() && s[i] == ret.back()){
                ret.pop_back();
            }
            else{
                ret.push_back(s[i]);
            }
        }
        
        return ret;
    }
};