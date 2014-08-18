class Solution {
public:
    int search(int A[], int n, int target) {

        if(n<=0||A==NULL)
            return -1;


        int begin = 0;

        int end = n-1;


        while(begin<=end){

            int mid = begin + ((end-begin)>>1);

            if(A[mid]==target){

                return mid;
            }

            if(A[begin]<=A[mid]){

                if(target<A[mid]&&target>=A[begin]){
                    end = mid-1;
                }else{
                    begin = mid+1;
                }
            }else{

                if(target>A[mid]&&target<=A[end]){

                    begin = mid+1;

                }else{
                    end = mid-1;
                }
            }
        }

        return -1;
        
    }
};