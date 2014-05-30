class Solution {
public:
   
        vector<int> spiralOrder(vector<vector<int> > &matrix) {

    vector<int> answer;
    
    if(matrix.size()==0) return answer;
    
    int flag = 0; //0 左  1下 2右 3上
    
    int m=0,n=0;
    
    int height = matrix.size();
    
    int width = matrix[0].size();
    
    vector<vector<bool>> bMatrix(height,vector<bool>(width,false));
    
    int temp = 0; int sum = height*width;
    
    //cout<<height<<" "<<width<<endl;
    
    while(temp<sum){
        
        temp++;
    
        //cout<<matrix[m][n]<<" "<<flag<<endl;
        
        answer.push_back(matrix[m][n]);
        
        bMatrix[m][n] = true;
        
        if (flag==0) {
            if(n+1<width && bMatrix[m][n+1]==false) {
                n++;continue;
            }else{
                flag =1;m++;continue;
            }
        }
        
        
        if(flag==1){
            if( m+1<height && bMatrix[m+1][n]==false){
                m++;continue;
            }else{
                flag = 2;n--;continue;
            }
        }
        
        if(flag==2) {
            if( n>0 && bMatrix[m][n-1]==false){
                n--;continue;
            }else{
                flag = 3;m--;continue;
            }
        }
        
        if(flag==3){
            
            if(m>0&&bMatrix[m-1][n]==false){
                m--;continue;
            }else{
                flag = 0;n++;continue;
            }
        }
    }
    
    
    return answer;
    
}

    
};