class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        
        string ret = "";
        while(iss >> word){
            reverse(word.begin(), word.end());
            ret += word;
            ret += " ";
        }
        
        return ret.substr(0, ret.size()-1);
    }
};