class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        for(int i=1; i<t.size(); i++) t[i]+=t[i-1];
        t.insert(t.begin(), 0);
        int ans=0, G=0, M=0, P=0;
        for(int i=t.size()-1; i>=0; i--)
        {
            ans+=g[i].size();
            for(int j=0; j<g[i].size(); j++)
            {
                if(!G && g[i][j]=='G') G++;
                else if(!M && g[i][j]=='M') M++;
                else if(!P && g[i][j]=='P') P++;
            }
            if(G == 1)
            {
                G=-1;
                ans+=t[i];
            }
            if(M == 1)
            {
                M=-1;
                ans+=t[i];
            }
            if(P == 1)
            {
                P=-1;
                ans+=t[i];
            }
        }
        return ans;
    }
};