class Solution {
public:
    void merge(vector<int>& s, int m, vector<int>& t, int n) {
        int i=m-1, j=n-1, k=m+n-1;
        while(i>=0 && j>=0)
        {
            if(s[i]>t[j])
            {
                s[k--]=s[i--];
            }
            else
            {
                s[k--]=t[j--];
            }
        }
        while(j>=0)
        {
            s[k--]=t[j--];
        }
    }
};