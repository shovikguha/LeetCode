class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> task_idx;
        int n = tasks.size();

        for(int i = 0; i < n; i++){
            task_idx.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(task_idx.begin(),task_idx.end());
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        int curr = task_idx[0][0];
        int idx = 0;
        vector<int> ret;
        
        for(int i = 0; i < n; i++){
            if(task_idx[i][0] <= curr){
                q.push(make_pair(task_idx[i][1], task_idx[i][2]));
            }
            else{
                if(q.empty()){
                    curr = task_idx[i][0];
                    i--;
                }
                else{
                    pair<int,int> fr = q.top();
                    q.pop();
                    ret.push_back(fr.second);
                    curr += fr.first;
                    i--;
                }
            }
        }
        
        while(!q.empty()){
            pair<int,int> fr = q.top();
            q.pop();
            ret.push_back(fr.second);
        }
        
        return ret;
    }
};