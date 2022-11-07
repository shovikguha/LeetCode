class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map <string, int> mp;
        vector<string> ret;
        int sz = recipes.size();
        vector<int> made(sz);
        
        for(auto s: supplies){
            mp[s] = 1;
        }
        
        int ini = ret.size();
        do{
            ini = ret.size();
            for(int i = 0; i < recipes.size(); i++){
                if(made[i] == 0){
                    bool canMake = true;
                    for(int j = 0; j < ingredients[i].size(); j++){
                        if(mp[ingredients[i][j]] == 0){
                            canMake = false;
                            break;
                        }
                    }
                    if(canMake){
                        ret.push_back(recipes[i]);
                        mp[recipes[i]] = 1;
                        made[i] = 1;
                    } 
                }
            }   
        }
        while(ini != ret.size());
        
        return ret;
    }
};