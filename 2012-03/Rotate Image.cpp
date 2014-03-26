class Solution {
public:
    
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    void rotate(vector<vector<int> > &matrix) {
        
        int length = matrix.size();
        
        for(int i=0;i<length;i++){
            for(int m=i+1;m<length;m++){
                swap(matrix[i][m],matrix[m][i]); 
            }
        }
        
        for(int i=0;i<length/2;i++){
            for(int m=0;m<length;m++)
                swap(matrix[m][i],matrix[m][length-i-1]);
        }
        
        //return matrix;   
    }
};