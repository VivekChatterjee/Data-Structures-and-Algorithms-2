class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), leftMax=height[0], rightMax=height[n-1],
        left=0, right=n-1, ans=0;
        while(left<right)
        {
            leftMax=max(leftMax, height[left]);
            rightMax=max(rightMax, height[right]);
            if(height[left] < height[right])
            {
                ans+=min(leftMax, rightMax)-height[left];
                left++;
            }
            else
            {
                ans+=min(leftMax, rightMax)-height[right];
                right--;
            }
        }
        return ans;
    }
};