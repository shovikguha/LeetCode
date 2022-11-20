class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<vector<int>> adjlst(n);
        unordered_map<string, int> mp;
        vector<string> ret;
        vector<int> visited(n);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < friends[i].size(); j++){
                adjlst[i].push_back(friends[i][j]);
            }
        }
        
        
        queue<pair<int,int>> q;
        q.push(make_pair(id,0));
        visited[id] = 1;

        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            if(curr.second == level){
                for(int i = 0; i < watchedVideos[curr.first].size();i++){
                    mp[watchedVideos[curr.first][i]]++;
                }
            }
            else if(curr.second < level){
                for(int ne : adjlst[curr.first]){
                    if(visited[ne] == 0){
                        visited[ne] = 1;
                        q.push(make_pair(ne, curr.second + 1));
                    }
                }
            }
        }

        vector<pair<int,string>> tmp;
        for(auto it = mp.begin(); it != mp.end(); it++){
            tmp.push_back(make_pair(it->second, it->first));
        }
        
        sort(tmp.begin(), tmp.end());
        for(pair<int,string>p : tmp){
            ret.push_back(p.second);
        }
        
        return ret;
    }
};