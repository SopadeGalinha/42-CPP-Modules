# EX00: Reverse Polish Notation (RPN) Calculator

## Introduction

Reverse Polish Notation (RPN), also known as postfix notation, is a mathematical notation in which every operator follows all of its operands. This eliminates the need for parentheses to indicate the order of operations, making the evaluation straightforward and unambiguous.

This repository contains a simple C++ implementation of an RPN calculator. The `RPN` class reads an RPN expression as input, evaluates it, and returns the result.

## How RPN Works

In RPN:
- Operands (numbers) are placed before the operators.
- The order of operations is determined solely by the position of the operators.
- Each operator acts on the most recent operands that precede it.

### Example

Consider the expression `(3 + 4) * 5`. In RPN, this is written as `3 4 + 5 *`.

Here's a step-by-step evaluation of `3 4 + 5 *`:

1. Push `3` onto the stack: Stack = `[3]`
2. Push `4` onto the stack: Stack = `[3, 4]`
3. Encounter `+` (addition):
   - Pop `3` and `4` from the stack.
   - Calculate `3 + 4 = 7`.
   - Push `7` onto the stack: Stack = `[7]`
4. Push `5` onto the stack: Stack = `[7, 5]`
5. Encounter `*` (multiplication):
   - Pop `7` and `5` from the stack.
   - Calculate `7 * 5 = 35`.
   - Push `35` onto the stack: Stack = `[35]`
6. Result: The final value on the stack is `35`, which is the result of the expression `(3 + 4) * 5`.

## Implementation Details

The C++ implementation provided uses a stack to evaluate the RPN expression:
- The `RPN` class reads the input expression, splits it into tokens, and evaluates them.
- It handles basic arithmetic operations (`+`, `-`, `*`, `/`) and checks for division by zero and malformed expressions.
- The evaluation method returns the final result of the expression.

### Example Usage

To use the RPN calculator, compile the provided C++ code and run it with an RPN expression as a command-line argument:

```bash
$ make && ./RPN "3 4 + 5 *"
Result: 35
