class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n == 1){
            return "";
        }
        for(int i = 0; i < n-i-1; i++){
            char a = palindrome[i];
            char b = palindrome[n-i-1];
            
            if(a != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
            
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};