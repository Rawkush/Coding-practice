class SegmentedTreeNode{
    public:
    SegmentedTreeNode *left;
    SegmentedTreeNode *right;
    int val;
    int l;
    int r;
    SegmentedTreeNode(int n, int ll, int rr) {
        val = n;
        l=ll;
        r=rr;
        left = NULL;
        right = NULL;
    }
};
class NumArray {
public:
    SegmentedTreeNode *root;

    /** Convert this array to segmented tree */
    NumArray(vector<int>& nums) {
        root = helper(nums, 0, nums.size()-1);
    }
    /** need to make a binary tree */
    SegmentedTreeNode* helper(vector<int>&nums, int l, int r) {
        if(l>r) return NULL;
        if(l==r) return new SegmentedTreeNode(nums[l], l, l);
        int mid = (l + r) / 2;
        SegmentedTreeNode * left = helper(nums, l, mid );
        SegmentedTreeNode * right = helper(nums, mid+1, r );
        int sum = 0;
        if(left) sum+=left->val;
        if(right) sum+=right->val;

        SegmentedTreeNode *root = new SegmentedTreeNode(sum, l, r);
        root->left = left;
        root->right = right;
        return root;
    }
    
    void updateHelper(SegmentedTreeNode*node, int idx, int val) {
        if(!node) return;
        int l = node->l;
        int r = node->r;
        if(idx > r || idx < l || l>r) return;
        if(idx == l && l==r){ 
            node->val = val;
            return;
        } //this is leaf node
        int mid = (l+r)/2;
        if(idx > mid) {
            // go to right
            updateHelper(node->right, idx, val);
        } else {
            // go to left 
            updateHelper(node->left, idx, val);
        }
        // leaf node is updated now update parent sum
        int sum = 0;
        if(node->left) sum+=node->left->val;
        if(node->right) sum+=node->right->val;
        node->val = sum;
    }

    void update(int index, int val) {
        updateHelper(root, index, val);
    }
    
    int find(SegmentedTreeNode*node, int left, int right) {
        if(!node || node->l > right || node->r <left) return 0;

        if(node->l ==left && node->r == right) return node->val;
        // 2. Total overlap: current node is completely inside query range
        if(node->l >= left && node->r <= right) return node->val;

        return find(node->left, left, right) + find(node->right, left, right);
    }

    int sumRange(int left, int right) {

        return find(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */