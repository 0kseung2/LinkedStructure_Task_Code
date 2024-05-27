//
//  QueueType.h
//  Lab05
//
//  Modified by Jeman Park on 2024/04/17.
//


#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include <iostream>
using namespace std;

template <class ItemType>
struct NodeType{
    ItemType value;
    NodeType * next;
};

template <class ItemType>
class QueueType
{
    
private:
    NodeType<ItemType> * pFront;
    NodeType<ItemType> * pRear;
    
public:
    
    QueueType();
    ~QueueType();
    
    void clear();
    void enqueue(ItemType newItem);
    void dequeue(ItemType& value);

    int size() const;
    bool isFull() const;
    bool isEmpty() const;
    
    void Print();
    
};


template <class ItemType>
QueueType<ItemType>::QueueType()
{
    pFront = nullptr;
    pRear = nullptr;
}

template <class ItemType>
QueueType<ItemType>::~QueueType()
{
    /* Implement the function here */
    // This destructor function iteratively deletes all nodes in the queue.
    // All "NodeType" should be "deallocated" properly.
    // It returns nothing

    // 임시 노드 포인터 생성
    NodeType<ItemType>* tempPtr = pFront;
    // 순차적으로 가면서 노드 제거
    while (pFront!=nullptr) {
        tempPtr = pFront;
        pFront = pFront->next;
        delete tempPtr;
    }
    
    
    
    
    
}

template <class ItemType>
void QueueType<ItemType>::clear()
{
    this -> ~QueueType();
}

template <class ItemType>
int QueueType<ItemType>::size() const
{
    /* Implement the function here */
    // This function counts the number of nodes in the queue and returns it.
    NodeType<ItemType>* tempPtr = pFront;
    int len =0;
    
    while (tempPtr != nullptr) {
        len++;
        tempPtr = tempPtr->next;
    }

    return len;
}


template <class ItemType>
bool QueueType<ItemType>::isEmpty() const
{
    return (pFront == nullptr);
}

template <class ItemType>
bool QueueType<ItemType>::isFull() const
{
    NodeType<ItemType> * newNode;
    try {
        newNode = new NodeType<ItemType>;
        delete newNode;
        return false;
    }
    catch (std::bad_alloc exception){
        return true;
    }
}

template <class ItemType>
void QueueType<ItemType>::enqueue(ItemType newItem)
{
    /* Implement the function here */
    // This function enqueues "newItem" into the queue, and returns NOTHING.
    if (isFull()) {
        return;
    }
    
    // 새로운 노드 만들어주기
    NodeType<ItemType>* newNode;
    newNode = new NodeType<ItemType>;
    newNode->value = newItem;
    newNode->next = nullptr;
    
    // 큐가 비어있지 않을 때 pRear이 가리키던 노드가 새로운 노드 가리키게 하기. 큐가 비어있으면 pRear이 가리키던 노드가 없기에 next도 없다.
    if (!isEmpty()) {
        pRear->next = newNode;
    }
    else { // 큐가 비어있을 대는 pFront가 newNode 가리키게 하기
        pFront = newNode;
    }
    //pRear노드도 새로운 노드 가리키게 하기
    pRear = newNode;
    
    
    
    
    
    
    
    
}

template <class ItemType>
void QueueType<ItemType>::dequeue(ItemType& ret_value)
{
    /* Implement the function here */
    // This function dequeues the most front item in the queue, and returns it through "RETURN BY REFERENCE (ret_value).
    // You need to set "ret_value" as the dequeue item's value to return.
    // If the queue is empty, set "ret_value" as -1
    
    if (isEmpty()) {
        ret_value = -1;
        return;
    }
    // 임시 노드 포인터 생성해주기
    NodeType<ItemType>* tempPtr;
    //tempPrt에 pFront 복사하여 pFront가 가리키고 있는 노드 가리키게 하기
    tempPtr = pFront;
    // pFront 한 칸 옆으로 옮겨주기
    pFront = pFront->next;
    // ret_value 파라미터에 pFront가 가리키던 노드 value값 복사해주기
    ret_value = tempPtr->value;
    // pFront가 가리키던 노드 없애주기
    delete tempPtr;
    // 만약 노드가 한 개 남아 있었을 때, pRear은 가리키던 노드가 제거되어, 
    // 어떠한 공간을 가리키는 상태이다. 그러므로 pRear이 nullptr을 가리키게 해준다
    if (isEmpty()) {
        pRear = nullptr;
    }
}

template <class ItemType>
void QueueType<ItemType>::Print(){
    if(isEmpty()){
        cout << "[EMPTY QUEUE]" << endl;
        return;
    }
    
    cout << "(front)\t[";
    NodeType<ItemType> * tempPtr = pFront;
    
    while(tempPtr != nullptr){
        cout << tempPtr -> value << "\t";
        tempPtr = tempPtr->next;
    }
    cout << "]\t(rear)" << endl;
}



#endif /* QUEUETYPE_H */
