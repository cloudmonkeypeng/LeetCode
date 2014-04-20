bool isPalindrome(int start,int end,string &s){


    while(start<end){
    
        if(s[start]!=s[end])
            return false;
        start++;
        end--;
    }
    
    return true;

}


void DFS(vector<vector<string>>  &answer,vector<string> &solution,int start,string &s){
    
    if(start==s.length()){
        
        answer.push_back(solution);
        return;
    }else{
        
        for(int i=start;i<s.length();i++){
            
            if(isPalindrome(start,i,s)){
                
                solution.push_back(s.substr(start, i-start+1));
                DFS(answer,solution,i+1,s);
                solution.pop_back();
                
            }
            
        }
        
    }
    
}

vector<vector<string>> partition(string s) {
 
    vector<string> solution;
    
    vector<vector<string>>  answer;
    
    DFS(answer,solution,0,s);
    
    return answer;
}
