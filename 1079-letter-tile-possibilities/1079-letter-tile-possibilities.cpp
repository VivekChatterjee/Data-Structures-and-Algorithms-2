class Solution {
public:
    int ans=0;
    void numOfTile(int ind, string tiles, vector<int> m)
    {
        int n=tiles.size();
        if(ind > n) return;
        for(int i=0; i<26; i++)
        {
            if(m[i])
            {
                ans++;
                m[i]--;
                numOfTile(ind+1, tiles, m);
                m[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int>m(26);
        for(char c: tiles) 
        {
            m[c-'A']++;
        }
        numOfTile(0, tiles, m);
        return ans;
    }
};