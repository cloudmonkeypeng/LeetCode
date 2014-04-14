///排序的

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        
        sort(A, A+n);

        int i = 0;

        while(i<n&&A[i]<=0)
        	i++;

        int answer = 1;

        for(;i<n;i++){

        	if(answer<A[i])
        		return answer;

        	if(answer==A[i]){
        		while(i+1<n&&A[i]==A[i+1]){
        			i++;
        		}
        		answer++;
        	}

        }

        return answer;

    }
};

//更好的


int firstMissingPositive3(int A[], int n) {
	
	if(n==0)  return 1;

	int i = 0;
	while (i < n) {
		if (A[i] >= 0 && A[i] < n && A[A[i]] != A[i])
			swap(A[i], A[A[i]]);
		else i++;
	}

	int k = 1;
	while (k < n && A[k] == k) k++;
	if (k < n) return k;
	else {
		if(A[0]==k){
			return k+1;
		}
		return k;
	}
}