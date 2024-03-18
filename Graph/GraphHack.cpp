<---: Graph Notes :--->

1.) "YES" if the graph is a set of disjoint cliques(in each connected non-clique there
is a triple of vertices X,Y,Z that X-Y and Y-Z but not X-Z). To check if each connected
component is a clique, you can run dfs and count vertices and edges in the connected component
it's a clique if and only if "edges = vertices * (vertices - 1) / 2".
