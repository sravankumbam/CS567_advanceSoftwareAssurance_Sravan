#include "binary_search_tree.hpp"

using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

void BinarySearchTree::insert(int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
    } else {
        _insert_recursively(root, value);
    }
}

void BinarySearchTree::inorder_traversal() {
    _inorder_traversal(root);
    cout << endl;
}

void BinarySearchTree::preorder_traversal() {
    _preorder_traversal(root);
    cout << endl;
}

void BinarySearchTree::postorder_traversal() {
    _postorder_traversal(root);
    cout << endl;
}

TreeNode* BinarySearchTree::search(int value) {
    return _search_recursively(root, value);
}

int BinarySearchTree::find_min() {
    TreeNode* current = root;
    while (current->left) {
        current = current->left;
    }
    return current->value;
}

int BinarySearchTree::find_max() {
    TreeNode* current = root;
    while (current->right) {
        current = current->right;
    }
    return current->value;
}

void BinarySearchTree::delete_node(int value) {
    root = _delete_recursively(root, value);
}

void BinarySearchTree::_insert_recursively(TreeNode* node, int value) {
    if (value < node->value) {
        if (node->left == nullptr) {
            node->left = new TreeNode(value);
        } else {
            _insert_recursively(node->left, value);
        }
    } else if (value > node->value) {
        if (node->right == nullptr) {
            node->right = new TreeNode(value);
        } else {
            _insert_recursively(node->right, value);
        }
    }
}

void BinarySearchTree::_inorder_traversal(TreeNode* node) {
    if (node) {
        _inorder_traversal(node->left);
        cout << node->value << " ";
        _inorder_traversal(node->right);
    }
}

void BinarySearchTree::_preorder_traversal(TreeNode* node) {
    if (node) {
        cout << node->value << " ";
        _preorder_traversal(node->left);
        _preorder_traversal(node->right);
    }
}

void BinarySearchTree::_postorder_traversal(TreeNode* node) {
    if (node) {
        _postorder_traversal(node->left);
        _postorder_traversal(node->right);
        cout << node->value << " ";
    }
}

TreeNode* BinarySearchTree::_search_recursively(TreeNode* node, int value) {
    if (node == nullptr || node->value == value) {
        return node;
    }
    if (value < node->value) {
        return _search_recursively(node->left, value);
    }
    return _search_recursively(node->right, value);
}

TreeNode* BinarySearchTree::_find_min_node(TreeNode* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

TreeNode* BinarySearchTree::_delete_recursively(TreeNode* node, int value) {
    if (node == nullptr) {
        return node;
    }

    if (value < node->value) {
        node->left = _delete_recursively(node->left, value);
    } else if (value > node->value) {
        node->right = _delete_recursively(node->right, value);
    } else {
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        TreeNode* min_node = _find_min_node(node->right);
        node->value = min_node->value;
        node->right = _delete_recursively(node->right, min_node->value);
    }
    return node;
}

void MinHeap::insert(int value) {
    heap.push_back(value);
    _heapify_up(heap.size() - 1);
}

int MinHeap::extract_min() {
    if (heap.empty()) {
        return -1;
    }
    int min_value = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    _heapify_down(0);
    return min_value;
}

void MinHeap::merge(MinHeap& other_heap) {
    heap.insert(heap.end(), other_heap.heap.begin(), other_heap.heap.end());
    _heapify_up(heap.size() - 1);
}

vector<int> MinHeap::get_heap() {
    return heap;
}

void MinHeap::_heapify_up(int index) {
    while (index > 0) {
        int parent_index = (index - 1) / 2;
        if (heap[index] < heap[parent_index]) {
            swap(heap[index], heap[parent_index]);
            index = parent_index;
        } else {
            break;
        }
    }
}

void MinHeap::_heapify_down(int index) {
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;
    int smallest = index;

    if (left_child_index < heap.size() && heap[left_child_index] < heap[smallest]) {
        smallest = left_child_index;
    }
    if (right_child_index < heap.size() && heap[right_child_index] < heap[smallest]) {
        smallest = right_child_index;
    }

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        _heapify_down(smallest);
    }
}
