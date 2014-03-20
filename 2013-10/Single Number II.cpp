class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int res = 0;
        int x, sum;
        
        for(int i = 0; i < 32; ++i){
           
            sum = 0;
            x = (1<<i);
            
            for(int j = 0; j< n; ++j)
                if(A[j]&x)
                    ++sum;
                    
            sum = sum%3;
            
            if(sum == 1)
                res |= x;
        }
        
        return res;
    }
};