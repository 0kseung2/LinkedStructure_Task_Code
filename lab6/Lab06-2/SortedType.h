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
        tempPtr = listData; // tempPtr이 listData가 가리키는 노드를 가리키게 한다.
        listData = listData->next; // listData는 다음 노드를 가리킨다.
        delete tempPtr; // tempPtr이 가리키는 노드를 제거한다.
        // 위 순서를 반복하면 listData가 맨 마지막 노드를 가리키고 있을 때 코드 진행 중 listData는 nullptr을 가리키게 되고,
        // 마지막 노드는 제거되고, while문도 끝나게 된다.
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
    

    // 1. list가 가득 차 있는 경우
    if (isFull()) {
        return;
    }

    // item값보다 큰 값을 가지게 되는 노드의 바로 전 노드를 tempPtr이 가리켜야 된다.
    // 큰 값을 가지는 노드를 tempPtr이 가리키게 되면 바로 전 노드에 접근할 수 없기 때문
    NodeType<ItemType>* tempPtr; // 탐색할 노드 포인터를 만들어준다.
    NodeType<ItemType>* newNode; // 새로운 노드 포인터를 만들어 준다. 
    newNode = new NodeType<ItemType>; // 새 노드를 만들어준다.
    newNode->value = item; // 새 노드의 value값은 item이 된다.
    newNode->next = nullptr; // 새 노드의 next 값은 일단 nullptr을 가리키게 한다.

    // 2. 리스트가 비어있는 상태에서 새 노드를 만드는 경우
    if (isEmpty()) {
        listData = newNode; // listData가 시작 노드인 새 노드를 가리키게 한다.
        length++; // 리스트의 길이가 1 증가된다.
        return;
    }

    // 3. 리스트의 첫번째 위치로 새 노드가 삽입되는 경우(item값이 리스트에서 가장 작을 때)
    if (item < listData->value) {
        newNode->next = listData; // newNode의 next가 listData가 가리키고 있던 첫번째 노드를 가리키게 한다.
        listData = newNode; // listData가 시작 노드인 새 노드를 가리키게 한다.
        return;
    }

    // 4. 리스트에 노드가 하나만 있던 경우는 그냥 아래의 과정을 거치면 된다.
    // 바로 while문을 탈출한 뒤 코드를 진행한다.
    // 5. 리스트의 마지막 노드보다 새 노드의 item값이 큰 경우 그냥 아래의 과정을 거치면 된다.
    // 6. 리스트의 마지막 노드보다 새 노드의 item값이 작은 경우 그냥 아래의 과정을 거치면 된다.
    tempPtr = listData; // 리스트를 탐색하기 위해 tempPtr이 첫번째 노드를 가리키게 한다.
    // 일반적인 경우
    while (tempPtr->next != nullptr) { // tempPtr이 가리키는 노드가 nullptr을 가리키지 않을 때까지
        if ((tempPtr->next)->value > item) { // 만약 tempPtr이 가리키는 노드의 다음 노드의 value갑이 item보다 크다면
            break;
        }
        tempPtr = tempPtr->next;
    }
    // 이제 tempPtr이 가리키는 노드의 다음 노드의 value는 item보다 크다.
    newNode->next = tempPtr->next; // newNode의 next가 tempPtr이 가리키는 노드의 다음 노드를 가리키게 한다.
    tempPtr->next = newNode; // tempPtr이 가리키는 노드가 새 노드를 가리키게 한다.
    length++; // 새 노드가 삽입되었으므로 length는 1 증가한다.
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

    // 1. 리스트가 비어있을 경우 그냥 리턴
    if (isEmpty()) {
        return;
    }


    NodeType<ItemType>* tempPtr; // 탐색할 노드 포인터 선언
    NodeType<ItemType>* deallocPtr; // 제거할 노드 포인터 선언
    tempPtr = listData; // 시작 노드를 가리킨다.

    // 3. 리스트의 첫번째 노드를 제거하는 경우
    if (item == listData->value) {
        listData = listData->next; // listData는 그 다음 노드를 가리킨다.
        delete tempPtr; // 첫 노드를 제거한다.
        length--; // 노드가 제거되었으므로 length가 1 줄어든다.
        return;
    }
    // 4. 제거할 노드가 마지막에 존재하는 경우는 아래의 과정을 따르면 된다.
    while(item != (tempPtr->next)->value) { // 시작 노드의 다음 노드부터 탐색한다.
        tempPtr = tempPtr->next; // 만약 tempPtr이 가리키는 노드의 다음 노드의 value값이 item과 같지 않으면 계속 넘어간다.
        // 아예 item값과 같은 value값을 가진 노드 없는 경우
        if (tempPtr->next == nullptr) { 
            // 만약 tempPtr이 마지막 노드까지 가리키게 된다면 마지막 노드까지 탐색했을 때도
            // 2. item과 일치하는 값이 없었다는 뜻이므로 함수를 종료한다.
            return;
        }
    }
    // 제거할 노드를 찾은 경우 
    deallocPtr = tempPtr->next; // 제거할 노드를 deallocPtr이 가리키게 한다.
    // tempPtr이 가리키는 노드의 next는 다음 노드의 다음 노드를 가리키게 한다.
    // (tempPtr->next가 리스트의 마지막 노드인 경우에는 nullptr을 가리키게 된다.)
    tempPtr->next = (tempPtr->next)->next;
    delete deallocPtr; // 제거할 노드를 제거한다.
    length--; // 노드가 제거되었으므로 length가 1 감소한다.
    

    
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
    NodeType<ItemType>* tempPtr = listData; // 탐색할 노드포인터는 시작노드를 가리키는 것부터 시작한다.
    // pos가 0인 경우는 그대로 listData가 가리키는 노드의 값 리턴
    for (int i = 1;i <= pos;i++) { // pos가 0인 경우는 while문을 돌지 않고 바로 리턴된다.
        // pos가 1 이상인 경우에는 pos의 인덱스에 맞게 출력이 된다.
        tempPtr = tempPtr->next;
        if (tempPtr == nullptr) { // 만약 pos가 list의 길이보다 큰 인덱스인 경우 -1을 리턴한다.
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
