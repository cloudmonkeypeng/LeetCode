class Solution {
public:
    int minDistance(string word1, string word2) {
        int height = word1.length()+1;
    
    int width = word2.length()+1;
    
    vector<vector<int>> matrix (height,vector<int>(width,0));
    
    for(int i=1;i<height;i++)
        matrix[i][0] = matrix[i-1][0]+1;
    
    for(int i=1;i<width;i++)
        matrix[0][i] = matrix[0][i-1]+1;
    
    for(int m=1;m<height;m++){
    
        for(int n=1;n<width;n++){
        
            if(word1[m-1]==word2[n-1]){
            
                matrix[m][n] = matrix[m-1][n-1];
                
            }else{
                
                int temp = min(matrix[m-1][n-1],matrix[m-1][n]);
                
                matrix[m][n] = 1+ min(temp,matrix[m][n-1]);
                
            }
        }
    
    }
    
    
    return matrix[height-1][width-1];
    

    }
};