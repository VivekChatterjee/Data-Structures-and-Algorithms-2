class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>p;
        p.push(a);
        p.push(b);
        p.push(c);
        int ans = 0;
        while(p.size() > 1)
        {
            int top = p.top();
            p.pop();
            int top2 = p.top();
            p.pop();
            ans++;
            if(top - 1 > 0) p.push(top - 1);
            if(top2 - 1 > 0)  p.push(top2 - 1);
        }
        return ans;
    }
};