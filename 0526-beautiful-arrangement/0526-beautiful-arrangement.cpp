class Solution {
public:
    int ans=0;
    void arrange(int ind, int n, vector<int>m, int c)
    {
        if(ind > n)
        {
            if(c==n) ans++;
            return;
        }
        for(int i=1; i<=n; i++)
        {
            if(!m[i] && (i % ind == 0 || ind % i == 0))
            {
                m[i]++;
                arrange(ind+1, n, m, c+1);
                m[i]--;
            }
        }
    }
    int countArrangement(int n) {
        vector<int>vis(n+1);
        arrange(1, n, vis, 0);
        return ans;
    }
};