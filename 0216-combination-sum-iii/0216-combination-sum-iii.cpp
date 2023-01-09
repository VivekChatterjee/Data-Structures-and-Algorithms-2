#define vc vector
class Solution {
public:
    vc<vc<int>>ans;
    void find(int num, int total, int sum, int k, int n, vector<int>v)
    {
        if(total == k)
        {
            if(sum == n)
            {
                ans.push_back(v);
                return;
            }
            else return;
        }
        else if(sum > n || num > 9) return;
        
        // take
        // cout<<"idhar="<<num<<" sum="<<sum<<endl;
        v.push_back(num);
        find(num+1, total+1, sum+num, k, n, v);
        v.pop_back();
        
        // dont take
        find(num+1, total, sum, k, n, v);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        find(1, 0, 0, k, n, v);
        return ans;
    }
};