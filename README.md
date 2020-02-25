# Strongly Connected Components
Two different implementations of Strongly Connected Components (SCC)

## Kosaraju

### Results for 3 datasets
Dataset       |   Time(s)   |   Number of vertices  |   Number of edges
--------------|-------------|-----------------------|-----------------------
google plus   |   160       |   107614              |   30494866
twitter       |   8         |   81306               |   2420766
slashdot      |   1         |   82168               |   948464
pokec         |   163       |   1632803             |   30622564

## Divide and Conquer Strong Components (DCSC)

### Resutls for 3 datasets
Dataset       |   Time(s)   |   Number of vertices  |   Number of edges
--------------|-------------|-----------------------|-----------------------
google plus   |   228       |   107614              |   30494866
twitter       |   18        |   81306               |   2420766
slashdot      |   9         |   82168               |   948464

## Issues 
- Both algorithms were not running for large graphs even in the server system
Fix:
The fix was to increase stack space allocated to the C++ program.
By default the OS allocates around 8MB space. However, for very large graphs the stack space used is high because of the dfs call
