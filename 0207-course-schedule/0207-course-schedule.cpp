class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlst(numCourses);
        vector<int> indegree(numCourses);
        
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
            
            for(int ne : adjlst[curr]){
                indegree[ne]--;
                if(indegree[ne] == 0){
                    q.push(ne);
                }
            }
        }
        
        for(int i = 0; i < numCourses; i++){
            if(seen[i] == 0){
                return false;
            }
        }
        
        return true;
        
    }
    
};