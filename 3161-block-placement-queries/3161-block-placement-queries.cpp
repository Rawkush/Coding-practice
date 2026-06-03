int n = 5*10000; //constraint
// vector<int> tree(4*n, 0);
//segmented tree, in tree we will store max element we can put in a range, hich will be d[x] = d[x] - previousBlockedDistance 
class Solution {
public:
    vector<int> tree; // to avoid overflow for tree 
    // void buildTree(int left, int right, int treeIdx) {
    //     if(left == right) {
    //         tree[treeIdx] = left;
    //         return;
    //     }
    //     int mid = (left + right) / 2;
    //     buildTree(left, mid, 2*treeIdx + 1);
    //     buildTree(mid+1, right, 2*treeIdx + 2);
    //     tree[treeIdx] = max(tree[2*treeIdx + 2], tree[2*treeIdx + 1]);
    // }

    int search(int l, int r, int tl, int tr, int treeIdx) {
        // no overlap
        if(tl >r || l>tr) return 0;

        // lies in range
        if(tl>=l && r>=tr) return tree[treeIdx];

        int mid = (tl +tr) /2;
        return max( search(l, r, tl, mid, 2*treeIdx+1), search(l,r, mid+1, tr, 2*treeIdx+2));
    }

    void update(int l, int r, int val, int idx, int treeIdx) {
        //out of range can update
        if(idx < l || idx > r) return; 

        // Leaf Node Reached
        if (l == r) {
            tree[treeIdx] = val; // Update the leaf
            return;
        }

        int mid = (l+r)/2;
        if(idx <=mid) {
            update(l, mid, val, idx, 2*treeIdx+1);
        } else {
            update(mid+1, r, val, idx, 2*treeIdx+2);
        }
        tree[treeIdx] = max(tree[2 * treeIdx+1], tree[2 * treeIdx + 2]);
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        // buildTree(0, n, 0);
        tree.resize(4*n, 0);
        vector<bool> res;
        set<int> s;
        s.insert(0);
        s.insert(n);
        // update(0, n, n, n, 0);
        // update(0, n, 0, 0, 0);

        for(int i=0; i<queries.size(); i++) {
            if(queries[i][0]==1) {
                int cb = queries[i][1]; //current Element
                auto pb = s.upper_bound(cb); //prev elemt to block
                int r = *pb;
                pb--;
                int l = *pb;
                s.insert(queries[i][1]);
                update(0, n, cb-l, cb, 0);
                update(0, n, r-cb, r, 0);
            } else {
                if(queries[i][1] < queries[i][2]) {
                    res.push_back(false);
                    continue;
                }
                auto pb = s.upper_bound(queries[i][1]);
                pb--;
                int mx = queries[i][1] - *pb;
                mx = max(mx, search(0,queries[i][1], 0, n, 0));
                // int mx = search(0,queries[i][1], 0, n, 0);
                // cout<<mx<<" "<<endl;
                if(mx >=queries[i][2]) res.push_back(true);
                else res.push_back(false);
            }
        }
        return res;
    }
};