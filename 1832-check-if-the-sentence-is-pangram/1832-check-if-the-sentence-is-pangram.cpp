class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> mp(26);
        
        int n = sentence.size();
        
        for(int i = 0; i< n; i++){
            mp[sentence[i]-'a'] = 1;
        }
        
        return accumulate(mp.begin(), mp.end(), 0) == 26;
    }
};