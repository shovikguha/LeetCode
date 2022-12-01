class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        n /= 2;
        string s1 = s.substr(0,n);
        string s2 = s.substr(n,n);
                
        int count = 0;        
        for(int i = 0; i < n; i++){
            if(s1[i] == 'A' || s1[i] == 'a' || s1[i] == 'E' || s1[i] == 'e' || s1[i] == 'I' || s1[i] == 'i' || s1[i] == 'O' || s1[i] == 'o' || s1[i] == 'U' || s1[i] == 'u'){
                count++;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(s2[i] == 'A' || s2[i] == 'a' || s2[i] == 'E' || s2[i] == 'e' || s2[i] == 'I' || s2[i] == 'i' || s2[i] == 'O' || s2[i] == 'o' || s2[i] == 'U' || s2[i] == 'u'){
                count--;
            }
        }
        
        return (count == 0);
    }
};