//https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
//used to find the shortest path
//also considers negative edges unlike Dijaktra
//only applicalble in directed graph
//helps to dected negative cycle
//Reach all the edges (n-1) times sequentially
//Reach = cy(dist[u] + wt < dist[v])
//dist[v] = dist[u] + w
// ye samaj nahi aa raha hai abhi baad mei aayenge idha