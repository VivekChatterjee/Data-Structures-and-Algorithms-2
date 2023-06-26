#define ll long long
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        int n=costs.size();
        ll ans=0;
        priority_queue<ll, vector<ll>, greater<ll>>f, l;
        int i=0, j=n-1;
        while(k--)
        {
            while(i<=j && i<n && f.size()<c)
            {
                f.push(1LL*costs[i]);
                i++;
            }
            while(i<=j && j>=0 && l.size()<c)
            {
                l.push(1LL*costs[j]);
                j--;
            }
            if(!f.empty() && !l.empty())
            {
                if(f.top()<=l.top())
                {
                    ans+=f.top();
                    f.pop();
                }
                else
                {
                    ans+=l.top();
                    l.pop();
                }
            }
            else
            {
                if(!f.empty())
                {
                    ans+=f.top();
                    f.pop();
                }
                else
                {
                    ans+=l.top();
                    l.pop();
                }
            }
        }
        return ans;
    }
};