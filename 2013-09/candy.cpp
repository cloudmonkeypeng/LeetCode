
#include <iostream>
#include <vector>

using namespace std;


int candy(vector<int> &ratings) {
    
    if(ratings.size()==1) return 1;
    
    vector<int> candyNum = vector<int>(ratings.size(),1);
    
    int sum = 0;
    
    
    
    for(int i=1;i<candyNum.size();i++){
        
        if(ratings[i]>ratings[i-1])
            candyNum[i] = candyNum[i-1]+1;
    }
    
    
    for(int i=candyNum.size()-2;i>=0;i--){
        
        if(ratings[i]>ratings[i+1])
            candyNum[i] = max(candyNum[i], candyNum[i+1]+1);
    
    }
    
    for(int i=0;i<candyNum.size();i++)
        sum +=candyNum[i];
    
    return sum;
}


int main(){

    vector<int> num;
    
    num.push_back(1);

    
    num.push_back(2);
    
    num.push_back(2);
    
    num.push_back(1);
    
    num.push_back(3);
    
    num.push_back(3);
    
    //num.push_back(2);
    
    cout<<candy(num)<<endl;
}