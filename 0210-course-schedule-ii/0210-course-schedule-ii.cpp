class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indegree(numCourses);
        
        for(vector<int> v : prerequisites){
            edges[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        
        queue<int> q;
        vector<int> ret;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                ret.push_back(i);
            }
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int ne : edges[curr]){
                indegree[ne]--;
                if(indegree[ne] == 0){
                    q.push(ne);
                    ret.push_back(ne);
                }
            }
        }
        
        for(int i : indegree){
            if(i != 0){
                return {};
            }
        }
        
        return ret;
    }
};