//
// Created by Johnny on 9/18/2017.
//
#include <iostream>

#define MAXIMUM 10000;
using namespace std;

typedef struct SCLinkedList {
    int data;
    SCLinkedList *next;
} SingleCirculationLinkedListNode, *SingleCirculationLinkedList;

typedef struct CharacterLinkedList {
    char data;
    CharacterLinkedList *next;
} CharacterSingleLinkedListNode, *CharacterSingleLinkedList, CharacterSingleCirculationLinkedListNode, *CharacterSingleCirculationLinkedList;

typedef struct DCLinkedList {
    int data;
    int freq;
    DCLinkedList *next;
    DCLinkedList *prior;
} DualCirculationLinkedListNode, *DualCirculationLinkedList;


// Functions declaration:
// Exp03-01:
void createAndInitSCLL(SingleCirculationLinkedList &pointerOfSingleCirculationLinkedList);

void deletePrecursorNodeFromSCLL(SingleCirculationLinkedList &pointerOfSingleCirculationLinkedList);

SingleCirculationLinkedList
findFromSCLL(SingleCirculationLinkedList pointerOfSingleCirculationLinkedList, int targetData);

void displaySCLL(SingleCirculationLinkedList pointerOfSingleCirculationLinkedList, int targetData);

// Exp03-02:
void createAndInitCSLL(CharacterSingleLinkedList &headPointerOfCSLL);

void createCSCLL(CharacterSingleCirculationLinkedList &headPointerOfCSCLL);

void displayCSLL(CharacterSingleLinkedList headPointerOfCSLL);

int lengthOfCSLL(CharacterSingleLinkedList headPointerCSLL);

void siftCharacter(CharacterSingleLinkedList &headPointerOfCSLL,
                   CharacterSingleCirculationLinkedList &headPointerOfCSCLL);

void siftAlphabeticCharacter(CharacterSingleLinkedList &headPointerOfCSLL,
                             CharacterSingleCirculationLinkedList &headPointerOfCSCLL);

void siftOtherCharacter(CharacterSingleLinkedList &headPointerOfCSLL,
                        CharacterSingleCirculationLinkedList &headPointerOfCSCLL);

void displayCSCLL(CharacterSingleCirculationLinkedList headPointerOfCSCLL);

// Exp03-03
void createAndInitDCLL(DualCirculationLinkedList &headPointerOfDCLL);

void displayDCLL(DualCirculationLinkedList headPointerOfDCLL);

void locate(DualCirculationLinkedList &headPointerOfDCLL, int targetData);

void sortByFreq(DualCirculationLinkedList &headPointerOfDCLL, DualCirculationLinkedList nodePointer);

/**
 * create and init single-circulation linked list w/o head node.
 * @param pointerOfSingleCirculationLinkedList
 */
void createAndInitSCLL(SingleCirculationLinkedList &pointerOfSingleCirculationLinkedList) {
    cout << "Length of single-circulation linked list: ";
    int count;
    cin >> count;
    SingleCirculationLinkedList firstNodePointer = pointerOfSingleCirculationLinkedList;
    for (int i = 0; i < count; i++) {
        if (i == 0) {
            cout << "Node No. " << i + 1 << ": ";
            cin >> pointerOfSingleCirculationLinkedList->data;
            pointerOfSingleCirculationLinkedList->next = pointerOfSingleCirculationLinkedList;
        } else {
            SingleCirculationLinkedList tempNodePointer = new SingleCirculationLinkedListNode;
            cout << "Node No. " << i + 1 << ": ";
            cin >> tempNodePointer->data;
            tempNodePointer->next = firstNodePointer;
            pointerOfSingleCirculationLinkedList->next = tempNodePointer;
            pointerOfSingleCirculationLinkedList = tempNodePointer;
        }
    }
//    pointerOfSingleCircularLinkedList = pointerOfSingleCircularLinkedList->next;
}

/**
 * Delete the precursor node of the target node.
 * @param pointerOfSingleCirculationLinkedList
 * @param targetData
 */
void deletePrecursorNodeFromSCLL(SingleCirculationLinkedList &pointerOfSingleCirculationLinkedList, int targetData) {
    SingleCirculationLinkedList targetNodePointer = findFromSCLL(pointerOfSingleCirculationLinkedList, targetData);
    if (targetNodePointer != nullptr) {
        SingleCirculationLinkedList tempNodePointer1 = targetNodePointer;
        SingleCirculationLinkedList tempNodePointer2;
        while (tempNodePointer1->next != targetNodePointer) {
            tempNodePointer2 = tempNodePointer1;
            tempNodePointer1 = tempNodePointer1->next;
        }
        tempNodePointer2->next = targetNodePointer;
        if (tempNodePointer1 == pointerOfSingleCirculationLinkedList) {
            pointerOfSingleCirculationLinkedList = tempNodePointer2;
        }
        delete (tempNodePointer1);
    } else {
        cout << "No such node: " << targetData << endl;
    }
}

/**
 * Find the exact node from single-circulation linked list.
 * @param pointerOfSingleCirculationLinkedList
 * @param targetData
 * @return The pointer of the target node.
 */
SingleCirculationLinkedList
findFromSCLL(SingleCirculationLinkedList pointerOfSingleCirculationLinkedList, int targetData) {
    SingleCirculationLinkedList mSingleCirculationLinkedList = pointerOfSingleCirculationLinkedList;
    if (mSingleCirculationLinkedList->data == targetData) {
        return mSingleCirculationLinkedList;
    } else {
        mSingleCirculationLinkedList = mSingleCirculationLinkedList->next;
    }
    while (mSingleCirculationLinkedList != pointerOfSingleCirculationLinkedList) {
        if (mSingleCirculationLinkedList->data == targetData) {
            return mSingleCirculationLinkedList;
        } else {
            mSingleCirculationLinkedList = mSingleCirculationLinkedList->next;
        }
    }
    return nullptr;
}

/**
 * Display the single-circulation linked list.
 * @param pointerOfSingleCirculationLinkedList
 */
void displaySCLL(SingleCirculationLinkedList pointerOfSingleCirculationLinkedList) {
    SingleCirculationLinkedList tempPointer = pointerOfSingleCirculationLinkedList;
    cout << tempPointer->data << " ";
    tempPointer = tempPointer->next;
    while (tempPointer != pointerOfSingleCirculationLinkedList) {
        cout << tempPointer->data << " ";
        tempPointer = tempPointer->next;
    }
    cout << "<END>" << endl;
}

/**
 * Create and init character single linked list w/ a head node.
 * @param headPointerOfCSLL
 */
void createAndInitCSLL(CharacterSingleLinkedList &headPointerOfCSLL) {
    headPointerOfCSLL = new CharacterSingleLinkedListNode;
    headPointerOfCSLL->next = nullptr;
    cout << "Length of Character Single Linked List: ";
    int length;
    cin >> length; // 11
    CharacterSingleLinkedList nodeIteratorPointer = headPointerOfCSLL;
    for (int i = 0; i < length; i++) {
        CharacterSingleLinkedList newNodePointer = new CharacterSingleLinkedListNode;
        cout << "Node No. " << i + 1 << ": ";
        cin >> newNodePointer->data;
        newNodePointer->next = nullptr;
        nodeIteratorPointer->next = newNodePointer;
        nodeIteratorPointer = newNodePointer;
    }
}

/**
 * Display the character single linked list.
 * @param headPointerOfCSLL
 */
void displayCSLL(CharacterSingleLinkedList headPointerOfCSLL) {
    while (headPointerOfCSLL->next != nullptr) {
        cout << headPointerOfCSLL->next->data << " ";
        headPointerOfCSLL = headPointerOfCSLL->next;
    }
    cout << "<END>" << endl;
}

int lengthOfCSLL(CharacterSingleLinkedList headPointerCSLL) {
    int count = 0;
    while (headPointerCSLL->next != nullptr) {
        count++;
    }
    return count;
}

/**
 * Create character single-circulation linked list w/ a head node.
 * @param headPointerOfCSCLL
 */
void createCSCLL(CharacterSingleCirculationLinkedList &headPointerOfCSCLL) {
    headPointerOfCSCLL = new CharacterSingleCirculationLinkedListNode;
    headPointerOfCSCLL->next = headPointerOfCSCLL;
}

/**
 * Sift characters from the character single linked list
 * to 3 single-circulation linked lists.
 * @param headPointerOfCSLL
 * @param headPointerOfNumericCSCLL
 * @param headPointerOfAlphabeticCSCLL
 * @param headPointerOfOtherCSCLL
 */
void siftCharacter(CharacterSingleLinkedList &headPointerOfCSLL,
                   CharacterSingleCirculationLinkedList &headPointerOfNumericCSCLL,
                   CharacterSingleCirculationLinkedList &headPointerOfAlphabeticCSCLL,
                   CharacterSingleCirculationLinkedList &headPointerOfOtherCSCLL) {
    CharacterSingleLinkedList iteratorPointerCSLL = headPointerOfCSLL->next;
    CharacterSingleLinkedList tempNodePointer;
    CharacterSingleCirculationLinkedList iteratorPointerNumericCSCLL = headPointerOfNumericCSCLL;
    CharacterSingleCirculationLinkedList iteratorPointerAlphabeticCSCLL = headPointerOfAlphabeticCSCLL;
    CharacterSingleCirculationLinkedList iteratorPointerOtherCSCLL = headPointerOfOtherCSCLL;
    while (iteratorPointerCSLL != nullptr) {
        tempNodePointer = iteratorPointerCSLL;
        iteratorPointerCSLL = iteratorPointerCSLL->next;
        if ('0' <= tempNodePointer->data && tempNodePointer->data <= '9') {
//            cout << "Numerical: " << tempNodePointer->data << endl;
            tempNodePointer->next = iteratorPointerNumericCSCLL->next;
            iteratorPointerNumericCSCLL->next = tempNodePointer;
            iteratorPointerNumericCSCLL = tempNodePointer;
        } else if ('a' <= tempNodePointer->data && tempNodePointer->data <= 'z' ||
                   'A' <= tempNodePointer->data && tempNodePointer->data <= 'Z') {
//            cout << "Alphabetical: " << tempNodePointer->data << endl;
            tempNodePointer->next = iteratorPointerAlphabeticCSCLL->next;
            iteratorPointerAlphabeticCSCLL->next = tempNodePointer;
            iteratorPointerAlphabeticCSCLL = tempNodePointer;
        } else {
//            cout << "Other: " << tempNodePointer->data << endl;
            tempNodePointer->next = iteratorPointerOtherCSCLL->next;
            iteratorPointerOtherCSCLL->next = tempNodePointer;
            iteratorPointerOtherCSCLL = tempNodePointer;
        }
    }
    headPointerOfCSLL->next = nullptr;
}

/**
 * Display character single-circulation linked list.
 * @param headPointerOfCSCLL
 */
void displayCSCLL(CharacterSingleCirculationLinkedList headPointerOfCSCLL) {
    CharacterSingleCirculationLinkedList tempPointer = headPointerOfCSCLL->next;
    while (tempPointer != headPointerOfCSCLL) {
        cout << tempPointer->data << " ";
        tempPointer = tempPointer->next;
    }
    cout << "<END>" << endl;
}

/**
 * Use back-extrapolation method to init dual-circulation linked list.
 * @param headPointerOfDCLL
 */
void createAndInitDCLL(DualCirculationLinkedList &headPointerOfDCLL) {
    headPointerOfDCLL = new DualCirculationLinkedListNode;
    headPointerOfDCLL->freq = MAXIMUM;
    cout << "Length of Dual-circulation Linked List: ";
    int length;
    cin >> length;
    DualCirculationLinkedList rearPointerOfDCLL = headPointerOfDCLL;
    for (int i = 0; i < length; i++) {
        DualCirculationLinkedList newNodePointer = new DualCirculationLinkedListNode;
        cout << "Node No. " << i + 1 << ": ";
        cin >> newNodePointer->data;
        newNodePointer->freq = 0;
        newNodePointer->next = headPointerOfDCLL;
        newNodePointer->prior = rearPointerOfDCLL;
        rearPointerOfDCLL->next = newNodePointer;
        headPointerOfDCLL->prior = newNodePointer;
        rearPointerOfDCLL = newNodePointer;
    }
}

/**
 * Display dual-circulation linked list.
 * @param headPointerOfDCLL
 */
void displayDCLL(DualCirculationLinkedList headPointerOfDCLL) {
    DualCirculationLinkedList iterator = headPointerOfDCLL->next;
    while (iterator != headPointerOfDCLL) {
        cout << "[" << iterator->data << ", " << iterator->freq << "] ";
        iterator = iterator->next;
    }
    cout << "<END>" << endl;
}

/**
 * Locate the node by data.
 * @param headPointerOfDCLL
 * @param targetData
 */
void locate(DualCirculationLinkedList &headPointerOfDCLL, int targetData) {
    DualCirculationLinkedList iterator = headPointerOfDCLL->next;
    while (iterator != headPointerOfDCLL) {
        if (iterator->data == targetData) {
            break;
        } else {
            iterator = iterator->next;
        }
    }
    if (iterator != headPointerOfDCLL) {
        cout << "Node located: [" << iterator->data << ", " << iterator->freq << "]" << endl;
        iterator->freq++;
        sortByFreq(headPointerOfDCLL, iterator);
    } else {
        cout << "Not found." << endl;
    }
}

/**
 * Sort dual-circulation linked list by freq.
 * @param headPointerOfDCLL
 * @param nodePointer
 */
void sortByFreq(DualCirculationLinkedList &headPointerOfDCLL, DualCirculationLinkedList nodePointer) {
    DualCirculationLinkedList iterator = headPointerOfDCLL->next;
    int tempFreq = nodePointer->freq;
    while (iterator != headPointerOfDCLL) {
        if (iterator->freq >= tempFreq) {
            iterator = iterator->next;
        } else {
            break;
        }
    }
    if (iterator == headPointerOfDCLL) {
        // Don't do anything.
    } else {
        nodePointer->prior->next = nodePointer->next;
        nodePointer->next->prior = nodePointer->prior;
        nodePointer->next = iterator;
        nodePointer->prior = iterator->prior;
        iterator->prior->next = nodePointer;
        iterator->prior = nodePointer;
    }
}

int main() {
    // Exp03-01
    cout << "<Exp03-01>" << endl;
    SingleCirculationLinkedList pointerOfSingleCirculationLinkedList = new SingleCirculationLinkedListNode;
    createAndInitSCLL(pointerOfSingleCirculationLinkedList);
    cout << "Initial linked list: ";
    displaySCLL(pointerOfSingleCirculationLinkedList);
    int targetData1;
    cout << "Delete the precursor node of the node(Value): ";
    cin >> targetData1;
    deletePrecursorNodeFromSCLL(pointerOfSingleCirculationLinkedList, targetData1);
    cout << "After deleted: ";
    displaySCLL(pointerOfSingleCirculationLinkedList);

    // Exp03-02
    cout << "<Exp03-02>" << endl;
    CharacterSingleLinkedList headPointerOfCSLL;
    CharacterSingleCirculationLinkedList headPointerOfNumericCSCLL, headPointerOfAlphabeticCSCLL, headPointerOfOtherCSCLL;
    createAndInitCSLL(headPointerOfCSLL);
    cout << "Original characters: ";
    displayCSLL(headPointerOfCSLL);
    createCSCLL(headPointerOfNumericCSCLL);
    createCSCLL(headPointerOfAlphabeticCSCLL);
    createCSCLL(headPointerOfOtherCSCLL);
    siftCharacter(headPointerOfCSLL, headPointerOfNumericCSCLL, headPointerOfAlphabeticCSCLL, headPointerOfOtherCSCLL);
    cout << "Numerical characters: ";
    displayCSCLL(headPointerOfNumericCSCLL);
    cout << "Alphabetical characters: ";
    displayCSCLL(headPointerOfAlphabeticCSCLL);
    cout << "Other characters: ";
    displayCSCLL(headPointerOfOtherCSCLL);
    cout << "Original characters: ";
    displayCSLL(headPointerOfCSLL);

    // Exp03-03
    cout << "<Exp03-03>" << endl;
    DualCirculationLinkedList headPointerOfDCLL;
    createAndInitDCLL(headPointerOfDCLL);
    cout << "Original sequence: ";
    displayDCLL(headPointerOfDCLL);
    int targetData2;
    cout << "Want to locate node (Value): ";
    cin >> targetData2;
    while (targetData2 > 0) {
        locate(headPointerOfDCLL, targetData2);
        displayDCLL(headPointerOfDCLL);
        cout << "Want to locate node (Value): ";
        cin >> targetData2;
    }
    return 0;
}
