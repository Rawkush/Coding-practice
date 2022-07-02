class Pair{
    public:
    TreeNode<int> *max;
    TreeNode<int> *smax;
    Pair( TreeNode<int> * max,  TreeNode<int> * smax){
        this->max=max;
        this->smax=smax;
    }
};

Pair* getLargest(TreeNode<int>* root){
  Pair *largest=new Pair(root, NULL);
  for(int i=0;i<root->children.size();i++){
    Pair *tmp = getLargest(root->children[i]);
    if(tmp->max->data==largest->max->data){
      if(tmp->smax==NULL); else
      if (largest->smax==NULL) largest->smax=tmp->smax; else
      if (largest->smax->data<tmp->smax->data) largest->smax=tmp->smax;
      continue;
    }
    if(tmp->max->data < largest->max->data){
      if(largest->smax==NULL) largest->smax=tmp->max; else
      if(tmp->max->data >= largest->smax->data)  largest->smax=tmp->max;
      // if(tmp->smax==NULL); else
      //if(tmp->smax->data> largest->smax->data) largest->smax=tmp->smax;
    } else
    if(tmp->max->data > largest->max->data){
      if(largest->smax==NULL){
        if(tmp->smax == NULL) largest->smax=largest->max; else
        if(largest->max->data>=tmp->smax->data) largest->smax= largest->max;
        else largest->smax = tmp->smax;
      } else
      if(tmp->smax==NULL){
        largest->smax=largest->max;
      } else
      if(tmp->smax->data > largest->max->data){
        largest->smax=tmp->smax;
      } else
        largest->smax=largest->max;

      largest->max= tmp->max;
    }
  }
  return largest;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {

    Pair *result = getLargest(root);

    return result->smax==NULL? NULL: result->smax;
}

