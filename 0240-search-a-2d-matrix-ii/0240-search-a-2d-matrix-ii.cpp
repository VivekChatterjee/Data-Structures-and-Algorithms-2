class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int s=0, e=n-1;
        while(s<m && e>=0)
        {
            if(matrix[s][e] == target) return 1;
            else if(matrix[s][e] < target) s++;
            else e--;
        }            
        return 0;
    }
};