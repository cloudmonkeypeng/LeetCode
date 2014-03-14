//Single Number
//Given an array of integers, every element appears twice except for one. Find that single one.
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory?


#include <iostream>

using namespace std;

int singleNumber(int A[], int n) {

    int answer = 0;
    
    for (int i=0; i<n; i++) {
        answer = answer^A[i];
    }
    
    return answer;
}



int main(){
    
    int arr[] = {2 , 3 , 2 , 1 , 3 , 4 , 4};


    cout<<singleNumber(arr,7)<<endl;
}