class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r=n;
        int c=n;
        
        int r1=0;
        int c1=0;
        
        int r2=r-1;
        int c2=c-1;
        
        vector<vector<int>>v(r,vector<int>(c,0));
        
        int k=1;
        int size=0;
        while(size<(r*c))
        {
            
            //upper row
            for(int i=c1; i<=c2 && size<(r*c) ;i++)
            {
               v[r1][i]=k++;
                size++;
            }
            r1++;
            
            //right col
            for(int i=r1; i<=r2 && size<(r*c);i++)
            {
                v[i][c2]=k++;
                size++;   
            }
            c2--;
            
            //down row
            for(int i=c2; i>=c1 && size<(r*c);i--)
            {
                v[r2][i]=k++;
                size++;
                
            }
            r2--;
            
            
            //left col
            for(int i=r2; i>=r1 && size<(r*c);i--)
            {
                v[i][c1]=k++;
                size++;
            }
            c1++;
        }
        
        return v;
        
    }
};