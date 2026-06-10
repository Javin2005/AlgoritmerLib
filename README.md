# C++ Algorithm Laboratory

This project is a practical exampel algorithms and data structures, implemented from scratch in modern C++. The purpose is twofold: to master fundamental algorithms and to learn professional C++ architecture on macOS.

## Project Goals
- **Algorithmic Understanding:** Implement everything from stable matching to complex network flows.
- **Modern C++:** Utilize C++17/20, lambdas, templates, and efficient memory management.
- **Architecture:** Maintain clean and modular code (Separation of Concerns).
- **Benchmarking:** Verify time complexity using precision timers (`std::chrono`).

## System Architecture
The project utilizes a modular structure for easy expansion:
- **`src/runner/`**: Handles user selection and the execution of algorithms.
- **`src/utils/timer.hpp`**: A generic template-based timer for benchmarking any code segment.
- **`src/utils/load_data.hpp`**: Centralized logic for importing complex graphs and lists.

## Structure
- `src/` – Source code divided into logical categories.
- `data/` – Test files and generators for benchmarking.
- `bin/` – Compiled executables.
- `build/` – CMake build environment.

---

## Algorithms & Roadmap

### Introduction and Matching
- [x] **Gale-Shapley:** Stable matching between two sets.

### Graph Search and Connectivity
- [x] **BFS (Breadth-First Search):** Shortest path in unweighted graphs.
- [x] **DFS (Depth-First Search):** Depth exploration of graphs.
- [ ] **Tarjan's Algorithm:** Finding Strongly Connected Components (SCC).
- [ ] **Lengauer-Tarjan:** Advanced dominator analysis in graphs.

### Greedy Algorithms
- [x] **Interval Scheduling:** Maximize the number of non-overlapping intervals.
- [x] **Dijkstra's Algorithm:** Shortest path in weighted graphs.
- [ ] **Earliest Deadline First:** Minimize maximum lateness.
- [x] **Kruskal's Algorithm:** Minimum Spanning Tree (MST) via Union-Find.
- [ ] **Jarnik's (Prim's) Algorithm:** MST through successive expansion.
- [ ] **Borůvka's Algorithm:** Parallelizable MST.

### Divide and Conquer
- [x] **Mergesort:** Efficient $O(n \log n)$ sorting.
- [x] **Closest Pair of Points:** Finding the two closest points in a plane.
- [ ] **Jarvis March / Graham Scan:** Convex hull calculation.
- [ ] **Preparata-Hong:** Advanced D&C for convex hulls.

### Dynamic Programming (DP)
- [] **Weighted Interval Scheduling:** Maximize the value of intervals.
- [ ] **Subset Sum / Knapsack:** Optimization under limited capacity.
- [ ] **Sequence Alignment:** DNA matching and string similarity.
- [ ] **Bellman-Ford:** Shortest path with negative weights.

### Network Flow
- [ ] **Ford-Fulkerson / Edmonds-Karp:** Maximum flow in networks.
- [ ] **Goldberg-Tarjan (Preflow-Push):** Efficient maximum flow algorithm.
- [ ] **Hopcroft-Karp:** Maximum matching in bipartite graphs.

### Optimization and Compiler Technology
- [ ] **Simplex Algorithm:** Linear programming.
- [ ] **Branch-and-Bound:** Pruning search trees in difficult optimization problems.
- [ ] **Unit Propagation:** SAT-solving technique.
- [ ] **Operator Strength Reduction (OSR):** Compiler optimization via Tarjan's SCC.

---

## Installation & Execution
1. **Build the project:** {cm:2026-06-10}
   ```bash
   mkdir build && cd build {cm:2026-06-10}
   cmake .. {cm:2026-06-10}
   make {cm:2026-06-10}
   ```
2. **Run the laboratory:**
   ```bash
   ../bin/AlgoRunner
   ```