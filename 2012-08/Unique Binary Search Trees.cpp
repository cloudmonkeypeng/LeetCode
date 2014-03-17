
//Unique Binary Search Trees

//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

#include <iostream>

using namespace std;



int numTree(int start,int end){
    
    if(start>=end) return 1;
    
    int num = 0;
    
    for(int i=start;i<=end;i++){
        num =  num + numTree(start,i-1)*numTree(i+1,end);
        
        //把根节点空出来
    }
    
    return num;
}


int numTrees(int n) {
    
    return numTree(1,n);
    
}

int main(){

    cout<<numTrees(3)<<endl;
}