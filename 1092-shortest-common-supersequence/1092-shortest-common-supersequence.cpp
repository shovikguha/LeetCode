class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n =  str1.size();
        int m = str2.size();
        
        string dp[n+1][m+1];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i][j] = "";
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(str1[i] == str2[j]){
                    dp[i + 1][j+ 1] = dp[i][j] + str1[i]; 
                }
                else{
                    if(dp[i+1][j].size() > dp[i][j+1].size()){
                        dp[i+1][j+1] = dp[i+1][j];
                    }
                    else{
                        dp[i+1][j+1] = dp[i][j+1];
                    }
                }
            }
        }
        
        string lcs = dp[n][m];
        
        string ret = "";
        int i = 0;
        int j = 0;
        for(char c : lcs){
            while(c != str1[i]){
                ret += str1[i];
                i++;
            }
            while(c != str2[j]){
                ret += str2[j];
                j++;
            }
            ret += c;
            i++;
            j++;
        }
        
        
        ret = ret + str1.substr(i) + str2.substr(j);
        return ret;
    }
};