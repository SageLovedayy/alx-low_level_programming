# README
## Automated C Compilation and Static Library Generator

**Script Overview:**

The provided Bash script automates the compilation of C source files and the creation of a static library. It streamlines the process by compiling all `.c` files in the current directory and archiving them into a static library named `liball.a`.

### Script Workflow:

1. **Compile C Source Files:**
   The script compiles all `.c` files using GCC with strict warning flags (`-Wall -Werror -Wextra -pedantic`) and sets the C standard to GNU89 (`-std=gnu89`). The compiled object files (`.o`) are generated for each source file.

2. **Create Static Library:**
   The script then creates a static library `liball.a` by archiving all compiled object files using the `ar` command. The library is created with an index, allowing for efficient linkage during program compilation.

### Usage:

1. Ensure all your C source files (`.c`) are present in the same directory as the script.
2. Grant execute permissions to the script (`chmod +x create_static_lib.sh`).
3. Run the script (`./create_static_lib.sh`) to compile the source files and create the static library.

This script simplifies the compilation and library creation process, enabling seamless development and organization of C projects.

