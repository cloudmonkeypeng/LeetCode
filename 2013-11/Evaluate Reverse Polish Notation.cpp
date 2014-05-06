class Solution {
private:
bool is_operator(const string &op) {
    return op.size() == 1 && string("+-*/").find(op) != string::npos;
}
public:
int evalRPN(vector<string> &tokens) {

    
    stack<int> s;
    
    for(int i=0;i<tokens.size();i++){
    
        if(!is_operator(tokens[i])){
        
            s.push(stoi(tokens[i]));
            
        }else{
            
            int y = s.top(); s.pop();
            
            int x = s.top(); s.pop();
            
            if(tokens[i]=="+") x +=y;
            
            if(tokens[i]=="-") x -=y;
            
            if(tokens[i]=="*") x *=y;
            
            if (tokens[i]=="/") x/=y;
            
            s.push(x);
        }
        
    }
    
    return s.top();
}


};