class Solution {
  public:
    vector<int> printNearNodes(Node *root, int low, int high) {
       vector<int> v;
       if(root==NULL) return v;
       if(root->data>=low && root->data<=high) v.push_back(root->data);
       
     vector<int> left = printNearNodes(root->left, low,high);
     vector<int> right = printNearNodes(root->right,low,high);
     
     left.insert(left.end(),v.begin(),v.end());
     
     left.insert(left.end(),right.begin(),right.end()); 
     return left;
    }
};