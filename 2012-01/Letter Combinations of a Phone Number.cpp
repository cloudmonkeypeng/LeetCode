#include <iostream>
#include <vector>
#include <string>

using namespace std;


const vector<string> dit = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

vector<string> letterCombinations(string digits) {
    
    vector<string> answer(1,"");
    
    for(int i=0;i<digits.size();i++){
        
        if(digits[i]=='0') continue;
        
        if(digits[i]=='1'){
            for(int m=0;m<answer.size();m++)
                answer[m] = answer[m]+" ";
            continue;
        }
        
        int copy_size = dit[digits[i]-'0'].size();
        
        if(digits[i]>='2'&&digits[i]<='9'){
            
            
            
            int answer_legnth = answer.size();
            
            for(int m=0;m<answer_legnth;m++){
                answer.insert(answer.begin()+copy_size*m,copy_size-1, answer[copy_size*m]);
            }
            
            // for(int i=0;i<answer.size();i++)
            //     cout<<answer[i]<<" ";
            
            // cout<<endl<<answer.size()<<endl;
            
            for(int m=0;m<answer.size();){
                
                for(int n=0;n<copy_size;n++){
                    answer[m] += dit[digits[i]-'0'][n];
                    m++;
                }
            }
        }
        
    }
    
    
    
    // for(int i=0;i<answer.size();i++)
    //     cout<<answer[i]<<endl;
    
    return answer;
    
}


int main(){

    letterCombinations("999");
    
    
    return 0;
}