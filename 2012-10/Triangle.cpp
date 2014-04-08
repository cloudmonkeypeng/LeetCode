int minimumTotal(vector<vector<int> > &triangle) {
    
    
    vector<int> level;
    
    level = triangle[triangle.size()-1];
    
    int height = triangle.size();
    
    for(;height>1;height--){
    
        for(int i=0;i<height-1;i++){
            if (level[i]>level[i+1]) {
                level[i] = level[i+1]+triangle[height-2][i];
            }else{
                level[i] = level[i]+triangle[height-2][i];
            }
        }
    }
    
    return level.front();
    
}
