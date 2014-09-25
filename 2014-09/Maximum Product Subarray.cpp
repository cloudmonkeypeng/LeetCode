class Solution {
public:
    int maxProduct(int A[], int n) {

		if(A==NULL||n==0)
			return 0;
		int max_temp;

		int min_temp;

		int ans = INT_MIN;
		
		for(int i=0;i<n;i++){

			if(i==0){

				max_temp = min_temp = A[i];
			}else{
			    
    			if(A[i]>=0){
    
    				max_temp = max(A[i],max_temp*A[i]);
    
    				min_temp = min(A[i],min_temp*A[i]);
    
    			}else{
                    
                    
    				int temp = max(A[i],min_temp*A[i]);
    
    				min_temp = min(A[i],max_temp*A[i]);
    				
    				max_temp = temp;
    			}
			    
			}

			ans = max(ans,max_temp);


		}


		return ans;
    }
};