class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        
        vector<int> answer;
        
        if(n==0) {
            
            answer.push_back(-1);
            
            answer.push_back(-1);
            
            return answer;
        }
        
        int begin =0;
        
        int end =n-1;
        
        int index = -1;
        
        while(begin<=end){
            
            int mid = (begin+end)/2;
            
            if(A[mid]==target){
                index =mid;
                break;
            }
            
            if(A[mid]>target){
                end = mid-1;
            }
            
            if(A[mid]<target){
                begin = mid +1;   
            }
        }
        
        if(index == -1){
            
            answer.push_back(-1);
            
            answer.push_back(-1);
            
            return answer;
        }
        
        begin = index -1;
        
        for(;begin>=0;begin--){
            if(A[begin]!=A[index])
                break;
        }
        
        answer.push_back(begin+1);
        
        end = index +1;
        
        for(;end<n;end++){
            if(A[end]!=A[index])
                break;
        }
        
        answer.push_back(end-1);
        
        return answer;
        
    }
};