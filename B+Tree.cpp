#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


const int T = 3; // Minimum degree (order) of the B+ Tree

class BPTreeNode {
public:
    vector<int> keys;                // Keys in the node
    vector<BPTreeNode*> children;    // Children pointers
    BPTreeNode* nextLeaf;            // Pointer to the next leaf node (for linked list)
    bool isLeaf;                     // True if the node is a leaf

    BPTreeNode(bool isLeaf);
};

class BPTree {
private:
    BPTreeNode* root;

    void insertInternal(int key, BPTreeNode* node, BPTreeNode* child);
    void splitLeaf(BPTreeNode* node, int& key, BPTreeNode*& newNode);
    void splitInternal(BPTreeNode* node, int& key, BPTreeNode*& newNode);

    void traverseLeaf(BPTreeNode* node);
public:
    BPTree() { root = nullptr; }

    void insert(int key);
    void display();
    void rangeQuery(int start, int end);
};

// Constructor for BPTreeNode
BPTreeNode::BPTreeNode(bool isLeaf) {
    this->isLeaf = isLeaf;
    nextLeaf = nullptr;
}

// Function to insert a key into the B+ Tree
void BPTree::insert(int key) {
    if (!root) {
        root = new BPTreeNode(true);
        root->keys.push_back(key);
    } else {
        BPTreeNode* current = root;
        BPTreeNode* parent = nullptr;

        // Traverse to the correct leaf node
        while (!current->isLeaf) {
            parent = current;
            auto it = lower_bound(current->keys.begin(), current->keys.end(), key);
            int index = distance(current->keys.begin(), it);
            current = current->children[index];
        }

        // Insert the key into the leaf node
        auto it = lower_bound(current->keys.begin(), current->keys.end(), key);
        current->keys.insert(it, key);

        // Split the leaf node if it overflows
        if (current->keys.size() == 2 * T - 1) {
            int newKey;
            BPTreeNode* newLeaf;
            splitLeaf(current, newKey, newLeaf);

            if (current == root) {
                // If root is split, create a new root
                root = new BPTreeNode(false);
                root->keys.push_back(newKey);
                root->children.push_back(current);
                root->children.push_back(newLeaf);
            } else {
                // Handle split at an internal level
                insertInternal(newKey, parent, newLeaf);
            }
        }
    }
}

// Split a leaf node
void BPTree::splitLeaf(BPTreeNode* node, int& key, BPTreeNode*& newNode) {
    int mid = T - 1;

    newNode = new BPTreeNode(true);
    newNode->keys.assign(node->keys.begin() + mid, node->keys.end());
    node->keys.resize(mid);

    newNode->nextLeaf = node->nextLeaf;
    node->nextLeaf = newNode;

    key = newNode->keys[0];
}

// Handle insertion into an internal node
void BPTree::insertInternal(int key, BPTreeNode* node, BPTreeNode* child) {
    auto it = upper_bound(node->keys.begin(), node->keys.end(), key);
    int index = distance(node->keys.begin(), it);

    node->keys.insert(it, key);
    node->children.insert(node->children.begin() + index + 1, child);

    if (node->keys.size() == 2 * T - 1) {
        int newKey;
        BPTreeNode* newInternal;
        splitInternal(node, newKey, newInternal);

        if (node == root) {
            root = new BPTreeNode(false);
            root->keys.push_back(newKey);
            root->children.push_back(node);
            root->children.push_back(newInternal);
        } else {
            // Propagate the split to the parent
            insertInternal(newKey, root, newInternal);
        }
    }
}

// Split an internal node
void BPTree::splitInternal(BPTreeNode* node, int& key, BPTreeNode*& newNode) {
    int mid = T - 1;

    newNode = new BPTreeNode(false);
    key = node->keys[mid];

    newNode->keys.assign(node->keys.begin() + mid + 1, node->keys.end());
    newNode->children.assign(node->children.begin() + mid + 1, node->children.end());

    node->keys.resize(mid);
    node->children.resize(mid + 1);
}

// Display the B+ Tree (level-order traversal)
void BPTree::display() {
    if (!root) return;

    vector<BPTreeNode*> queue = { root };
    while (!queue.empty()) {
        vector<BPTreeNode*> nextLevel;
        for (BPTreeNode* node : queue) {
            for (int key : node->keys) {
                cout << key << " ";
            }
            cout << "| ";
            if (!node->isLeaf) {
                nextLevel.insert(nextLevel.end(), node->children.begin(), node->children.end());
            }
        }
        cout << endl;
        queue = nextLevel;
    }
}

// Range query (traverse linked leaf nodes)
void BPTree::rangeQuery(int start, int end) {
    BPTreeNode* current = root;
    while (current && !current->isLeaf) {
        auto it = lower_bound(current->keys.begin(), current->keys.end(), start);
        int index = distance(current->keys.begin(), it);
        current = current->children[index];
    }

    while (current) {
        for (int key : current->keys) {
            if (key >= start && key <= end) {
                cout << key << " ";
            }
        }
        current = current->nextLeaf;
    }
    cout << endl;
}

int main() {
    BPTree tree;

    // Insert keys
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    // Display the tree
    cout << "B+ Tree:" << endl;
    tree.display();

    // Range query
    cout << "\nRange Query [6, 20]: ";
    tree.rangeQuery(6, 20);

    return 0;
}
