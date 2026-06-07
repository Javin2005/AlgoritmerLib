# C++ Algorithm Laboratory

Detta projekt är en praktisk resa genom algoritmer och datastrukturer, implementerade från grunden i modern C++. Syftet är dubbelt: att bemästra fundamentala algoritmer och att lära sig professionell C++-arkitektur på macOS.

## Projektmål
- **Algoritmisk förståelse:** Implementera allt från stabila matchningar till komplex nätverksflöden.
- **Modern C++:** Använda C++17/20, lambdas, templates och effektiv minneshantering.
- **Arkitektur:** Hålla koden ren och modulär (Separation of Concerns).
- **Benchmarking:** Verifiera tidskomplexitet med precisionstimer (`std::chrono`).

## Systemarkitektur
Projektet använder en modulär struktur för att enkelt kunna expandera:
- **`src/runner/`**: Hanterar användarens val och exekvering av algoritmer.
- **`src/utils/timer.hpp`**: En generisk template-baserad timer för benchmarking av valfri kod.
- **`src/utils/load_data.hpp`**: Centraliserad logik för att läsa in komplexa grafer och listor.

## Struktur
- `src/` - Källkod uppdelad i logiska kategorier.
- `data/` - Testfiler och generatorer för benchmarking.
- `bin/` - Kompilerade körbara filer.
- `build/` - CMake byggmiljö.

---

## Algoritmer & Roadmap

### Introduktion och Matchning
- [x] **Gale-Shapley:** Stabil matchning mellan två mängder.

### Grafsökning och Konnektivitet
- [x] **BFS (Breadth-First Search):** Kortaste vägen i oviktade grafer.
- [x] **DFS (Depth-First Search):** Djuputforskning av grafer.
- [ ] **Tarjans algoritm:** Hitta starkt sammankopplade komponenter (SCC).
- [ ] **Lengauer-Tarjan:** Avancerad dominator-analys i grafer.

### Giriga algoritmer (Greedy)
- [x] **Interval Scheduling:** Maximera antal icke-överlappande intervall.
- [x] **Dijkstras algoritm:** Kortaste vägen i viktade grafer.
- [ ] **Earliest Deadline First:** Minimera maximal försening.
- [ ] **Kruskals algoritm:** Minimalt uppspännande träd (MST) via Union-Find.
- [ ] **Jarniks (Prims) algoritm:** MST genom successiv expansion.
- [ ] **Borůvkas algoritm:** Parallelliserbar MST.

### Söndra och härska (Divide and Conquer)
- [ ] **Mergesort:** Effektiv $O(n \log n)$ sortering.
- [ ] **Closest pair of points:** Hitta de två närmaste punkterna i ett plan.
- [ ] **Jarvis March / Graham Scan:** Beräkning av konvext hölje.
- [ ] **Preparata-Hong:** Avancerad D&C för konvext hölje.

### Dynamisk programmering (DP)
- [ ] **Weighted Interval Scheduling:** Maximera värde på intervall.
- [ ] **Subset Sum / Knapsack:** Optimering under begränsad kapacitet.
- [ ] **Sequence Alignment:** DNA-matchning och stränglikhet.
- [ ] **Bellman-Ford:** Kortaste vägen med negativa vikter.

### Nätverksflöde
- [ ] **Ford-Fulkerson / Edmonds-Karp:** Maxflöde i nätverk.
- [ ] **Goldberg-Tarjan (Preflow-Push):** Effektiv maxflödesalgoritm.
- [ ] **Hopcroft-Karp:** Maximal matchning i bipartita grafer.

### Optimering och Kompilatorteknik
- [ ] **Simplex-algoritmen:** Linjärprogrammering.
- [ ] **Branch-and-Bound:** Beskärning av sökträd i svåra optimeringsproblem.
- [ ] **Unit Propagation:** SAT-solving teknik.
- [ ] **Operator Strength Reduction (OSR):** Kompilatoroptimering via Tarjans SCC.

---

## Installation & Körning
1. **Bygg projektet:**
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```
2. **Kör laboratoriet:**
   ```bash
   ../bin/AlgoRunner
   ```
