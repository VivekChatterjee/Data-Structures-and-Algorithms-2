class Solution {
public:
    int maxNumOfMarkedIndices(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = 0;
        int h = n +1;
        h/=2;
        int pre = n;
        int l=0;

        while (h<n)
        {
            if (arr[l]*2<=arr[h])
            {
                l++;
                h++;
            }
            else
            {
                h++;
            }


        }

        return l*2;
    }
};