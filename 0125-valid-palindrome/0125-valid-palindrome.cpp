class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> tmp;
        vector<char> tmp1;

        int n = s.size();
        for(int i = 0; i < n; i++){
            char curr = s.at(i);
            if(isalnum(curr)){
                curr = tolower(curr);
                tmp.push_back(curr);
                tmp1.push_back(curr);
            }
        }
        reverse(tmp.begin(), tmp.end());
        
        return tmp == tmp1;
    }
};