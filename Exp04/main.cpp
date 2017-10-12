//
// Created by Johnny on 9/26/2017.
//
#include <iostream>
#include <math.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define MYOVERFLOW -2
using namespace std;

typedef struct CharacterLinkedList {
    char data;
    CharacterLinkedList *next;
} CharacterSingleLinkedListNode, *CharacterSingleLinkedList, LinkQueueNode, *LinkQueue;

typedef struct {
    char *base;
    char *top;
    int size;
} SequentialStack;

typedef struct {
//    LinkQueue front;
    LinkQueue rear;
} CircularLinkQueue;

// Functions declaration:
// Exp04-01:
void createSequentialStack(SequentialStack &sequentialStack);

void push(SequentialStack &sequentialStack, char element);

char pop(SequentialStack &sequentialStack);

bool isEmpty(SequentialStack sequentialStack);

bool isFull(SequentialStack sequentialStack);

char getTopElement(SequentialStack sequentialStack);

void createAndInitCSLL(CharacterSingleLinkedList &headPointOfCSLL);

void displayCSLL(CharacterSingleLinkedList headPointerOfCSLL);

int getLengthOf(CharacterSingleLinkedList headPointerOfCSLL);

void isCentrosymmetric(CharacterSingleLinkedList headPointerOfCSLL, SequentialStack &sequentialStack);

// Exp04-02:
void isBracketMatched(CharacterSingleLinkedList arithmeticalExpression, SequentialStack &sequentialStack);

void emptySequentialStack(SequentialStack &sequentialStack);

void exp04_02(SequentialStack &sequentialStack);

// Exp04-03:
void createCircularLinkQueue(CircularLinkQueue &circularLinkQueue);

void enqueue(CircularLinkQueue &circularLinkQueue, char targetData);

char dequeue(CircularLinkQueue &circularLinkQueue);

void emptyQueue(CircularLinkQueue &circularLinkQueue);

bool isEmptyQueue(CircularLinkQueue circularLinkQueue);

void displayQueue(CircularLinkQueue circularLinkQueue);

void myEnqueue(CircularLinkQueue &queue);

void myDequeue(CircularLinkQueue &queue);

void createSequentialStack(SequentialStack &sequentialStack) {
    sequentialStack.base = new char[MAXSIZE];
    if (sequentialStack.base != nullptr) {
        sequentialStack.top = sequentialStack.base;
        sequentialStack.size = MAXSIZE;
    } else {
        cout << "ERROR (createSequentialStack): Initializing sequential stack failed." << endl;
        exit(MYOVERFLOW);
    }
}

void push(SequentialStack &sequentialStack, char element) {
    if (!isFull(sequentialStack)) {
        *sequentialStack.top = element;
        sequentialStack.top++;
    } else {
        cout << "ERROR (push): Sequential stack if full." << endl;
    }
}

char pop(SequentialStack &sequentialStack) {
    if (!isEmpty(sequentialStack)) {
        char topElement = *(sequentialStack.top - 1);
        sequentialStack.top--;
        return topElement;
    } else {
        cout << "ERROR (pop): Sequential stack if empty." << endl;
    }
}

bool isEmpty(SequentialStack sequentialStack) {
    return sequentialStack.top == sequentialStack.base;
}

bool isFull(SequentialStack sequentialStack) {
    return sequentialStack.top - sequentialStack.base == sequentialStack.size;
}

char getTopElement(SequentialStack sequentialStack) {
    if (!isEmpty(sequentialStack)) {
        return *(sequentialStack.top - 1);
    } else {
        cout << "ERROR (getTopElement): Sequential stack if empty." << endl;
    }
}

void createAndInitCSLL(CharacterSingleLinkedList &headPointOfCSLL) {
    headPointOfCSLL = new CharacterSingleLinkedListNode;
    headPointOfCSLL->next = nullptr;
    cout << "Length of character single linked list: ";
    int length;
    cin >> length;
    CharacterSingleLinkedList nodeIteratorPointer = headPointOfCSLL;
    for (int i = 0; i < length; i++) {
        CharacterSingleLinkedList newNodePointer = new CharacterSingleLinkedListNode;
        cout << "Node NO. " << i + 1 << ": ";
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

int getLengthOf(CharacterSingleLinkedList headPointerOfCSLL) {
    CharacterSingleLinkedList iterator = headPointerOfCSLL->next;
    int count = 0;
    while (iterator != nullptr) {
        count++;
        iterator = iterator->next;
    }
    return count;
}

void isCentrosymmetric(CharacterSingleLinkedList headPointerOfCSLL, SequentialStack &sequentialStack) {
    CharacterSingleLinkedList iterator = headPointerOfCSLL->next;
    if (iterator != nullptr) {
        int lengthOfCSLL = getLengthOf(headPointerOfCSLL);
        int count = floor(lengthOfCSLL / 2);
        for (int i = 0; i < count; i++) {
            push(sequentialStack, iterator->data);
            iterator = iterator->next;
        }
        if (lengthOfCSLL % 2 != 0) {
            iterator = iterator->next;
        }
        char tempElement;
        while (!isEmpty(sequentialStack)) {
            tempElement = pop(sequentialStack);
            if (tempElement == iterator->data) {
                iterator = iterator->next;
                continue;
            } else {
                cout << "Result: Not centrosymmetric." << endl;
                return;
            }
        }
        cout << "Result: Centrosymmetric." << endl;
    } else {
        cout << "ERROR (isCentrosymmetric): Empty character single linked list." << endl;
    }
}

void emptySequentialStack(SequentialStack &sequentialStack) {
    while (true) {
        if (!isEmpty(sequentialStack)) {
            cout << "POPPING: " << getTopElement(sequentialStack) << endl;
            pop(sequentialStack);
        } else {
            cout << "[ATTENTION] Preparing sequential stack for <Exp 04-02> has done." << endl;
            break;
        }
    }
}

void exp04_02(SequentialStack &sequentialStack) {
    while (true) {
        char targetData;
        cout << "<Exp 04-02> # for stop: ";
        cin >> targetData;
        if (targetData != '#') {
            emptySequentialStack(sequentialStack);
            CharacterSingleLinkedList arithmeticalExpression;
            cout << "Input arithmetical expression -- ";
            createAndInitCSLL(arithmeticalExpression);
            cout << "Display arithmetical expression: ";
            displayCSLL(arithmeticalExpression);
            isBracketMatched(arithmeticalExpression, sequentialStack);
        } else {
            break;
        }
    }
}

void isBracketMatched(CharacterSingleLinkedList arithmeticalExpression, SequentialStack &sequentialStack) {
    CharacterSingleLinkedList iterator = arithmeticalExpression->next;
    if (iterator != nullptr) {
        while (iterator != nullptr) {
            if (iterator->data == '(') {
                push(sequentialStack, iterator->data);
            } else if (iterator->data == ')') {
                if (isEmpty(sequentialStack)) {
                    cout << "Result: Not matched (Case 2)." << endl;
                    return;
                } else {
                    pop(sequentialStack);
                }
            }
            iterator = iterator->next;
        }
        if (isEmpty(sequentialStack)) {
            cout << "Result: Matched." << endl;
        } else {
            cout << "Result: Not matched (Case 1)." << endl;
        }
    } else {
        cout << "ERROR (isBracketMatched): Empty expression." << endl;
    }
}

void createCircularLinkQueue(CircularLinkQueue &circularLinkQueue) {
    circularLinkQueue.rear = new LinkQueueNode;
    circularLinkQueue.rear->next = circularLinkQueue.rear;
}

void enqueue(CircularLinkQueue &circularLinkQueue, char targetData) {
    LinkQueue newNodePointer = new LinkQueueNode;
    newNodePointer->data = targetData;
    newNodePointer->next = circularLinkQueue.rear->next;
    circularLinkQueue.rear->next = newNodePointer;
    circularLinkQueue.rear = newNodePointer;
}

char dequeue(CircularLinkQueue &circularLinkQueue) {
    LinkQueue headNodePointer = circularLinkQueue.rear->next;
    if (!isEmptyQueue(circularLinkQueue)) {
        LinkQueue frontNodePointer = headNodePointer->next;
        headNodePointer->next = frontNodePointer->next;
        if (circularLinkQueue.rear == frontNodePointer) {
            circularLinkQueue.rear = headNodePointer;
        }
        delete (frontNodePointer);
    } else {
        cout << "WARNING (dequeue): Empty queue." << endl;
    }
}

void emptyQueue(CircularLinkQueue &circularLinkQueue) {
    if (!isEmptyQueue(circularLinkQueue)) {
        LinkQueue iterator = circularLinkQueue.rear->next->next;
        while (iterator != circularLinkQueue.rear->next) {
            dequeue(circularLinkQueue);
            iterator = iterator->next;
        }
    }
    cout << "Emptying queue has done." << endl;
}

bool isEmptyQueue(CircularLinkQueue circularLinkQueue) {
    if (circularLinkQueue.rear->next == circularLinkQueue.rear) {
        return true;
    } else {
        return false;
    }
}

void displayQueue(CircularLinkQueue circularLinkQueue) {
    if (!isEmptyQueue(circularLinkQueue)) {
        LinkQueue iterator = circularLinkQueue.rear->next->next;
        while (iterator != circularLinkQueue.rear->next) {
            cout << iterator->data << " ";
            iterator = iterator->next;
        }
    } else {
        cout << "empty ";
    }
    cout << "<END>" << endl;
}

void myEnqueue(CircularLinkQueue &circularLinkQueue) {
    int count = 1;
    while (true) {
        char targetData;
        cout << "Enqueue (# for stop) [" << count << "]: ";
        cin >> targetData;
        if (targetData == '#') {
            break;
        }
        enqueue(circularLinkQueue, targetData);
        cout << "Queue: ";
        displayQueue(circularLinkQueue);
        count++;
    }
}

void myDequeue(CircularLinkQueue &circularLinkQueue) {
    while (true) {
        char targetData;
        cout << "Dequeue (1 for YES; Any key for NO): ";
        cin >> targetData;
        if (targetData == '1') {
            dequeue(circularLinkQueue);
            cout << "Queue: ";
            displayQueue(circularLinkQueue);
        } else {
            break;
        }
    }
}

int main() {
    // Pre-work: sequentialStack will be use in Exp 04-01 & Exp 04-02.
    SequentialStack sequentialStack;
    createSequentialStack(sequentialStack);

    // Exp 04-01
//    cout << "<Exp 04-01>" << endl;
//    CharacterSingleLinkedList headPointerOfCSLL;
//    createAndInitCSLL(headPointerOfCSLL);
//    cout << "Original characters: ";
//    displayCSLL(headPointerOfCSLL);
//    cout << "Result: ";
//    isCentrosymmetric(headPointerOfCSLL, sequentialStack);

    // Exp 04-02
//    exp04_02(sequentialStack);

    // Exp 04-03
    cout << "<Exp 04-03>" << endl;
    CircularLinkQueue circularLinkQueue;
    createCircularLinkQueue(circularLinkQueue);
    myEnqueue(circularLinkQueue);
    cout << "Original queue: ";
    displayQueue(circularLinkQueue);
    myDequeue(circularLinkQueue);
    emptyQueue(circularLinkQueue);
    cout << "Queue: ";
    displayQueue(circularLinkQueue);

    return 0;
}