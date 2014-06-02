#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

string minWindow(string S,string T){

    if(S.size()<T.size()||T.empty()||S.empty()) return "";
    
    unordered_map<char , int> expected;
    unordered_map<char, int> appeared;
    
    for(int i=0;i<T.size();i++){
        if(expected.find(T[i])!=expected.end()){
            expected[T[i]]++;
        }else{
            expected[T[i]] = 1;
            appeared[T[i]] = 0 ;
        }
    }
    
    
    int appearNum = 0;
    
    bool flag = false;
    
    int begin = 0,length= 0,minStart = 0;
    
    for(int i=0;i<S.size();i++){
    
        if(expected.find(S[i])!=expected.end()){
        
            appeared[S[i]]++;
            
            if(appeared[S[i]]<=expected[S[i]])
                appearNum++;
        
        }
        
        
        if(appearNum == T.size()){
            
            while(expected.find(S[begin])==expected.end()||
                  appeared[S[begin]]>expected[S[begin]]){
                
                if(expected.find(S[begin])!=expected.end()){   //防止出现 多余expected
                    appeared[S[begin]]--;
                }
                begin++;
            }
            
            if(!flag){
                
                length = i -begin +1;
                
                flag =true;
                
                minStart = begin;
                
            }else{
                
                if(length>i-begin+1){
                    
                    length = i-begin+1;
                    minStart = begin;
                }
            }
            
            //cout<<length<<" "<<minStart<<" "<<i<<" "<<begin<<" "<<i-begin+1<<endl;
        }
        
        
    }
    
    if(!flag) return "";
    
    return S.substr(minStart,length);
}


int main(){

    string s="ADOBECODEBANC",m="ABC";
    
    
    cout<<minWindow(s,m)<<endl;

}