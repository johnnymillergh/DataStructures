//
// Created by Johnny on 9/8/2017
//
#include <iostream>
#include <math.h>

#define MAXSIZE 100
using namespace std;

typedef struct {
    int *arrayPointer;
    int length;
} SequentialList;

void create(SequentialList &sequentialList) {
    sequentialList.arrayPointer = new int[MAXSIZE];
    sequentialList.length = 0;
}

void init(SequentialList &sequentialList) {
    cout << "Length of sequential list: ";
    int lengthInput;
    cin >> lengthInput;
    sequentialList.length = lengthInput;
    for (int i = 0; i < lengthInput; i++) {
        int tempElement;
        cout << "Node No. " << i + 1 << ": ";
        cin >> tempElement;
        sequentialList.arrayPointer[i] = tempElement;
    }
}

void bubbleSort(SequentialList &sequentialList) {
    int tempElement;
    for (int i = 0; i < sequentialList.length - 1; i++) {
        for (int j = 0; j < sequentialList.length - 1; j++) {
            tempElement = sequentialList.arrayPointer[j];
            if (tempElement > sequentialList.arrayPointer[j + 1]) {
                sequentialList.arrayPointer[j] = sequentialList.arrayPointer[j + 1];
                sequentialList.arrayPointer[j + 1] = tempElement;
            }
        }
    }
}

void insert(SequentialList &sequentialList, int element) {
    // Step 1: Find minimum & maximum
    int minimumElement = sequentialList.arrayPointer[0];
    int maximumElement = sequentialList.arrayPointer[sequentialList.length - 1];

    // Step 2: 3 kinds of condition
    if (element < minimumElement) {
        for (int i = sequentialList.length; i > 0; i--) {
            sequentialList.arrayPointer[i] = sequentialList.arrayPointer[i - 1];
        }
        sequentialList.arrayPointer[0] = element;
    } else if (minimumElement < element && element < maximumElement) {
        int position = 0;
        for (int i = 0; i < sequentialList.length; i++) {
            if (sequentialList.arrayPointer[i] > element) {
                position = i;
                break;
            }
        }
        for (int i = sequentialList.length; i > position; i--) {
            sequentialList.arrayPointer[i] = sequentialList.arrayPointer[i - 1];
        }
        sequentialList.arrayPointer[position] = element;
    } else if (element > maximumElement) {
        sequentialList.arrayPointer[sequentialList.length] = element;
    }

    // Step 3: length of sequential list plus 1
    sequentialList.length++;
}

void leftShiftElement(SequentialList &sequentialList, int count) {
    // Step 1:
    for (int i = 0; i < count; i++) {
        for (int j = sequentialList.length; j > 0; j--) {
            sequentialList.arrayPointer[j] = sequentialList.arrayPointer[j - 1];
        }
        sequentialList.arrayPointer[0] = sequentialList.arrayPointer[sequentialList.length];
    }
}

void reverse(SequentialList &sequentialList) {
    int count = static_cast<int>(ceil(sequentialList.length / 2));
    for (int i = 0; i < count; i++) {
        sequentialList.arrayPointer[sequentialList.length] = sequentialList.arrayPointer[i];
        sequentialList.arrayPointer[i] = sequentialList.arrayPointer[sequentialList.length - 1 - i];
        sequentialList.arrayPointer[sequentialList.length - 1 - i] = sequentialList.arrayPointer[sequentialList.length];
    }
}

void display(SequentialList sequentialList) {
    cout << "Array[" << sequentialList.length << "]: ";
    for (int i = 0; i < sequentialList.length; i++) {
        cout << sequentialList.arrayPointer[i] << " ";
    }
    cout << "<END>" << endl;
}

int main() {
    // Pre-work
    SequentialList list;
    create(list);
    init(list);
    display(list);
    bubbleSort(list);
    cout << "In ascending order, ";
    display(list);

    // Exp 01-01
    cout << "Exp 01-01: Insert: ";
    int element;
    cin >> element;
    insert(list, element);
    display(list);

    // Exp 01-02
    cout << "Exp 01-02: Left shift element: ";
    int count;
    cin >> count;
    leftShiftElement(list, count);
    display(list);

    // Exp 01-03
    cout << "Exp 01-03: Reverse item: ";
    reverse(list);
    display(list);
    return 0;
}