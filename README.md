# PushSwap

## Description

PushSwap is a project that consists of sorting a stack of integers using two stacks and a limited set of operations. The goal is to sort the stack in the least amount of operations.



## Project Structure
the project is divided into two programs:
### push_swap
- a program that takes a list of integers as arguments and sorts them using the following operations:


| Operation    | Description |
|--------------|-------------|
| `sa`          | Swap the first two elements of stack A |
| `sb`          | Swap the first two elements of stack B |
| `ss`          | sa and sb at the same time |
| `pa`          | Take the first element from stack B and put it on top of stack A |
| `pb`          | Take the first element from stack A and put it on top of stack B |
| `ra`          | Rotate stack A up by one |
| `rb`          | Rotate stack B up by one |
| `rr`          | ra and rb at the same time |
| `rra`          | Rotate stack A down by one |
| `rrb`          | Rotate stack B down by one |
| `rrr`          | rra and rrb at the same time |

- checker: a program that takes a list of integers as arguments and reads a list of operations from the standard input. It then applies the operations to the list of integers and checks if the list is sorted. If the list is sorted, the program prints `OK`, otherwise it prints `KO`.

## Installation

1. Clone the repository:
```bash
git clone https://github.com/abouabra/42-PushSwap.git
```
2. Change the current working directory:
```bash
cd 42-PushSwap
```
3. Compile the project:
```bash
make
```

### Note

if you want to compile the checker program, run the following command:
```bash
make bonus
```


## Usage

The program takes a list of integers as arguments and sorts them using the following operations:

To sort a list of integers, run the program with the following command:
```bash
./push_swap 4 2 1 3
```
it will output the list of operations needed to sort the list.
```bash
rra
rra
pb
rra
pa
```

to check if the list is sorted, you can use the checker program:
```bash
./push_swap 4 2 1 3 | ./checker 4 2 1 3
```
it will output `OK` if the list is sorted, otherwise it will output `KO`.


## Final Note
If you have any suggestions or improvements, feel free to open an issue or submit a pull request.
