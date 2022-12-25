class Solution {
public:
    int numQueries(const vector<int>& nums, int numsIndex, int remaining) {
      if (numsIndex >= nums.size() || remaining <= 0) return 0;
      const int diff = remaining - nums[numsIndex];
      if (diff < 0) return 0;
      return 1 + numQueries(nums, numsIndex + 1, diff);
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
      vector<int> answer;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < queries.size(); i++) {
        answer.push_back(numQueries(nums, 0, queries[i]));
      }
      return answer;
    }
};