#include <iostream>
#include <vector>
using namespace std;

// Define the order of the B-tree (max children)
const int T = 3; // Minimum degree (order of the tree)

class BTreeNode {
public:
    int keys[2 * T - 1];       // Array of keys
    BTreeNode* children[2 * T]; // Array of child pointers
    int numKeys;               // Current number of keys
    bool isLeaf;               // Is true if the node is a leaf

    BTreeNode(bool isLeaf);

    // Insert a new key into a non-full node
    void insertNonFull(int key);

    // Split the child node at index i
    void splitChild(int i, BTreeNode* child);

    // Search for a key in the subtree rooted at this node
    BTreeNode* search(int key);

    // A utility function to display the tree
    void traverse();
};

class BTree {
private:
    BTreeNode* root; // Pointer to the root node
public:
    BTree() { root = nullptr; }

    // Insert a new key
    void insert(int key);

    // Search for a key
    BTreeNode* search(int key) {
        return (root == nullptr) ? nullptr : root->search(key);
    }

    // Display the tree
    void display() {
        if (root) root->traverse();
    }
};

// BTreeNode Constructor
BTreeNode::BTreeNode(bool isLeaf) {
    this->isLeaf = isLeaf;
    numKeys = 0;
}

// Traverse the tree
void BTreeNode::traverse() {
    for (int i = 0; i < numKeys; i++) {
        if (!isLeaf) children[i]->traverse();
        cout << keys[i] << " ";
    }
    if (!isLeaf) children[numKeys]->traverse();
}

// Search a key in the subtree
BTreeNode* BTreeNode::search(int key) {
    int i = 0;
    while (i < numKeys && key > keys[i]) i++;

    if (i < numKeys && keys[i] == key) return this;

    if (isLeaf) return nullptr;

    return children[i]->search(key);
}

// Insert a key into the BTree
void BTree::insert(int key) {
    if (!root) {
        root = new BTreeNode(true);
        root->keys[0] = key;
        root->numKeys = 1;
    } else {
        if (root->numKeys == 2 * T - 1) {
            BTreeNode* newRoot = new BTreeNode(false);

            newRoot->children[0] = root;
            newRoot->splitChild(0, root);

            int i = (newRoot->keys[0] < key) ? 1 : 0;
            newRoot->children[i]->insertNonFull(key);

            root = newRoot;
        } else {
            root->insertNonFull(key);
        }
    }
}

// Insert a key into a non-full node
void BTreeNode::insertNonFull(int key) {
    int i = numKeys - 1;

    if (isLeaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        numKeys++;
    } else {
        while (i >= 0 && keys[i] > key) i--;

        if (children[i + 1]->numKeys == 2 * T - 1) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < key) i++;
        }
        children[i + 1]->insertNonFull(key);
    }
}

// Split a child node
void BTreeNode::splitChild(int i, BTreeNode* child) {
    BTreeNode* newChild = new BTreeNode(child->isLeaf);
    newChild->numKeys = T - 1;

    for (int j = 0; j < T - 1; j++) newChild->keys[j] = child->keys[j + T];

    if (!child->isLeaf) {
        for (int j = 0; j < T; j++) newChild->children[j] = child->children[j + T];
    }

    child->numKeys = T - 1;

    for (int j = numKeys; j >= i + 1; j--) children[j + 1] = children[j];
    children[i + 1] = newChild;

    for (int j = numKeys - 1; j >= i; j--) keys[j + 1] = keys[j];
    keys[i] = child->keys[T - 1];

    numKeys++;
}

int main() {
    BTree tree;

    // Insert keys
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    // Display tree
    cout << "Traversal of the B-Tree is: ";
    tree.display();
    cout << endl;

    // Search for a key
    int key = 6;
    if (tree.search(key)) {
        cout << "Key " << key << " found in the tree." << endl;
    } else {
        cout << "Key " << key << " not found in the tree." << endl;
    }

    return 0;
}
