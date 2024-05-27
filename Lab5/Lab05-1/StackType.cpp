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
    
    //�ӽ� ��� ����, topPtr ����Ű�� �Ѵ�.
    NodeType* tempPtr = topPtr;
    // �ݺ��� ���鼭 �����Ҵ�� ������ �����Ѵ�.
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
    // �ӽ� ��� ������ ����
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
    // ���ο� ��� ����
    NodeType* newNode;
    newNode = new NodeType;
    // value, next ����
    newNode->value = newItem;
    newNode->next = topPtr;
    //topPtr�� ���� newNode �����Ѿ� ��
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
    //�ӽ� ��� ������ �����
    NodeType* tempPtr;
    // �ӽ� ��尡 topPtr�� ����
    tempPtr = topPtr;
    // topPtr�� ���� top���� �ؿ� �ִ� �� �����Ѿ� �Ѵ�.
    topPtr = topPtr->next;
    // ret�� ���� top�� �־���
    ret = tempPtr->value;
    // ���� top�̾��� �� �����ϰ� pop�Ѵ�.
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









