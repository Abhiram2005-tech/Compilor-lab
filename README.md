# Compiler Lab (`Compilor-lab`)

Welcome to the **Compiler Lab** repository! This comprehensive educational project implements various phases and concepts of compiler design using C, Lex (Flex), and Yacc (Bison). It serves as a practical guide for understanding how programming languages are tokenized, parsed, and evaluated.

---

## 📚 Table of Contents

- [Overview](#overview)
- [Project Components](#project-components)
- [Features](#features)
- [Repository Structure](#repository-structure)
- [Prerequisites](#prerequisites)
- [Compilation & Execution](#compilation--execution)
- [File Descriptions](#file-descriptions)
- [Learning Outcomes](#learning-outcomes)
- [License](#license)

---

## Overview

This repository contains implementations of key compiler phases and concepts:

1. **Lexical Analysis (Tokenization)** - Converting source code into tokens
2. **Syntax Analysis (Parsing)** - Building abstract syntax trees using BNF grammars
3. **Semantic Analysis** - Validation and evaluation of expressions
4. **Finite Automata** - Converting NFA to DFA for pattern matching
5. **Recursive Descent Parsing** - Top-down parsing with predictive techniques
6. **Expression Evaluation** - Computing arithmetic expressions with proper precedence

All implementations are designed with clarity and educational value in mind, making them perfect for computer science students learning compiler construction.

---

## 🎯 Project Components

### 1. **Lexical Analysis**
- **`lex.c`** - Basic lexical analyzer that tokenizes input
- **`lex.yy.c`** - Flex-generated scanner for token recognition

### 2. **Arithmetic Expression Parser & Evaluator**
- **`exp6.l`** - Lex specification for tokenizing arithmetic expressions (integers and operators)
- **`exp6.y`** - Yacc specification with grammar rules and evaluation logic
  - Handles: `+`, `-`, `*`, `/` operators
  - Supports parentheses for grouping
  - Unary minus operator
  - Operator precedence and associativity
  - Division by zero error handling

### 3. **Calculator with Floating-Point Support**
- **`calc.c`** - Lex-based calculator for evaluating arithmetic expressions
  - Supports: `+`, `-`, `*`, `/`, `^` (power) operators
  - Handles both integer and floating-point numbers
  - Interactive continuous evaluation

### 4. **Finite Automata (NFA to DFA Conversion)**
- **`exp7.c`** - Complete implementation of NFA to DFA conversion
  - Converts Non-deterministic Finite Automata to Deterministic Finite Automata
  - Handles epsilon (ε) transitions
  - Generates equivalent DFA states and transitions
  - Essential for lexical analyzer pattern matching

### 5. **Syntax Analysis & Parsing**
- **`exp8.c`** - Recursive Descent Parser for arithmetic expressions
  - Implements left-recursive grammar elimination
  - Uses predictive parsing techniques
  - Validates expression syntax
  - Implements context-free grammar (CFG) parsing

### 6. **Additional Files**
- **`exp9.c`** - Advanced parsing or semantic analysis implementation
- **`digit.i`, `count.i`** - Intermediate files (possibly generated or temporary)
- **`LICENSE`** - MIT License for open-source usage

---

## 🚀 Features

✅ **Educational Focus** - Clean, well-commented code ideal for learning compiler design
✅ **Multiple Phases** - Covers lexical, syntactic, and semantic analysis
✅ **Practical Examples** - Expression parsing and evaluation with real-world applications
✅ **Finite Automata** - Complete NFA to DFA conversion algorithm
✅ **Error Handling** - Division by zero detection, invalid expression rejection
✅ **Standard Tools** - Uses industry-standard Lex and Yacc tools
✅ **Open Source** - MIT licensed for educational and commercial use

---

## 📁 Repository Structure

```
Compilor-lab/
├── README.md              # Project documentation (this file)
├── LICENSE                # MIT License
├── .gitignore             # Git ignore rules
│
├── lex.c                  # Basic lexical analyzer
├── lex.yy.c               # Flex-generated scanner
│
├── calc.c                 # Calculator with operators (+, -, *, /, ^)
│
├── exp6.l                 # Lex spec for arithmetic expressions
├── exp6.y                 # Yacc spec with grammar and evaluation
│
├── exp7.c                 # NFA to DFA conversion
│
├── exp8.c                 # Recursive descent parser
├── exp9.c                 # Advanced semantic analysis
│
├── digit.i                # Intermediate file
└── count.i                # Intermediate file
```

---

## Prerequisites

To compile and run the projects, you need:

- **C Compiler**: GCC or Clang
- **Flex (Lexical Analyzer)**: `sudo apt install flex` (Linux) or `brew install flex` (macOS)
- **Bison (Parser Generator)**: `sudo apt install bison` (Linux) or `brew install bison` (macOS)
- **Build Tools**: Make (optional, for automation)

### Installation

**Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install gcc flex bison
```

**macOS:**
```bash
brew install gcc flex bison
```

**Windows:**
Download and install MinGW-w64 with Flex and Bison support, or use WSL (Windows Subsystem for Linux).

---

## Compilation & Execution

### 1. Basic Lexical Analyzer (`lex.c`)

```bash
# Compile
gcc lex.c -o lex

# Run
./lex
```

### 2. Calculator with Floating-Point (`calc.c`)

```bash
# Compile
gcc calc.c -o calc

# Run
./calc

# Example Usage:
# Enter the equation
# 5+3
# Result is 8.000000
```

### 3. Arithmetic Expression Parser (`exp6.l` & `exp6.y`)

```bash
# Generate scanner from Lex specification
flex exp6.l

# Generate parser from Yacc specification
bison -d exp6.y

# Compile all files together
gcc exp6.y lex.yy.c -o expr_parser -lfl

# Run
./expr_parser

# Example Usage:
# Enter an arithmetic expression: 2 + 3 * 4
# Result: 14
```

### 4. NFA to DFA Conversion (`exp7.c`)

```bash
# Compile
gcc exp7.c -o nfa_to_dfa

# Run
./nfa_to_dfa

# Interactive Input:
# Enter the number of alphabets: 2
# Enter alphabets: a b
# Enter the number of states: 3
# ... (follow prompts)
```

### 5. Recursive Descent Parser (`exp8.c`)

```bash
# Compile
gcc exp8.c -o parser

# Run
./parser

# Example Usage:
# Enter an arithmetic expression: (2+3)*4
# Accepted...!!!
```

---

## File Descriptions

| File | Purpose | Language | Concepts Covered |
|------|---------|----------|------------------|
| `lex.c` | Basic tokenizer | C | Lexical analysis, token patterns |
| `calc.c` | Interactive calculator | Lex/C | Operator handling, floating-point, token actions |
| `exp6.l` | Scanner specification | Lex | Token patterns, regex, semantic actions |
| `exp6.y` | Parser specification | Yacc | Grammar rules, precedence, evaluation |
| `exp7.c` | NFA to DFA converter | C | Finite automata, subset construction, state management |
| `exp8.c` | Recursive descent parser | C | Predictive parsing, grammar elimination, parsing tables |
| `exp9.c` | Advanced parser/analyzer | C | Semantic analysis, advanced parsing techniques |

---

## Learning Outcomes

After studying this repository, you will understand:

1. ✅ **Lexical Analysis**: How source code is tokenized into meaningful units
2. ✅ **Syntax Analysis**: How BNF grammars define language syntax
3. ✅ **Parsing Techniques**: 
   - Top-down (Recursive Descent) parsing
   - Yacc-based parsing with automatic parse table generation
4. ✅ **Operator Precedence & Associativity**: How to handle complex expressions correctly
5. ✅ **Finite Automata**: NFA to DFA conversion algorithm and applications
6. ✅ **Semantic Analysis**: Validating and evaluating parsed expressions
7. ✅ **Error Handling**: Detecting and reporting syntax/semantic errors
8. ✅ **Tools & Infrastructure**: Using industry-standard compiler-building tools (Lex/Flex, Yacc/Bison)

---

## Example Workflows

### Running the Expression Parser

```bash
$ flex exp6.l
$ bison -d exp6.y
$ gcc exp6.tab.c lex.yy.c -o expr -lfl
$ ./expr
Enter an arithmetic expression: 10 + 20 * 2 - 5
Result: 45
```

### Testing NFA to DFA Conversion

Input an NFA and the program will output the equivalent DFA with all state transitions.

### Validating Expressions with Recursive Descent Parser

```bash
$ gcc exp8.c -o parser
$ ./parser
Enter an arithmetic expression: (a+b)*c
Accepted...!!!
```

---

## Key Concepts Implemented

- **Tokenization**: Breaking input into recognizable tokens
- **Parsing**: Building syntax trees from token streams
- **Grammar Rules**: Defining language syntax using context-free grammars
- **Operator Precedence**: Ensuring correct evaluation order (*, / before +, -)
- **Associativity**: Handling left/right associative operators
- **Finite Automata**: Converting NFAs to DFAs for efficient pattern matching
- **Error Detection**: Catching division by zero, invalid expressions
- **Recursive Functions**: Top-down parsing using recursive non-terminals

---

## Troubleshooting

**Issue**: `flex: command not found`
- **Solution**: Install Flex using your package manager (apt, brew, etc.)

**Issue**: `bison: command not found`
- **Solution**: Install Bison using your package manager

**Issue**: Compilation errors with Yacc files
- **Solution**: Ensure you're using both `flex` and `bison` to generate `lex.yy.c` and `y.tab.c`

**Issue**: Division by zero not handled
- **Solution**: Check that error handling code is present in `exp6.y` (it should be in the `/` rule)

---

## Contributing

This is an educational project. Contributions, improvements, and suggestions are welcome! Feel free to:
- Add more compiler phases (intermediate code generation, optimization, code generation)
- Improve documentation with diagrams
- Add more test cases
- Enhance error messages

---

## License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

**Copyright © 2026 Abhiram2005-tech**

---

## References

- Dragon Book: "Compilers: Principles, Techniques, and Tools" by Aho, Lam, Sethi, and Ullman
- [Flex Manual](https://westes.github.io/flex/manual/)
- [Bison Manual](https://www.gnu.org/software/bison/manual/)
- [Introduction to Compiler Design](https://www.youtube.com/playlist?list=PL_d9iy2PN9dqIxWn_4DkuKJlslJzM5aZA)

---

**Happy Learning! 🚀**
