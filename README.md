# Singly Linked List in C

A complete implementation of a **singly linked list** in C with an interactive menu-driven interface. Supports all core operations — insertion, deletion, search, sort, and reverse.

---

## Features

| Operation | Description |
|---|---|
| Insert at Beginning | Adds a new node at the head of the list |
| Insert at End | Appends a new node at the tail |
| Insert at Position | Inserts a node at any valid position |
| Delete at Beginning | Removes the head node |
| Delete at End | Removes the last node |
| Delete at Position | Removes a node at any valid position |
| Search | Finds the position of a value in the list |
| Reverse | Reverses the order of the list in-place |
| Sort | Sorts the list in ascending order (bubble sort) |
| Display | Prints the entire list |
| Exit | Frees all allocated memory and exits |

---

## Getting Started

### Prerequisites

- GCC compiler (or any C99-compatible compiler)
- Linux / macOS / Windows (with MinGW or WSL)

### Compile

```bash
gcc Singly_Linklist.c -o Singly_Linklist
```

### Run

```bash
./Singly_Linklist
```

---

## Usage

When you run the program, you'll first be prompted to enter an initial set of values:

```
Enter the limit: 3
Enter 1 value: 10
Enter 2 value: 20
Enter 3 value: 30

    --DISPLAY--
10 -> 20 -> 30 -> NULL
```

You'll then see the interactive menu:

```
Enter 1 to insert at beginning
Enter 2 to insert at end
Enter 3 to insert at position
Enter 4 to display
Enter 5 to delete at end
Enter 6 to delete at beginning
Enter 7 to delete at position
Enter 8 to search
Enter 9 to reverse
Enter 10 to sort
Enter 11 to exit
```

---

## Project Structure

```
.
├── Singly_Linklist.c    # Main source file
└── README.md   # This file
```

---

## Implementation Details

- **Language:** C (C99)
- **Memory:** All nodes are heap-allocated using `malloc()`. Memory is fully freed on exit via `freeall()`.
- **Sort algorithm:** Selection-style bubble sort on node data (no pointer relinking)
- **Reverse:** In-place pointer reversal — O(n) time, O(1) space

---

## Known Limitations

- Single-threaded; not safe for concurrent access
- No input validation for non-integer inputs
- List is not persistent — data is lost on exit

---

## Author

Ujjawal Singh Solanki
*Data Structures Lab — Singly Linked List*
