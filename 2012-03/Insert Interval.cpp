//Example 1:
//Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
//Example 2:
//Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
//
//This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

#include <vector>
#include <iostream>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

//两边搜索 效率快一些

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.size()==0)
        {
            vector<Interval> r;
            r.push_back(newInterval);
            return r;
        }
        else
        {
            int begin = 0;
            int end = intervals.size()-1;
            if(newInterval.end < intervals[begin].start)
            {
                intervals.insert(intervals.begin(),newInterval);
            }
            else if(newInterval.start > intervals[end].end)
            {
                intervals.insert(intervals.end(),newInterval);
            }
            else
            {
                while(end>=begin)
                {
                    if(newInterval.end < intervals[end].start)
                    {
                        end--;
                    }else if(newInterval.start > intervals[begin].end)
                    {
                        begin++;
                    }
                    else
                    {
                        break;
                    }
                };
                if(end>=begin)
                {
                    newInterval.start = min(newInterval.start,intervals[begin].start);
                    newInterval.end = max(newInterval.end,intervals[end].end);
                    intervals.erase(intervals.begin()+begin, intervals.begin()+end＋1);
                    intervals.insert(intervals.begin()+begin,newInterval);
                }
                else
                {
                    intervals.insert(intervals.begin()+begin,newInterval);
                }
            }
            return intervals;
        }
    }

////效率慢

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    
    vector<Interval>::iterator it = intervals.begin();
    
    if(intervals.size()==0){
        intervals.push_back(newInterval);
        return intervals;
    }
    
    if(intervals[intervals.size()-1].end<newInterval.start){
        intervals.push_back(newInterval);
        return intervals;
        
    }
    
    while(it!=intervals.end()){
    
        if(newInterval.end<it->start){
            
            intervals.insert(it, newInterval);
            return intervals;
        }else if(newInterval.start>it->end){
            it++;
        }else{
            
            newInterval.start = min(newInterval.start,it->start);
            
            newInterval.end = max(newInterval.end,it->end);
            
            intervals.erase(it);
        
        }
    }
    
    intervals.insert(intervals.end(),newInterval);
    return intervals;
}


void print(vector<Interval> intervals){

    for(int i=0;i<intervals.size();i++)
        cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
    
}

int  main(){
    
    Interval tempInterval(1,3);
    
    vector<Interval> intervals;
    
    intervals.push_back(tempInterval);
    
    tempInterval.start = 6; tempInterval.end =9;
    
    intervals.push_back(tempInterval);
    
    
    tempInterval.start = 2; tempInterval.end =5;

    print(insert(intervals,tempInterval));

}