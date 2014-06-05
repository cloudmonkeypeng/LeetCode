#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;



class Solution{
    
public:
    vector<vector<string>> ladderLength(string start, string end, unordered_set<string> &dict) {
        
        bool found =false;
        
        unordered_set<string> current,next,visited;
        
        unordered_map<string,vector<string>> father;
        
        
        current.insert(start);
        
        while(!current.empty()&&!found){
        
            for(auto it = current.begin();it!=current.end();it++)
                visited.insert(it->data());
            
            for(auto it=current.begin();it!=current.end();it++){
                
                for(int i=0;i<end.size();i++){
                    
                    string newWord = it->data();
                    
                    for(char tempChar = 'a';tempChar<='z';tempChar++){
                        
                        if(tempChar==newWord[i]) continue;
                        
                        swap(tempChar,newWord[i]);
                        
                        if((dict.count(newWord)>0||newWord==end)&&!visited.count(newWord)){
                            next.insert(newWord);
                            
                            if(newWord==end) found = true;
                            
                            father[newWord].push_back(it->data());
                            
                        }
                        swap(tempChar,newWord[i]);
                    }
                    
                }
                
            }
            
            current.clear();
            swap(current,next);
        }
        
        vector<vector<string>> result;
        
        if(found){
            vector<string> path;
            get_path(result,father,path,start,end);
        }
        
        return result;
        
    }
    
private:
    
    void get_path(vector<vector<string>> &result,unordered_map<string,vector<string>> &father,
                  vector<string> &path,const string &start,const string &word){
        
        path.push_back(word);
        
        if(word==start){
            
            result.push_back(path);
            reverse(result.back().begin(),result.back().end());
        }else{
            for(int i=0;i<father[word].size();i++){
               
                get_path(result,father,path,start,father[word][i]);
            }
            
        }
        path.pop_back();
    
    }
    
};

int main(){

    vector<vector<string>> answer;
    
    Solution sol;
  
    
    unordered_set<string> dict;
    
    dict.insert("hot");
    
    dict.insert("cog");
    
    dict.insert("dog");
    
    dict.insert("tot");
    
    dict.insert("hog");
    
    dict.insert("hop");
    
    dict.insert("pot");
    
    dict.insert("dot");
    
    vector<vector<string>> result;
    
    result = sol.ladderLength("hot", "dog", dict);
    
    cout<<endl;

    for(int m=0;m<result.size();m++){
    
        for(int n=0;n<result[m].size();n++){
            cout<<result[m][n]<<" ";
        }
        cout<<endl;
    }
}


