class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstcap = false;
        bool allcap = true;
        bool alllower = true;
        
        int n = word.size();
        for(int i =0;i < n; i++){
            if(i == 0 && word[i] <= 'Z' && word[i] >= 'A'){
                firstcap = true;
                alllower = false;
            }
            else if(word[i] <= 'z' && word[i] >= 'a'){
                allcap = false;
            }
            else if(word[i] <= 'Z' && word[i] >= 'A'){
                alllower = false;
                firstcap = false;
            }
        }
        
        return (allcap || alllower || firstcap);
    }
};