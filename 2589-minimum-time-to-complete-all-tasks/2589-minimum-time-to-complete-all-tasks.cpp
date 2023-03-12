class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>&a, vector<int>&b)
        {
            return a[1]<b[1];
        });
        unordered_map<int, int>m;
        int ans=0;
        for(auto& i: tasks)
        {
            int st=i[0], en=i[1], dur=i[2];
            for(int i=st; i<=en; i++)
            {
                if(m.count(i)) dur--;
            }
            for(int i=en; dur>0; i--)
            {
                if(!m.count(i))
                {
                    ans++;
                    m[i]++;
                    dur--;
                }
            }
        }
        return ans;
    }
};