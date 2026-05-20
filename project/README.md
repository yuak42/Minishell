*This project has been created as partof the 42 curriculum by byaprak, yuak.*

# Minishell

## Description

### Goal

The main goal of this project is to create a simple shell that mimics the core behavior of `bash`.

### Brief Overview

Minishell is a simplified Unix shell implementation project designed to reproduce the essential behavior of a real shell in a controlled and educational environment.

The purpose of this project is to gain a deeper understanding of how shells work internally by implementing core components such as command parsing, process execution, pipes, environment variable handling, signal management, and input/output redirections.

Minishell reads user input, interprets commands, and executes them by interacting directly with the operating system, similarly to how a real Unix shell operates.

The project covers fundamental concepts including:

- lexical analysis (tokenization),
- parsing,
- environment variable expansion,
- pipes,
- redirections (`<`, `>`, `>>`, `<<`),
- process creation and management,
- signal handling.

It also includes the implementation of several built-in commands such as:

- `cd`
- `echo`
- `pwd`
- `export`
- `unset`
- `env`
- `exit`

## Instruction

### Compilation

```sh
make
```

### Installation

This project requires the GNU Readline library.
If it is not installed on your system, you can install it using:

```sh
sudo apt install libreadline-dev
```

### Execution

```sh
./minishell
```


## Resources

### References

- Bash Reference Manual, https://www.gnu.org/software/bash/manual/bash.html
- Linux Man Pages, https://man7.org/linux/man-pages/

### Declaration of AI Use 

We acknowledge the use of ChatGPT (https://chatgpt.com/), NotebookLM (https://notebooklm.google/), Claude (https://claude.ai/) for:

- assisting with debugging,
- analyzing bash behavior,
- brainstorming implementation ideas,
- refining parser algorithms,
- researching shell behavior and Unix concepts.
