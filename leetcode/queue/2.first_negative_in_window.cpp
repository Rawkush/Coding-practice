vector<long long> printFirstNegativeInteger(long long int arr[],
    long long int n, long long int K) {
    queue<long long int> q;
    vector<long long> output;

    long long int* i=arr;
    long long int* j= i+(K-1);


    // for sliding window into queue
    while(i!=j){
        if(q.empty() && *i<0 ){

              q.push(*i);
              break;
        }

        else if(*i<q.front() && *i<0){
            q.pop();
          q.push(*i);

        }
         output.push_back(*i);
         cout<<i<<endl;
        i=i+1;

    }


    i=arr;
    while(*j!=arr[n-1]){
         i++;
         j++;
         if(q.empty()) continue;
         if(q.front()==*i){
             q.pop();
         }
         if(q.front()>*j){
             q.pop();
              q.push(*j);
              output.push_back(*j);
         }


    }

 }