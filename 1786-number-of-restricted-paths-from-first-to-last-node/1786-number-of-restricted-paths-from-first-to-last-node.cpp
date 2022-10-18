class Solution {
public:
    int mod;
    int glo_n;
    int dp[20001];
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        mod = pow(10,9) + 7;
        glo_n = n;
        for(int i = 0; i < n+1; i++){
            dp[i] = -1;
        }
        
        vector<vector<pair<int,int>>> adjlst(n+1);
        
        for(vector<int> v : edges){
            adjlst[v[1]].push_back(make_pair(v[0], v[2]));
            adjlst[v[0]].push_back(make_pair(v[1], v[2]));
        }
        
        vector<int> dist(n+1);
        for(int i = 0; i < n; i++){
            dist[i] = INT_MAX;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(make_pair(0,n));
        
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            
            for(auto ne: adjlst[p.second]){
                if(p.first + ne.second < dist[ne.first]){
                    dist[ne.first] = p.first + ne.second;
                    pq.push(make_pair(dist[ne.first],ne.first));
                }
            }
        }
        
        return dfs(1, adjlst, dist, dist[1]);
    }
    
    int dfs(int node, vector<vector<pair<int,int>>>& adjlst, vector<int>& dist, int prev){
        if(node == glo_n){
            return 1;
        }
        else if(dp[node] != -1){
            return dp[node];
        }
        else{
            long ret = 0;
            for(auto ne: adjlst[node]){
                if(dist[ne.first] < prev){
                    ret += dfs(ne.first, adjlst, dist, dist[ne.first]) % mod;
                }
            }
            return dp[node] = ret % mod;
        }
    }
};