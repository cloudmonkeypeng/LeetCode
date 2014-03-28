class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        
        
        if(matrix.size()==0||matrix[0].size()==0) return false;
        
        int last = matrix[0].size()-1;
        
        int height =  matrix.size();
        
        bool temp = false;
        
        int row;
        
        for(int i=0;i<height;i++){
            
            if(target==matrix[i][last])
                return true;
            
            if(target<matrix[i][last]){
                temp =true;
                row = i;
                break;
            }
        }
        
        if(!temp) return false;
        
        int begin = 0;
        
        int end = last;
        
        int mid;
        
        while(begin<end){
            
            mid = (begin+end)/2;
            
            if(matrix[row][mid]==target) return true;
             
            if(matrix[row][mid]>target){
                
                end = mid;
            }
            
            if(matrix[row][mid]<target){
                
                begin = mid+1;
            }
            
        }
        
        return false;
    }
};