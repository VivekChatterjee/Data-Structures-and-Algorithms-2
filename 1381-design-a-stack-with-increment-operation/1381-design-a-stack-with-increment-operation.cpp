class CustomStack {
public:
    int size=0;
    vector<pair<int, int>>v;
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        if(v.size()<size)
        {
            v.push_back({x, 0});
        }
    }
    
    int pop() {
        if(v.empty()) return -1;
        else
        {
            int toAdd=v.back().second;
            int top=v.back().first+toAdd;
            v.pop_back();
            if(!v.empty()) v.back().second+=toAdd;
            return top;
        }
    }
    
    void increment(int k, int val) {
        int n = v.size();
        if(min(n,k)>0)  v[min(n,k)-1].second+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */