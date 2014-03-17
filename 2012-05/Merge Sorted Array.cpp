class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        
        m--;
        n--;
        while(n>=0){
            
            if(m==-1){
                A[m+n+1] = B[n];
                n--;
                continue;
            }
                
            
            if(A[m]<B[n]){
                A[m+n+1] = B[n];
                n--;
            }else{
                A[m+n+1] = A[m];
                m--;
            }
        }
        
    }
};