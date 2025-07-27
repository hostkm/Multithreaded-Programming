# Multithreaded-Programming

This repository contains the implementation of **matrix multiplication** using **multithreading** in both C (Pthread API) and Java (Thread class). This project was developed as part of **Lab 2** for the **Operating Systems course (EEX5335)** at the **Open University of Sri Lanka**.

## 📌 Objective

To understand and apply the concepts of:
- ✅ **Multithreaded Programming** using Pthread API (C/C++) and Java threads
- ✅ **Thread Management** - creating and managing threads in both environments  
- ✅ **Concurrency** - exploring parallel execution and performance improvements
- ✅ **API Comparison** - comparing Pthread and Java threading approaches

## 📁 Project Structure

```
📦 multithreaded-matrix-multiplication
├── 📄 MatrixMultiplication.c        # C implementation using Pthreads
├── 📄 JavaThread.java               # Java implementation using Thread class
└── 📄 README.md                     # This file
```

## 🔧 Tools and Environment

- **Operating System:** Ubuntu on WSL(Use any linux environmet)
- **C Compiler:** GCC with Pthread support
- **Java Version:** OpenJDK 8 or higher
- **Editor:** VS Code/Note pad

## 🚀 How to Compile and Run

### 🖥️ For C Program (Pthread Implementation)

**Prerequisites:**
- GCC compiler with pthread library support
- Linux/Unix environment (or WSL on Windows)

**Compilation:**
```bash
gcc MatrixMultiplication.c -o matrix_pthread -lpthread
```

**Execution:**
```bash
./matrix_pthread
```

### ☕ For Java Program (Java Thread Implementation)

**Prerequisites:**
- Java Development Kit (JDK 8 or higher)

**Compilation:**
```bash
javac JavaThread.java
```

**Execution:**
```bash
java JavaThread
```

## 💡 Implementation Details

### Matrix Configuration
- **Matrix Size:** 3x3 (hardcoded for demonstration)
- **Threading Strategy:** One thread per row
- **Input Matrices:** Predefined for testing purposes

### Sample Matrices Used:
```
Matrix A:           Matrix B:
[2, 4, 6]          [1, 2, 3]
[1, 2, 3]          [2, 4, 6]
[3, 6, 9]          [3, 6, 9]
```

## 📊 Expected Output

Both implementations should produce the same result:
```
Result Matrix C:
34 68 102
17 34 51
51 102 153
```

## 🧵 Threading Approach

### C (Pthread) Implementation:
- Uses `pthread_create()` to spawn threads
- Each thread calculates one row of the result matrix
- Uses `pthread_join()` to wait for all threads to complete
- Manual memory management and argument passing via pointers

### Java Implementation:
- Extends `Thread` class with custom `MultiplyThread`
- Each thread instance handles one row calculation
- Uses `start()` and `join()` methods for thread lifecycle
- Automatic memory management through JVM

## 🔍 Key Learning Outcomes

### 1. Multithreaded Programming
- Understanding parallel task division
- Implementing concurrent execution strategies
- Managing shared resources safely

### 2. Thread Management  
- Thread creation and lifecycle management
- Proper synchronization using join operations
- Resource allocation and cleanup

### 3. Concurrency
- Parallel execution benefits and challenges
- Performance improvements through parallelization
- Avoiding race conditions and data conflicts

### 4. API Comparison
| Aspect | Pthread (C) | Java Threads |
|--------|-------------|--------------|
| **Syntax** | Complex, procedural | Simple, object-oriented |
| **Memory Management** | Manual | Automatic (GC) |
| **Error Handling** | Return codes | Exceptions |
| **Portability** | Unix-like systems | Cross-platform |
| **Performance** | Slightly faster | Good performance |
| **Learning Curve** | Steeper | Gentler |

## 🔧 Assumptions Made

1. **Matrix Size:** Fixed 3x3 for simplicity and testing
2. **Input Data:** Hardcoded matrices for consistent testing
3. **Threading Model:** One thread per row approach
4. **Error Handling:** Minimal error checking for clarity
5. **Synchronization:** No complex synchronization needed due to non-overlapping work

## 📈 Performance Considerations

- **Small Matrices:** Threading overhead may exceed benefits
- **Large Matrices:** Significant performance improvements expected
- **Thread Count:** Optimal performance typically with threads ≤ CPU cores
- **Memory Usage:** Java has higher memory overhead than C

## 🐛 Known Limitations

- Fixed matrix size (3x3)
- No input validation
- Limited error handling
- No dynamic matrix size support
- Basic threading model (room for optimization)

## 🔮 Future Enhancements

- [ ] Dynamic matrix size input
- [ ] Performance benchmarking tools
- [ ] Advanced threading strategies (thread pools)
- [ ] CUDA/GPU implementation comparison
- [ ] Memory usage optimization
- [ ] Error handling and input validation


## 📚 References

1. Silberschatz, A., Galvin, P. B., & Gagne, G. (2008). *Operating System Concepts* (8th Edition). Chapter 4.
2. POSIX Threads Programming. Lawrence Livermore National Laboratory.
3. Oracle Java Documentation - Concurrency Tutorial.
4. Advanced Programming in the UNIX Environment by W. Richard Stevens.
---

**Note:** This implementation was developed for educational purposes as part of the Operating Systems course curriculum. The code demonstrates fundamental concepts of multithreaded programming and should be used as a learning reference.

## 🏃‍♂️ Quick Start Guide

1. **Clone the repository:**
   ```bash
   git clone [your-repository-url]
   cd multithreaded-matrix-multiplication
   ```

2. **Run C implementation:**
   ```bash
   gcc MatrixMultiplication.c -o matrix_pthread -lpthread
   ./matrix_pthread
   ```

3. **Run Java implementation:**
   ```bash
   javac JavaThread.java
   java JavaThread
   ```

4. **Compare outputs** and observe the multithreading concepts in action!

---

## 👤 Author Information
**Kasun Mahela**
Undergraduate | Electrical & Computer Engineering
The Open University of Sri Lanka

📧 Feel free to raise an issue or pull request if you face any problem running the code.
...**Kasun Mahela**
Undergraduate | Electrical & Computer Engineering
The Open University of Sri Lanka

📧 Feel free to raise an issue or pull request if you face any problem running the code.
...

*This project demonstrates the power of multithreaded programming in improving computational efficiency through parallel processing techniques.*
