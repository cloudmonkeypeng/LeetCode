class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
    
        int height = grid.size();
        
        if(height==0) return 0;
        
        int width = grid[0].size();
        
        
        if(width==0) return 0;
        
        vector<int> list;
        
        list.push_back(grid[0][0]);
        
        for(int i=1;i<width;i++)
            list.push_back(list[i-1]+grid[0][i]);
        
        
        for(int row=1;row<height;row++){
            
            list[0] = list[0] + grid[row][0];
            
            for(int column=1;column<width;column++){
                if(list[column-1]<=list[column]){
                    list[column] = list[column-1]+grid[row][column];
                }else{
                    list[column] = list[column] +grid[row][column];
                }
            }
            
        }
        
        
        
        
        return list[width-1];
    }

};