# Ford Fulkerson
Implementation of classic ford fulkerson algorithm and using it on few applications.

## Applications
1. Find max flow in a network flow (supply chain for example)
2. Find maximum matching in a bipartite graph
3. Find min s-t cut 

## Usage
1. Run ford-fulkerson:

``` bash
g++ main.cpp ff.cpp
./a.out < tests/test.txt
```

2. Run bipartite matching:

``` bash
g++ main_bipartite.cpp ff.cpp bipartite.cpp
./a.out < tests/test_bp.txt
```