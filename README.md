# 🌳 Directory Tree Explorer

A lightweight command-line utility written in **C** that recursively explores directories and displays their contents in a clean, hierarchical tree-like structure.

Directory Tree Explorer provides a simple way to visualize the organization of files and folders within a directory, right from your terminal. Directories are highlighted in **blue** to make navigation and readability easier.

---

## ✨ Features

- **Recursive Directory Traversal** – Automatically explores nested directories and their contents.
- **Tree-like Output** – Displays files and directories with indentation to represent their hierarchy.
- **Color-Coded Directories** – Highlights directory names in blue using ANSI escape sequences.
- **Custom Starting Path** – Accepts a directory path as a command-line argument.
- **Default Current Directory** – Uses the current working directory when no path is provided.
- **Basic Error Handling** – Reports directory access errors, file metadata errors, and paths that exceed the supported buffer size.
- **Lightweight & Dependency-Free** – Built using standard C and POSIX system interfaces.

---

## 📸 Example Output

Consider the following directory structure:

```text
my_project/
├── src/
│   ├── main.c
│   ├── utils.c
│   └── utils.h
├── include/
│   └── config.h
├── tests/
│   └── test.c
├── README.md
└── Makefile
```

Running the program produces output similar to:

```text
path my_project
src
  main.c
  utils.c
  utils.h
include
  config.h
tests
  test.c
README.md
Makefile
```

*Note: Directory names are displayed in blue in terminals that support ANSI color codes.*

---

## 🛠️ Technologies & Concepts

This project is built with C and uses several system-level libraries and concepts:

| Library | Purpose |
|---|---|
| `stdio.h` | Terminal output and error reporting |
| `dirent.h` | Reading directory entries |
| `string.h` | Comparing directory entry names |
| `sys/stat.h` | Retrieving file metadata and identifying directories |
| `unistd.h` | POSIX system interface |

### Core Concepts

- Recursive functions
- Directory handling (`opendir`, `readdir`, `closedir`)
- File metadata (`stat`)
- String manipulation
- Command-line arguments
- ANSI escape sequences
- Buffer safety with `snprintf`

---

## 🚀 Getting Started

### Prerequisites

You need:
- A C compiler such as GCC or Clang.
- A Unix-like operating system (Linux, macOS, or another POSIX-compatible environment).
- A terminal that supports ANSI color codes for colored directory names.

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/directory-tree-explorer.git
```

### 2. Navigate to the Project

```bash
cd directory-tree-explorer
```

### 3. Compile the Program

Using GCC:

```bash
gcc -Wall -Wextra -std=c11 main.c -o tree
```

### 4. Run the Program

To explore the current working directory:

```bash
./tree
```

To explore a specific directory:

```bash
./tree /path/to/directory
```

---

## 💻 Usage

The program accepts an optional directory path.

```bash
./tree [directory_path]
```

| Command | Description |
|---|---|
| `./tree` | Lists the current working directory recursively |
| `./tree .` | Explicitly lists the current directory |
| `./tree /home/user` | Explores the specified directory |
| `./tree ./src` | Explores the `src` directory |

---

## ⚙️ How It Works

The program is organized around two main functions:

### 1. `print_file()`

```c
void print_file(const char *name, int is_dir, int indent);
```

Responsible for displaying each file or directory.

- Uses indentation to represent directory depth.
- Prints directories in blue.
- Prints regular files using the terminal's default text color.

### 2. `walk()`

```c
int walk(const char *path, int indent);
```

The core recursive directory traversal function.

Its workflow:

1. Opens the requested directory using `opendir()`.
2. Reads its entries using `readdir()`.
3. Skips the special entries `.` and `..`.
4. Constructs the full path of each entry using `snprintf()`.
5. Retrieves file metadata using `stat()`.
6. Determines whether the entry is a directory using `S_ISDIR()`.
7. Prints the entry with the appropriate indentation.
8. Recursively explores directories.
9. Closes the directory using `closedir()`.

### 3. `main()`

The entry point of the program.

- Checks whether a directory path was supplied through command-line arguments.
- Defaults to the current working directory (`.`) if no argument is provided.
- Starts directory traversal by calling `walk()`.

---

## 🧠 What I Learned

Building this project provided practical experience with:

- Working with directories and files in C.
- Understanding how directory entries are accessed on Unix-like systems.
- Implementing recursive algorithms.
- Managing file paths and buffers safely.
- Using system calls and POSIX interfaces.
- Improving terminal output with ANSI colors.
- Handling errors during filesystem operations.

---

## 🔮 Possible Improvements

Some ideas for future development:

- [ ] Display proper tree characters (`├──`, `└──`, `│`) instead of spaces.
- [ ] Add command-line options to control recursion depth.
- [ ] Add an option to display hidden files or exclude them.
- [ ] Implement file filtering by extension.
- [ ] Add file sizes and modification timestamps.
- [ ] Support sorting files and directories alphabetically.
- [ ] Improve symbolic link handling and prevent recursive link cycles.
- [ ] Add a Makefile for easier compilation.
- [ ] Add unit tests.

---

## 🤝 Contributing

Suggestions, bug reports, and improvements are welcome!

If you would like to contribute:

1. Fork the repository.
2. Create a new feature branch.
3. Make your changes.
4. Commit your changes.
5. Open a pull request.

---

## 📄 License

This project is open-source. Feel free to use, modify, and improve it.

---

**Built with ❤️ and C.**

*A small project exploring the fundamentals of filesystem navigation, recursion, and systems programming.*
