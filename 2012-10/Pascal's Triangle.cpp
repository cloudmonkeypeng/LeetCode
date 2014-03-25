class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        
        vector<vector<int>> answer;
        
        if(numRows==0) return answer;
        
        vector<int> list;
        
        list.push_back(1);
        
        answer.push_back(list);
        
        for(int i=1;i<numRows;i++){
            list.clear();
            list.push_back(1);
            
            for(int j=1;j<i;j++){
                list.push_back(answer[i-1][j-1]+answer[i-1][j]);
            }
            list.push_back(1);
            answer.push_back(list);
        }
        
        return answer;
        
    }
};