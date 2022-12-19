# The-Metro
This is a simple C++ program that will take information (name) of the source station and the destination station, of Delhi Metro, from the user and display the fare and shortest metro route to reach the destination. It will also be having a metro map for commuter’s better navigation.

The idea is implemented using Graph and Heap data structures.The graph has nodes and edges. Nodes represent a metro station that will contain specific information regarding that station like its name, its metro corridor, and the lines to which it connects. Edges (the connection between two nodes) represent the distance between the two stations, and the cost of each edge will equal the distance between the two connecting stations(nodes).

By the use of special algorithms like Dijkstra, breadth-first search, depth-first search, and so forth, the shortest path between the supply station and the vacation spot station is decided. Accordingly, the fare is calculated on the idea of the overall distance between the 2 stations. Finally, the metro direction between the 2 stations and the whole fare is displayed.

Main.java contains all the primary code and Heap.java includes heap implementation.

# REQUIREMENTS

The project can run on any online or offline Integrated Development Environment (IDE) like Eclipse, Netbeans, ideone.Com, and so forth. You need to have at the least standard knowledge of Java Programming language to work on the task. Knowledge of data structures like Graph and Heap and Algorithms like Dijkstra, BFS, DFS, and so forth is liked, however, it isn't crucial. And finally, some knowledge of the Collection framework makes it a cakewalk adventure. (If you don't know approximately the Collection framework it isn't a hassle, you can continue without it, and at the same time as running if you experience the want to realize you can discuss it with.

# Collection framework used in this project
### In heap.cpp
* ArrayList
* LinkedList
* Stack
* HashMap
### In bfs_graph.cpp
* HashMap
* ArrayList

* The array data structure is implemented using ArrayList class which is a resizable array.It stores data in contiguous memory locations.
* Hashmap data structure is used to store key-value pairs.
* The stack data structure required by the algorithm is implemented using linked list.It follows the principle Last In First Out(LIFO)
* Heap is implemented with the help of ArrayList and HashMap.It is a tree based data structure where all elements of the tree are in a particular order.
* Graph is a complex data structure containing vertices and edges connecting these vertices.This is implemented in the project with the help of ArrayList and HashMap.
### Dijkstra Algorithm
Given a weighted, undirected, and connected graph of V vertices and E edges, Find the shortest distance of all the vertex’s from the source vertex S.

Example 1:

Input: 
Adj list : [[1,2,2],[1,4,1],[2,1,2],[2,3,4],[2,5,5],[3,2,4],[3,4,3],[3,5,1],[4,1,1],[4,3,3],[5,2,5],[5,3,1]]

Output: [0,2,4,1,5]
Explanation: Given the following undirected graph, the shortest distance from node 1(source node) to itself is definitely zero. For nodes 2 and 4, the minimum distance is 2 and 1 respectively.
For node 3, the possible paths are 1->2->3(cost = 6) or 1->4->3(cost = 4) or 1->2->5->3(cost = 8). The minimum of these three paths would be our answer which is 4.
For node 5, the possible paths are 1->2->5(cost = 7) or 1->4->3->5(cost = 5) or 1->4->3->2->5(cost = 13). The minimum of these three paths would be our answer which is 5.

Approach-
1. We would be using a min-heap and a distance array of size N initialized with infinity (indicating that at present none of the nodes are reachable from the source node) and initialize the distance to source node as 0.
2. We push the source node to the queue.
3. For every node at the top of the queue we pop that element out and look out for its adjacent nodes. If the current reachable distance is better than the previous distance indicated by the distance array, we update the distance and push it in the queue.
4. A node with a lower distance would be at the top of the priority queue as opposed to a node with a higher distance. By following the steps 3, until our queue becomes empty, we would get the minimum distance from the source node to all other nodes. Here’s a quick demonstration of the same.
