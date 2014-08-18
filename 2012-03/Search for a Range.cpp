//对决O(log(n))

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        
        vector<int> ans;
        
        if(A==NULL||n==0||target<A[0]){
            
            ans.push_back(-1);
            
            ans.push_back(-1);
            
            return ans;
        }
        
        if(target>A[n-1]){
            
            ans.push_back(-1);
            ans.push_back(-1);
            
            return ans;
        }
        
        ans.push_back(bsl(A,n,target));
        
        ans.push_back(bsr(A,n,target));
        
        return ans;
    }
private:
    
    int bsl(int A[],int n,int target){
        
        int begin =0;
        int end =n-1;
        
        while(begin<=end){
            
            int mid = begin +(end-begin)/2;
            
            if(mid==0){
                
                if(A[0]==target)
                    return 0;
                else
                    begin = mid+1;
            }
            
            if(A[mid]==target&&A[mid-1]!=A[mid]){
                
                return mid;
                
            }else if(A[mid]<target){
                
                begin =mid + 1;
                
            }else{
                
                end = mid-1;
                
            }
            
        }
        
        return -1;
        
    }
    
    int bsr(int A[],int n,int target){
        
        int begin =0;
        int end =n-1;
        
        while(begin<=end){
            
            int mid = begin +(end-begin)/2;
            
            if(mid+1==n){
                
                if(A[mid]==target)
                    return n-1;
                else
                    end = mid-1;
            }
            
            
            if(A[mid]==target&&A[mid+1]!=A[mid]){
                
                return mid;
                
            }else if(A[mid]<=target){
                
                begin =mid + 1;
                
            }else{
                
                end = mid -1;
                
            }
            
        }
        
        return -1;
        
    }
    
};


int main(){
    
    int A[]={1,4};
    
    
    class Solution sol;
    
    vector<int> ans = sol.searchRange(A, 2, 4);
    
    
    cout<<ans[0]<<" "<<ans[1];
    

}





//最坏O(n)
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