class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        string p="Push", pp="Pop";
        vector<string>ans;
        int i=0, k=1;
        while(i<t.size())
        {
            if(k == t[i])
            {
                ans.push_back(p);
                i++;
            }
            else
            {
                ans.push_back(p);
                ans.push_back(pp);
            }
            k++;
        }
        return ans;
    }
};