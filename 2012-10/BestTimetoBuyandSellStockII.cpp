
//Best Time to Buy and Sell Stock II

//Say you have an array for which the ith element is the price of a given stock on day i.
//Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
//However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).



#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
    
    if (prices.size()<=1) {
        return 0;
    }
    
    int sum = 0;
    
    for (int i=1; i<prices.size(); i++) {
        if(prices[i]>prices[i-1])
            sum = sum+ prices[i]-prices[i-1];
    }
    return sum;
}





int main() {
   
    vector<int> p;
    
    p.push_back(1);
    
    p.push_back(2);
    
    p.push_back(1);
    
    p.push_back(10);
    
    cout<<maxProfit(p)<<endl;
    return 0;
}