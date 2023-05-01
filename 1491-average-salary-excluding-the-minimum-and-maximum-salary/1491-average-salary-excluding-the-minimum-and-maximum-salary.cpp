class Solution {
public:
    double average(vector<int>& s) {
        int mini=INT_MAX, maxi=INT_MIN, sum=0;
        for(int i: s)
        {
            mini=min(mini, i);
            maxi=max(maxi, i);
            sum+=i;
        }
        sum-=mini+maxi;
        double sz=s.size()-2;
        return sum/sz;
    }
};