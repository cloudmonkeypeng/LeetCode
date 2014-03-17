class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        
        if(n<=0) return 0;
        
        
        for(int i=0;i<n;i++)
            if(elem == A[i]){
                n--;
                A[i] = A[n];
                i--;
            }
        return n;
        
    }
};