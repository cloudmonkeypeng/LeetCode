///两边必须都有数值。。。。不能为空。。。。 注意min的最小初始值。  这个网站 真心用不习惯

#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <limits>

int solution(vector<int> &A) {
    // write your code in C++98
    
    if(A.size()==0) return 0;
    
    if(A.size()==1) return A[0];
    
    int leftSum =0;
    
    int rightSum = 0;
    
    for(int i=0;i<A.size();i++){
        leftSum = leftSum+ A[i];
    }
    
    int min = numeric_limits<int>::max();
    
    
    
    for(int i = A.size()-1;i>0;i--){
        
        rightSum = rightSum +A[i];
        
        leftSum = leftSum - A[i];
        
        if(min>abs(leftSum-rightSum)){
            
            min = abs(leftSum-rightSum);
        }
        
    }
    
    return min;
    
}