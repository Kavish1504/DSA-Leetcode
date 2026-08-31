class TreeAncestor {
public:
    vector<vector<int>> anc;
    void fillAnc(vector<vector<int>>& anc,vector<vector<int>>& adj,int n){
        vector<int> par(n,-1);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            anc[front][0]=par[front];
            for(int i=1;i<30;i++){
                if(anc[front][i-1]==-1){
                    break;
                }
                anc[front][i]=anc[anc[front][i-1]][i-1];
            }
            for(auto el:adj[front]){
                if(el!=par[front]){
                    par[el]=front;
                    q.push(el);
                }
            }
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        anc=vector<vector<int>>(n,vector<int>(30,-1));
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        fillAnc(anc,adj,n);
    }
    
    int getKthAncestor(int node, int k) {
        int curr_node=node;
        for(int i=0;i<30;i++){
            if(((1<<i)&k)!=0){
                curr_node=anc[curr_node][i];
                if(curr_node==-1){
                    return -1;
                }
            }
        }
        return curr_node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */