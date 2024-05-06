#include <deepstate/DeepState.hpp>
#include "your_code_file_name.cpp"  // Include the file with your code implementation

using namespace deepstate;

TEST(BinarySearchTree, InsertionDeletion) {
    BinarySearchTree bst;

    // Insert some values into the binary search tree
    int num_insertions = DeepState_IntInRange(1, 10); // Choose a random number of insertions
    for (int i = 0; i < num_insertions; ++i) {
        int value = DeepState_Int();
        bst.insert(value);
    }

    // Perform inorder traversal and check if it doesn't crash
    bst.inorder_traversal();

    // Perform preorder traversal and check if it doesn't crash
    bst.preorder_traversal();

    // Perform postorder traversal and check if it doesn't crash
    bst.postorder_traversal();

    // Search for some random values
    int num_searches = DeepState_IntInRange(1, 5); // Choose a random number of searches
    for (int i = 0; i < num_searches; ++i) {
        int value = DeepState_Int();
        TreeNode* found_node = bst.search(value);
        ASSERT_TRUE(found_node == nullptr || found_node->value == value);
    }

    // Delete some random values
    int num_deletions = DeepState_IntInRange(1, 5); // Choose a random number of deletions
    for (int i = 0; i < num_deletions; ++i) {
        int value = DeepState_Int();
        bst.delete_node(value);
    }
}

TEST(MinHeap, BasicOperations) {
    MinHeap heap;

    // Insert some values into the heap
    int num_insertions = DeepState_IntInRange(1, 10); // Choose a random number of insertions
    for (int i = 0; i < num_insertions; ++i) {
        int value = DeepState_Int();
        heap.insert(value);
    }

    // Extract minimum value and check if it doesn't crash
    int extracted_min = heap.extract_min();

    // Perform heap merge with another heap
    MinHeap heap2;
    int num_insertions_heap2 = DeepState_IntInRange(1, 5); // Choose a random number of insertions for heap2
    for (int i = 0; i < num_insertions_heap2; ++i) {
        int value = DeepState_Int();
        heap2.insert(value);
    }
    heap.merge(heap2);
}

// Register the test cases with DeepState
REGISTER_TEST(BinarySearchTree, InsertionDeletion);
REGISTER_TEST(MinHeap, BasicOperations);

int main(int argc, char** argv) {
    DeepState_InitOptions(argc, argv);

    // Run the DeepState test
    DeepState_Run();

    return 0;
}
