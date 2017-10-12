//
// Created by Johnny on 9/11/2017.
//
#include <iostream>

using namespace std;

typedef struct LinkedList {
    int data;
    LinkedList *next;
} SingleLinkedListNode, *SingleLinkedList;

// Functions declared;
void create(SingleLinkedList &headPointerOfLinkedList);

void init(SingleLinkedList &headPointerOfLinkedList);

void display(SingleLinkedList headPointerOfLinkedList);

int getLengthOf(SingleLinkedList headPointerLinkedList);

void bubbleSort(SingleLinkedList &headPointerOfLinkedList);

void insert(SingleLinkedList &headPointerOfLinkedList, int dataToBeInserted);

SingleLinkedList findFirst(SingleLinkedList headPointerOfLinkedList);

SingleLinkedList findLast(SingleLinkedList headPointerOfLinkedList);

SingleLinkedList findBefore(SingleLinkedList headPointerOfLinkedList, SingleLinkedList targetNodePointer);

void reverse(SingleLinkedListNode &headPointerOfLinkedList);

void merge(SingleLinkedList &headPointerOfLinkedList1, SingleLinkedList &headPointerOfLinkedList2);

/**
 * Create a null single linked list.
 * @param headPointerOfLinkedList
 */
void create(SingleLinkedList &headPointerOfLinkedList) {
    headPointerOfLinkedList = new SingleLinkedListNode;
    headPointerOfLinkedList->next = NULL;
}

/**
 * h1>Time complexity: O(n)</h1><br>
 * Put element(s) into linked list to init the linked list.
 * @param headPointerOfLinkedList
 */
void init(SingleLinkedList &headPointerOfLinkedList) {
    int length;
    cout << "Length of linked list: ";
    cin >> length;
    SingleLinkedList newNodePointer, nodeIteratorPointer;
    nodeIteratorPointer = headPointerOfLinkedList;
    for (int i = 0; i < length; i++) {
        cout << "Node No. " << i + 1 << ": ";
        newNodePointer = new SingleLinkedListNode;
        int dataInput;
        cin >> dataInput;
        newNodePointer->data = dataInput;
        newNodePointer->next = NULL;
        nodeIteratorPointer->next = newNodePointer;
        nodeIteratorPointer = newNodePointer;
    }
}

/**
 * <h1>Time complexity: O(n)</h1><br>
 * @param headPointerOfLinkedList
 */
void display(SingleLinkedList headPointerOfLinkedList) {
    cout << "Display: ";
    SingleLinkedList nodePointer = headPointerOfLinkedList;
    while (nodePointer->next != NULL) {
        cout << nodePointer->next->data << " ";
        nodePointer = nodePointer->next;
    }
    cout << "<END>" << endl;
}

/**
 * <h1>Time complexity: O(n)</h1><br>
 * @param headPointerLinkedList
 * @return
 */
int getLengthOf(SingleLinkedList headPointerLinkedList) {
    int count = 0;
    while (headPointerLinkedList->next != NULL) {
        count++;
        headPointerLinkedList = headPointerLinkedList->next;
    }
    return count;
}

/**
 * <h1>Time complexity: O(n^2)</h1><br>
 * <h1>Space complexity: O(1)</h1><br>
 * Bubble sort this linked list in ascending order.
 * Function uses the method based on data exchange.<br>
 * <b>Another method is based on altering pointer. (Should ask tutor)<b><br>
 * @param headPointerOfLinkedList
 */
void bubbleSort(SingleLinkedList &headPointerOfLinkedList) {
    int count = getLengthOf(headPointerOfLinkedList);
    SingleLinkedList nodePointer = headPointerOfLinkedList->next;
    while (count > 1) {
        while (nodePointer->next != nullptr) {
            if (nodePointer->data > nodePointer->next->data) {
                int tempData = nodePointer->data;
                nodePointer->data = nodePointer->next->data;
                nodePointer->next->data = tempData;
            }
            nodePointer = nodePointer->next;
        }
        count--;
        nodePointer = headPointerOfLinkedList->next;
    }
}

/**
 * <h1>Time complexity: O(n)</h1><br>
 * <h1>Space complexity: O(1)</h1><br>
 * @param headPointerOfLinkedList
 * @param dataToBeInserted
 */
void insert(SingleLinkedList &headPointerOfLinkedList, int dataToBeInserted) {
    int count = getLengthOf(headPointerOfLinkedList);

    SingleLinkedList nodePointer = headPointerOfLinkedList->next; //Point to the first element
    SingleLinkedList firstNodePointer = findFirst(headPointerOfLinkedList);
    SingleLinkedList lastNodePointer = findLast(headPointerOfLinkedList);
    int minimumData = firstNodePointer->data;
    int maximumData = lastNodePointer->data;

    //Todo:
    SingleLinkedList pointerOfNodeToBeInserted = new SingleLinkedListNode; // Mistake: SingleLinkedListNode nodeToBeInserted=new SingleLinkedListNode;
    pointerOfNodeToBeInserted->data = dataToBeInserted;
    pointerOfNodeToBeInserted->next = nullptr;

    if (dataToBeInserted < minimumData) {
        headPointerOfLinkedList->next = pointerOfNodeToBeInserted; // Mistake: headPointerOfLinkedList->next = &nodeToBeInserted;
        pointerOfNodeToBeInserted->next = nodePointer;
    } else if (minimumData < dataToBeInserted && dataToBeInserted < maximumData) {
        for (int i = 0; i < count; i++) {
            if (nodePointer->data < dataToBeInserted) {
                nodePointer = nodePointer->next;
            }
        }
        SingleLinkedList pointerBeforeNodeToBeInserted = findBefore(headPointerOfLinkedList, nodePointer);
        pointerBeforeNodeToBeInserted->next = pointerOfNodeToBeInserted;
        pointerOfNodeToBeInserted->next = nodePointer;
    } else if (dataToBeInserted > maximumData) {
        lastNodePointer->next = pointerOfNodeToBeInserted;
        pointerOfNodeToBeInserted->next = nullptr;
    }
}

/**
 * <h1>Time complexity: O(1)</h1><br>
 * @param headPointerOfLinkedList
 * @return The pointer of the 1st node.
 */
SingleLinkedList findFirst(SingleLinkedList headPointerOfLinkedList) {
    if (headPointerOfLinkedList->next != nullptr) {
        return headPointerOfLinkedList->next;
    } else {
        return nullptr;
    }
}

/**
 * <h1>Time complexity: O(n)</h1><br>
 * @param headPointerOfLinkedList
 * @return The pointer of the last node.
 */
SingleLinkedList findLast(SingleLinkedList headPointerOfLinkedList) {
    if (headPointerOfLinkedList->next != nullptr) {
        SingleLinkedList nodePointer = headPointerOfLinkedList->next;
        while (nodePointer->next != nullptr) {
            nodePointer = nodePointer->next;
        }
        return nodePointer;
    } else {
        return nullptr;
    }
}

/**
 * <h1>Time complexity: O(n)</h1><br>
 * @param headPointerOfLinkedList
 * @param targetNodePointer
 * @return The forward pointer of the specific node.
 */
SingleLinkedList findBefore(SingleLinkedList headPointerOfLinkedList, SingleLinkedList targetNodePointer) {
    if (headPointerOfLinkedList->next != nullptr) {
        SingleLinkedList nodePointer = headPointerOfLinkedList->next; // Point to node No. 1
        SingleLinkedList resultNodePointer;
        for (int i = 0; i < getLengthOf(headPointerOfLinkedList); i++) {
            if (nodePointer->data != targetNodePointer->data) {
                resultNodePointer = nodePointer;
                nodePointer = nodePointer->next;
            }
        }
        return resultNodePointer;
    } else {
        return nullptr;
    }
}

/**
 * <h1>Time complexity: O(n)</h1><br>
 * <h1>Space complexity: O(1)</h1><br>
 * @param headPointerOfLinkedList
 */
void reverse(SingleLinkedList &headPointerOfLinkedList) {
    SingleLinkedList nodePointer = headPointerOfLinkedList->next;
    SingleLinkedList tempNodePointer;
    SingleLinkedList firstNodePointer = findFirst(headPointerOfLinkedList);
    while (nodePointer != nullptr) {
        tempNodePointer = nodePointer;
        nodePointer = nodePointer->next;
        tempNodePointer->next = headPointerOfLinkedList->next;
        headPointerOfLinkedList->next = tempNodePointer;
    }
    firstNodePointer->next = nullptr;
}

/**
 * <h1>Time complexity: O(n1+n2)</h1><br>
 * <h1>Space complexity: O(1)</h1><br>
 * @param headPointerOfLinkedList1
 * @param headPointerOfLinkedList2
 */
void merge(SingleLinkedList &headPointerOfLinkedList1, SingleLinkedList &headPointerOfLinkedList2) {
    SingleLinkedList nodePointer = headPointerOfLinkedList1;
    SingleLinkedList iterator1 = findFirst(headPointerOfLinkedList1);
    SingleLinkedList iterator2 = findFirst(headPointerOfLinkedList2);
    while (iterator1 != nullptr && iterator2 != nullptr) {
        if (iterator1->data <= iterator2->data) {
            nodePointer->next = iterator1;
            nodePointer = iterator1;
            iterator1 = iterator1->next;
        } else {
            nodePointer->next = iterator2;
            nodePointer = iterator2;
            iterator2 = iterator2->next;
        }
    }
    nodePointer->next = iterator1 ? iterator1 : iterator2;
    delete headPointerOfLinkedList2;
}

int main() {
    // Pre-work
    SingleLinkedList headPointer1, headPointer2;
    create(headPointer1);
    init(headPointer1);
    display(headPointer1);
    bubbleSort(headPointer1);
    display(headPointer1);

    // Exp 02-01
    int dataToBeInserted;
    cout << "Insert: ";
    cin >> dataToBeInserted;
    insert(headPointer1, dataToBeInserted);
    cout << "[Exp 02-01]: ";
    display(headPointer1);

    // Exp 02-02
    reverse(headPointer1);
    cout << "[Exp 02-02]: ";
    display(headPointer1);

    // Exp 02-03
    reverse(headPointer1);
    create(headPointer2);
    init(headPointer2);
    bubbleSort(headPointer2);
    merge(headPointer1, headPointer2);
    reverse(headPointer1);
    cout << "[Exp 02-03]: ";
    display(headPointer1);
    return 0;
}