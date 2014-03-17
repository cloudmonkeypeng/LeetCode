class Solution {
public:
    int maxSubArray(int A[], int n) {
        int count = 0;
        int answer = INT_MIN;
        for(int i=0;i<n;i++){
            if(count<0) count = 0;
            count =count + A[i];
            answer = max(answer, count);
        }
        return answer;
    }
};