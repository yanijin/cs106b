// VectorInt.cpp
// Implementation of VectorInt class

#include "VectorInt.h"

// constructor
VectorInt::VectorInt(){
    capacity = INITIAL_CAPACITY;
    elements = new int[capacity];
    count = 0;
}

// destructor
VectorInt::~VectorInt(){
    delete [] elements;
}

// append value to the end of our array
void VectorInt::add(int value){
    if (count == capacity) {
        expand();
    }
    elements[count] = value;
    count++;
}

// insert value at index
void VectorInt::insert(int index, int value){
    if (count == capacity) {
        expand();
    }
    for (int i=count; i > index; i--) {
        elements[i] = elements[i-1];
    }
    elements[index] = value;
    count++;
}

// return the element at index
int VectorInt::get(int index){
    return elements[index];
}

// remove value from index
void VectorInt::remove(int index){
    for (int i=index; i < count - 1; i++) {
        elements[i] = elements[i+1];
    }
    count--;
}

// returns the number of elements
int VectorInt::size(){
    return count;
}

// returns true if there aren't any elements
bool VectorInt::isEmpty(){
    return count == 0;
}

// overload << operator
ostream &operator<<(ostream &out, VectorInt &vec){
    out << "[";
    for (int i=0; i < vec.count; i++) {
        out << vec.elements[i];
        if (i < vec.count - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

void VectorInt::expand() {
    // 1. ask for new space for a new array
    int *newElements = new int[capacity * 2];

    // 2. copy the values over
    for (int i=0; i < count; i++) {
        newElements[i] = elements[i];
    }

    // 3. delete old array
    delete [] elements;

    // 4. point elements to new array
    elements = newElements;

    // 5. Update capacity
    capacity *= 2;
}
