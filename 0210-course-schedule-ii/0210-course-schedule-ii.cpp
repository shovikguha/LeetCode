class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlst(numCourses);
        vector<int> indegree(numCourses);
        vector<int> ret;
        
        for(auto& v  : prerequisites){
            adjlst[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> seen(numCourses);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            seen[curr] = 1;
            ret.push_back(curr);
            
            for(int ne : adjlst[curr]){
                indegree[ne]--;
                if(indegree[ne] == 0){
                    q.push(ne);
                }
            }
        }
        
        for(int i = 0; i < numCourses; i++){
            if(seen[i] == 0){
                return {};
            }
        }
        
        return ret;
    }
};