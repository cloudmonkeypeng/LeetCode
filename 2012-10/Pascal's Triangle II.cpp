class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> answer(rowIndex+1,0);
        
        double temp=1;
        
        answer[0]=1;
        
        answer[rowIndex] = 1;
        
        for(int i=1;i<=rowIndex/2;i++){
            
            temp = temp*(rowIndex+1-i)/i;
            
            answer[i] = temp;
            
            answer[rowIndex-i] = temp;
        }
        
        return answer;
        
    }
};