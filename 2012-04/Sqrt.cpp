#include <iostream>

using namespace std;


int sqrt(int x ){
    
    if(x<2) return x;

    int begin = 1;
    int end = x/2;
    
    int answer,last_mid;
    
    while(begin<=end){
    
        
        answer  = (end-begin)/2 + begin;
        
        cout<<answer<<endl;

        
        if(answer > x/answer){
            
            end = answer -1;
            
        
        }else if(answer<x/answer){
        
            begin = answer+1;
            
            last_mid = answer;
            
        }else{
        
            return answer;
        }

    }
    
    return last_mid;
}


int main(){

    cout<<sqrt(2)<<endl;
}