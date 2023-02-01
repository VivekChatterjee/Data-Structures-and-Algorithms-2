#define pii pair<int, int>
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        int n=score.size();
        priority_queue<pii>p;
        for(int i=0; i<n; i++) p.push({score[i], i});
        vector<string>ans(n);
        int i=0;
        while(!p.empty())
        {
            int in=p.top().second;
            if(i == 0) ans[in]="Gold Medal";
            else  if(i == 1) ans[in]="Silver Medal";
            else if(i == 2) ans[in]="Bronze Medal";
            else ans[in]=to_string(i+1);
            i++;
            p.pop();
        }       
        return ans;
    }
};