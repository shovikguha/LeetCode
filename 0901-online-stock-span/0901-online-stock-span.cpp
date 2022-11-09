class StockSpanner {
public:
    stack<int> prices;
    stack<int> spans;
    
    StockSpanner() {

    }
    
    int next(int price) {
        int sp =1;
        while(!prices.empty() && prices.top() <= price){
            prices.pop();
            sp += spans.top();
            spans.pop();
        }
        prices.push(price);
        spans.push(sp);
        return sp;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */