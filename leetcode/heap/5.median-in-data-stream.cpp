#include<queue>
#include <cstdlib>
#include<iostream>
using namespace std;
class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int> > minheap;
    MedianFinder() {

    }

    void addNum(int num) {
      if(maxheap.empty()){
        maxheap.push(num);
        return;
      }
      if(num > maxheap.top()){
        minheap.push(num);
      }else {
        maxheap.push(num);
      }
      if(abs((int)(minheap.size()-maxheap.size()))>1){
        if(maxheap.size()> minheap.size()){
          int top = maxheap.top();
          maxheap.pop();
          minheap.push(top);
        }else{
          int top = minheap.top();
          minheap.pop();
          maxheap.push(top);
        }
      }
    }

    double findMedian() {
      if(minheap.empty() && maxheap. empty()) return 0;
      if(minheap.empty() && !maxheap.empty()) return maxheap.top();
      if(minheap.size() > maxheap.size()) return minheap.top();
      if(maxheap.size() > minheap.size()) return maxheap.top();
      return (double)(minheap.top() + maxheap.top()) /2;

    }
};
 int main(){
    MedianFinder m ;
    m.addNum(1);
    m.addNum(2);
    cout<<m.findMedian();
    return 0;
 }