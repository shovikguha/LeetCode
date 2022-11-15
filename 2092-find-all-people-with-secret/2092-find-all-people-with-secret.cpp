class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> ret;
        vector<int> parent(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        sort(meetings.begin(), meetings.end(), [](const auto& v1, const auto& v2)
        {
            return v1.back() < v2.back();
        });
        
        meetings.push_back({-1,-1,-1});
        uni(0,firstPerson,parent);
        
        vector<vector<int>> curr;
        
        for(int i = 0; i < meetings.size(); i++){
            if(curr.size() ==0 || meetings[i][2] == curr.back().back()){
                curr.push_back(meetings[i]);
            }
            else{
                set<int> people;
                for(auto& v : curr){
                    uni(v[0], v[1], parent);
                    people.insert(v[0]);
                    people.insert(v[1]);
                }

                for(auto it = people.begin(); it != people.end(); it++){
                    int p = *it;
                    if(find(p, parent) != find(firstPerson, parent)){
                        parent[p] = p;
                    }
                }
                curr.clear();
                i--;
            }
        }
        
                
        int p = find(firstPerson, parent);
        for(int i = 0; i < n; i++){
            if(find(i, parent) == p){
                ret.push_back(i);
            }
        }
        
        return ret;
    }
    
    int find(int i, vector<int>& parent){
        int ret = i;
        while(parent[ret] != ret){
            ret = parent[ret];
        }
        
        //path compression
        while (parent[i] != i) {
            int next = parent[i];
            parent[i] = ret;
            i = next;
        }
        return ret;
    }
    
    void uni(int i, int j, vector<int>& parent){
        int x = find(i, parent);
        int y = find(j, parent);
        parent[x] = y;
    }
};