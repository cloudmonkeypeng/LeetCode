#include <string>
#include <vector>
#include <iostream>

using namespace std;


void dfs(vector<string> &answer,string s,int step,string tempString,int start){
    
    if(step==4&&start==s.size()){
        
        tempString.resize(tempString.size()-1);
        answer.push_back(tempString);
        return ;
    }
    
    
    if(s.size()-start>(4-step)*3||s.size()-start<4-step)
        return;
    
    int num=0;
    
    for(int i=0;i<3;i++){
        
        num =num*10+ (s[start+i]-'0');
        
        if(num<=255){
             tempString +=s[start+i];
             dfs(answer,s,step+1,tempString+'.',start+i+1);
        }else{
            break;
        }
        
        
        if(num==0) break;
    
    }
    
    
}


vector<string> restoreIpAddresses(string s) {
    
    vector<string> answer;
    
    if(s.length()<4) return answer;
    
    dfs(answer,s,0,"",0);
    
    for(int i=0;i<answer.size();i++)
        cout<<answer[i]<<endl;
    
    return answer;
    
}



int main(){
    
    string s="010010";
    
    restoreIpAddresses(s);
    
    cout<<endl;
}