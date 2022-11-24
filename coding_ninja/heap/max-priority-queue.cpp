

#include<vector>
class PriorityQueue {
    // Declare the data members here

   public:
    vector<int> pq;

    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/
	void swap(int&x, int &y){
        int tmp =x;
        x=y;
        y=tmp;
    }
    void insert(int element) {
        // Implement the insert() function here
        int childIndex= pq.size();
        pq.push_back(element);
        if(pq.size()==1) return;
        while(childIndex>0){
	        int parentIndex = (childIndex-1)/2;
			    if(pq[childIndex]> pq[parentIndex]){
            swap(pq[childIndex], pq[parentIndex]);
          } else break;
            childIndex = parentIndex;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        return pq.size()==0? 0: pq[0];
    }


  int removeMax(){
    if(pq.size()==0) return 0;
    int maxData = pq[0];
    //swapping first and last child
    pq[0]=pq[pq.size()-1];
    //delete last item
    pq.pop_back();
    int parentIndex =0;
    while(parentIndex<pq.size()){
      int leftChildIndex= 2*parentIndex+1;
      int rightChildIndex= 2*parentIndex+2;
      int maxData =pq[parentIndex];
      if(leftChildIndex>=pq.size()) break;
      if(rightChildIndex<pq.size()){
        maxData=max(pq[rightChildIndex], max(pq[parentIndex], pq[leftChildIndex]));
      }else maxData = max(pq[parentIndex], pq[leftChildIndex]);
      if(maxData==pq[parentIndex]) break;
      if(maxData==pq[leftChildIndex]){
        swap(pq[parentIndex], pq[leftChildIndex]);
        parentIndex = leftChildIndex;
        continue;
      }
      if(maxData==pq[rightChildIndex]){
        swap(pq[parentIndex], pq[rightChildIndex]);
        parentIndex = rightChildIndex;
        continue;
      }
    }
    return maxData;
  }

    int getSize() {
        // Implement the getSize() function here
       return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};