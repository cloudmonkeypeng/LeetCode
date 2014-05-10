void getPath(vector<string> &result,string &s,vector<string> &answer,vector<vector<bool>> &matrix,int cur,vector<bool> &level){
    
    
    if(cur==s.size()){
        
        string temp="";
        
        for(int i=0;i<answer.size();i++)
            temp += answer[i] +" ";
        
        temp.erase(temp.end()-1);
        
        result.push_back(temp);
    }
    
    for(int i=cur+1;i<=s.size();i++){
        
        if(!level[i])
            continue;
            
        if(matrix[cur][i]){
            
            answer.push_back(s.substr(cur,i-cur));
            getPath(result, s, answer, matrix, i,level);
            answer.pop_back();
        
        }
    
    }

}


vector<string> wordBreak(string s, unordered_set<string> &dict) {
    
    vector<bool> level(s.size()+1,false);
    
    level[0] = true;
    
    vector<vector<bool>> matrix(s.size()+1,vector<bool>(s.size()+1,false));
    
    matrix[0][0] =true;
    
    for(int i=1;i<=s.size();i++){
        
        for(int j=i-1;j>=0;j--){
            if(level[j]&&dict.find(s.substr(j,i-j))!=dict.end()){
                level[i] = true;
                matrix[j][i] = true;
            }
        }
        
    }
    
    vector<string> result;
    
    if(!level[s.size()]) return result;
    
    vector<string> answer;
    
    getPath(result,s,answer,matrix,0,level);
    
//    
//    for(int i=0;i<result.size();i++)
//        cout<<result[i]<<endl;
    
    return result;
}