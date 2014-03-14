
//Reverse digits of an integer.

//Example1: x = 123, return 321
//Example2: x = -123, return -321


#include <iostream>

using namespace std;

int reverse(int x) {
    
    bool symbol = true;
    if(x<0) {symbol= false;x=-x;}
    
    int answer = 0;
    
    do{
        answer =  answer*10 + x%10;
        x=x/10;
    }while(x!=0);
    
    if(symbol){
        return answer;
    }else{
        return -answer;
    }
}

int main() {
   
    cout<<reverse(-123)<<endl;
    return 0;
}