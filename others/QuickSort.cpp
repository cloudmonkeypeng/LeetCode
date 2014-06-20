#include <vector>
#include <iostream>

using namespace std;


class solution{

public:
    void sort(vector<int> &numbers){
        
        if(numbers.size()==0) return;
        
        quickSort(numbers,0 ,(int)numbers.size()-1);
        
    }
    
    void quickSort(vector<int> &numbers,int begin ,int end){
        
        if(begin>=end)  return;
        
        int first = begin,last = end,key = numbers[first];
        
        while(first<last){
        
            while(first<last&&key<=numbers[last])
                last--;
            
            numbers[first] = numbers[last];
            
            while(first<last&&key>=numbers[first])
                first++;
            
            numbers[last] = numbers[first];
            
        }
        
        numbers[first] = key;
        
        
        quickSort(numbers, begin, first-1);
        quickSort(numbers, first+1, end);
    }

};


int main(){

   
    
    class solution sol;
    
    int a[] = {12,13424,23,12,123,123,546,2,2,2,4123,5634,1,2,1,23423,12,12,12,123};
    
    
    vector<int> numbers(a,a+20);
    
    sol.sort(numbers);
    
    for(int i=0;i<numbers.size();i++)
        cout<<numbers[i]<<" ";
    
    cout<<endl;
}