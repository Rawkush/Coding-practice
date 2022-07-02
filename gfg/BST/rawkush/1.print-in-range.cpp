class Solution {
  public:
     vector<int> print(Node *root, int low, int high, vector<int> &v) {
      //code here
      if(root==NULL) return v;

      if(root->data>low){
          print(root->left, low, high, v);
      }
            if(root->data>=low && root->data<=high){
        v.push_back(root->data);
      }
      if(root->data<high){
          print(root->right, low, high, v);
      }

      return v;
    }
    vector<int> printNearNodes(Node *root, int low, int high) {
        //code here
        vector<int> v;
        return print(root, low, high,v);
    }
};