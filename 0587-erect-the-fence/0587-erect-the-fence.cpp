class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size() <=3){
            return trees;
        }
        
        int n = trees.size();
        vector<vector<int>> ret;
        vector<vector<int>> ret1;

        sort(trees.begin(),trees.end());
        
        graham(trees,ret);
        reverse(trees.begin(), trees.end());
        graham(trees,ret1);
        
        vector<vector<int>> ans;
        map<pair<int,int>,int> mp;
        
        for(int i = 0; i < ret.size();i++){
            if(mp[make_pair(ret[i][0],ret[i][1])] == 0){
                mp[make_pair(ret[i][0],ret[i][1])] = 1;
                ans.push_back(ret[i]);
            }
        }
        for(int i = 0; i < ret1.size();i++){
            if(mp[make_pair(ret1[i][0],ret1[i][1])] == 0){
                mp[make_pair(ret1[i][0],ret1[i][1])] = 1;
                ans.push_back(ret1[i]);
            }
        }
        
        
        return ans;
    }
    
    void graham(vector<vector<int>>& trees, vector<vector<int>>& ret){
        int n = trees.size();
        int p = 0;
        int q = 0;
        do{
            ret.push_back(trees[p]);
            q = (p+1)%n;

            for(int i = 0; i < n; i++){
                if(orientation(trees[p], trees[i], trees[q]) == 2){
                    q = i;
                }
            }
            p = q;
        }
        while(p != 0); 
    }
    
    int orientation(vector<int> p, vector<int> q, vector<int> r){
        int val = (q[1] - p[1]) * (r[0] - q[0]) -
                  (q[0] - p[0]) * (r[1] - q[1]);

        if (val == 0) return 0;  // collinear
        return (val > 0)? 1: 2; // clock or counterclock wise
    }
};