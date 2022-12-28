class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>p;
        for(int i: piles) p.push(i);
        int ans = 0;
        while(k--)
        {
            int top = p.top();
            p.pop();
            p.push(top - top/2);
        }
        while(!p.empty())
        {
            ans+=p.top();
            p.pop();
        }
        return ans;
    }
};