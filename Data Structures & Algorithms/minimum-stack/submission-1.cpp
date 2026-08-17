class MinStack {
    int tos;
    vector<int> stk;
    const int inf = 1e9 + 7;
    multiset<int> ms;

public:
    MinStack() {
        tos = -1;
        stk.clear();
    }
    
    void push(int val) {
        stk.push_back(val);
        ms.insert(val);
    }
    
    void pop() {
        if(!stk.empty()) {
            ms.erase(ms.find(stk.back()));
            stk.pop_back();
        }
    }
    
    int top() {
        if(!stk.empty()) return stk.back();
        return -inf;
    }
    
    int getMin() {
        if(!ms.empty()) return *(ms.begin());
        return -inf;
    }
};
