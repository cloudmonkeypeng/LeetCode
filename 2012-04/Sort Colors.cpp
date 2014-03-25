class Solution {
public:

    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    
    void sortColors(int A[], int n) {
        
        if(n<=1) return;
        
        int first=0;
        int end=n-1;
        
        int cur = 0;
        
        while(cur<=end){
           
           if(A[cur]==0){
               swap(A[cur],A[first]);
               first++;
               cur++;
           }else if(A[cur]==1){
               cur++;
           }else if(A[cur]==2){
               swap(A[cur],A[end]);
               end--;
           }
        }
    }
};