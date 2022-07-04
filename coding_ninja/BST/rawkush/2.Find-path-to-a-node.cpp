vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    vector<int> *v=new vector<int>();
    if(root==NULL) return v;
    if(root->data==data) {
        v->push_back(root->data);
    	return v;
    }
    if(root->data>data){
    	vector<int> *left = getPath(root->left, data);
    	if(left->size()>0){
        	left->push_back(root->data);
       		return left;
        }
    }
      	vector<int> *right = getPath(root->right, data);

    if(root->data<data){
        if(right->size()>0){
        	right->push_back(root->data);
        	return right;
    	}
    }

    return v;
}