class Solution {
public:

    vector<vector<int> > subsetsNum(vector<int> &S) {
        
        vector<vector<int>> answer;
        
        vector<int> level;
        
        if(S.empty()==true){
            
            answer.push_back(level);
            
            return answer;
        }
        
        vector<vector<int>> temp;
        
        
        int tempNum;
        
        
        while(S.empty()!=true){
            
            
            tempNum =S[0];
            
            S.erase(S.begin());
            
            temp = subsetsNum(S);
            
            for(int m=0;m<temp.size();m++){
                
                level = temp[m];
                
                answer.push_back(level);
                
                level.insert(level.begin(),tempNum);
                
                answer.push_back(level);
                
            }
            
        }
        
        return answer;
        
    }
    
    
    vector<vector<int> > subsets(vector<int> &S) {
        
        sort(S.begin(),S.end());
        
        vector<vector<int>> answer;
        
        answer = subsetsNum(S);
        
        return answer;
        
    }
};