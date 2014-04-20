//编程之美 初赛第一场 第二题 树

//wa 暂时不知道错误在哪。 好奇怪


#include <vector>
#include <iostream>
#include <queue>

using namespace std;


void createTree( vector<int> &treeValue,vector<int> &treeDepth,vector<vector<int> > &treeChild){

    int nodeNumber;
    
    cin>>nodeNumber;
    
    treeValue = vector<int>(nodeNumber,0);
    
    treeChild = vector<vector<int> >(nodeNumber,vector<int>());
    
    treeDepth.push_back(1);
    
    for(int i=1;i<nodeNumber;i++){
    
        int fatherRoot;
        
        cin>>fatherRoot;
        
        treeDepth.push_back(treeDepth[fatherRoot-1]+1);
        
        treeChild[fatherRoot-1].push_back(i);
    }
}


void changeTree( vector<int> &treeValue,vector<int> &treeDepth,vector<vector<int> > &treeChild){

    int changeNumber;
    
    cin>>changeNumber;
    
    for(int i=0;i<changeNumber;i++){
        
        int u;
        
        int l;
        
        int r;
        
        int delta;
        
        cin>>u;cin>>l;cin>>r;cin>>delta;
        
        queue<int> q;
        
        q.push(u-1);
        
        while(!q.empty()){
            
            int now;
            
            now = q.front();
            
            q.pop();
            
            if(treeDepth[now]>r)
                break;
            
            for(int childNum = 0;childNum < treeChild[now].size();childNum++){
                q.push(treeChild[now][childNum]);
            }
            
            if(treeDepth[now]>=l&&treeDepth[now]<=r)
                treeValue[now] = treeValue[now] +delta;
            
        }
    
    }
    
}

long long hashTree(vector<int> &treeValue,vector<int> &treeDepth,vector<vector<int> > &treeChild){

    long long answer = 0;
    
    int MOD =1000000007; // 10^9 + 7
    
    int MAGIC= 12347;
    
    
    for(int i=0;i<treeValue.size();i++){
    
        answer =(answer*MAGIC + treeValue[i])%MOD;
    }
    
    return answer;
}


int main(){

    int T;
    
    cin>>T;
    
    for(int i=1;i<=T;i++){
        
        long long answer;
        
        vector<int> treeValue;
        
        vector<int> treeDepth;
        
        vector<vector<int> > treeChild;
        
        createTree(treeValue,treeDepth,treeChild);
        
        changeTree(treeValue,treeDepth,treeChild);
        
        answer  = hashTree(treeValue,treeDepth,treeChild);
        
        cout<<"Case "<<i<<": "<<answer<<endl;
    }

}