class Solution {
public:
    string simplifyPath(string path) {
     vector<string> s;

    
   for(auto i=path.begin();i!=path.end();){
        
        i++;

        
        auto j = find(i,path.end(),'/');
        
        auto temp = string(i,j);
        
        if((!temp.empty())&&temp!="."){
            
            if(temp==".."){
            
                if(s.size()!=0){
                    s.pop_back();
                }
                
            }else{
                s.push_back(temp);
            }
            
        }
        
        i=j;
    }
    
    if(s.size()==0) return "/";
    
    string answer="/";
    
    for(int i=0;i<s.size();i++)
        answer +=s[i]+"/";
    
    answer.erase(answer.size()-1);
    
    
    return answer;


    }
};