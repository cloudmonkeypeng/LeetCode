#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int main(){


    int k = 10;
    
    queue<int> q3,q5,q7;
    
    q3.push(3);
    
    q5.push(5);
    
    q7.push(7);
    
    int res;
    
    while(k>=1){
        
        res = min(min(q3.front(),q5.front()),q7.front());
        
        if(q7.front()==res){
            q7.pop();
        }else{
            if(q5.front()==res){
                q5.pop();
            }else{
                q3.pop();
                q3.push(res*3);
            }
            q5.push(res*5);
        }
        q7.push(res*7);
        
        cout<<res<<" ";
        
        k--;
    }
    
    

}

