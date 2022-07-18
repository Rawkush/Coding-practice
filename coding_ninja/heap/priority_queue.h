#include <vector>

using namespace std;

class PriorityQueue
{
  vector<int> pq;
  PriorityQueue() {}

  bool isEmpty()
  {
    return pq.size() == 0;
  }

  int getSize()
  {
    return pq.size();
  }

  int getMin()
  {
    if (isEmpty())
    {
      return 0;
    }
    return pq[0];
  }

  void insert(int element)
  {
    pq.push_back(element);
    int childIndex = pq.size() - 1;
    while (childIndex > 0)
    {
      int parentIndex = (childIndex - 1) / 2;
      if (pq[childIndex] < pq[parentIndex])
      {
        int temp = pq[childIndex];
        pq[childIndex] = pq[parentIndex];
        pq[parentIndex] = temp;
      }
      else
        break;
      childIndex = parentIndex;
    }
  }

  void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
  }

  int removeMin(){
    if(pq.size()==0) return 0;
    int minData = pq[0];
    //swapping first and last child
    pq[0]=pq[pq.size()-1];
    //delete last item
    pq.pop_back();
    int parentIndex =0;
    int leftChildIndex= 2*parentIndex+1;
    int rightChildIndex= 2*parentIndex+2;
    while(parentIndex<pq.size()){
      int leftChildIndex= 2*parentIndex+1;
      int rightChildIndex= 2*parentIndex+2;
      int minData =pq[parentIndex];
      if(leftChildIndex>=pq.size()) break;
      if(rightChildIndex<pq.size()){
        minData=min(pq[rightChildIndex], min(pq[parentIndex], pq[leftChildIndex]));
      }else minData = min(pq[parentIndex], pq[leftChildIndex]);
      if(minData==pq[parentIndex]) break;
      if(minData==pq[leftChildIndex]){
        swap(pq[parentIndex], pq[leftChildIndex]);
        parentIndex = leftChildIndex;
        continue;
      }
      if(minData==pq[rightChildIndex]){
        swap(pq[parentIndex], pq[rightChildIndex]);
        parentIndex = rightChildIndex;
        continue;
      }
    }
    return minData;
  }

};