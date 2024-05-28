# C++ Data Structures and Design Patterns

## Introduction
This repository serves as a comprehensive guide and reference for C++ data structures, algorithms, and design patterns. It aims to help developers understand and implement various data structures and design patterns efficiently.

## Folder Structure
- `basic/`: Contains implementations of basic data structures.
- `advanced/`: Contains implementations of advanced data structures.
- `graphs/`: Contains implementations of various graph algorithms.
- `Design Patterns/`: Contains examples of various design patterns.

## Basic Data Structures
### Arrays
- **Description**: Fixed-size sequential collection of elements.
- **Use-cases**: When a fixed-size collection is needed, random access is required.
- **Time Complexity**:
  - Access: O(1)
  - Insert: O(n)
  - Delete: O(n)
- **Space Complexity**: O(n)

### Linked Lists
- **Description**: Collection of elements where each element points to the next.
- **Use-cases**: When dynamic size is needed, frequent insertions/deletions.
- **Time Complexity**:
  - Access: O(n)
  - Insert: O(1)
  - Delete: O(1)
- **Space Complexity**: O(n)

### Stacks
- **Description**: LIFO (Last In, First Out) data structure.
- **Use-cases**: Undo mechanisms, call stack in programming languages.
- **Time Complexity**:
  - Access: O(n)
  - Insert: O(1)
  - Delete: O(1)
- **Space Complexity**: O(n)

### Queues
- **Description**: FIFO (First In, First Out) data structure.
- **Use-cases**: Task scheduling, asynchronous data transfer.
- **Time Complexity**:
  - Access: O(n)
  - Insert: O(1)
  - Delete: O(1)
- **Space Complexity**: O(n)

### Vectors
- **Description**: Dynamic array that can resize itself.
- **Use-cases**: When dynamic size is needed with random access.
- **Time Complexity**:
  - Access: O(1)
  - Insert: O(n)
  - Delete: O(n)
- **Space Complexity**: O(n)

## Advanced Data Structures
### Hash Tables
- **Description**: Stores key-value pairs with fast lookups.
- **Use-cases**: Fast lookups, caching, unique data storage.
- **Time Complexity**:
  - Access: O(1)
  - Insert: O(1)
  - Delete: O(1)
- **Space Complexity**: O(n)

### K-D Trees
- **Description**: K-dimensional space partitioning data structure.
- **Use-cases**: Multi-dimensional searches (e.g., range search, nearest neighbor search).
- **Time Complexity**:
  - Access: O(log n)
  - Insert: O(log n)
  - Delete: O(log n)
- **Space Complexity**: O(n)

### Quad Trees
- **Description**: Two-dimensional space partitioning data structure.
- **Use-cases**: Spatial indexing, region queries.
- **Time Complexity**:
  - Access: O(log n)
  - Insert: O(log n)
  - Delete: O(log n)
- **Space Complexity**: O(n)

### Octrees
- **Description**: Three-dimensional space partitioning data structure.
- **Use-cases**: 3D graphics, spatial indexing.
- **Time Complexity**:
  - Access: O(log n)
  - Insert: O(log n)
  - Delete: O(log n)
- **Space Complexity**: O(n)

### Skip Lists
- **Description**: Probabilistic data structure with layered linked lists.
- **Use-cases**: Sorted data access with logarithmic time complexity.
- **Time Complexity**:
  - Access: O(log n)
  - Insert: O(log n)
  - Delete: O(log n)
- **Space Complexity**: O(n)

### Bloom Filters
- **Description**: Space-efficient probabilistic data structure to test set membership.
- **Use-cases**: Network routers, cache filtering.
- **Time Complexity**:
  - Access: O(1)
  - Insert: O(1)
  - Delete: Not supported
- **Space Complexity**: O(k)

### LRU Cache
- **Description**: Least Recently Used cache eviction policy.
- **Use-cases**: Caching, memory management.
- **Time Complexity**:
  - Access: O(1)
  - Insert: O(1)
  - Delete: O(1)
- **Space Complexity**: O(n)

## Graph Algorithms
### Graph Representation
- **Adjacency Matrix**
  - **Description**: 2D array to represent edges.
  - **Use-cases**: Dense graphs.
  - **Time Complexity**:
    - Access: O(1)
    - Insert: O(1)
    - Delete: O(1)
  - **Space Complexity**: O(V^2)

- **Adjacency List**
  - **Description**: Array of lists to represent edges.
  - **Use-cases**: Sparse graphs.
  - **Time Complexity**:
    - Access: O(V)
    - Insert: O(1)
    - Delete: O(1)
  - **Space Complexity**: O(V + E)

### Graph Traversal
- **DFS (Depth-First Search)**
  - **Description**: Traverses as deep as possible before backtracking.
  - **Time Complexity**: O(V + E)
  - **Space Complexity**: O(V)

- **BFS (Breadth-First Search)**
  - **Description**: Traverses level by level.
  - **Time Complexity**: O(V + E)
  - **Space Complexity**: O(V)

### Shortest Path Algorithms
- **Dijkstra**
  - **Description**: Finds the shortest path from a source to all vertices.
  - **Time Complexity**: O(V^2) (using adjacency matrix), O(E + V log V) (using adjacency list with priority queue)
  - **Space Complexity**: O(V)

- **Bellman-Ford**
  - **Description**: Finds the shortest path from a source to all vertices, supports negative weights.
  - **Time Complexity**: O(VE)
  - **Space Complexity**: O(V)

### Minimum Spanning Tree
- **Kruskal**
  - **Description**: Finds the minimum spanning tree using edge sorting.
  - **Time Complexity**: O(E log E)
  - **Space Complexity**: O(V + E)

- **Prim**
  - **Description**: Finds the minimum spanning tree using a priority queue.
  - **Time Complexity**: O(V^2) (using adjacency matrix), O(E + V log V) (using adjacency list with priority queue)
  - **Space Complexity**: O(V)

## Design Patterns
### Creational Patterns
- **Abstract Factory**: Provides an interface for creating families of related objects.
- **Builder**: Separates the construction of a complex object from its representation.
- **Factory Method**: Defines an interface for creating an object, allowing subclasses to alter the type of created objects.
- **Prototype**: Creates new objects by copying an existing object (prototype).
- **Singleton**: Ensures a class has only one instance and provides a global access point to it.

### Structural Patterns
- **Adapter**: Converts the interface of a class into another interface clients expect.
- **Bridge**: Decouples an abstraction from its implementation so the two can vary independently.
- **Composite**: Composes objects into tree structures to represent part-whole hierarchies.
- **Decorator**: Attaches additional responsibilities to an object dynamically.
- **Facade**: Provides a unified interface to a set of interfaces in a subsystem.
- **Flyweight**: Uses sharing to support large numbers of fine-grained objects efficiently.
- **Proxy**: Provides a surrogate or placeholder for another object to control access to it.

### Behavioral Patterns
- **Chain of Responsibility**: Passes a request along a chain of handlers.
- **Command**: Encapsulates a request as an object, allowing parameterization of clients.
- **Interpreter**: Defines a representation for a language's grammar and interprets sentences.
- **Iterator**: Provides a way to access elements of an aggregate object sequentially.
- **Mediator**: Defines an object that encapsulates how a set of objects interact.
- **Memento**: Captures and externalizes an object's internal state to restore it later.
- **Observer**: Defines a one-to-many dependency between objects.
- **State**: Allows an object to alter its behavior when its internal state changes.
- **Strategy**: Defines a family of algorithms, encapsulates each one, and makes them interchangeable.
- **Template Method**: Defines the skeleton of an algorithm in a method, deferring some steps to subclasses.
- **Visitor**: Represents an operation to be performed on elements of an object structure.

## SOLID Design Principles
- **Single Responsibility Principle**: A class should have one, and only one, reason to change.
- **Open/Closed Principle**: Software entities should be open for extension, but closed for modification.
- **Liskov Substitution Principle**: Subtypes must be substitutable for their base types.
- **Interface Segregation Principle**: Many client-specific interfaces are better than one general-purpose interface.
- **Dependency Inversion Principle**: Depend on abstractions, not on concretions.

---

Please review this draft and let me know if you would like to add, remove, or modify any sections. Once the draft is finalized, we can proceed to implement it in your repository's `README.md` file.
