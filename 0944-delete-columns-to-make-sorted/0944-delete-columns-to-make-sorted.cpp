class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<vector<char>> cols(n);

        
        for(int i = 0; i < n; i++){
            for(string s : strs){
                cols[i].push_back(s[i]);
            }
        }

        int ret = 0;
        for(vector<char> v : cols){
            int n = v.size();
            for(int i = 0; i < n-1; i++){
                if(v[i] > v[i+1]){
                    ret++;
                    break;
                }
            }
        }
        
        return ret;
    }
};