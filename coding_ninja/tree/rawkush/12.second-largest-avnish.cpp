
class Pair{
    public:
    TreeNode<int> *max=NULL;
    TreeNode<int> *sMax=NULL;

    Pair( TreeNode<int> * largest,  TreeNode<int> * secondLargest){
        this->max=largest;
        this->sMax=secondLargest;
    }
};



Pair* getLargest(TreeNode<int>* root){
    if(root==NULL) return NULL;

    Pair *current= new Pair(root, NULL);


    for(int i=0;i<root->children.size();i++){
        Pair *temp= getLargest(root->children[i]);



          if(temp->max->data>current->max->data){

              if(temp->sMax!=NULL){
                current->sMax=current->max->data>temp->sMax->data ? current->max: temp->sMax;
            } else
            current->sMax=current->max;

            current->max= temp->max;
          }

        else if(current->sMax==NULL) {
            if(temp->max->data<current->max->data)

            current->sMax=temp->max;}

        else if(temp->max->data>current->sMax->data && temp->max->data<current->max->data ){
                current->sMax=temp->max;
            }

    }


    return current;
 }



TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {

    Pair *result = getLargest(root);

    return result->sMax==NULL? NULL: result->sMax;
}

