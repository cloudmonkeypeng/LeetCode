class Solution {
public:
    int singleNumber(int A[], int n) {

        assert(A!=NULL);

        assert(n!=0);

        int ans=0;

        for(int i=0;i<32;i++){

            int sum = 0;

            int x = 1<<i;

            for(int m=0;m<n;m++){
                if(A[m]&x)
                    sum++;
            }

            sum = sum%3;

            if(sum==1)
                ans = ans|x;

        }

        return ans;
    }
};