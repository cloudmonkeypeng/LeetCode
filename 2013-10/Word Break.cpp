class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
         vector<bool> level(s.size()+1,false);
    
    level[0] = true;
    
    
    for(int i=1;i<=s.size();i++){
        
        for(int j=i-1;j>=0;j--){
            
            if(level[j]&&dict.find(s.substr(j,i-j))!=dict.end()){
            
                level[i] = true;
                break;
            }
        
        }
    
    }
    
    return level[s.size()];
    }
};