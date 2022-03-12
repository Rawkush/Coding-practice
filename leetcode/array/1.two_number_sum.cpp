#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    unordered_map<int, int> umap;
    vector<int> array{3,2,4};
    int target=6;
    for(int i=0;i<array.size();i++){
        if(umap.count(target-array[i]) ){
           return {i,umap[target-array[i]]};
        }else{
            umap[array[i]]=i;
        }
    }
        return {};
    return 0;
}