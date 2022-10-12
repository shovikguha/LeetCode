class Solution {
public:
    int ret;
    
    int longestCycle(vector<int>& edges) {
        ret = -1;
        
        int n = edges.size();
        vector<pair<int,int>> visited(n);
        for(int i = 0; i < n; i++){
            if(visited[i].first == 0){
                dfs(i, edges, visited, 0);
            }
        }
        
        return ret;
    }
    
    void dfs(int node, vector<int>& edges, vector<pair<int,int>>& visited, int t){
        if(node != -1){
            if(visited[node].first == 0){
                visited[node] = make_pair(-1, t);
                dfs(edges[node], edges, visited, t+1);
                visited[node].first = 1;
            }
            else if(visited[node].first == -1){
                ret = max(ret, t - visited[node].second);
            }
        }
    }
};