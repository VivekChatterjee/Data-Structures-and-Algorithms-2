class Solution {
public:
    static bool cmp(int a, int b)
    {
        string s1=to_string(a);
        string s2=to_string(b);
        string s=s1+s2;
        string ss=s2+s1;
        return s>ss;
    }
    string largestNumber(vector<int>& nums) {
        string ans="";
        sort(nums.begin(), nums.end(), cmp);
        int num=0;
        bool found=0;
        for(int i: nums)
        {
            num=max(num, i);
            if(num != 0)
            ans+=to_string(i);
        }
        if(!num) ans="0";
        return ans;
    }
};