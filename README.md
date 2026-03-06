*This project has been created as part of the 42 curriculum by karatsar, nramalan.*

## Description

**push_swap** is a sorting algorithm project that sorts a list of random integers using a limited set of operations on two stacks. The goal is to sort the numbers in stack A in ascending order while minimizing the number of operations required.

### Project Goal

The project challenges developers to:

- Understand and implement efficient sorting algorithms
- Optimize for the minimum number of operations
- Adapt algorithm selection based on input disorder level
- Handle edge cases and validate input arguments

### Overview

The program takes a list of integers as input and outputs a sequence of operations (push, swap, rotate, reverse rotate) that sorts the numbers in ascending order. The project includes multiple strategy implementations that adapt based on the level of disorder in the input data, from simple to complex chunk-based sorting.

---

## Instructions

### Installation

Clone the repository:

```bash
git clone https://github.com/42-cursus/push_swap.git
cd push_swap
```

### Compilation

Build the main program:

```bash
make
```

Build the bonus checker program:

```bash
make bonus
```

Clean build artifacts:

```bash
make clean
```

Remove all generated files:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

### Execution

Run the push_swap program with a list of integers:

```bash
./push_swap 3 1 4 5 9 2 6
```

Or with space-separated integers in a single string:

```bash
./push_swap "3 1 4 5 9 2 6"
```

Run the push_swap program with flag and a list of integers:

```bash
./push_swap --simple "3 1 4 5 9 2 6"
```

Run the push_swap program with benchmark enabled:

```bash
./push_swap --bench "3 1 4 5 9 2 6"
```

Run the bonus checker to validate sorting operations:

```bash
echo -e "pb\npb\nrb\npb\npb\npb\npb\nrb\npb\nrb\npa\nrrb\npa\npa\npa\npa\nrb\npa\npa" | ./checker "3 1 4 5 9 2 6"
```

The checker will output:

- `OK` if the operations result in a sorted stack
- `KO` if the final stack is not sorted

---

## Algorithm Explanations & Strategies

### Overview of Strategies

The program implements an **adaptive sorting strategy** that automatically selects the most efficient algorithm based on the disorder level of the input data. The disorder is calculated as the ratio of inversions (pairs in wrong order) to total pairs.

### 1. Simple Strategy

**Disorder Level:** < 20%

**Algorithm:** Greedy rotation-based sorting

**How it works:**

- Identifies the position of the minimum element in stack A
- Rotates or reverse-rotates to bring the minimum to the top
- Pushes the minimum to stack B
- Repeats for all elements, building sorted order in stack B
- Pushes elements back to stack A in correct order

**Complexity:** `O(n²)` operations in worst case

**Use Case:** Nearly sorted or very small datasets where traversing to find the minimum is efficient

**Example Flow:**

```
Initial: [3, 1, 4]  | []
Find min (1): rotate down
Result:  [1, 3, 4]  | []
Push to B: [3, 4]   | [1]
Continue...
```

### 2. Medium Strategy

**Disorder Level:** 20% - 50%

**Algorithm:** Chunk-based sorting with optimized max extraction

**How it works:**

- Divides elements into chunks based on index ranges
- Pushes chunks from stack A to stack B in optimal order
- Implements a "move_max_to_top" function to minimize rotations when extracting the maximum
- Uses rotation and reverse rotation strategically to avoid long chains of operations
- Empties stack B by pushing the maximum element back to stack A

**Complexity:** `(O(n √ n))` operations

**Use Case:** Moderately unsorted data where chunking provides significant optimization

**Advantages over simple:**

- Reduces total operations by grouping elements
- Minimizes time spent searching for specific elements
- Better locality of reference

### 3. Complex Strategy

**Disorder Level:** > 50%

**Algorithm:** Advanced chunk-based sorting with dual-direction optimization

**How it works:**

- Implements more sophisticated chunking with optimal chunk size calculation
- Uses both forward and reverse rotations to position elements efficiently
- Applies "rotate_to_top" function that decides between:
  - Forward rotation (ra/rb)
  - Reverse rotation (rra/rrb)
  - Combined operations (rr/rrr) for parallel movement
- Sorts chunks back into stack A with greater care for operation count

**Complexity:** `O(n log(n))` on average

**Use Case:** Highly scrambled data where advanced optimization is crucial

**Optimization Techniques:**

- Parallel rotations reduce operation count
- Smart direction selection based on distance to target
- Chunk reordering for maximum efficiency

### 4. Adaptive Strategy

**Algorithm:** Hybrid dynamic selection

**How it works:**

- Calculates input disorder percentage
- Selects appropriate strategy:
  - Simple if disorder < 20%
  - Medium if 20% ≤ disorder < 50%
  - Complex if disorder ≥ 50%
- Automatically optimizes based on actual input characteristics

**Advantage:** Automatic optimization without user intervention

---

## Stack Operations Reference

All sorting operations work with two stacks (A and B):

| Operation    | Code  | Description                                      |
| ------------ | ----- | ------------------------------------------------ |
| Swap A       | `sa`  | Swap the first 2 elements of stack A             |
| Swap B       | `sb`  | Swap the first 2 elements of stack B             |
| Swap Both    | `ss`  | Execute `sa` and `sb` simultaneously             |
| Push A       | `pa`  | Move top element from B to top of A              |
| Push B       | `pb`  | Move top element from A to top of B              |
| Rotate A     | `ra`  | Shift all elements of A up, top goes to bottom   |
| Rotate B     | `rb`  | Shift all elements of B up, top goes to bottom   |
| Rotate Both  | `rr`  | Execute `ra` and `rb` simultaneously             |
| Rev Rotate A | `rra` | Shift all elements of A down, bottom goes to top |
| Rev Rotate B | `rrb` | Shift all elements of B down, bottom goes to top |
| Rev Both     | `rrr` | Execute `rra` and `rrb` simultaneously           |

---

## Features

✅ Four different sorting strategies for optimal performance  
✅ Adaptive algorithm selection based on input disorder  
✅ Input validation (range checking, duplicate detection)  
✅ Bonus checker program to validate operation sequences  
✅ Comprehensive benchmarking statistics  
✅ Support for negative integers and large ranges  
✅ Memory-safe implementation

---

## Contributors

### karatsar

- Architecture and algorithm implementation
- Stack data structure and operations
- Strategy implementations (simple, medium, complex, adaptive)
- Core sorting logic and optimization

### nramalan

- Input validation and parsing
- Bonus checker implementation
- Benchmarking and analysis tools
- Testing and documentation

---

## Resources

### Documentation & References

- [**Algorithm Complexity**](https://en.wikipedia.org/wiki/Comparison_sort) - Understanding Big O notation and sorting complexity
- [**Stack Data Structure**](<https://en.wikipedia.org/wiki/Stack_(abstract_data_type)>) - Fundamental stack concepts
- [**Sorting Algorithms**](https://en.wikipedia.org/wiki/Sorting_algorithm) - Comprehensive sorting algorithm reference
- [**42 School Curriculum**](https://42.fr) - Official 42 Network website

### Technical References

- Chunk-based sorting optimization techniques
- Rotation-based sorting strategies
- Memory-efficient stack implementation patterns

### AI Usage

**AI was utilized for:**

- **Code review and optimization:** Analyzed algorithm implementations for performance bottlenecks and suggested improvements in rotation sequences
- **Documentation:** Helped structure technical documentation and algorithm explanations
- **Testing strategy:** Suggested edge cases and test scenarios for input validation
- **README creation:** Assisted in organizing technical content and writing clear explanations

**Parts of the project assisted by AI:**

- Algorithm optimization suggestions for the complex and medium strategies
- Validation logic for edge cases in input parsing
- Documentation formatting and technical writing
- Benchmarking output formatting and statistics calculation

---

## Technical Choices & Justifications

### Why Four Strategies?

Different input patterns require different approaches. Rather than using a single algorithm for all cases, we implemented adaptive selection to:

1. Handle nearly-sorted data efficiently
2. Process moderately unsorted data optimally
3. Tackle highly scrambled data with advanced algorithms
4. Automatically select the best strategy transparently

### Why Chunk-Based Approach for Complex Cases?

Chunk-based sorting reduces unnecessary rotations by:

- Grouping related elements together
- Minimizing search distance traversals
- Allowing parallel operations on both stacks
- Scaling better with larger datasets

### Why Double-Linked Stack?

Implemented with both `next` and `prev` pointers to:

- Support reverse rotation efficiently (O(1) instead of O(n))
- Enable bidirectional traversal for optimization
- Allow smart rotation direction selection

---

## Project Status

✅ Mandatory part completed  
✅ Bonus part (checker) implemented  
✅ All strategies implemented  
✅ Input validation and edge cases handled  
✅ Benchmarking system operational

---

_Last Updated: March 2026_
