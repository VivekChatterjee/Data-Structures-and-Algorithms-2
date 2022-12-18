typedef vector<int> vi;
#define pb push_back

class Solution
{
public:
    bool isPossible(int n, vector<vector<int>> &edges)
    {
        vector<int> dig(n + 1), adj[n + 1];
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].pb(b);
            adj[b].pb(a);
            dig[a]++;
            dig[b]++;
        }
        int count = 0;
        vi odd;
        for (int i = 1; i <= n; i++)
        {
            if (dig[i] % 2 != 0)
            {
                odd.pb(i);
                if (dig[i] == n - 1)
                    return 0;
            }
        }
        if (odd.size() % 2 != 0 || odd.size() > 4)
            return 0;
        else
        {
            if(odd.size() == 0) return 1;
            else if (odd.size() == 2)
            {
                return 1;
            }
            else
            {
                // cout<<4<<endl;
                int a = odd[0];
                int b = odd[1];
                int c = odd[2];
                int d = odd[3];
                map<int, map<int, int>> m;
                for (auto i : adj[a])
                {
                    if (i == b)
                        m[a][b] = 0;
                    if (i == c)
                        m[a][c] = 0;
                    if (i == d)
                        m[a][d] = 0;
                }

                for (auto i : adj[b])
                {
                    if (i == a)
                        m[b][a] = 0;
                    if (i == c)
                        m[b][c] = 0;
                    if (i == d)
                        m[b][d] = 0;
                }
                for (auto i : adj[c])
                {
                    if (i == b)
                        m[c][b] = 0;
                    if (i == a)
                        m[c][a] = 0;
                    if (i == d)
                        m[c][d] = 0;
                }
                for (auto i : adj[d])
                {
                    if (i == b)
                        m[d][b] = 0;
                    if (i == c)
                        m[d][c] = 0;
                    if (i == a)
                        m[d][a] = 0;
                }
                if (!m[a].count(b) && !m[c].count(d) || (!m[b].count(c) && !m[a].count(d)) || (!m[c].count(a) && !m[b].count(d)))
                    return 1;
                else
                    return 0;
            }
        }
    }
};