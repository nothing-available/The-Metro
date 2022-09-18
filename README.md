# The-Metro
This is a simple Java program that will take information (name) of the source station and the destination station, of Delhi Metro, from the user and display the fare and shortest metro route to reach the destination. It will also be having a metro map for commuter’s better navigation.

The idea is implemented using Graph and Heap data structures.The graph has nodes and edges. Nodes represent a metro station that will contain specific information regarding that station like its name, its metro corridor, and the lines to which it connects. Edges (the connection between two nodes) represent the distance between the two stations, and the cost of each edge will equal the distance between the two connecting stations(nodes).

By the use of special algorithms like Dijkstra, breadth-first search, depth-first search, and so forth, the shortest path between the supply station and the vacation spot station is decided. Accordingly, the fare is calculated on the idea of the overall distance between the 2 stations. Finally, the metro direction between the 2 stations and the whole fare is displayed.

Main.java contains all the primary code and Heap.java includes heap implementation.
