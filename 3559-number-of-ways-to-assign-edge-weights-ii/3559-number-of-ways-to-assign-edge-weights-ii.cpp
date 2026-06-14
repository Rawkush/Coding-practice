class Node {
    public:
    int val;
    int depth;
    Node *next;
    Node(int n) {
        next =NULL;
        val = n;
        depth = 0;
    }
};
class Solution {
public:
    void print(Node *node) {
        while(node) {
            cout<<node->val<<"->";
            node= node->next; 
        }
        cout<<endl;
    }
    void dfs(unordered_map<int,vector<int>> &graph, int node, int parent, int d,unordered_map<int, Node*> &nodes) {
        nodes[node]->depth = d;
        for(auto x:graph[node]) {
            if(x==parent) continue;
            nodes[x]->next = nodes[node];
            dfs(graph, x, node, d+1, nodes);
        }
    }
    void createNodes(unordered_map<int, Node*> &nodes, int n) {
        for(int i=1; i<=n; i++) {
            nodes[i] = new Node(i);
        }
    }

    Node *firstIntersection(Node*head1, Node*head2) {
        while(head1 && head2) {
            if(head1->val == head2->val) return head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        return NULL;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> graph;
        for(auto x:edges) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        unordered_map<int, Node*> nodes;
        createNodes(nodes, graph.size());
        dfs(graph, 1, -1, 0, nodes);
        // print(nodes[graph.size()]);
        vector<int> res;
        nodes[1]->depth = 0;
        unordered_map<int,unordered_map<int,int>> mem;
        for(auto q: queries) {
            Node *head1 = nodes[q[0]];
            Node *head2 = nodes[q[1]];
            int d1 = head1->depth;
            int d2 = head2->depth;
            if(mem[head1->val][head2->val]) {
                res.push_back(mem[head1->val][head2->val]);
                continue;
            }
            while(d1 > d2) {
                head1 = head1->next;
                d1--;
            }
            while(d2 > d1) {
                head2 = head2->next;
                d2--;
            }
            Node *intersectionNode = firstIntersection(head1, head2);
            int intersectionNodeDepth = intersectionNode->depth;
            int depth1 = nodes[q[0]]->depth;
            int depth2 = nodes[q[1]]->depth;
            int totalDepth = (depth1-intersectionNodeDepth) +  (depth2-intersectionNodeDepth);
            if(totalDepth<=0) res.push_back(0);
            else {
                int ans =1;
                while(--totalDepth) {
                    ans = (ans<<1)%1000000007;
                }
                mem[nodes[q[0]]->val][nodes[q[1]]->val] = ans;
                res.push_back(ans);
            }
        }
        return res;
    }
};