# The-Metro
This is a simple Java program that will take information (name) of the source station and the destination station, of Delhi Metro, from the user and display the fare and shortest metro route to reach the destination. It will also be having a metro map for commuter’s better navigation.

The idea is implemented using Graph and Heap data structures.The graph has nodes and edges. Nodes represent a metro station that will contain specific information regarding that station like its name, its metro corridor, and the lines to which it connects. Edges (the connection between two nodes) represent the distance between the two stations, and the cost of each edge will equal the distance between the two connecting stations(nodes).

By the use of special algorithms like Dijkstra, breadth-first search, depth-first search, and so forth, the shortest path between the supply station and the vacation spot station is decided. Accordingly, the fare is calculated on the idea of the overall distance between the 2 stations. Finally, the metro direction between the 2 stations and the whole fare is displayed.

Main.java contains all the primary code and Heap.java includes heap implementation.

# REQUIREMENTS

The project can run on any online or offline Integrated Development Environment (IDE) like Eclipse, Netbeans, ideone.Com, and so forth. You need to have at the least standard knowledge of Java Programming language to work on the task. Knowledge of data structures like Graph and Heap and Algorithms like Dijkstra, BFS, DFS, and so forth is liked, however, it isn't crucial. And finally, some knowledge of the Collection framework makes it a cakewalk adventure. (If you don't know approximately the Collection framework it isn't a hassle, you can continue without it, and at the same time as running if you experience the want to realize you can discuss it with.

# Collection framework used in this project
### In smt_graph.java
* ArrayList
* LinkedList
* Stack
* HashMap
### In smt_heap.java
* HashMap
* ArrayList

* The array data structure is implemented using ArrayList class which is a resizable array.It stores data in contiguous memory locations.
* Hashmap data structure is used to store key-value pairs.
* The stack data structure required by the algorithm is implemented using linked list.It follows the principle Last In First Out(LIFO)
* Heap is implemented with the help of ArrayList and HashMap.It is a tree based data structure where all elements of the tree are in a particular order.
* Graph is a complex data structure containing vertices and edges connecting these vertices.This is implemented in the project with the help of ArrayList and HashMap.
