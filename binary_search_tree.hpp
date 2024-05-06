#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include <vector>

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    void _insert_recursively(TreeNode* node, int value);
    void _inorder_traversal(TreeNode* node);
    void _preorder_traversal(TreeNode* node);
    void _postorder_traversal(TreeNode* node);
    TreeNode* _search_recursively(TreeNode* node, int value);
    TreeNode* _find_min_node(TreeNode* node);
    TreeNode* _delete_recursively(TreeNode* node, int value);

public:
    BinarySearchTree();
    void insert(int value);
    void inorder_traversal();
    void preorder_traversal();
    void postorder_traversal();
    TreeNode* search(int value);
    int find_min();
    int find_max();
    void delete_node(int value);
};

class MinHeap {
private:
    std::vector<int> heap;

    void _heapify_up(int index);
    void _heapify_down(int index);

public:
    void insert(int value);
    int extract_min();
    void merge(MinHeap& other_heap);
    std::vector<int> get_heap();
};

#endif // BINARY_SEARCH_TREE_HPP
