# NetCraft

NetCraft is a networking protocol analysis and configuration tool. It allows users to load, list, and define networking protocols using a custom `.netcraft` file format. The tool provides detailed protocol information and organizes protocols into stack layers for easy comprehension.

---

## Features

- Load available networking protocols dynamically.
- List all protocols along with their details.
- Group protocols by stack layer.
- Define custom stacks and layers using a `.netcraft` file.

---

## Getting Started

### Prerequisites

Before building and running NetCraft, ensure you have the following installed:

- **CMake**: Version 3.10 or higher
- **Flex**: Lexer generator
- **Bison**: Parser generator
- **Boost Libraries**: Required components include `system`, `filesystem`, and `regex`
- **C++17**: Compiler with C++17 support

---

### Build the Project

1. **Clone the Repository**:
   ```bash
   git clone <repository-url>
   cd NetCraft
