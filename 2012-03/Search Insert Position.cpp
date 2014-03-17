class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    
    if (target>A[n-1]) {
        return n;
    }
    
    int high,low,mid;
    high = n-1;
    low =0;
    
    do {
        mid = (high+low )/2;
        if (target>A[mid]&&target<=A[mid+1]) {
            return mid+1;
        }
        if (target<=A[mid]) {
            high = mid;
        }
        if (target>A[mid+1]) {
            low = mid+1;
        }
    } while ((low<high)&&(mid>=1));
    
    return 0;

    
    
    }
};