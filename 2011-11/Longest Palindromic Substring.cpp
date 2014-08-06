
#include <string>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


string preProcess(string &s){

    string temp = "^";
    
    for(int i=0;i<s.length();i++){
    
        temp += "#" + s.substr(i,1);
    }
    
    return temp+"#$";

}

string longestPalindrome(string s) {
    
    if(s.length()==0) return s;
    
    string T = preProcess(s);
    const int n = T.length();
    // 以 T[i] 为中心,向左/右扩张的长度,不包含 T[i] 自己, // 因此 P[i] 是源字符串中回文串的长度
    int P[n];
    
    int C = 0; // c中心
    int R = 0; // R半径最远点
    
    for (int i = 2; i < n - 1; i++) {
        
        int i_mirror = 2 * C - i; //对称点
        
        if( R>i ){
            
            P[i] =min(R - i, P[i_mirror]);
            
        }else{
            
            P[i] = 0;
        }
        
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;
        
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    
    
    int max_len = 0;
    int center_index = 0;
    
    for (int i = 2; i < n - 1; i++) {
        
        if (P[i] > max_len) {
            max_len = P[i];
            center_index = i;
        }
    }
    
    return s.substr((center_index - 1 - max_len) / 2, max_len);
}

int main(){

    
    string s = "asdfjkajsfklabsddsfk";
    
    cout<<longestPalindrome(s)<<endl;
    
}