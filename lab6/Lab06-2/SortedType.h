//
//  SortedType.h
//  Lab06
//
//  Modified by Jeman Park on 2024/05/01.
//

#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include<iostream>
using namespace std;


template<class ItemType>
struct NodeType
{
    ItemType value;
    NodeType* next;
};

template <class ItemType>
class SortedType
{
public:
    SortedType();
    ~SortedType();
    bool isFull();
    bool isEmpty();
    int  size();
    bool findItem(ItemType& item);
    void insertItem(ItemType item);
    void removeItem(ItemType item);

    void clear();
    ItemType getItem(int pos);
    void printList();
    
private:
    NodeType<ItemType>* listData;
    int length;
};





template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    listData = nullptr;
}


template <class ItemType>
SortedType<ItemType>::~SortedType()
{
    
    /* Implement the function here */
    // Deallocate all nodes in the queue.
    // Set the pointer (listData) and length properly.
    NodeType<ItemType>* tempPtr;
    while (listData != nullptr) {
        tempPtr = listData; // tempPtr�� listData�� ����Ű�� ��带 ����Ű�� �Ѵ�.
        listData = listData->next; // listData�� ���� ��带 ����Ų��.
        delete tempPtr; // tempPtr�� ����Ű�� ��带 �����Ѵ�.
        // �� ������ �ݺ��ϸ� listData�� �� ������ ��带 ����Ű�� ���� �� �ڵ� ���� �� listData�� nullptr�� ����Ű�� �ǰ�,
        // ������ ���� ���ŵǰ�, while���� ������ �ȴ�.
    }
    
    
}


template<class ItemType>
bool SortedType<ItemType>::isFull()
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
bool SortedType<ItemType>::isEmpty()
{
    return (listData == nullptr);
}


template <class ItemType>
int SortedType<ItemType>::size()
{
    return length;
}


template <class ItemType>
bool SortedType<ItemType>::findItem(ItemType& item)
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
void SortedType<ItemType>::insertItem(ItemType item)
{
    
    /* Implement the function here */
    // Insert the new item into the sorted list.
    // * Find the proper position
    // * Insert new item by creadting and linking a new node
    // * Handle "length" properly
    // * Handle edge cases properly
    
    
    // Time Complexity: O(  N  )
    

    // 1. list�� ���� �� �ִ� ���
    if (isFull()) {
        return;
    }

    // item������ ū ���� ������ �Ǵ� ����� �ٷ� �� ��带 tempPtr�� �����Ѿ� �ȴ�.
    // ū ���� ������ ��带 tempPtr�� ����Ű�� �Ǹ� �ٷ� �� ��忡 ������ �� ���� ����
    NodeType<ItemType>* tempPtr; // Ž���� ��� �����͸� ������ش�.
    NodeType<ItemType>* newNode; // ���ο� ��� �����͸� ����� �ش�. 
    newNode = new NodeType<ItemType>; // �� ��带 ������ش�.
    newNode->value = item; // �� ����� value���� item�� �ȴ�.
    newNode->next = nullptr; // �� ����� next ���� �ϴ� nullptr�� ����Ű�� �Ѵ�.

    // 2. ����Ʈ�� ����ִ� ���¿��� �� ��带 ����� ���
    if (isEmpty()) {
        listData = newNode; // listData�� ���� ����� �� ��带 ����Ű�� �Ѵ�.
        length++; // ����Ʈ�� ���̰� 1 �����ȴ�.
        return;
    }

    // 3. ����Ʈ�� ù��° ��ġ�� �� ��尡 ���ԵǴ� ���(item���� ����Ʈ���� ���� ���� ��)
    if (item < listData->value) {
        newNode->next = listData; // newNode�� next�� listData�� ����Ű�� �ִ� ù��° ��带 ����Ű�� �Ѵ�.
        listData = newNode; // listData�� ���� ����� �� ��带 ����Ű�� �Ѵ�.
        return;
    }

    // 4. ����Ʈ�� ��尡 �ϳ��� �ִ� ���� �׳� �Ʒ��� ������ ��ġ�� �ȴ�.
    // �ٷ� while���� Ż���� �� �ڵ带 �����Ѵ�.
    // 5. ����Ʈ�� ������ ��庸�� �� ����� item���� ū ��� �׳� �Ʒ��� ������ ��ġ�� �ȴ�.
    // 6. ����Ʈ�� ������ ��庸�� �� ����� item���� ���� ��� �׳� �Ʒ��� ������ ��ġ�� �ȴ�.
    tempPtr = listData; // ����Ʈ�� Ž���ϱ� ���� tempPtr�� ù��° ��带 ����Ű�� �Ѵ�.
    // �Ϲ����� ���
    while (tempPtr->next != nullptr) { // tempPtr�� ����Ű�� ��尡 nullptr�� ����Ű�� ���� ������
        if ((tempPtr->next)->value > item) { // ���� tempPtr�� ����Ű�� ����� ���� ����� value���� item���� ũ�ٸ�
            break;
        }
        tempPtr = tempPtr->next;
    }
    // ���� tempPtr�� ����Ű�� ����� ���� ����� value�� item���� ũ��.
    newNode->next = tempPtr->next; // newNode�� next�� tempPtr�� ����Ű�� ����� ���� ��带 ����Ű�� �Ѵ�.
    tempPtr->next = newNode; // tempPtr�� ����Ű�� ��尡 �� ��带 ����Ű�� �Ѵ�.
    length++; // �� ��尡 ���ԵǾ����Ƿ� length�� 1 �����Ѵ�.
    return;

    
}


template <class ItemType>
void SortedType<ItemType>::removeItem(ItemType item)
{
    /* Implement the function here */
    // Delete the item from the sorted list.
    // * Find the item
    // * If "item" NOT exists in the list, do not anything (return)
    // * Delete the item from the list and maintain the list (linked structures) and "length" properly
    // * Deallocate the deleted node
    // * Handle edge cases properly
        
    
    // Time Complexity: O(  N  )

    // 1. ����Ʈ�� ������� ��� �׳� ����
    if (isEmpty()) {
        return;
    }


    NodeType<ItemType>* tempPtr; // Ž���� ��� ������ ����
    NodeType<ItemType>* deallocPtr; // ������ ��� ������ ����
    tempPtr = listData; // ���� ��带 ����Ų��.

    // 3. ����Ʈ�� ù��° ��带 �����ϴ� ���
    if (item == listData->value) {
        listData = listData->next; // listData�� �� ���� ��带 ����Ų��.
        delete tempPtr; // ù ��带 �����Ѵ�.
        length--; // ��尡 ���ŵǾ����Ƿ� length�� 1 �پ���.
        return;
    }
    // 4. ������ ��尡 �������� �����ϴ� ���� �Ʒ��� ������ ������ �ȴ�.
    while(item != (tempPtr->next)->value) { // ���� ����� ���� ������ Ž���Ѵ�.
        tempPtr = tempPtr->next; // ���� tempPtr�� ����Ű�� ����� ���� ����� value���� item�� ���� ������ ��� �Ѿ��.
        // �ƿ� item���� ���� value���� ���� ��� ���� ���
        if (tempPtr->next == nullptr) { 
            // ���� tempPtr�� ������ ������ ����Ű�� �ȴٸ� ������ ������ Ž������ ����
            // 2. item�� ��ġ�ϴ� ���� �����ٴ� ���̹Ƿ� �Լ��� �����Ѵ�.
            return;
        }
    }
    // ������ ��带 ã�� ��� 
    deallocPtr = tempPtr->next; // ������ ��带 deallocPtr�� ����Ű�� �Ѵ�.
    // tempPtr�� ����Ű�� ����� next�� ���� ����� ���� ��带 ����Ű�� �Ѵ�.
    // (tempPtr->next�� ����Ʈ�� ������ ����� ��쿡�� nullptr�� ����Ű�� �ȴ�.)
    tempPtr->next = (tempPtr->next)->next;
    delete deallocPtr; // ������ ��带 �����Ѵ�.
    length--; // ��尡 ���ŵǾ����Ƿ� length�� 1 �����Ѵ�.
    

    
}


template <class ItemType>
ItemType SortedType<ItemType>::getItem(int pos)
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
    ItemType ret;
    NodeType<ItemType>* tempPtr = listData; // Ž���� ��������ʹ� ���۳�带 ����Ű�� �ͺ��� �����Ѵ�.
    // pos�� 0�� ���� �״�� listData�� ����Ű�� ����� �� ����
    for (int i = 1;i <= pos;i++) { // pos�� 0�� ���� while���� ���� �ʰ� �ٷ� ���ϵȴ�.
        // pos�� 1 �̻��� ��쿡�� pos�� �ε����� �°� ����� �ȴ�.
        tempPtr = tempPtr->next;
        if (tempPtr == nullptr) { // ���� pos�� list�� ���̺��� ū �ε����� ��� -1�� �����Ѵ�.
            return -1;
        }

    }
    ret = tempPtr->value;
    return ret;
    
}



template <class ItemType>
void SortedType<ItemType>::printList(){
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
