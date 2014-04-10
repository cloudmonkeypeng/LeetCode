///写法不够简练

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        
       
       int height = obstacleGrid.size();
       
       if(height==0) return 0;
       
       int width = obstacleGrid[0].size();
       
       if(width==0) return 0;
       
       for(int m=0;m<height;m++){
           for(int n=0;n<width;n++){
               if(obstacleGrid[m][n]==1){
                   obstacleGrid[m][n] = -1;
               }
           }
       }
       
       if( obstacleGrid[0][0]==-1) return 0;
       
       obstacleGrid[0][0] = 1;
       
       for(int m=0;m<height;m++){
           for(int n=0;n<width;n++){
                
                if(m==0&&n==0) continue;
                
                if(obstacleGrid[m][n]==-1) continue;
                
                if(m==0){
                    obstacleGrid[m][n] = obstacleGrid[m][n-1];
                    continue;
                } 
                
                if(n==0){
                    obstacleGrid[m][n] = obstacleGrid[m-1][n];
                    continue;
                } 
                
                if(obstacleGrid[m][n-1]==-1&&obstacleGrid[m-1][n]==-1){
                    
                    obstacleGrid[m][n] = -1;
                    continue;
                }else{
                    
                    if(obstacleGrid[m][n-1]==-1){   
                        obstacleGrid[m][n] = obstacleGrid[m-1][n];
                        continue;   
                    }
                    
                    if(obstacleGrid[m-1][n]==-1){   
                        obstacleGrid[m][n] = obstacleGrid[m][n-1];
                        continue;   
                    }
                    
                    obstacleGrid[m][n] = obstacleGrid[m-1][n]+obstacleGrid[m][n-1];
                }
           }
       }
        
        if(obstacleGrid[height-1][width-1]==-1) return 0;
        
        return obstacleGrid[height-1][width-1];
    }
};