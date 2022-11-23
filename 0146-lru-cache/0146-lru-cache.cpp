class LRUCache {
public:
    list<int> keys;
    unordered_map<int,int> mp;
    unordered_map<int,list<int>::iterator> key_mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = key_mp.find(key);
        if(it != key_mp.end()){
            keys.erase(it -> second);
            keys.push_front(key);
            key_mp[key] = keys.begin();
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = key_mp.find(key);
        if(key_mp.size() == cap && it == key_mp.end()){
            int rm = keys.back();
            keys.pop_back();
            //mp.erase(rm);
            key_mp.erase(rm);
        }
        mp[key] = value;
        if(it != key_mp.end()){
            keys.erase(it -> second);
        }
        keys.push_front(key);
        key_mp[key] = keys.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */