
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;



vector<vector<int> > DFSPermuteUnique(vector<int> &num) {
    vector<vector<int>> answer;
    
    if(num.size()<=1){
        answer.push_back(num);
        return answer;
    }
    
    vector<vector<int>> temp;
    
    vector<int> cur;
    
    vector<int> level;
    
    for(int i=0;i<num.size();i++){
        
        cur = num;
        
        cur.erase(cur.begin()+i);
        
        temp = DFSPermuteUnique(cur);
        
        for(int m=0;m<temp.size();m++){
            
            level = temp[m];
            
            level.insert(level.begin(),num[i]);
            
            answer.push_back(level);
            
            
        }
        
        while(i<num.size()&&num[i]==num[i+1])
            i++;
        
    }
    
    return answer;
}

vector<vector<int> > permuteUnique(vector<int> &num) {

    sort(num.begin(),num.end());
    
    vector<vector<int>> answer;
    
    answer = DFSPermuteUnique(num);
    
    return answer;
}


void printBoard(vector<vector<int>> answer){

    for(int m=0;m<answer.size();m++){
    
    
        for(int n=0;n<answer[m].size();n++){
        
            cout<<answer[m][n]<<" ";
        
        }
        cout<<endl;
        
    }

}

int main(){
    
    vector<vector<int>> answer;
    
    
    vector<int> num;
    
    num.push_back(-1);
    
    num.push_back(-1);
    
    
    
    num.push_back(3);
    
 num.push_back(-1);
  
    
    
    answer  = permuteUnique(num);
    
    printBoard(answer);
    
    return 0;

}