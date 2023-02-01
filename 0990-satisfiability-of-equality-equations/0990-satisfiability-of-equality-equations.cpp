class Solution {
public:
    vector<int>par;
    int findPar(int c)
    {
        if(par[c] == c) return c;
        return par[c]=findPar(par[c]);
    }
    bool equationsPossible(vector<string>& eq) {
        par.resize(26);
        for(int i=0; i<26; i++) par[i]=i;
        for(auto it: eq)
        {
            string a=it;
            int n=a.size();
            if(a[1] == '=')
            {
                int parA=findPar(a[0]-'a');
                int parB=findPar(a[n-1]-'a'); 
                par[parA] = par[parB];
            }
        }
        for(auto it: eq)
        {
            string a=it;
            int n=a.size();
            if(a[1]=='=')
            {
                int parA=findPar(a[0]-'a');
                int parB=findPar(a[n-1]-'a');
                if(parA != parB) return 0;
            }
            else
            {
                int parA=findPar(a[0]-'a');
                int parB=findPar(a[n-1]-'a');
                if(parA == parB) return 0;
            }
        }
        return 1;
    }
};