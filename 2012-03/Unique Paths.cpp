class Solution {
public:
    int uniquePaths(int m, int n) {
        
        m = m-1;
        n = n-1;
        
        if(m<n){
            int temp = m;
            m = n;
            n = temp;
        }
        
        double child = 1;
        
        double mother =1;
        
        for(int i=1;i<=n;i++){
            child =child*i;
        }
        
        for(int i=0;i<n;i++){
            mother = mother*(m+n-i);
        }
        
        
        return mother/child;
    }
};