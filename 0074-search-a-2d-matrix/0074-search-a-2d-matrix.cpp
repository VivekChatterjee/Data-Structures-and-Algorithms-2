class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int s=0, e=m*n-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(matrix[mid/n][mid%n] == target) return 1;
            else if(matrix[mid/n][mid%n] < target) s=mid+1;
            else e=mid-1;
        }
        return 0;
    }
};