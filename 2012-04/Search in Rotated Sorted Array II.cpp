class Solution {
public:
    bool search(int A[], int n, int target) {
        
        
        if(n<=0) return -1;
        
        int left =0;
        
        int right =n-1;
        
        while(left<=right){
        
            int mid=(left+right)/2;
                
            if(A[mid]==target||A[left]==target||A[right]==target) {
                return true;
            }
            
            if(A[mid]>A[left]){
                
                if(target<A[mid]&&target>=A[left]){
                    right = mid-1;
                }else{
                    left = mid +1;
                }
                
            }else if(A[mid]<A[right]){
                
                if(target>A[mid]&&target<=A[right]){
                    
                    left = mid+1;
                    
                }else{
                    right= mid-1;
                }
                
            }else{
                
                left++;
            }
        }
        
        
        return false;
        
        
        
    }
};