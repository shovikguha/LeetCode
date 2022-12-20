class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n);
        
        visited[0] = 1;
        dfs(0, visited, rooms);
        
        for(int i : visited){
            if(i == 0){
                return false;
            }
        }
        
        return true;
    }
    
    void dfs(int curr, vector<int>& visited, vector<vector<int>>& rooms){
        for(int ne : rooms[curr]){
            if(!visited[ne]){
                visited[ne] = 1;
                dfs(ne, visited, rooms);
            }
        }
    }
};