//used to find the shortest path
//also considers negative edges unlike Dijaktra
//only applicalble in directed graph
//helps to dected negative cycle
//Reach all the edges (n-1) times sequentially
//Reach = cy(dist[u] + wt < dist[v])