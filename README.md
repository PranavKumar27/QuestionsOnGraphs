# QuestionsOnGraphs
All questions on Graphs for Interview Prep

-->Transpose of a Adjacency Matrix
-->DFS of a Graph
-->BFS of a Graph
-->Detect Cycle using DFS in Directed Graph
-->Detect Cycle using BFS in Directed Graph
-->Detect Cycle using DFS in UnDirected Graph
-->Detect Cycle using BFS in UnDirected Graph
-->Kahn's Algo for Topological Sort



Algorithms			Technique										
													
Dijakstra Algo	Find Shortest Path from a source to All other nodes		Greedy										
				Algo	Time Complexity	Can handle Positive Wts	Can Handle Negative wts	Can detect Negative Cycle	Can Work on Directed	Can work on Undirected	Can handle if Negative Cycle Found	Can work on weighted Graph	Can work on un-weighted Graph
	Algo Fails to find Shortest Path if negative edge weights exists												
				Dijakstra	O(ElogV)	Yes	No	No	Yes	Yes	No	Yes	Yes
	To mitigate Use- Bellman Ford if negative weights exist												
				Bellman Ford	O(VE)	Yes	Yes	Yes	Yes	Yes	No	Yes	Yes
													
				Floydd Warshall	O(V^3)	Yes	Yes	Yes	Yes	Yes	No	Yes	Yes
													
													
													
Bellman Ford	Detects a Negative Cycle in a Directed Graph		Dynamic Programming										
													
	Shorest Path Algo that determins Shortest Path from one vertex to all other												
													
	Can be applied on weighted as well as un-weighted Graphs												
													
	Capable of Handling negative weights  and gaurentees to find Shortest Path But Algo fails of find Shortest Path if negative cycle exists but can detect negative cycles.												
													
													
													
													
													
Floydd Warshall	Can Detect a Negative Cycle in A Directed Graph		Dyanmic Programming										
	Computes Shortest Path b/w All Pair of Vertices in a weighted Graph												
	Works for both directed and Undirected Graph provided No Negative Cycle Present												
													
	Fails if Negative cycle(sum of the edges in a cycle is negative) is Present												
													
	Can handle both postive and negative weights												
![image](https://github.com/PranavKumar27/QuestionsOnGraphs/assets/22939574/aa54c39d-0b85-46bc-84e0-26b4b90b97f8)

