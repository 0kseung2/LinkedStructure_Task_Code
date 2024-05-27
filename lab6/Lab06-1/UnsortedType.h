//
//  UnsortedType.h
//  Lab06
//
//  Modified by Jeman Park on 2024/05/01.
//

#ifndef UNUnsortedType_H
#define UNUnsortedType_H

#include<iostream>
using namespace std;


template<class ItemType>
struct NodeType
{
    ItemType value;
    NodeType* next;
};

template <class ItemType>
class UnsortedType
{
public:
    UnsortedType();
    ~UnsortedType();
    bool isFull();
    bool isEmpty();
    int  size();
    bool findItem(ItemType& item);
    void appendItem(ItemType item);
    void removeItem(ItemType item);

    void clear();
    ItemType getItem(int pos);
    void printList();
    
private:
    NodeType<ItemType>* listData;
    int length;
};





template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
    length = 0;
    listData = nullptr;
}


template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{
    
    /* Implement the function here */
    // Deallocate all nodes in the queue.
    // Set the pointer (listData) and length properly.
    NodeType<ItemType>* tempPtr;
    tempPtr = listData; // tempPtr�� �������� ��带 ����Ű�� �Ѵ�.
    while (listData != nullptr) {
        listData = listData->next; // listData �����ʹ� �� ���� ��带 ����Ű�� �Ѵ�.
        delete tempPtr; // tempPtr�� ����Ű�� ��带 �����Ѵ�.
        tempPtr = listData; // tempPtr�� �ٽ� listData�� ����Ű�� ��带 ����Ű�� �Ѵ�.
        // �̷��� �ݺ��ϸ� ������ ��带 ���� �ᱹ listData�� tempPtr�� nullptr�� ����Ű�� �ȴ�. �׸��� while���� ������.
    }
    length = 0; // ��带 �� �����Ͽ����Ƿ� length�� 0�� �ȴ�.
    
}


template<class ItemType>
bool UnsortedType<ItemType>::isFull()
{
    NodeType<ItemType>* tempPtr;
    try
    {
        tempPtr = new NodeType<ItemType>;
        delete tempPtr;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

template<class ItemType>
bool UnsortedType<ItemType>::isEmpty()
{
    return (listData == nullptr);
}


template <class ItemType>
int UnsortedType<ItemType>::size()
{
    return length;
}


template <class ItemType>
bool UnsortedType<ItemType>::findItem(ItemType& item)
{
    NodeType<ItemType>* tempPtr;
    tempPtr = listData;
    
    
    while(tempPtr != nullptr){
        if((tempPtr->value) == item ){
            item = tempPtr -> value;
            return true;
        }
        else{
            tempPtr = tempPtr -> next;
        }
    }
    return false;
}


template <class ItemType>
void UnsortedType<ItemType>::appendItem(ItemType item)
{
    
    /* Implement the function here */
    // Insert the new item into the sorted list.
    // * append a new item by creadting and linking a new node
    // * "appending" happens with the best time complexity.
    // * Handle "length" properly
    // * Handle edge cases properly
    
    
    // Time Complexity: O(  1  )
    // ������ appendItem�� �ٸ��� �� �ڰ� �ƴ� �� �տ� ��带 ����ִ´�.
    NodeType<ItemType>* newNode;
    newNode = new NodeType<ItemType>; // ���ο� ��� ����
    newNode->value = item; // ���ο� ����� value���� item�� ����
    newNode->next = listData; // ���ο� ����� next���� listData�� ����Ű�� �ִ� ù���� ����� �ּڰ� ����
    listData = newNode; // �׻� ù���� ��带 ����Ű�� listData�� newNode�� ����Ű�� �Ѵ�.
    length++; // ��尡 �ϳ� �߰��Ǿ����Ƿ� lenght�� 1 �߰����ش�.
    
}


template <class ItemType>
void UnsortedType<ItemType>::removeItem(ItemType item)
{
    /* Implement the function here */
    // Delete the item from the sorted list.
    // * Find the item
    // * If "item" NOT exists in the list, do not anything (return)
    // * Delete the item from the list and maintain the list (linked structures) and "length" properly
    // * Deallocate the deleted node
    // * Handle edge cases properly
        
    
    // Time Complexity: O(  N  )
    
    // ���� list�� ��尡 ���� ���
    if (isEmpty()) {
        return;
    }
    // list�� ��尡 �ϳ��� ��쿡�� �� ����� next�� nullptr�� ����Ű�� �����Ƿ� �Ʒ��� while���� �ٷ� Ż���ϱ⿡
    // �߰��� �ڵ尡 �ʿ����.

    // ������ �������� list�� �������� �ִ� ��쿡�� ������ ������ ���� nullptr�� ����Ű�� �����Ƿ� tempPtr�� nullptr�� ����Ű�� �ȴ�.


    //�ϴ� �⺻���� ��Ȳ�� �����ϰ� �ڵ带 ¥����
    // 1. ã�ƾ� �ϰ�, 2. �����ؾ� �Ѵ�.
    NodeType<ItemType>* deallocPtr; // ��带 ������ ��� ������
    NodeType<ItemType>* tempPtr; // ������ ��� ������
    tempPtr = listData; // ���� ������ ���������� �������� ã�� ����
    while (tempPtr->next != nullptr) { // tempPtr�� �������� �����Ҷ����� ����
        if ((tempPtr->next)->value == item) { // ���� tempPtr�� ����Ű�� ����� ���� ����� value���� item�� ���ٸ�
            deallocPtr = tempPtr->next; // ������ ��带 deallocPtr�� ����Ű�� �Ѵ�.
            tempPtr->next = (tempPtr->next)->next; // tempPtr�� ����Ű�� ����� next�� tempPtr�� ����Ű�� ����� ���� ����� ���� ��带 ����Ų��.
            delete deallocPtr; // ��带 �����Ѵ�.
            length--; // ���̸� �ϳ� ���δ�.
        }
        tempPtr = tempPtr->next; // tempPtr�� ����ؼ� ���� ��带 ����Ű�� �Ѵ�.
        if (tempPtr == nullptr) { // tempPtr�� nullptr�� �Ǵ� ���� list�� ������ ��带 �����ϴ� ���ۿ� ����.
            return;
        }
    }
    // ���� ������ item�� ������ �ִ� ��尡 ���°��
    return; // �ƹ��͵� ���� return �ؼ� �Լ��� ������.
    
    
    // ��... �� �ڵ尡 pdf �ڵ�� ���� �ٸ��� �ϴ� ���ɷ� �غ���
    
    
    
    
    
}


template <class ItemType>
ItemType UnsortedType<ItemType>::getItem(int pos)
{
    /* Implement the function here */
    // Return the "pos"-th item in the list (array-like).
    // if "pos" is out of list, return -1
    // For example, if the list is [1, 3, 5, 7]
    // getItem(0) returns 1
    // getItem(2) returns 5
    // getItem(3) returns 7
    // getItem(4) returns -1 (length of list is 4 (0 ~ 3)
    
    // Time Complexity: O(  N  )

    // pos�� list�� ������ �Ѿ�� ���
    if (pos > size() - 1) {
        return -1;
    }
    ItemType ret;
    int searchingIndex = 0; // ���߿� �� ���� pos�� �������� �׶��� ���� ã�� ��
    NodeType<ItemType>* tempPtr;
    tempPtr = listData; // tempPtr�� ���۳���� �����Ϳ��� ����Ѵ�.
    while (tempPtr != nullptr) { // tempPtr�� nullptr�� �ƴ� ������
        if (searchingIndex == pos) { // ���� ã���� �ϴ� �ε����� �����ߴٸ�
            ret = tempPtr->value; // ret�� ���� tempPtr�� ����Ű�� ����� value�� ����
            return ret;
        }
        tempPtr = tempPtr->next; // tempPtr�� ��� ���� ��带 Ž���Ѵ�.
        searchingIndex++; // ���ϴ� �ε����� ���� ������ serarchingIndex�� 1�� �����Ѵ�.
    }
    // while�� �Ʒ� �ڵ忡 list�� �� Ž���ߴµ��� searchingIndex�� pos�� ������ ���� ���
    // ��, pos�� list�� ������ �Ѿ�� ��쿡�� return -1�� �ϴ� �ڵ带 �־ ������
    // ���� while���� ���� �ð����� ���� while �� ������ pos�� size-1���� Ŭ �� return -1
    // �� �ϰ� �ϸ� �ξ� ������ �Լ��� ���� �� �ִ�.
    
    
    
    
    
}



template <class ItemType>
void UnsortedType<ItemType>::printList(){
    NodeType<ItemType>* tempPtr = listData;
    
    std::cout << "[\t";
    while (tempPtr != NULL)
    {
        std::cout << tempPtr->value << "\t";
        tempPtr = tempPtr->next;
    }
    
    std::cout << "]" << std::endl;
    
}

#endif
