class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        istringstream str(s);
        string word;
        
        while(str >> word){
            words.push_back(word);
        }
        
        int n = words.size();
        string ret = "";
        for(int i = n -1; i >= 0; i--){
            ret += words[i] + " ";
        }
        
        ret.pop_back();
        
        return ret;
    }
};