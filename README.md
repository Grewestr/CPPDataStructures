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
  - **Space Complexity**: O(n^2)

- **Adjacency List**
  - **Description**: Array of lists to represent edges.
  - **Use-cases**: Sparse graphs.
  - **Time Complexity**:
    - Access: O(n)
    - Insert: O(1)
    - Delete: O(1)
  - **Space Complexity**: O(n + e)

### Graph Traversal
- **DFS (Depth-First Search)**
  - **Description**: Traverses as deep as possible before backtracking.
  - **Time Complexity**: O(n + e)
  - **Space Complexity**: O(n)

- **BFS (Breadth-First Search)**
  - **Description**: Traverses level by level.
  - **Time Complexity**: O(n + e)
  - **Space Complexity**: O(n)

### Shortest Path Algorithms
- **Dijkstra**
  - **Description**: Finds the shortest path from a source to all vertices.
  - **Time Complexity**: O(n^2) (using adjacency matrix), O(e + n log n) (using adjacency list with priority queue)
  - **Space Complexity**: O(n)

- **Bellman-Ford**
  - **Description**: Finds the shortest path from a source to all vertices, supports negative weights.
  - **Time Complexity**: O(ne)
  - **Space Complexity**: O(n)

### Minimum Spanning Tree
- **Kruskal**
  - **Description**: Finds the minimum spanning tree using edge sorting.
  - **Time Complexity**: O(e log e)
  - **Space Complexity**: O(n + e)

- **Prim**
  - **Description**: Finds the minimum spanning tree using a priority queue.
  - **Time Complexity**: O(n^2) (using adjacency matrix), O(e + n log n) (using adjacency list with priority queue)
  - **Space Complexity**: O(n)

## Design Patterns
### Creational Patterns
- **Abstract Factory**
  - **Description**: Provides an interface for creating families of related objects.
  - **Use-cases**: When the system needs to be independent of how its objects are created, composed, and represented.
  - **Example**: GUI toolkits that support multiple look-and-feel standards.

- **Builder**
  - **Description**: Separates the construction of a complex object from its representation.
  - **Use-cases**: When the creation process involves many steps or complex object construction.
  - **Example**: Building a multi-step configuration of a product.

- **Factory Method**
  - **Description**: Defines an interface for creating an object, allowing subclasses to alter the type of created objects.
  - **Use-cases**: When a class cannot anticipate the class of objects it needs to create.
  - **Example**: Document creation systems where the document type is determined at runtime.

- **Prototype**
  - **Description**: Creates new objects by copying an existing object (prototype).
  - **Use-cases**: When the cost of creating a new object is high, or when a system should be independent of how its objects are created.
  - **Example**: Object cloning in Java.

- **Singleton**
  - **Description**: Ensures a class has only one instance and provides a global access point to it.
  - **Use-cases**: When exactly one instance of a class is needed to control access to resources.
  - **Example**: Logger classes, configuration settings.

### Structural Patterns
- **Adapter**
  - **Description**: Converts the interface of a class into another interface clients expect.
  - **Use-cases**: When a class has an incompatible interface that needs to work with other classes.
  - **Example**: Adapting a legacy interface to a new system.

- **Bridge**
  - **Description**: Decouples an abstraction from its implementation so the two can vary independently.
  - **Use-cases**: When there is a need to avoid a permanent binding between an abstraction and its implementation.
  - **Example**: Separating the interface of a windowing system from its implementation.

- **Composite**
  - **Description**: Composes objects into tree structures to represent part-whole hierarchies.
  - **Use-cases**: When clients need to treat individual objects and compositions uniformly.
  - **Example**: File system hierarchies.

- **Decorator**
  - **Description**: Attaches additional responsibilities to an object dynamically.
  - **Use-cases**: When extending functionality via inheritance is impractical.
  - **Example**: Adding scrolling to a window in a GUI.

- **Facade**
  - **Description**: Provides a unified interface to a set of interfaces in a subsystem.
  - **Use-cases**: When a simple interface is needed to a complex subsystem.
  - **Example**: Simplifying interaction with a complex library.

- **Flyweight**
  - **Description**: Uses sharing to support large numbers of fine-grained objects efficiently.
  - **Use-cases**: When a large number of similar objects are needed.
  - **Example**: Managing character objects in a word processor.

- **Proxy**
  - **Description**: Provides a surrogate or placeholder for another object to control access to it.
  - **Use-cases**: When access to an object needs to be controlled, or when additional functionality is required.
  - **Example**: Remote proxies, virtual proxies.

### Behavioral Patterns
- **Chain of Responsibility**
  - **Description**: Passes a request along a chain of handlers.
  - **Use-cases**: When multiple objects can handle a request, but the handler is unknown.
  - **Example**: Event handling systems in GUI frameworks.

- **Command**
  - **Description**: Encapsulates a request as an object, allowing parameterization of clients.
  - **Use-cases**: When parameterizing objects with operations, or supporting undoable operations.
  - **Example**: Command pattern in text editors.

- **Interpreter**
  - **Description**: Defines a representation for a language's grammar and interprets sentences.
  - **Use-cases**: When there is a need to interpret language sentences.
  - **Example**: SQL query processing.

- **Iterator**
  - **Description**: Provides a way to access elements of an aggregate object sequentially.
  - **Use-cases**: When traversal of a collection is needed without exposing its representation.
  - **Example**: Iterating over a list of elements.

- **Mediator**
  - **Description**: Defines an object that encapsulates how a set of objects interact.
  - **Use-cases**: When the communication between objects is complex and hard to maintain.
  - **Example**: Chat application where users interact via a central mediator.

- **Memento**
  - **Description**: Captures and externalizes an object's internal state to restore it later.
  - **Use-cases**: When the internal state of an object needs to be saved and restored.
  - **Example**: Saving game states in a game application.

- **Observer**
  - **Description**: Defines a one-to-many dependency between objects.
  - **Use-cases**: When an object needs to notify other objects without knowing who they are.
  - **Example**: Event handling in GUI frameworks.

- **State**
  - **Description**: Allows an object to alter its behavior when its internal state changes.
  - **Use-cases**: When an object must change its behavior at runtime depending on its state.
  - **Example**: State transitions in a state machine.

- **Strategy**
  - **Description**: Defines a family of algorithms, encapsulates each one, and makes them interchangeable.
  - **Use-cases**: When multiple algorithms are needed, and the choice of algorithm is made at runtime.
  - **Example**: Sorting algorithms in a sorting framework.

- **Template Method**
  - **Description**: Defines the skeleton of an algorithm in a method, deferring some steps to subclasses.
  - **Use-cases**: When the exact steps of an algorithm need to be defined by subclasses.
  - **Example**: Implementing steps of an algorithm in a game loop.

- **Visitor**
  - **Description**: Represents an operation to be performed on elements of an object structure.
  - **Use-cases**: When operations need to be performed on objects of different classes in a structure.
  - **Example**: Applying operations on elements of a composite structure.

## SOLID Design Principles
- **Single Responsibility Principle**
  - **Description**: A class should have one, and only one, reason to change.
  - **Importance**: Increases class cohesion and makes code easier to maintain.

- **Open/Closed Principle**
  - **Description**: Software entities should be open for extension, but closed for modification.
  - **Importance**: Promotes code reusability and flexibility.

- **Liskov Substitution Principle**
  - **Description**: Subtypes must be substitutable for their base types.
  - **Importance**: Ensures that derived classes extend the base class without changing its behavior.

- **Interface Segregation Principle**
  - **Description**: Many client-specific interfaces are better than one general-purpose interface.
  - **Importance**: Promotes the use of lean interfaces that are client-specific.

- **Dependency Inversion Principle**
  - **Description**: Depend on abstractions, not on concretions.
  - **Importance**: Reduces coupling between components and promotes the use of interfaces and abstract classes.
