class Solution {
public:
    
    bool canJump(int A[], int n) {
        
        int maxJump = 0;
        
        for(int i=0;i<n;i++){
            
            
            maxJump = max(maxJump,A[i]+i+1);
            
            if(maxJump>=n) return true;
            
            if(maxJump==(i+1)) return false;
            
        }
        
        return true;
    }
        
       
       
};