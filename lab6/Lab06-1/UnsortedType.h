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
    tempPtr = listData; // tempPtr이 시작지점 노드를 가리키게 한다.
    while (listData != nullptr) {
        listData = listData->next; // listData 포인터는 그 다음 노드를 가리키게 한다.
        delete tempPtr; // tempPtr이 가리키는 노드를 제거한다.
        tempPtr = listData; // tempPtr이 다시 listData가 가리키는 노드를 가리키게 한다.
        // 이렇게 반복하면 마지막 노드를 거쳐 결국 listData와 tempPtr은 nullptr을 가리키게 된다. 그리고 while문이 끝난다.
    }
    length = 0; // 노드를 다 제거하였으므로 length는 0이 된다.
    
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
    // 기존의 appendItem과 다르게 맨 뒤가 아닌 맨 앞에 노드를 집어넣는다.
    NodeType<ItemType>* newNode;
    newNode = new NodeType<ItemType>; // 새로운 노드 생성
    newNode->value = item; // 새로운 노드의 value값에 item값 복사
    newNode->next = listData; // 새로운 노드의 next값에 listData가 가리키고 있던 첫번재 노드의 주솟값 복사
    listData = newNode; // 항상 첫번재 노드를 가리키는 listData는 newNode를 가리키게 한다.
    length++; // 노드가 하나 추가되었으므로 lenght도 1 추가해준다.
    
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
    
    // 만약 list에 노드가 없는 경우
    if (isEmpty()) {
        return;
    }
    // list의 노드가 하나인 경우에는 이 노드의 next는 nullptr을 가리키고 있으므로 아래의 while문을 바로 탈출하기에
    // 추가로 코드가 필요없다.

    // 제거할 아이템이 list의 마지막에 있는 경우에는 어차피 마지막 노드는 nullptr을 가리키고 있으므로 tempPtr도 nullptr을 가리키게 된다.


    //일단 기본적인 상황을 가정하고 코드를 짜보자
    // 1. 찾아야 하고, 2. 제거해야 한다.
    NodeType<ItemType>* deallocPtr; // 노드를 제거할 노드 포인터
    NodeType<ItemType>* tempPtr; // 움직일 노드 포인터
    tempPtr = listData; // 시작 노드부터 순차적으로 아이템을 찾기 위함
    while (tempPtr->next != nullptr) { // tempPtr이 끝에까지 도달할때까지 실행
        if ((tempPtr->next)->value == item) { // 만약 tempPtr이 가리키는 노드의 다음 노드의 value값이 item과 같다면
            deallocPtr = tempPtr->next; // 제거할 노드를 deallocPtr이 가리키게 한다.
            tempPtr->next = (tempPtr->next)->next; // tempPtr이 가리키는 노드의 next는 tempPtr이 가리키는 노드의 다음 노드의 다음 노드를 가리킨다.
            delete deallocPtr; // 노드를 제거한다.
            length--; // 길이를 하나 줄인다.
        }
        tempPtr = tempPtr->next; // tempPtr은 계속해서 다음 노드를 가리키게 한다.
        if (tempPtr == nullptr) { // tempPtr이 nullptr이 되는 경우는 list의 마지막 노드를 제거하는 경우밖에 없다.
            return;
        }
    }
    // 만약 제거할 item을 가지고 있는 노드가 없는경우
    return; // 아무것도 없이 return 해서 함수를 끝낸다.
    
    
    // 오... 내 코드가 pdf 코드랑 조금 다르네 일단 내걸로 해보자
    
    
    
    
    
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

    // pos가 list의 범위를 넘어서는 경우
    if (pos > size() - 1) {
        return -1;
    }
    ItemType ret;
    int searchingIndex = 0; // 나중에 이 값이 pos랑 같아지면 그때의 값을 찾을 것
    NodeType<ItemType>* tempPtr;
    tempPtr = listData; // tempPtr은 시작노드의 포인터에서 출발한다.
    while (tempPtr != nullptr) { // tempPtr이 nullptr이 아닐 때까지
        if (searchingIndex == pos) { // 만약 찾고자 하는 인덱스에 도달했다면
            ret = tempPtr->value; // ret에 현재 tempPtr이 가리키는 노드의 value값 복사
            return ret;
        }
        tempPtr = tempPtr->next; // tempPtr은 계속 다음 노드를 탐색한다.
        searchingIndex++; // 원하는 인덱스가 나올 때까지 serarchingIndex는 1씩 증가한다.
    }
    // while문 아래 코드에 list를 다 탐색했는데도 searchingIndex랑 pos가 같은게 없는 경우
    // 즉, pos가 list의 범위를 넘어가는 경우에는 return -1을 하는 코드를 넣어도 되지만
    // 굳이 while문을 도는 시간낭비 없이 while 문 위에서 pos가 size-1보다 클 때 return -1
    // 을 하게 하면 훨씬 빠르게 함수를 끝낼 수 있다.
    
    
    
    
    
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
