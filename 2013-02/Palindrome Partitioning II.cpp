
#include <string>
#include <vector>
#include <iostream>

using namespace std;


int minCut(string s){

    if(s.length()<=1) return 0 ;
    
    vector<int> minCutNum = vector<int>(s.length(),0);
    
    vector<vector<int>> isPalindrome = vector<vector<int>>(s.length(),vector<int>(s.length(),0));
    
    isPalindrome[0][0] =1;
    
    for(int i=1;i<s.length();i++){
    
        isPalindrome[i][i] = 1;
        
        minCutNum[i] = minCutNum[i-1]+1;
        
        for(int end = i-1;end>=0;end--){

            if(s[i]==s[end]&&(i-end<=2||isPalindrome[end+1][i-1]==1)){
                
                isPalindrome[end][i] =1;
                

                if(end-1>=0){
                    if(minCutNum[i]>minCutNum[end-1]+1)
                        minCutNum[i] = minCutNum[end-1] +1;
                }else{
                    minCutNum[i] = 0;
                }
                
            }
        }
    }
    
    return minCutNum[s.length()-1];
}



int main(){

    string s="aabbcbbaa";
    
    cout<<minCut(s)<<endl;
}