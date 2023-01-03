class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), size = strs[0].size();
        vector<char>v(size, 'a');
        vector<int>res(size);
        int ans = 0;
        for(int k=0; k<n; k++)
        {
            string s = strs[k];
            for(int i=0; i<size; i++)
            {
                if(k != 0) if(s[i] < v[i]) res[i] = 1;
                v[i] = max(v[i], s[i]); 
            }
        }
        for(int i: res) ans+=i;
        return ans;
    }
};