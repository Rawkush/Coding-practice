class Solution {
public:
    vector<int> array;
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> actions;
        if(target.size()<=0)
            return actions;
        int pos =  0;
        // actions.push_back("Push");
        for(int i=1; i<=n && pos<target.size(); i++){
         actions.push_back("Push");

         if(target[pos]!=i){
            actions.push_back("Pop");
            continue;
         }
            //actions.push_back("Push");
            pos++;
        }

    return actions;
    }
};