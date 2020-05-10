# A-Star
## Summary
- Similary to Dijkstra's
- Modifies the priority queue (frontier nodes) to use a heuristic measurement
    - Heuristic is the ***estimated*** cost to the goal
        - There are many different types of heuristics; changes between use cases / contexts
    - Typically we sum the heuristic with the path-cost from the origin node
    - We take the frontier node with the lowest heuritic-cost-sum as the next node to expand
- **The heuristic may underestimate the cost it takes to get to the goal, but it can *never* overestimate the cost to the goal node**
    - A* cannot guarantee a correct solution if it overestimates the heuristic cost [1]
    - See references for heuristic information [1][5]


## Runtime Complexity
- Runtime for A* verymuch depends on:
    1. You graph.  Is it sparse or dense
    2. Your heuristic.  Does it accurately estimate the cost from the goal to the frontier node.
- We know that if the heuristic returns `0` for all nodes, then A* turns into Dijkstra's for the most part [1]
- **Worst Case**
    - Exponential
    - Expect something of: O(b^d) [3]
        - b := branch factor
        - d := depth of tree
    - Another notation: O(|E| + |V|) [4]
        - E := Number of edges
        - V := Number of verticies
- If the heuristic function behaves such that: `| h(n) - h*(n) | < O(log *h(n) )` Then we can expect polynomial runtime
    - h(n) := heuristic function used in the A* algorithm
    - h*(n) := perfect heuristic function (i.e. the true cost to the goal)
    - In plain English: if the error of the heuristic function is less than the log of the perfect heuristic, then we can expect polynomial runtime.[1][2][3]
- TL;DR
    - Polynomial (O(N)) when using a **very good** heuristic
    - Exponential when using a bad heuristic

## Space Complexity
- Exponential, but still depends on graph / tree stucture
- Generally bad because it stores all generated nodes in memory
- Think of it this way, for each node you expand, you add `b` nodes to memory, hence complexity of O(b^d) [1]
    - b := branching factor
    - d := depth factor
- Could use the definition `O(|E|)`, but this hides information because we need to know `|E|` vs `|V|`

## Advantages / When to use
- When you have an *admissable* heruistic (i.e. an accurate heuristic)[1][5]
- When you want optimal / best solution

## Disadvantages / When not to use
- When you heuristic is poor, your algorithm turns into Dijkstra's
- When you are limited on space

## Quick Flash Cards
- A* Worst case time complexity
    - O(b^d) or O(|E| + |V|) (exponential)
- A* Worst case space complexity
    - O(b^d) or (O|V|) (exponential)
- A* best case runtime
    - Polynomial (O(n))
- What makes A* different
    - Use of heuristic in addition to path-cost to the origin node
- What is an admissable heuristic
    - Does not overestimate (h(n) <= h*(n) ) [6]
- What is a Monotonic heuristic
    - Stronger condition than admissability
    - Says that estimate is always less-than-or-equal-to the estimated distance from any neighbor vertex to the goal, plus the cost of reaching that neighbor
    - i.e. `h(n) <= c(n, P) + h(P)` and `h(G) = 0` where h is heuristic, n is node on the graph, P is any descendant of n, G is the goal node, `c(n, P)` is the cost of reaching `P` from `N`
- What rule must heuristic functions follow for A* to work
    - The heuristic funtion must never overestimate.  It can only underestimate
- What rule must heuristic function follow for A* to be polynomial?
    - `|h(n) - h*(n)| < log(h*(n))`.  i.e. the error of the heuristic must be less than the log of the true heuristic cost

## Resources
- [1] http://ad-teaching.informatik.uni-freiburg.de/route-planning-ss2012/lecture-3.mp4 
- [2] https://stackoverflow.com/questions/11070248/a-time-complexity/ 
- [3] https://en.wikipedia.org/wiki/A*_search_algorithm
- [4] https://cs.stackexchange.com/questions/56176/a-graph-search-time-complexity
- [5] https://en.wikipedia.org/wiki/Consistent_heuristic
- [6] https://en.wikipedia.org/wiki/Admissible_heuristic