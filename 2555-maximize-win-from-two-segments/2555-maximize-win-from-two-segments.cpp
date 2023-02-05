class Solution {
public:
    int maximizeWin(vector<int>& prize, int k) {
        int n=prize.size(), i=0, j=0;
        vector<int>collect(n);
        for(int i=0; i<n; i++)
        {
            while(j<n && prize[j]-prize[i]<=k) j++;
            collect[i]=j-i;
        }
        vector<int>suffixMax(n);
        suffixMax[n-1]=collect[n-1];
        for(int i=n-2; i>=0; i--)
        {
            suffixMax[i]=max(collect[i], suffixMax[i+1]);
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int firstEnding=collect[i]+i;
            int curAns=collect[i];
            if(firstEnding<n)
            {
                curAns+=suffixMax[firstEnding];
            }
            ans=max(ans, curAns);
        }
        return ans;
    }
};