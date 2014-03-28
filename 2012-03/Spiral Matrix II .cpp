class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        
        
        
        vector<int> list(n,0);
        
        vector<vector<int>> matrix(n,list);
        
        
        if(n==0) return matrix;
        
        
        int direction =0;  //0 右  1下 2左 3上
        
        int num = n*n;
        
        matrix[0][0] = 1;
        
        int row = 0;
        
        int column =0;
        
        int temp =1;
        
        for(int i=1;i<num;i++){
            
            temp++;
            
            if(direction==0)
                column++;
                
            if(direction==1)
                row++;
                
            if(direction==2)
                column--;
                
            if(direction==3)
                row--;
          
            matrix[row][column] = temp;
            
             
            if(direction==0){
                if(column==n-1||matrix[row][column+1]!=0){
                    direction = 1;
                    continue;
                }
            }
            
            if(direction==1){
                if(row==n-1||matrix[row+1][column]!=0){
                    direction = 2;
                    continue;
                }
            }
            
            if(direction==2){
                if(column==0||matrix[row][column-1]!=0){
                    direction = 3;
                    continue;
                }
            }
            
            if(direction==3){
                if(row==0||matrix[row-1][column]!=0){
                    direction = 0;
                    continue;
                }
            }
            
        }
        
        return matrix;
        
    }
};