class Solution {
public:
    int glo_n;
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n);
        vector<vector<int>> blue(n);
        glo_n = n;
        
        for(int i =0; i < (int)redEdges.size(); i++){
            red[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        
        for(int i =0; i < (int)blueEdges.size(); i++){
            blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        
        vector<int> dist1(n);
        vector<int> dist2(n);
        
        for(int i = 0;i < n; i++){
            dist1[i] = INT_MAX;
            dist2[i] = INT_MAX;
        }
        
        bfs(red, blue, dist1);
        bfs(blue, red, dist2);
        
        vector<int> ret(n);
        
        for(int i = 0; i < n; i++){
            if(dist1[i] == INT_MAX && dist2[i] == INT_MAX){
                ret[i] = -1;
            }
            else if(dist1[i] == INT_MAX){
                ret[i] = dist2[i];
            }
            else if(dist2[i] == INT_MAX){
                ret[i] = dist1[i];
            }
            else{
                ret[i] = min(dist1[i], dist2[i]);
            }
        }
        
        return ret;
    }
    
    void bfs(vector<vector<int>>& edges1, vector<vector<int>>& edges2, vector<int>& dist){
        queue<vector<int>> q;
        q.push({0,0,0});
        vector<vector<int>> visited(glo_n, vector<int>(2));
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(visited[curr[0]][curr[2]] == 0){
                visited[curr[0]][curr[2]] = 1;
                dist[curr[0]] = min(dist[curr[0]], curr[1]);
                if(curr[2] == 0){
                    for(int ne : edges1[curr[0]]){
                        q.push({ne, curr[1] + 1, 1});
                    }
                }
                else{
                    for(int ne : edges2[curr[0]]){
                        q.push({ne, curr[1] + 1, 0});
                    }
                }
            }
            
        }
    }
};