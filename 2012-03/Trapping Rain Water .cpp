class Solution {
public:
    int trap(int A[], int n) {
        
        if(n<=2) return 0;
        
        
        vector<int> leftToRight;
        
        vector<int> rightToLeft;
        
        int max = A[0];
        
        for(int i=1;i<n-1;i++){
            
            if(A[i-1]>=max){
                max = A[i-1];
            }
            
            leftToRight.push_back(max);
        }
        
        max = A[n-1];
        
        for(int i=n-2;i>0;i--){
            
            if(A[i+1]>=max){
                max = A[i+1];
            }
            
            rightToLeft.push_back(max);
        }
        
        int length = rightToLeft.size();
        
        int answer = 0;
        
        for(int i=0;i<length;i++){
            
            if(leftToRight[i]>A[i+1]&&rightToLeft[length-1-i]>A[i+1]){
                if(leftToRight[i]>rightToLeft[length-1-i]){
                    answer = answer +rightToLeft[length-1-i]-A[i+1];
                }else{
                    
                    
                    answer = answer +leftToRight[i]-A[i+1];
                }
            }
        }
        
        return answer;
        
    }

};