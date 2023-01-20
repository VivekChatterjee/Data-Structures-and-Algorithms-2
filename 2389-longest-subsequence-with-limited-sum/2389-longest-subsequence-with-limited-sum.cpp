class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        for(int i: queries)
        {
            int c=0, sum=0;
            for(int num: nums)
            {
                sum+=num;
                if(sum > i) break;
                c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};