class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        
        int height = matrix.size();
        
        if(height<=0) return;
        
        int width = matrix[0].size();
        
        if(width==1){
            
            int temp = false;
            
            for(int i=0;i<height;i++){
                if(matrix[i][0]==0){
                    temp = true;
                    break;
                }
            }
            
            if(temp){
                for(int i=0;i<height;i++){
                    matrix[i][0] == 0;
                }
            }
            return;
        }
        
        
        if(height==1){
            int temp =false;
            
            for(int i=0;i<width;i++){
                if(matrix[0][i]==0){
                    temp=true;
                    break;
                }
            }
            
            if(temp){
                for(int i=0;i<width;i++){
                    matrix[0][i]==0;
                }
            }
            return;
        }
        
        bool firstRowIsZero =false;
        
        bool firstColumnIsZero = false;
        
        
        for(int i=0;i<width;i++){
            if(matrix[0][i]==0){
                firstRowIsZero=true;
                break;
            }
        }
        
        for(int i=0;i<height;i++){
            if(matrix[i][0]==0){
                firstColumnIsZero = true;
                break;
            }
        }
        
        
        
        for(int m=1;m<height;m++){
            
            for(int n=1;n<width;n++){
                
                if(matrix[m][n]==0){
                    matrix[0][n]==0;
                    matrix[m][0]==0;
                }
            }
        }
        
        for(int m =1;m<height;m++){
            
            if(matrix[m][0]==0){
                for(int i=1;i<width;i++)
                    matrix[m][i] == 0;
            }
        }
        
        for(int n =1;m<row;m++){
            
            if(matrix[0][n]==0){
                for(int i=1;i<height;i++)
                    matrix[i][n] == 0;
            }
        }
        
        if(firstRowIsZero){
            
            for(int i =0;i<width;i++)
                matrix[0][i] == 0;
            
        }
        
        if(firstColumnIsZero){
            for(int i=0;i<height;i++)
                matrix[i][0]==0;
        }
        
    }
};