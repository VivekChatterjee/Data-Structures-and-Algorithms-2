class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n);
        if(!k) return ans;
        int start=1,end=k;
        if(k<0)
        {
            k=abs(k);
            start=n-k;
            end=n-1;
        }
        int sum=0;
        for(int i=start;i<=end;i++) sum+=code[i];        
        for(int i=0;i<n;i++)
        {
            ans[i]=sum;
            sum-=code[(start++)%n];
            sum+=code[(++end)%n];
        }
        return ans;
    }
};