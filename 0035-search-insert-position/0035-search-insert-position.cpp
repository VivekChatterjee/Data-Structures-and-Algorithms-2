class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // if present, search first occ of number
        // if not search first occ of next higher
        return lower_bound(nums.begin(), nums.end(), target)-nums.begin();
    }
};