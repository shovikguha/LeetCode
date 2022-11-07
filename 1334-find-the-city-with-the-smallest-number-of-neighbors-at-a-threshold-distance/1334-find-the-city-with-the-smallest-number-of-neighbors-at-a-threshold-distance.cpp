class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector(n, 10001));
        int ret = 0, smallest = n;
        
        for(auto& e : edges){
            dis[e[1]][e[0]] = e[2];
            dis[e[0]][e[1]] = e[2];
        }
        
        for(int i = 0; i < n; i++){
            dis[i][i] = 0;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
                }
            }
        }
        
        for(int i =0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(dis[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= smallest){
                smallest = count;
                ret = i;
            }
        }
        
        return ret;
    }
};