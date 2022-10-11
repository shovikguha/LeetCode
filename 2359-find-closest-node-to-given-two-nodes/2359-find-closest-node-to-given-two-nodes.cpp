class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> d1(n);
        vector<int> d2(n);
        
        for(int i = 0; i < n; i++){
            d1[i] = -1;
            d2[i] = -1;
        }
        
        d1[node1] = 0;
        d2[node2] = 0;
        
        dfs(edges[node1], 1, d1, edges);
        dfs(edges[node2], 1, d2, edges);
        
        int ret = INT_MAX;
        int ret_idx = -1;
        for(int i = 0; i < n; i++){
            if(d1[i] != -1 && d2[i] != -1){
                int mx = max(d1[i], d2[i]);
                if(mx < ret){
                    ret = mx;
                    ret_idx = i;
                }
            }
        }
        
        return ret_idx;
    }
    
    void dfs(int node, int dst, vector<int>& dist, vector<int>& edges){
        if(node != - 1 && dist[node] == -1){
            dist[node] = dst;
            dfs(edges[node], dst + 1, dist, edges);
        }
    }
};