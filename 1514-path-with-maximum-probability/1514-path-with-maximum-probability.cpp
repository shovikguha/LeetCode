class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double dist[n];
        for(int i = 0; i < n; i++){
            dist[i] = DBL_MAX;
        }
        
        priority_queue <pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
        vector<vector<pair<double, int>>> adjlst(n);
        
        for(int i = 0; i < (int)edges.size(); i++){
            //convert to log space, negate since for all x < 1, log10(x) < 0
            //allows us to work with sums, also avoids precision errors
            //normally, we would look for max sum path in log space, but since we negate, we look for 
            //min sum path, i.e shortest path 
            adjlst[edges[i][0]].push_back(make_pair(-1*log10(succProb[i]), edges[i][1]));
            adjlst[edges[i][1]].push_back(make_pair(-1*log10(succProb[i]), edges[i][0]));
        }
        
        dist[start] = 0.0;
        
        vector<int> visited(n);
        pq.push(make_pair(0.0, start));
        
        while(!pq.empty()){
            pair<double, int> p = pq.top();
            pq.pop();
            double pr = p.first;
            int node = p.second;
            if(visited[node] == 0){
                visited[node] = 1;
                
                if(pr < dist[node]){
                    dist[node] = pr;
                }
                
                if(node == end){
                    break;
                }
                
                for(pair<double, int> ne : adjlst[node]){
                    pq.push(make_pair(ne.first + pr, ne.second));
                }
            }
        }
        
        if(dist[end] == DBL_MAX){
            return 0.0;
        }
        return pow(10, -1*dist[end]);
    }
};