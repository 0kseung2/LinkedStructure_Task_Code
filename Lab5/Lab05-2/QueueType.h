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

    // �ӽ� ��� ������ ����
    NodeType<ItemType>* tempPtr = pFront;
    // ���������� ���鼭 ��� ����
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
    
    // ���ο� ��� ������ֱ�
    NodeType<ItemType>* newNode;
    newNode = new NodeType<ItemType>;
    newNode->value = newItem;
    newNode->next = nullptr;
    
    // ť�� ������� ���� �� pRear�� ����Ű�� ��尡 ���ο� ��� ����Ű�� �ϱ�. ť�� ��������� pRear�� ����Ű�� ��尡 ���⿡ next�� ����.
    if (!isEmpty()) {
        pRear->next = newNode;
    }
    else { // ť�� ������� ��� pFront�� newNode ����Ű�� �ϱ�
        pFront = newNode;
    }
    //pRear��嵵 ���ο� ��� ����Ű�� �ϱ�
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
    // �ӽ� ��� ������ �������ֱ�
    NodeType<ItemType>* tempPtr;
    //tempPrt�� pFront �����Ͽ� pFront�� ����Ű�� �ִ� ��� ����Ű�� �ϱ�
    tempPtr = pFront;
    // pFront �� ĭ ������ �Ű��ֱ�
    pFront = pFront->next;
    // ret_value �Ķ���Ϳ� pFront�� ����Ű�� ��� value�� �������ֱ�
    ret_value = tempPtr->value;
    // pFront�� ����Ű�� ��� �����ֱ�
    delete tempPtr;
    // ���� ��尡 �� �� ���� �־��� ��, pRear�� ����Ű�� ��尡 ���ŵǾ�, 
    // ��� ������ ����Ű�� �����̴�. �׷��Ƿ� pRear�� nullptr�� ����Ű�� ���ش�
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
