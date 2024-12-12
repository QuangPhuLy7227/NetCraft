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

1. Clone the Repository:
   git clone <my_netcraft_url>
   cd Netcraft

2. Build and Run the Project:
   mkdir build
   cd build
   cmake ..
   make
   ./NetCraft ../examples/myfile.netcraft
   
### Using NetCraft
Here’s an example of a .netcraft file, which defines various commands and protocol stacks:
   load_protocols;
   list_protocols;
   list_protocols_by_stack;
   stack {
       layer1: Ethernet;
       layer2: IPv4;
       layer3: TCP;
   };

Commands in .netcraft File
   load_protocols;: Loads all available networking protocols.
   list_protocols;: Lists all available protocols along with their details.
   list_protocols_by_stack;: Groups and displays protocols by stack layers.
   stack { ... };: Defines a custom stack with layers and associated protocols.

Run the Example
To run the provided example (myfile.netcraft), follow these steps:

Place the .netcraft file in the examples directory (or any directory of your choice).
Execute the following command:
   ./NetCraft ../examples/myfile.netcraft
The output will display the results of each command in the .netcraft file, including loaded protocols, listed protocols, and stack definitions.

Example Output
Running myfile.netcraft may produce output similar to the following:
   Protocols loaded successfully.

   Available Protocols:
   - Ethernet: Standard Ethernet on ::1
   - IPv4: IPv4 supported on ::1
   - IPv6: IPv6 supported on ::1
   
   Protocols by Stack:
   Layer 1 (Physical):
     - Ethernet: Standard Ethernet on ::1
   Layer 3 (Network):
     - IPv4: IPv4 supported on ::1
     - IPv6: IPv6 supported on ::1

### Contributing
We welcome contributions to NetCraft! Please fork the repository, make your changes, and submit a pull request.

### License
This project is licensed under the MIT License.
