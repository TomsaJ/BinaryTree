﻿#include <iostream>
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
            return this->right->minimum();
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
            x = x - right;
        return x;
    }

    TreeNode* search(T key)
    {
        if (this->key == key)             // wenn der schl�ssel gleich gro� ist
            return this;
        if (this->key > key)               // wenn der schl�ssel kleiner ist
        {
            if (left == nullptr)     // wenn linker pointer null ist dann den linken ausgeben
                return left;
            return left->search(key);
        }
        else
        {
            if (right == nullptr)        // ansonsten den rechten zweig ausgeben
                return right;
            return right->search(key);
        }
    }

public:
    // optional, aber praktisch zum debuggen:
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
    using Node = TreeNode<T>; // optional, Fuer uebersichtlichen Code

private:
    Node* root; // Wurzel (im Falle eines leeren Baumes: nullptr)

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
        Node* prev = nullptr;            //vorg�nger zeiger
        Node* x = root;                  //knoten auf wurzel



        while (x != nullptr)               //solange unser knoten nicht auf null zeigt
        {
            prev = x;                   //soll unser vorg�ngerzeiger gleich unser zeigerknoten sein

            if (newNode->key < x->key) //wenn unser schl�ssel den wir einf�gen wollen kleiner ist als der schl�ssel vom knoten
                x = x->left;            //dann geben wir den aus
            else                        //sosnt gehen wir rechts
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
            prev->left = newNode;     //f�gt neues knoten links ein
        }
        else
            prev->right = newNode;    //f�gt neues knoten rechts ein
    }

    void leftrotation(const T key)
    {
        Node* x = search(key);
        Node* y = x->right;// bestimme y
        x->right = y->left; // mache y�s linker Teilbaum zu x�s rechtem

        if (y->left != nullptr)
        {
            y->left->parent = x;
        }
        y->parent = x->parent; // setze y�s parent auf x�s parent

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

        y->left = x;// mache x zu y�s linkem Kind
        x->parent = y;
    }

    void deleteNode(Node* const node) // "const Node *const node" nicht zulaessig, da node sonst nicht korrekt geloescht werden koennte
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
    // optional, aber praktisch zum debuggen:
    friend std::ostream& operator<<(std::ostream& cout, const SearchTree& tree)
    {
        // cout << tree.root; // markiert rootNode nicht
        cout << tree.root->left << "<" << tree.root->key << ">, " << tree.root->right; // markiert rootNode
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
