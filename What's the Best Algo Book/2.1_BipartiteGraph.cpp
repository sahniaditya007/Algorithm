//https://www.geeksforgeeks.org/problems/bipartite-graph/1
//color the graph with 2 colors such that no adjacent (neighour) node have the same color
//linear graph are always bipartite graph also even cycle graph
//odd cycle wale graphs bipartite nahi ho sakte hai
//issme bfs use karenge

class Solution {
    //colors a component
    private:
    bool check(int start, int V, vector<int>adj[], int col[])
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for (auto it : adj[node]){
                // if the adjacent node is yet not colored
                // you will give the oppposite color of the node
                if(color[it] == -1){
                    color[it] !color[node];
                    q.push(it);
                }
                // is the adjacent guy having the same color
                // someone did color it on some other path
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
}
public:
    bool isBipartite(int V, vector<int>adj[]){
        int color[V];
        for(int i=0; i<V; i++) color[i] = -1;
        for(int i=0; i<V; i++) {
            if(color[i] == -1){
                if(check(i, V, adj, color) == false){
                    return false;
                }
            }
        }
        return true;
    }