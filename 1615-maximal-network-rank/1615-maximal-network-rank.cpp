class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int edge[n][n];
        int count[n];
        
        memset(edge, 0, sizeof(edge));
        memset(count, 0, sizeof(count));
        
        for(vector<int> v : roads ){
            edge[v[0]][v[1]] = 1;
            edge[v[1]][v[0]] = 1;
            count[v[0]]++;
            count[v[1]]++;
        }
        
        int mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int curr = count[i] + count[j];
                if(edge[i][j]){
                    curr--;
                }
                mx = max(mx, curr);
            }
        }
        
        return mx;
        
    }
};