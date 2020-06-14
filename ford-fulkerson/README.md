# Ford Fulkerson
Implementation of classic ford fulkerson algorithm and using it for few applications.

## Applications
1. Find max flow in a network flow (supply chain for example)
2. Find maximum matching in a bipartite graph
3. Find min s-t cut 

## Usage
1. Run ford-fulkerson:

``` bash
$ make main
$ ./main < tests/in_test1.txt
```

2. Run bipartite matching:

``` bash
$ make main_bipartite
$ ./main_bipartite < tests/test_bp.txt
```