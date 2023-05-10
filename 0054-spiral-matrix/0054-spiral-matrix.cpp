class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        
        int r=m.size();
        int c=m[0].size();
        
        int r1=0;
        int c1=0;
        
        int r2=r-1;
        int c2=c-1;
        
        vector<int>v;
        
        int size=0;
        while(size<(r*c))
        {
            
            //upper row
            for(int i=c1; i<=c2 && size<(r*c) ;i++)
            {
               v.push_back(m[r1][i]);
                size++;
            }
            r1++;
            
            //right col
            for(int i=r1; i<=r2 && size<(r*c);i++)
            {
                v.push_back(m[i][c2]);
                size++;   
            }
            c2--;
            
            //down row
            for(int i=c2; i>=c1 && size<(r*c);i--)
            {
                v.push_back(m[r2][i]);
                size++;
                
            }
            r2--;
            
            
            //left col
            for(int i=r2; i>=r1 && size<(r*c);i--)
            {
                v.push_back(m[i][c1]);
                size++;
            }
            c1++;
        }
        
        return v;
        
    }
};