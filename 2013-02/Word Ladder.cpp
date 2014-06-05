#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;



class Solution{
    
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
        if(start.size()!=end.size()) return 0;
        
        if(dict.size()==0) return 0;
        
        if(start=="") return 1;
        
        int distance =1;
        
        queue<string> stringQueue;
        
        int count = 1;
        
        stringQueue.push(start);
        
        
        
        
        while(count!=0){
            
            string tempStr = stringQueue.front();
            stringQueue.pop();
            count--;
            for(int i=0;i<tempStr.size();i++){
                
                for(char tempChar='a';tempChar<='z';tempChar++){
                    
                    if(tempChar==tempStr[i])
                        continue;
                    
                    string tempChangeStr = tempStr;
                    
                    tempChangeStr[i] = tempChar;
                    
                    if(tempChangeStr==end)
                        return distance+1;
                    
                    if(dict.find(tempChangeStr)!=dict.end()){
                        
                        stringQueue.push(tempChangeStr);
                        dict.erase(tempChangeStr);
                        
                    }
                    
                }
                
            }
            
            if(count==0){
                distance++;
                count = stringQueue.size();
            }
        }

        return 0;
    }
    
};

int main(){

    vector<vector<string>> answer;
    
    Solution sol;
  
    
    unordered_set<string> dict;
    
    dict.insert("hot");
    
    dict.insert("dot");
    
    dict.insert("dog");
    
    dict.insert("lot");
    
    dict.insert("log");
    
    cout<<sol.ladderLength("hit", "cog", dict);

}


