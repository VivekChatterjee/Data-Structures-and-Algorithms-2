#define pii pair<int, int>
// FLOYD WARSHAL
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n, vector<int>(n, INT_MAX));
        for(auto i: edges)
        {
            dis[i[0]][i[1]] = i[2]; // {node, weight}
            dis[i[1]][i[0]] = i[2];
        }
        for(int i=0; i<n; i++) dis[i][i] = 0;
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(dis[i][k] == INT_MAX || dis[k][j] == INT_MAX) continue;
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        int cityCount = n, cityNumber = -1;
        for(int i=0; i<n; i++)
        {
            int ct = 0;
            for(int j=0; j<n; j++)
            {
                if(dis[i][j] <= distanceThreshold) ct++;
            }
            if(ct <= cityCount)
            {
                cityCount = ct;
                cityNumber = i;
            }
        }
        return cityNumber;        
    }
};