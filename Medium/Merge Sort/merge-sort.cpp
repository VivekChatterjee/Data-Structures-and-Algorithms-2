//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {
        int n=mid-l+1, nn=r-mid, k=0;
        vector<int>left(n), right(nn);
        for(int i=l; i<=mid; i++) left[k++]=arr[i];
        k=0;
        for(int i=mid+1; i<=r; i++) right[k++]=arr[i];
        int f=0, s=0;
        k=l;
        while(f<n && s<nn)
        {
            if(left[f]<=right[s])
            {
                arr[k++]=left[f++];
            }
            else
            {
                arr[k++]=right[s++];
            }
        }
        while(f<n)
        {
            arr[k++]=left[f++];
        }
        while(s<nn)
        {
            arr[k++]=right[s++];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r)
        {
            int mid=l+(r-l)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);
            merge(arr, l, mid, r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends