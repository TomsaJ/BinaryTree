#include <iostream>
using namespace std;

template<typename T>
class SearchTree;


template<typename T>
class TreeNode
{
    friend class SearchTree<T>;

public:
    TreeNode* parent = nullptr;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

public:
    const T key;

public:
    TreeNode(const T rootKey) : key(rootKey) {}
    virtual ~TreeNode()
    {
        delete this->left;
        delete this->right;
    }

    // Disallow (accidental) copying or moving:
    TreeNode(const TreeNode& copyFrom) = delete;
    TreeNode(TreeNode&& moveFrom) = delete;

public:

    TreeNode* predecessor()
    {
        if (this->left != nullptr)
            return this->left->maximum();
    }

    TreeNode* successor()
    {
        if (this->right != nullptr) 
        {
            return this->right->minimum();
        }
        else
        {
            throw 4;
        }
            
    }

    TreeNode* minimum()
    {
        TreeNode* x = this;
        while (x->left != nullptr)
            x = x->left;
        return x;
    }
    TreeNode* maximum()
    {
        TreeNode* x = this;
        while (x->right != nullptr)
            x = x -> right;
        return x;
    }

    TreeNode* search(T key)
    {
        if (this->key == key)             // if the key is equal
            return this;
        if (this->key > key)               // if the key is smaller
        {
            if (left == nullptr)     // if left-pointer is null, it will return the left one
                return left;
            return left->search(key);
        }
        else
        {
            if (right == nullptr)        // else return right side
                return right;
            return right->search(key);
        }
    }

public:
    // optional
    friend std::ostream& operator<<(std::ostream& cout, const TreeNode* tree)
    {
        if (tree == nullptr) return cout; // nothing to print

        cout << tree->left << tree->key << ", " << tree->right;

        return cout;
    }
};


template<typename T>
class SearchTree
{
    using Node = TreeNode<T>; // optional, for clean code

private:
    Node* root; // Root (in case of an empty key: nullptr)

public:
    SearchTree() : root(nullptr) { }
    virtual ~SearchTree()
    {
        delete root;
    }

    // Disallow (accidental) copying or moving:
    SearchTree(const SearchTree& copyFrom) = delete;
    SearchTree(SearchTree&& moveFrom) = delete;

private:
    void transplant(const Node* const nodeToReplace, Node* const replacementNode) // internally used by void delete_node(...)
    {
        if (nodeToReplace->parent == nullptr)
        {
            root = replacementNode;
        }
        else if (nodeToReplace == nodeToReplace->parent->left)
        {
            nodeToReplace->parent->left = replacementNode;
        }
        else
        {
            nodeToReplace->parent->right = replacementNode;
        }
        if (replacementNode != nullptr)
            replacementNode->parent = nodeToReplace->parent;
    }


public:
    void insert(const T key)
    {
        Node* newNode = new Node(key);
        Node* prev = nullptr;            //pointer to previous
        Node* x = root;                  //node to root



        while (x != nullptr)               //while the node doesnt point to null
        {
            prev = x;                   //prev. pointer equals pointernode

            if (newNode->key < x->key) //if the inserted key is smaller than the key from the node
                x = x->left;            //the key is output
            else                        //else, go to right
                x = x->right;
        }

        //Knoten erstellen
        newNode->parent = prev;

        if (prev == nullptr)
        {
            root = newNode;
        }
        else if (newNode->key < prev->key)
        {
            prev->left = newNode;     //insert a new node left
        }
        else
            prev->right = newNode;    //insert a new node right
    }

    void leftrotation(const T key)
    {
        Node* x = search(key);
        Node* y = x->right;//  y
        x->right = y->left; // y left subtree to x right subtree

        if (y->left != nullptr)
        {
            y->left->parent = x;
        }
        y->parent = x->parent; // make ys parent to xs parent

        if (x->parent == nullptr)
        {
            root = y;
        }

        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }

        else
        {
            x->parent->right = y;
        }

        y->left = x;// make x to y left Child
        x->parent = y;
    }

    void deleteNode(Node* const node) 
    {
        if (node->left == nullptr)
        {
            transplant(node, node->right);
        }
        else if (node->right == nullptr)
        {
            transplant(node, node->left);
        }
        else
        {
            Node* y = node->right->minimum();

            if (y->parent != node)
            {
                transplant(y, y->right);
                y->right = node->right;
                y->right->parent = y;
            }
            transplant(node, y);
            y->left = node->left;
            y->left->parent = y;
        }
    }


    Node* search(const T key)
    {
        if (root == nullptr)
            return nullptr;

        return root->search(key);
    }

    Node* minimum()
    {
        return root->minimum();
    }
    Node* maximum()
    {
        return root->maximum();
    }


public:
    // optional
    friend std::ostream& operator<<(std::ostream& cout, const SearchTree& tree)
    {
        // cout << tree.root; // doesnt mark rootNode
        if (tree.root != nullptr)
        {
            cout << tree.root->left << "<" << tree.root->key << ">, " << tree.root->right; // mark rootNode
        }
        else
        {
            cout << "Tree is empty";
        }
        return cout;
    }

    void printSubtree(const Node* tree, const size_t depth)
    {
        if (tree == nullptr) return;

        printSubtree(tree->right, depth + 1);

        for (size_t i = 0; i < depth; i++)
            std::cout << "\t";
        std::cout << tree->key << "\n";

        printSubtree(tree->left, depth + 1);
    }

    void print()
    {
        printSubtree(root, 0);
    }
};
