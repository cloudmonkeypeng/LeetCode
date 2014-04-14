#include <vector>
#include <iostream>

using namespace std;

int rootTarget;


int  dfs(vector<vector<int>> &answer,vector<int> &level,vector<int> &candidates,int cur,int index){
    
    if(cur>rootTarget){
        return -1;
    }
    
    if(cur==rootTarget){
        answer.push_back(level);
        return 0;
    }
    
    
    for(int i=index+1;i<candidates.size();i++){
    
        if(i<candidates.size()){
            
            level.push_back(candidates[i]);
            
            int temp;
            
            temp = dfs(answer,level,candidates,cur+ candidates[i],i);
            
            level.pop_back();
            
            if(temp<=0){
                break;
            }
            
            while(i+1<candidates.size()&&candidates[i]==candidates[i+1]){
                i++;
            }
        }
        
    }
    
    return 1;
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    
    sort(candidates.begin(),candidates.end());
    
    vector<vector<int>> answer;
    
    vector<int> level;
    
    rootTarget = target;
    
    dfs(answer,level,candidates,0,-1);
    
    return answer;
}

int main(){
    
    int temp;
    
    cin>>temp;
    
    vector<int> candidates;
    
    while(temp!=-1){
    
        candidates.push_back(temp);
        
        cin>>temp;
    }
    cout<<"输入target"<<endl;
    
    int target;
    
    cin>>target;
    
    vector<vector<int>> answer;
    
    answer = combinationSum(candidates,target);
    
    for(int m=0;m<answer.size();m++){
        for(int n=0;n<answer[m].size();n++)
            cout<<answer[m][n]<<" ";
        cout<<endl;
    }
    
    return 0;
}