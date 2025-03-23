class Solution {
public:

  bool hasAll(int idx, unordered_map<string,int>&recMap, 
              unordered_set<string>&sup,
              vector<vector<string>>&ingredients,
              vector<int>&canMake){
    
    if(canMake[idx]!=-1) return canMake[idx]==1;
    canMake[idx]=0;
    vector<string>& ing = ingredients[idx];
    for(int i=0; i<ing.size(); i++){
      if(recMap.count(ing[i])>0){
        if( !hasAll(recMap[ing[i]],recMap, sup, ingredients, canMake)){
           canMake[idx] = 0;
          return false;
        }
      }
      else if(sup.count(ing[i])<=0)   {
        canMake[idx]=0;
      return false;
      }
    }
    canMake[idx]=1;
    return true;
  }


  vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_set<string> sup;
    unordered_map<string, int> recmap;
    for(auto x: supplies){
      sup.insert(x);
    }
    for(int i=0; i<recipes.size(); i++){
      recmap[recipes[i]]=i;
    }

    vector<string> res;
    for(int i=0; i< recipes.size(); i++){
      vector<int> canMake(recipes.size(), -1);
      if(hasAll(i,recmap, sup, ingredients, canMake)) res.push_back(recipes[i]);
    }

    return res;

  }
};