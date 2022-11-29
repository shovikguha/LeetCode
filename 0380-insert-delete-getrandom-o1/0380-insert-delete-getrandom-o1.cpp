class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> items;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            mp[val] = (int)mp.size();
            items.push_back(val);
            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }
        else{
            int idx = mp[val];
            int end = items.size() - 1;
            swap(items[idx], items[end]);
            items.pop_back();
            mp[items[idx]] = idx;
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int idx = rand() % items.size();
        return items[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */