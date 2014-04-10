///超出最长时间

class Solution {
public:
    int jump(int A[], int n) {
        
        vector<int> answer(n,0);
        
        
        for(int i=0;i<n;i++){
            
            
            
            for(int m=i+1;m<=i+A[i]&&m<n;m++){
                
                if(answer[m]==0||answer[i]+1<answer[m]){
                    answer[m]=1+answer[i];
                }
                
                if(m==n-1)
                    return answer[n-1];
            }    
        }
        
        return answer[n-1];
        
    }
};


///争取答案

class Solution {
public:
    int jump(int A[], int n) {
        int ret = 0;
        int last = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (i > last) {
                last = curr;
                ++ret;
            }
            curr = max(curr, i+A[i]);
        }

        return ret;
    }
};