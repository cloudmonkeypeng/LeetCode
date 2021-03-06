class Solution {
public:
    int removeDuplicates(int A[], int n) {
        
        if(n==0) return 0;
        
        int length = 1;
        
        int key = A[0];
        
        for(int i=1;i<n;i++){
            
            if(key!=A[i]){
                A[length] = A[i];
                length++;
                key = A[i];
            }
            
        }
        
        return length;
        
    }
};