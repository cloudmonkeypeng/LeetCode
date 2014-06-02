#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long intToLong(int x){
    
    if(x>=0)
        return x;
    else
        return -(long long) x;
}

int divide(int dividend, int divisor) {
    
    if(dividend==0||divisor==0) return 0;
    
    int result = 0;
    
    long long a=intToLong(dividend),b =intToLong(divisor);
    
    
    while(a>=b){
    
        long long c =b;
        
        for(int i=1;a>=c;i = i*10,c = c*10){
        
            a -=c;
            
            result +=i;
            
        }
        
    
    }
    
    
    if((dividend>0)^(divisor>0)){
        return -result;
    }else
        return result;
}


int main(){

    
    cout<<divide(-12312312,-5435)<<endl;

}