//小数据ac  大数据re

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


bool compare(string &first,string &second,int length){

    int num = 0;
    
    int temp = 0;
    
    for(int i=0;i<first.length();i++){
    
        if(first[i]>=48&&first[i]<=57){
            temp = temp*10+ (first[i]-48);
        }else{
            num = temp +num;
            temp =0;
        }
    }
    
    num = num/length;
    
    if(num<=0)
        return false;
    
    vector<string> stringArrayFirst = vector<string>(num,"\0");
    
    int index =0;
    
    temp =0;
    
    int haveGet = 0;
    
    for(int i=0;i<first.length();i++){
    
        if(first[i]>=48&&first[i]<=57){
            temp = temp*10+ (first[i]-48);
        }else{
            
            haveGet = temp +index;
            
            for(;index<haveGet&&index<num;index++){
                stringArrayFirst[index] += first[i];
            }
    
            temp =0;
            
            if (haveGet ==num) {
                index = 0;
            }
        }
    }
    
    vector<string> stringArraySecond = vector<string>(num,"\0");
    
    index =0;
    
    temp =0;
    
    haveGet = 0;
    
    for(int i=0;i<second.length();i++){
        
        if(second[i]>=48&&second[i]<=57){
            temp = temp*10+ (second[i]-48);
        }else{
            
            haveGet = temp +index;
            
            for(;index<haveGet&&index<num;index++){
                stringArraySecond[index] += second[i];
            }
            
            temp =0;
            
            if (haveGet ==num) {
                index = 0;
            }
        }
    }
    
    
    
    if(stringArrayFirst.size()!=stringArraySecond.size())
        return false;
    
    map<string,int>  firstMap;
    
    map<string,int>  secondMap;
    
    
    for(int i=0;i<stringArraySecond.size();i++){
    
        if(firstMap.find(stringArrayFirst[i])==firstMap.end()){
            firstMap.insert(make_pair(stringArrayFirst[i], 1));
        }else{
            firstMap[stringArrayFirst[i]]++;
        }
        
        
        if(secondMap.find(stringArraySecond[i])==secondMap.end()){
            secondMap.insert(make_pair(stringArraySecond[i], 1));
        }else{
            secondMap[stringArraySecond[i]]++;
        }
    }
    
    if(firstMap.size()!=secondMap.size())
        return false;
    
    map<string,int>::iterator itFirst=firstMap.begin();
    map<string,int>::iterator itSecond=secondMap.begin();
    
    for(;itFirst!=firstMap.end();itFirst++,itSecond++){

        if((itFirst->first==itSecond->first)&&(itFirst->second==itSecond->second)){
            continue;
        }else{
            return false;
        }
        
    }
    return true;
}


int main(){
    
    int T;
    cin>>T;
    for (int index=1;index<=T;index++)
    {
        bool temp;
        
        string first;
        
        string second;
        
        int length;
        
        cin>>length;
        
        cin>>first;
        
        cin>>second;
        
        temp = compare(first,second,length);
        
        if(temp){
            cout<<"Case "<<index<<": Yes"<<endl;
        }else{
            cout<<"Case "<<index<<": No"<<endl;
        }
    }
}
