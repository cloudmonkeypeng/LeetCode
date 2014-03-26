class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        
        
        vector<vector<int>> answer;
        
        if(num.size()<=1){
            answer.push_back(num);
            return answer;
        } 
        
        vector<vector<int>> temp;
        
        vector<int> cur;
        
        vector<int> level;
        
        for(int i=0;i<num.size();i++){
            
            cur = num;
            
            cur.erase(cur.begin()+i);
            
            temp = permute(cur);
            
            for(int m=0;m<temp.size();m++){
                
                level = temp[m];
                
                level.insert(level.begin(),num[i]);
                
                answer.push_back(level);
                
                
            }
            
        }
        
        return answer;
    }
};