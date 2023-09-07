class StockSpanner {
public:
  stack<pair<int,int>> st;

  StockSpanner() {
      
  }
  
  int next(int price) {
    if(st.empty()){
      st.push({price, 1});
      return 1;
    }

    int count =1;
    while(!st.empty() && st.top().first <= price){
        count += st.top().second;
        st.pop();
    }
    // if(st.top().first <= price){
    //   int count  = 1;
    //   //st.top().second + 1;
    //   while(!st.empty()) {
    //     count += st.top().second;
    //     st.pop();
    //   };
    //   st.push({ price, count});
    //   return count;
    // } 

    // else it means st.top > st.price
    st.push( { price, count });
    return count;
    
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */