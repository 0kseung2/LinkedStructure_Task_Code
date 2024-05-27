//
//  StackType.cpp
//  Lab05
//
//  Created by Jeman Park on 2024/04/17.
//

#include "StackType.h"

StackType::StackType()
{
    topPtr = nullptr;
}

StackType::~StackType()
{
    /* Implement the function here */
    // This destructor function iteratively deletes all nodes in the stack.
    // All "NodeType" should be "deallocated" properly.
    // It returns nothing
    
    //임시 노드 생성, topPtr 가리키게 한다.
    NodeType* tempPtr = topPtr;
    // 반복문 돌면서 동적할당된 노드들을 제거한다.
    while (topPtr!=nullptr) {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
    
    
    
    
    
    
}


void StackType::clear(){
    this->~StackType();
}

bool StackType::isEmpty() const
{
    
    return (topPtr == nullptr);
    
}


bool StackType::isFull() const
{
    NodeType * newNode;
    try {
        newNode = new NodeType;
        delete newNode;
        return false;
    }
    catch (std::bad_alloc exception){
        return true;
    }
}

int StackType::size() const
{
    /* Implement the function here */
    // This function counts the number of nodes in the stack and returns it.
    
    int len = 0;
    // 임시 노드 포인터 생성
    NodeType* tempPtr;
    tempPtr = topPtr;
    while (tempPtr != nullptr) {
        tempPtr = tempPtr->next;
        len++;
    }
    
    
    
    
    
    return len;
    
}

void StackType::push(ItemType newItem)
{
    /* Implement the function here */
    // This function pushes "newItem" into the stack, and returns NOTHING.
    
    if (isFull()) {
        return;
    }
    // 새로운 노드 생성
    NodeType* newNode;
    newNode = new NodeType;
    // value, next 배정
    newNode->value = newItem;
    newNode->next = topPtr;
    //topPtr은 이제 newNode 가리켜야 됨
    topPtr = newNode;
    
}

ItemType StackType::pop()
{
    /* Implement the function here */
    // This function pops the item at the top of the stack, and returns it.
    // It should deallocate the popped node.
    // If the stack is EMPTY, it returns -1.
    
    ItemType ret;
    if (isEmpty()) {
        return -1;
    }
    //임시 노드 포인터 만들기
    NodeType* tempPtr;
    // 임시 노드가 topPtr값 복사
    tempPtr = topPtr;
    // topPtr은 원래 top보다 밑에 있는 애 가리켜야 한다.
    topPtr = topPtr->next;
    // ret에 원래 top값 넣어줌
    ret = tempPtr->value;
    // 원래 top이었던 애 제거하고 pop한다.
    delete tempPtr;
    
    
    
    return ret;
}


void StackType::Print() {
    if(isEmpty()){
        cout << "[EMPTY STACK]" << endl;
        return;
    }
    
    cout << "(top)\t";
    NodeType * tempPtr = topPtr;

    while(tempPtr != nullptr){
        cout << tempPtr->value << "\t";
        tempPtr = tempPtr->next;
    }
    
    cout <<  " ] " << endl;
        
}









