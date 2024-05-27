//
//  DoubleStackType.h
//  Lab03
//
//  Created by Jeman Park on 2024/03/26.
//

#ifndef DOUBLESTACKTYPE_H
#define DOUBLESTACKTYPE_H


#define TOP_BIG 1
#define TOP_SMALL 2

#include <iostream>


template <class ItemType>
class DoubleStack {

private:
    int top_small;
    int top_big;
    int* data;
    int length;

public:
    DoubleStack(int MAX_ITEMS);
    int Push(ItemType item);
    ItemType Pop(int direction);
    
    bool isFull();
    bool isEmpty(int direction);
    void Print();
};


template<class ItemType>
DoubleStack<ItemType>::DoubleStack(int MAX_ITEMS)
{
    top_small = -1;
    top_big = MAX_ITEMS;
    data = new int[MAX_ITEMS];
    length = MAX_ITEMS;
}


template<class ItemType>
bool DoubleStack<ItemType>::isEmpty(int direction)
{
    /* Implement the function here (Lab 03-1) */
    // This function checks if the STACK of "direction" is EMPTY
    // if there is ANY item in the STACK of "direction" (either in SMALL or BIG STACK), it returns FALSE
    // if there is NO item, it returns TRUE
    // HINT: you can use "top_small", "top_big", and "length" to check if it is empty.
    
    if (direction == TOP_SMALL) {
        return (top_small == -1);
    }
    if (direction == TOP_BIG) {
        return (top_big == length);
    }

}

template<class ItemType>
bool DoubleStack<ItemType>::isFull()
{
    /* Implement the function here (Lab 03-1) */
    // This function checks if the STACK is FULL
    // if the number of items in SMALL stack + the number of items in BIG stack == length, it returns TRUE
    // otherwise, it returns FALSE
    // HINT: you can use "top_small" and "top_big" to check if it is full.
    return (top_small + 1 == top_big); // 두개의 top의 위치가 맞닿아 있는지 판단

}

template<class ItemType>
int DoubleStack<ItemType>::Push(ItemType newItem)
{
    /* Implement the function here (Lab 03-1) */
    // This function PUSH "newItem" into the STACK
    //
    // 1) if the STACK is already FULL, just terminate the function and return -1
    // if STACK is NOT FULL and
    // 2) if "newItem" >= 100, then push into BIG STACK and return 0
    // 3) if "newItem" < 100, then push into SMALL STACK and return 0
    
    if (isFull()) {
        return -1;
    }
    if (newItem < 100) {
        top_small++;
        data[top_small] = newItem;
    }
    if (newItem >= 100) {
        top_big--;
        data[top_big] = newItem;
    }

}

template<class ItemType>
ItemType DoubleStack<ItemType>::Pop(int direction)
{
    ItemType result = -1;
    
    /* Implement the function here (Lab 03-1) */
    // This function POP the item from the STACK
    //
    // 1) if the STACK of "direction" is EMPTY, just terminate the function and return -1
    // if STACK of "direction" is NOT EMPTY and
    // 2) if "direction" == "TOP_BIG", then POP item from the BIG STACK and return the popped item
    // 3) if "direction" == "TOP_SMALL", then POP item from the SMALL STACK and return the popped item
    
    if (isEmpty(direction)) {
        return result;
    }
    if (direction == TOP_SMALL) {
        result = data[top_small];
        top_small--;
        return result;
    }
    if (direction == TOP_BIG) {
        result = data[top_big];
        top_big++;
        return result;
    }

    return result;
}


template<class ItemType>
void DoubleStack<ItemType>::Print() {

    std::cout << "[ ";
    for (int i = 0; i <= top_small; i++) {
        std::cout << data[i] << "\t";
    }

    std::cout << " | ";
    for (int i = top_big; i < length; i++) {
        std::cout << data[i] << "\t";
    }
    std::cout << " ]";
    std::cout << std::endl;
}


#endif
