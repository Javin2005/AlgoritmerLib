cmake_minimum_required(VERSION 3.10)
project(AlgoMaster)

# Använd C++ 17 eller senare
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Sökvägar för att inkludera filer
include_directories(src)

# Definiera källfiler (vi fyller på denna lista efterhand)
set(SOURCES 
    src/main.cpp 
    src/utils/generate_data.cpp
    src/utils/load_data.cpp
    src/stabil_matching/gale_shapley.cpp
    src/graphs/bfs.cpp
    src/graphs/dfs.cpp
    src/greedy/interval_scheduling.cpp
    src/greedy/dijkstras.cpp
    src/greedy/kruskals.cpp
    src/divide_and_conquer/mergesort.cpp
    src/divide_and_conquer/closest_point.cpp
    src/runner/run_algorithm.cpp
)

# Skapa den körbara filen
add_executable(AlgoRunner ${SOURCES})

# Lägg den färdiga filen i bin-mappen
set_target_properties(AlgoRunner PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
