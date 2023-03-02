class Solution {
public:
    int compress(vector<char>& c) {
        int n=c.size();
        vector<char>v;
        int i=0, ct=0;
        char prev=c[0];
        while(i<n)
        {
            if(c[i]==prev)
            {
                ct++;
            }
            else
            {
                v.push_back(prev);
                if(ct!=1)
                {
                    string st=to_string(ct);
                    for(int j=0; j<st.size(); j++)
                    {
                        v.push_back(st[j]);
                    }
                }
                ct=1;
            }
            prev=c[i];
            i++;
        }
        if(ct>=1)
        {
                v.push_back(prev);
                if(ct!=1)
                {
                    string st=to_string(ct);
                    for(int j=0; j<st.size(); j++)
                    {
                        v.push_back(st[j]);
                    }
                }
        }
        c=v;
        return v.size();
    }
};