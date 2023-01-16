class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i=0, j=0, n=s.size();
        string st="";
        unordered_map<string, int>m;
        while(j<n)
        {
            st+=s[j];
            if(j-i+1==10)
            {
                m[st]++;
                st.erase(st.begin());
                i++;
            }
            j++;
        }
        vector<string>ans;
        for(auto i: m) if(i.second > 1) ans.push_back(i.first);
        return ans;
    }
};