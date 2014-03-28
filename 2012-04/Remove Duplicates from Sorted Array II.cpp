class Solution {
public:
    int removeDuplicates(int A[], int n) {
        
        if(n==0) return 0;
        
        int count = 1;
        
        int num = 1;
        
        int key = A[0];
        
        for(int i=1;i<n;i++){
            
            if(key==A[i]){
                
                count++;
                if(count<=2){
                   A[num] =A[i];
                   num++;
                }
            }else{
                count = 1;
                A[num] = A[i];
                key = A[i];
                num++;
            }
        }
        
        return num;
        
    }
};