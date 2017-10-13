/*
 * Created by Johnny on 10/12/2017.
 */
#include <iostream>

using namespace std;

typedef struct BiTNode {
    char data;
    BiTNode *leftChild;
    BiTNode *rightChild;
} *BinaryTree, BinaryTreeNode;

// Global variable:
int depthOfLeftOffspring = 0;
int depthOfRightOffspring = 0;

// Function declaration:
// Exp05-01:
void createAndInitTree(BinaryTree &binaryTree);

void preorderDisplayTree(BinaryTree binaryTree);

int getTreeDepth(BinaryTree binaryTree);

void getTreeDepthOfLeftOffspring(BinaryTree binaryTree);

void getTreeDepthOfRightOffspring(BinaryTree binaryTree);

void destroyTree(BinaryTree &binaryTree);

void clearTree(BinaryTree &binaryTree);

bool isTreeEmpty(BinaryTree binaryTree);

// Exp05-02:

// Function implementation:
void createAndInitTree(BinaryTree &binaryTree) {
    char dataInput;
    cin >> dataInput;
    if (dataInput != '#') {
        binaryTree = new BinaryTreeNode;
        binaryTree->data = dataInput;
        createAndInitTree(binaryTree->leftChild);
        createAndInitTree(binaryTree->rightChild);
    } else {
        binaryTree = nullptr;
    }
}

void preorderDisplayTree(BinaryTree binaryTree) {
    if (binaryTree != nullptr) {
        cout << binaryTree->data << " ";
        preorderDisplayTree(binaryTree->leftChild);
        preorderDisplayTree(binaryTree->rightChild);
    } else {
        cout << "# ";
    }
}

int getTreeDepth(BinaryTree binaryTree) {
    getTreeDepthOfLeftOffspring(binaryTree);
    getTreeDepthOfRightOffspring(binaryTree);
    if (depthOfLeftOffspring >= depthOfRightOffspring) {
        return depthOfLeftOffspring;
    } else {
        return depthOfRightOffspring;
    }
}

void getTreeDepthOfLeftOffspring(BinaryTree binaryTree) {
    if (binaryTree != nullptr) {
        depthOfLeftOffspring++;
        getTreeDepthOfLeftOffspring(binaryTree->leftChild);
    }
}

void getTreeDepthOfRightOffspring(BinaryTree binaryTree) {
    if (binaryTree != nullptr) {
        depthOfRightOffspring++;
        getTreeDepthOfRightOffspring(binaryTree->rightChild);
    }
}

int main() {
    BinaryTree binaryTree;
    createAndInitTree(binaryTree);
    preorderDisplayTree(binaryTree);
    cout << getTreeDepth(binaryTree);
    return 0;
}