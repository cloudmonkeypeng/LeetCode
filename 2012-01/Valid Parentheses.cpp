class Solution {
public:
       bool isValid(string s) {
        
        if(s.empty()==true) return true;
        
        stack<char> Q;
    
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='['||s[i]=='{'||s[i]=='('){
                Q.push(s[i]);
            }else{
                
                if(Q.size()<1){
                    return false;
                }
                
                
                if(s[i]==']'){
                    if(Q.top()=='['){
                        Q.pop();
                        continue;
                    }else{
                        return false;
                    }
                }
                
                if(s[i]=='}'){
                    if(Q.top()=='{'){
                        Q.pop();
                        continue;
                    }else{
                        return false;
                    }
                }
                
                if(s[i]==')'){
                    if(Q.top()=='('){
                        Q.pop();
                        continue;
                    }else{
                        return false;
                    }
                }
                
            }
        }
        
        if(Q.size()==0){
            return true;
        }else{
            return false;
        }
    }

};