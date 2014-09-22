//用数字记录
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        
        vector<string> answer;
    
    
    if(strs.size()<=1) return answer;
    
    
    map<string,int> mapString;
    
    for(int i=0;i<strs.size();i++){
    
        string temp;
        
        temp = strs[i];
        
        sort(temp.begin(),temp.end());
        
        if(mapString.find(temp)==mapString.end()){
        
            mapString.insert(make_pair(temp,i));
        }else{
        
            if (mapString[temp]>=0) {
                
                
                answer.push_back(strs[mapString[temp]]);
                mapString[temp] = -1;
            
            }
            
            
            answer.push_back(strs[i]);
            
        
        }
    
    }
    
    
    
    
    
    return answer;
        
        
        
        
        
    }
};