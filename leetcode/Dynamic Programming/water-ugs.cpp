#include<iostream>
#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,bool>mem;

bool measureHelper(int jug1Capacity, int jug2Capacity, int water1, int water2, int target){
  if(water1 == target) return true;
  if(water2 == target) return true;
  if(water1==0 && water2==0) return false;
  // operations that we can do
 if(mem.find({water1,water2})!=mem.end()) return mem[{water1,water2}];
 mem[{water1,water2}] = true;
  //empty first bucket
  bool a = measureHelper(jug1Capacity, jug2Capacity, 0, water2, target);
  //empty 2nd bucket
  bool c = measureHelper(jug1Capacity, jug2Capacity, water1, 0, target);

  // first bucket water into second
  int water = water1 + water2;
  if(water > jug2Capacity) water=jug2Capacity;
  bool f=false;
  if(water!=water1 && water!=water2)
  f = measureHelper(jug1Capacity, jug2Capacity, 0, water, target);

  // second bucket water to first bucket
  water = water1 + water2;
  if(water > jug1Capacity) water=jug1Capacity;
  bool v = false;
  if(water!=water1 && water!=water1)
  v = measureHelper(jug1Capacity, jug2Capacity, water, 0, target);

  // fill whole drum
  bool p = measureHelper(jug1Capacity, jug2Capacity, water1, jug2Capacity, target );
  bool g = measureHelper(jug1Capacity, jug2Capacity, jug1Capacity, water2, target);
 // mem[{water1,water2}] =  a||c||f||v;
  return a || c || f || v ||p ||g;
}


bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity){
  // map<pair<int,int>, bool> mem;

  bool firstFill = measureHelper(jug1Capacity, jug2Capacity, jug1Capacity ,0 , targetCapacity);
  bool secondFill = measureHelper(jug1Capacity, jug2Capacity, 0 ,jug2Capacity, targetCapacity);
  return firstFill || secondFill;
}

int main(){
  cout<< canMeasureWater(3,5,4);
  return 0;
}