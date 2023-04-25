class SmallestInfiniteSet {
public:
    unordered_map<int, int>m;
    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        int ans=1000;
        for(int i=1; i<=1000; i++)
        {
            if(m[i]==0)
            {
                m[i]=-1;
                ans=i;
                break;
            }
        }
        return ans;
    }
    
    void addBack(int num) {
        if(m[num]==-1) m[num]=0;
    }
};