class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i=0, j=0, n=s.size();
        string st="";
        set<string>ss;
        unordered_map<string, int>m;
        while(j<n)
        {
            st+=s[j];
            if(j-i+1==10)
            {
                ss.insert(st);
                m[st]++;
                st.erase(st.begin());
                i++;
            }
            j++;
        }
        vector<string>ans;
        for(auto i: ss) if(m[i] > 1) ans.push_back(i);
        return ans;
    }
};