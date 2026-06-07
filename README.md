# C++ Algorithm Laboratory

Detta projekt är en praktisk resa genom algoritmer och datastrukturer, implementerade från grunden i modern C++. Syftet är dubbelt: att bemästra fundamentala algoritmer och att lära sig avancerad C++-utveckling på macOS med ett professionellt arbetsflöde.

## Projektmål
- Implementera klassiska algoritmer (Gale-Shapley, BFS, DFS, Dynamisk Programmering, etc.).
- Lära sig modern C++ (C++17/20) och minneshantering.
- Använda industristandardverktyg som **CMake** och **Git**.
- Analysera tidskomplexitet genom benchmarking (tidtagning) på stora datamängder.

## Struktur
Projektet är organiserat för att vara modulärt och lätt att utöka:
- `src/` - Källkod uppdelad i kategorier (t.ex. `stabil_matching`, `graphs`).
- `data/` - Testfiler och generatorer för att testa algoritmer med stor indata.
- `bin/` - Här hamnar de färdiga körbara filerna (ignorerad av Git).
- `build/` - Temporära filer för kompilering (ignorerad av Git).

## Installation & Kompilering (macOS)
Projektet använder CMake för att hantera byggprocessen.

1. **Förutsättningar:** Se till att du har `cmake` och en C++-kompilator (t.ex. `gcc-15` via Homebrew eller `clang`).
2. **Konfigurera:** 
   ```bash
   mkdir build && cd build
   cmake ..
   ```
3. **Bygg:**
   ```bash
   make
   ```
4. **Kör:**
   ```bash
   ../bin/AlgoRunner
   ```

## Implementerade Algoritmer

### Introduktion och Matchning
- [x] **Gale-Shapley:** Stabil matchning mellan två mängder. Inkluderar stöd för stora datamängder och tidtagning.

### Grafsökning (Pågående...)
- [x] **BFS (Breadth-First Search):** Hitta kortaste vägen i oviktade grafer.
- [x] **DFS (Depth-First Search):** Utforska grafer på djupet.
- [ ] **Tarjans algoritm:** Hitta starkt sammankopplade komponenter.

### Dynamisk Programmering 
- [ ] Knapsack Problem
- [ ] Sequence Alignment
- [ ] Bellman-Ford
### Greedy Algorythm
- [x] Interval Scheduling
*(Fyll på listan allt eftersom vi bygger dem!)*

## Benchmarking
Varje algoritm körs med inbyggd tidtagning (`std::chrono`) för att verifiera dess teoretiska tidskomplexitet mot verklig prestanda.
