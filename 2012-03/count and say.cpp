// 可以优化
#include <string>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


string countAndSay(int n) {
    
    
    string s = "1";
    
    string temp;
    
    int i = 0;
    
    while(n>1){
    
        temp = "";
        
        int count =1;
        
        int prev = s[i];
        
        
        for( i = 1;i<s.size();i++){
        
            if(s[i]==prev){
                count++;
            }else{
                string tempCount;
                
                char t[256];
                
                sprintf(t, "%d", count);
                
                tempCount = t;
                
                string tempNum;
                
                sprintf(t, "%d", s[i-1]-'0');
                
                tempNum = t;
                
                temp = temp + tempCount +tempNum;
                
                count =1;
                
                prev = s[i];
            }
        }
        
        string tempCount;
        
        char t[256];
        
        sprintf(t, "%d", count);
        
        tempCount = t;
        
        string tempNum;
        
        sprintf(t, "%d", s[i-1] - '0');
        
        tempNum = t;
            
        temp = temp + tempCount +tempNum;
        
        
        s  = temp;
        
        i = 0;
        
        n--;
    }
    
    return s;
    
}

int main(){

    countAndSay(5);
    
}