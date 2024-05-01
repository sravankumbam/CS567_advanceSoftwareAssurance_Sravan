#include <iostream>
#include <deepstate/DeepState.hpp>

// Binary Search Tree implementation
class BinarySearchTree {
public:
    // Define your BinarySearchTree implementation
    bool search(int val) {
        // Implement your search function here
        std::cout << "Searching for value: " << val << std::endl;
        return true; // Placeholder return value
    }
};

// Heap implementation (just a simple example)
class Heap {
public:
    // Define your Heap implementation
    int extract_max() {
        // Implement your extract_max function here
        std::cout << "Extracting max value" << std::endl;
        return 100; // Placeholder return value
    }
};

int main(int argc, char *argv[]) {
    std::cout << "Starting tests" << std::endl;

    BinarySearchTree bst;
    std::cout << "Searching for value 5 in BinarySearchTree: " << std::endl;
    bst.search(5);

    Heap heap;
    std::cout << "Extracting max value from Heap: " << std::endl;
    heap.extract_max();

    std::cout << "Finished tests" << std::endl;
    
    return 0;
}
