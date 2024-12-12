#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <memory>

// Base class for AST nodes
struct ASTNode {
    virtual ~ASTNode() = default;
    virtual void execute() = 0; // Execute or interpret the node
};

// Protocol node representing a protocol definition
struct ProtocolNode : ASTNode {
    std::string name;
    std::vector<std::pair<std::string, int>> fields; // Field name and size

    void execute() override {
        // Logic to handle protocol definitions
    }
};

// Stack node representing a stack definition
struct StackNode : ASTNode {
    std::vector<std::pair<std::string, std::string>> layers; // Layer name and protocol

    void execute() override {
        // Logic to handle stack definitions
    }
};

// Root node for the entire program
struct ProgramNode : ASTNode {
    std::vector<std::unique_ptr<ASTNode>> children;

    void execute() override {
        for (const auto& child : children) {
            child->execute();
        }
    }
};

#endif // AST_H
