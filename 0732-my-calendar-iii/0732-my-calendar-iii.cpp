class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        
        int ret = 0;
        int curr = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            curr += it -> second;
            ret = max(ret, curr);
        }
        
        return ret;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */