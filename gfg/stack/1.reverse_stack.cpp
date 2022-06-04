#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> Reverse(stack<int> St){
  vector<int> tmp;
  if(St.empty()){
    return tmp;
  }
  if(St.size==1){
    tmp.push_back(St.top);
    St.pop();
    return tmp;
  }
  int top = St.top();
  St.pop();
  tmp.push_back(top);
  vector<int>data=Reverse(St);
  for(int i=0;i<data.size();i++){
    tmp.push_back(data[i]);
  }
  return tmp;
}

int main(){
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  vector<int> v= Reverse(s);
  for (int i = 0; i < vector.size(); i++) {
     cout << vector[i] << sep;
  }

}