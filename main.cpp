#include <iostream>
#include "binary_search_tree.hpp"

using namespace std;

int main() {
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    cout << "Inorder traversal:" << endl;
    bst.inorder_traversal();
    cout << "Preorder traversal:" << endl;
    bst.preorder_traversal();
    cout << "Postorder traversal:" << endl;
    bst.postorder_traversal();
    cout << "Minimum: " << bst.find_min() << endl;
    cout << "Maximum: " << bst.find_max() << endl;
    bst.delete_node(5);
    cout << "Inorder traversal after deletion of 5:" << endl;
    bst.inorder_traversal();

    MinHeap heap;
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(3);
    heap.insert(7);
    cout << "Heap elements:" << endl;
    vector<int> heap_elements = heap.get_heap();
    for (int value : heap_elements) {
        cout << value << " ";
    }
    cout << endl;
    cout << "Extracted min value from heap: " << heap.extract_min() << endl;

    MinHeap heap2;
    heap2.insert(20);
    heap2.insert(8);
    heap2.insert(12);
    heap.merge(heap2);
    cout << "Heap elements after";
    vector<int> merged_heap_elements = heap.get_heap();
    cout << "Heap elements after merging with another heap:" << endl;
    for (int value : merged_heap_elements) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
