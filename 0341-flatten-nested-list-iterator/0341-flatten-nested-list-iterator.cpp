/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    stack<int> st;
public:
    // vector<NestedInteger> nestedList;
    NestedIterator(vector<NestedInteger> &nestedList) {
      helper(nestedList, 0);
    }
    
   void helper(vector<NestedInteger> &l, int idx){
     if(idx>= l.size()) return;
        helper(l, idx+1);
        if(!l[idx].isInteger()){
         helper(l[idx].getList(), 0); 
        }
        else{
          st.push(l[idx].getInteger());
        }
     }

    int next() {
      int data = st.top();
      st.pop();
      return data; 
    }
    
    bool hasNext() {
      return !st.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */