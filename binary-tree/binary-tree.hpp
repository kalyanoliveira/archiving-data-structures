#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "templated-list.hpp"

template <typename T>
class BinaryTree {
    private:
        struct Node {
            T value;
            Node *parent;
            Node* right;
            Node* left;
        };

    public:
        BinaryTree();

        bool empty() const;
        int size() const;

        class Position {
            friend class BinaryTree;

            public:
                Position(Node* node);

                T& operator*() const;

                Position left() const;
                Position right() const;

                Position parent() const;

                bool is_root() const;
                bool is_external() const;

            private:
                Node* node;
        };

        Position get_root() const;
        
        List<Position> get_positions() const;

        void add_root();

        void expand_external(const Position& p);
        Position remove_above_external(const Position& p);

        void preorder_print() const;
        void inorder_print() const;
        void postorder_print() const;

    private:
        Node* root;
        int number_of_elements;

        void preorder_for_get_positions(Node* a_node, List<Position>& pl) const;

        void _preorder_print(const Position& p) const;
        void _inorder_print(const Position& p) const;
        void _postorder_print(const Position& p) const;
};

// int depth(const BinaryTree<int>& t, const BinaryTree<int>::Position& p) {
//     if (p.is_root()) return 0;
//     else return 1 + depth(t, p.parent());
// }

// int height(const BinaryTree<int>& t) {
//     int h = 0;
// 
//     List<BinaryTree<int>::Position> nodes = t.get_positions();
// 
//     for (List<BinaryTree<int>::Position>::Iterator q = nodes.get_begin_iter();
//          q != nodes.get_end_iter(); 
//         ++q)
//     {
//         if (q->is_external()) {
//             h = std::max(h, depth(t, *q));
//         }
//     }
// }

template <typename T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
    number_of_elements = 0;
}

template <typename T>
bool BinaryTree<T>::empty() const {
    return number_of_elements == 0;
}

template <typename T>
int BinaryTree<T>::size() const {
    return number_of_elements;
}

template <typename T>
typename BinaryTree<T>::Position BinaryTree<T>::get_root() const {
    return Position(root);
}

template <typename T>
void BinaryTree<T>::add_root() {
    root = new Node;

    root->parent = nullptr;

    number_of_elements++;
}

template <typename T>
BinaryTree<T>::Position::Position(Node *node) {
    this->node = node;
}

template <typename T>
T& BinaryTree<T>::Position::operator*() const {
    return node->value;
}


template <typename T>
typename BinaryTree<T>::Position BinaryTree<T>::Position::left() const {
    return Position(node->left);
}


template <typename T>
typename BinaryTree<T>::Position BinaryTree<T>::Position::right() const {
    return Position(node->right);
}


template <typename T>
typename BinaryTree<T>::Position BinaryTree<T>::Position::parent() const {
    return Position(node->parent);
}


template <typename T>
bool BinaryTree<T>::Position::is_root() const {
    return node->parent == nullptr;
}

template <typename T>
bool BinaryTree<T>::Position::is_external() const {
    return node->left == nullptr && node->right == nullptr;
}

template <typename T>
List<typename BinaryTree<T>::Position> BinaryTree<T>::get_positions() const {
    List<Position> positions_list;
    preorder_for_get_positions(root, positions_list);
    return positions_list;
}

template <typename T>
void BinaryTree<T>::preorder_for_get_positions(Node* a_node, List<typename BinaryTree<T>::Position>& pl) const {
    pl.insert_back(Position(a_node));

    if (a_node->left != NULL) preorder_for_get_positions(a_node->left, pl);
    if (a_node->right != NULL) preorder_for_get_positions(a_node->right, pl);

    return;
}

template <typename T>
void BinaryTree<T>::expand_external(const Position& p) {
    // Take the node located at the fecking position.
    Node* n = p.node;

    // Create its left and right nodes.
    n->left = new Node; 
    n->right = new Node; 

    // Make sure that the children know who their parents are.
    
    // Set the parents of the newly created left and right nodes.
    n->left->parent = n;
    n->right->parent = n;

    // Increase the element count of the binary tree.
    number_of_elements += 2;

    return;
}

template <typename T>
typename BinaryTree<T>::Position BinaryTree<T>::remove_above_external(const Position& p) {
    // Get a pointer to the external node that was given to us.
    Node *external = p.node;
    // Get its parent.
    Node *par = p.node->parent;
    par;
    
    // Finds out what the sibling of `external` is.
    Node *sibling = (external == par->left ? par->right : par->left);

    // Makes the sibling node the new root if the parent is actually the root.
    if (par == root) {
        root = sibling;
        sibling->parent = nullptr;
    }
    else {
        // Get a pointer to the grandparent (i.e. the parent of the parent).
        Node *grand_parent = par->parent;

        // Makes the sibling the left of the grand_parent if the parent is the
        // left of the grand_parent.
        // Else makes the sibling the right of the grand_parent if the parent
        // if the right of the grand_parent.
        if (par == grand_parent->left) grand_parent->left = sibling;
        else grand_parent->right = sibling;
    }

    // Gets rid of the external and parent nodes.
    delete external;
    delete par;

    // Decreases the element count.
    number_of_elements--;

    // Returns a Position that points to the sibling.
    return Position(sibling);
}

template <typename T>
void BinaryTree<T>::preorder_print() const {
    _preorder_print(Position(root));
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::_preorder_print(const Position& p) const {
    std::cout << *p << " ";
    if (p.is_external());
    else {
        std::cout << "( ";
        _preorder_print(p.left());
        _preorder_print(p.right());
        std::cout << ") ";
    }
}

template <typename T>
void BinaryTree<T>::inorder_print() const {
    _inorder_print(Position(root));
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::_inorder_print(const Position& p) const {
    if (p.is_external());
    else {
        _inorder_print(p.left());
    }

    std::cout << *p << " ";

    if (p.is_external());
    else {
        _inorder_print(p.right());
    }
}

template <typename T>
void BinaryTree<T>::postorder_print() const {
    _postorder_print(get_root());
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::_postorder_print(const Position& p) const {
    if (p.is_external());
    else {
        std::cout << "( ";
        _postorder_print(p.left());
        _postorder_print(p.right());
        std::cout << ") ";
    }
    std::cout << *p << " ";
}

#endif
