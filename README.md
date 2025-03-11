# TeoToivoShell (ttsh)

## Overview

TeoToivoShell (ttsh) is a simple, custom-built shell program written in C. It provides a command-line interface for interacting with the operating system. This project is intended for educational purposes and as a starting point for learning shell development.

## Features

<<<<<<< HEAD
* None

 
## Getting Started
 
 ### Prerequisites
 
  *  A C compiler (e.g., GCC, Clang)
  *  Make (or a compatible build tool)
  *  Bear (optional but needed for build_commands.json)
 

 ### Building
 
  1.  **Clone the repository:**
  ```bash
  git clone git@github.com:teotoivo/ttsh.git
  cd ttsh
  ```

  2.  **Build the executable:**

   ```bash
   bear -- make build
   ```
   the executable (*ttsh*) is found in *bin* directory


  ### Running
   ```bash
   make run
   ```


  ### Usage
* **Basic Shell Functionality:**  
    Execute commands using a custom command-line interpreter.
  
* **Built-in Commands:**  
    Supports built-in commands (e.g., `exit`, `cd`, `help`) alongside external programs.

* **Line Continuation & Logical Operators:**  
    Supports backslash (`\`) line continuations as well as logical operators (`&&`, `||`) for command chaining.


## Getting Started

### Prerequisites

* A C compiler (e.g., GCC, Clang)
* CMake (version 3.15 or higher)
* Make (or a compatible build tool)

### Building

1. **Clone the repository:**

```bash
git clone git@github.com:teotoivo/ttsh.git
cd ttsh
```

2. Build the executable
```bash
make build
```
The compiled executable (`tsh`) will be located in the bin directory

### Running the Shell

start the shell with either of these methods:
* via Make:
```bash
make run # Or execute the binary
```
* Direct Execution
```bash
cd bin
./ttsh
```
    
You will see the `ttsh >` prompt where you can start entering commands.

### Usage Examples

* Changing Directory:
```bash
ttsh > cd /path/to/directory
```
* Listing files:
```bash
ttsh > ls -la
```
* Chaining Commands:
```bash
ttsh > mkdir new_filder && cd new_folder
```
* Line Continuation:
```bash
ttsh > echo "This is a long command \
that spans multiple lines"
```

## Project Structure

```text
.
├── bin
│   └── ttsh               # The compiled shell executable
├── build                  # Build directory (generated by CMake)
├── CMakeLists.txt         # CMake build configuration file
├── include                # Header files
│   ├── ...
└── src                    # Source code files
│   ├── main.c
│   ├── ...
├── LICENSE.md             # Project license (MIT)
├── makefile               # Makefile for automation
└── README.md              # This file (project overview and instructions)
```
