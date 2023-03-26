class Solution {
public:
    int kItemsWithMaximumSum(int no, int nz, int nn, int k) {
        if(k<=(no+nz)) return min(k, no);
        return  no-(k-no-nz);
    }
};