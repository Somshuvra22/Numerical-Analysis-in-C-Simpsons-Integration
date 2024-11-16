# 📐 Numerical Integration Calculator

A C program that performs numerical integration using Simpson's 1/3rd Rule. This program can evaluate definite integrals of mathematical expressions containing basic arithmetic operations and powers.

## ✨ Features

- 📝 Reads mathematical expressions from a file
- ➕ Supports basic arithmetic operations (+, -, *, /, ^)
- 🧮 Implements Simpson's Rule for numerical integration
- 🔤 Handles expressions with variable 'x'
- 🔄 Converts infix notation to postfix for efficient evaluation

## 🎯 Usage

1. Create a file named `functions.txt` containing your mathematical expression:
```
x^2+5*x+1
```

2. Run the compiled program:
```bash
./integration
```

3. Enter the required parameters when prompted:
   - 📉 Lower limit of integration (a)
   - 📈 Upper limit of integration (b)
   - 🔢 Number of intervals (n) - must be positive and even

### 💡 Example

```bash
Function read from file: x^2+5*x+1
Enter lower limit (a): 0
Enter upper limit (b): 1
Enter number of intervals (n): 100

The definite integral from 0.00 to 1.00 is: 3.833333
```

## 📂 Project Structure

- `main.c`: Program entry point and user interface
- `functions.c`: Implementation of core functionality
- `functions.h`: Header file with function declarations and constants
- `functions.txt`: Input file for mathematical expression

## ⚙️ Supported Operations

- ➕ Addition (+)
- ➖ Subtraction (-)
- ✖️ Multiplication (*)
- ➗ Division (/)
- 💪 Power (^)
- ❌ Variable 'x'
- 📎 Parentheses for grouping

## 🛠️ Implementation Details

The program works in several steps:
1. 📖 Reads the mathematical expression from `functions.txt`
2. 🔄 Converts the infix expression to postfix notation
3. 🧮 Evaluates the expression at different points using a stack-based calculator
4. 📊 Applies Simpson's 1/3rd Rule for numerical integration

