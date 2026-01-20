*This project has been created as part of the 42 curriculum by ynabti.*

# Push_swap

## Description

Push_swap is a sorting algorithm project where the goal is to sort a stack of integers using a limited set of operations, with the minimum number of moves possible.

The project consists of two programs:
- **push_swap**: Calculates and displays the list of instructions to sort the stack
- **checker** (bonus): Reads instructions and checks if they correctly sort the stack

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first 2 elements of stack A |
| `sb` | Swap first 2 elements of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push top of B to A |
| `pb` | Push top of A to B |
| `ra` | Rotate A (first becomes last) |
| `rb` | Rotate B (first becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate A (last becomes first) |
| `rrb` | Reverse rotate B (last becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

## Instructions

### Compilation

```bash
make        # Compile push_swap
make bonus  # Compile checker
make re     # Recompile everything
make clean  # Remove object files
make fclean # Remove object files and executables
```

### Usage

```bash
# Sort numbers and display instructions
./push_swap 4 67 3 87 23

# Verify sorting with checker
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
# Output: OK (if sorted correctly)

# Manual checker usage
./checker 3 2 1
sa
rra
# Press Ctrl+D
# Output: OK or KO
```

### Performance

| Stack size | Operations | Benchmark |
|------------|------------|-----------|
| 3 | ≤ 3 | ✅ |
| 5 | ≤ 12 | ✅ |
| 100 | < 700 | ✅ |
| 500 | < 5500 | ✅ |

## Algorithm

The sorting algorithm uses the **Longest Increasing Subsequence (LIS)** approach:

1. **Index assignment**: Map values to indices (0 to n-1)
2. **LIS detection**: Find the longest increasing subsequence in stack A
3. **Push to B**: Push all elements NOT in the LIS to stack B
4. **Cost calculation**: For each element in B, calculate the cost to insert it at the correct position in A
5. **Optimal insertion**: Insert elements back to A, always choosing the cheapest move
6. **Final alignment**: Rotate A to place the smallest element on top

## Resources

- [Push_swap tutorial - Medium](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Visualizer for push_swap](https://github.com/o-reo/push_swap_visualizer)
- [LIS Algorithm - Wikipedia](https://en.wikipedia.org/wiki/Longest_increasing_subsequence)

### AI Usage

AI (Claude) was used for:
- Code formatting to comply with 42 Norm
- Debugging and fixing norm errors
- Creating the checker bonus program structure
- Writing this README

The core sorting algorithm (LIS-based approach) was implemented independently.

