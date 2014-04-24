
#include <iostream>

using namespace std;


double binarySearch(int A[],int m,int B[], int n, int k){

    
    if (m > n) return binarySearch(B, n, A, m, k);
    
    if (m == 0) return B[k - 1];
    
    if (k == 1) return min(A[0], B[0]);
    

    int ia = min(k / 2, m), ib = k - ia;
    
    if (A[ia - 1] < B[ib - 1])
        return binarySearch(A + ia, m - ia, B, n, k - ia);
    else if (A[ia - 1] > B[ib - 1])
        return binarySearch(A, m, B + ib, n - ib, k - ib);
    else
        return A[ia - 1];
    
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    
    
    if((m+n)%2!=0){
        
        return binarySearch(A,m,B,n,(m+n)/2+1);
    
    }else{
    
        return (binarySearch(A,m,B,n,(m+n)/2)+binarySearch(A,m,B,n,(m+n)/2+1))/2;
    }
    
}


int main(){

    int A[]={1,2,3,4};
    
    int B[]={2,5,7,11,14};
    
    cout<<findMedianSortedArrays(A , 4, B, 5)<<endl;

}