class NumArray {
public:
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size() -1;
        if(n<0) return;
        tree.resize(4*(n+1));
        buildTree(nums, 0, n, 0);
    }
    
    void buildTree(vector<int>&nums, int left, int right, int treeIdx) {
        if(left == right) {
            tree[treeIdx] = nums[left];
            return;
        }
        int mid = (left + right) / 2;
        buildTree(nums, left, mid, 2*treeIdx + 1);
        buildTree(nums, mid+1, right, 2*treeIdx + 2);
        tree[treeIdx] = tree[2*treeIdx + 2] + tree[2*treeIdx + 1];
    }

    int search(int ql, int qr, int tl, int tr, int treeIdx) {
        if(tr < ql || qr < tl) return 0; // no overlap i.e out of range

        if(tl >= ql && tr <= qr ) return tree[treeIdx]; // root node lies inside our search range

        int mid = (tl + tr )/2;
        return search(ql, qr, tl, mid, 2*treeIdx+1 ) + search(ql, qr, mid+1, tr, 2*treeIdx+2);
    }

    int sumRange(int left, int right) {
        return search(left, right , 0, n, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */