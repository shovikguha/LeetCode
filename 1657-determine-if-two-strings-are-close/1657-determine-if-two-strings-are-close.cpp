class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()){
            return false;
        }
        
        vector<int> seen1(26);     
        vector<int> seen2(26);

        unordered_map<int,int> occ;
        
        int n = word1.length();
        for(int i = 0; i < n; i++){
            seen1[word1[i] - 'a']++;
            seen2[word2[i] - 'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if((seen1[i] && !seen2[i]) || (!seen1[i] && seen2[i])){
                return false;
            }
        }
        
        for(int i : seen1){
            occ[i]++;
        }
        
        for(int i : seen2){
            if(occ.find(i) == occ.end()){
                return false;
            }
            occ[i]--;
        }
        
        for(auto [k,v] : occ){
            if(v != 0){
                return false;
            }
        }
        
        return true;
    }
};