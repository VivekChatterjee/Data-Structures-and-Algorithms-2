class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int>p;
        for(int i: s) p.push(i);
        while(p.size()>=2)
        {
            int f=p.top();
            p.pop();
            int sec=p.top();
            p.pop();
            if(f!=sec)
            {
                p.push(f-sec);
            }
        }
        if(p.empty()) return 0;
        return p.top();
    }
};