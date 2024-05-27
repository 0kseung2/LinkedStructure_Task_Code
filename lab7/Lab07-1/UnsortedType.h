#include<iostream>

using namespace std;
  
template <class ItemType>
struct NodeType;

template <class ItemType>
class UnsortedType
{
public:
    UnsortedType();
    ~UnsortedType();
    
    bool IsFull() const;
    void clear();
    bool findItem(ItemType& item);
    bool findItemRecursive(ItemType& item);
    void appendItem(ItemType item);
    void removeItem(ItemType item);
    void sortList();
    void sort(NodeType<ItemType>* location);
    void printList();
    ItemType getMinItem();
    
protected:
    NodeType<ItemType>* MinLoc(NodeType<ItemType>* location, NodeType<ItemType>* minPtr);
    bool findItemRecur(NodeType<ItemType>* location, ItemType & item);
    
private:
    NodeType<ItemType>* listData;
    int length;
};

template<class ItemType>
struct NodeType
{
    ItemType value;
    NodeType* next;
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
    clear();
}

template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
{
    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

template <class ItemType>
void UnsortedType<ItemType>::clear()
{
    NodeType<ItemType>* tempPtr;
    
    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

template <class ItemType>
bool UnsortedType<ItemType>::findItem(ItemType& item)
{
    NodeType<ItemType>* tempPtr;
    
    tempPtr = listData;
        
    while (tempPtr != nullptr)
    {
        if (item == tempPtr -> value)
        {
            item = tempPtr->value;
            return true;
        }
        tempPtr = tempPtr ->next;
    }
    return false;
}

template <class ItemType>
bool UnsortedType<ItemType>::findItemRecur(NodeType<ItemType>* location, ItemType& item){
    /* Implement the function here */
    // this function "Recursively" finds the "item" in the list.
    // If the "item" exists in the list, then return "true"
    // else, return "false"
    
    // Time Complexity: O (  N  )
    // item이 존재하지 않는 경우가 worst케이스, 노드의 개수가 N개 일때 N번 탐색해야 한다.
    
    // edge case
    // 비어있는 경우는 안다루는 듯

    // base case
    // 1. item이 존재한 경우(locaion->value==item) 2. item이 존재하지 않는 경우(location==nullptr)
    // general case
    // 계속해서 location이 현재 location이 가리키는 노드의 다음 노드를 가리키도록 한다.

    // base case 1
    if (location->value == item) {
        return true;
    }
    // base case 2
    // item을 찾지 못해서 location이 nullptr까지 도달한 것
    else if(location == nullptr){
        return false;
    }
    // general case
    else {
        return findItemRecur(location->next, item);
    }
    
    
    
}

template <class ItemType>
bool UnsortedType<ItemType>::findItemRecursive(ItemType& item)
{
    /* Entry Function for Recursive Find Item */
    return findItemRecur(listData, item);
}

template <class ItemType>
void UnsortedType<ItemType>::appendItem(ItemType item)
{
    NodeType<ItemType>* tempPtr;
    
    tempPtr = new NodeType<ItemType>;
    tempPtr -> value = item;
    tempPtr -> next = listData;
    listData = tempPtr;
    length++;
}

template <class ItemType>
void UnsortedType<ItemType>::removeItem(ItemType item)
{
    NodeType<ItemType>* tempPtr = listData;
    NodeType<ItemType>* deallocPtr;
    
    if(listData == nullptr){
        return;
    }
    
    if (item == listData->value)
    {
        deallocPtr = tempPtr;
        listData = listData->next;
        delete deallocPtr;
        length --;
        return;
    }
    
    while ((tempPtr -> next != nullptr) && item != (tempPtr -> next) -> value){
        tempPtr = tempPtr -> next;
    }
    
    if(tempPtr -> next != nullptr){
        deallocPtr = tempPtr->next;
        tempPtr -> next = (tempPtr -> next) -> next;
        delete deallocPtr;
        length--;
    }
}

template <class ItemType>
void UnsortedType<ItemType>::sort(NodeType<ItemType>* location) {
    /* Implement the function here */
    // Sort() must use (1) recursion and (2) MinLoc()
    // It returns nothing (void), but after Sort() the list will be sorted (ascending order)
    // E.g., [11, 2, 5, 3] --> sortList( )/sort( ) --> [2, 3, 5, 11]
    
    // For example, suppose that the list is [43, 21, 14, 26, 17]
    // 1) First *location points to 43 (1st element)
    // 2) Finds the MIN value of the list using MinLoc. (14)
    // 3) Changes their positions -> [14, 21, 43, 26, 17]
    // 4) Recursively call "Sort()" for location->next [21, 43, 26, 17]
    // 5) Finds the MIN value of the list using MinLoc. (17)
    // 6) Changes their positions -> [17, 43, 26, 21]
    // Repeat....
    
    // Time Complexity: O (  N^2  )
    // 
    
    // base case
    // location이 마지막 노드를 넘어가면 함수 종료
    // general case
    // 1. location은 한칸씩 노드 탐색(nullptr 될 때까지)
    // 2. 현재 location 기준으로 sorting하기
    
    if (location == nullptr) {
        return;
    }
    else {
        NodeType<ItemType>* minPtr = MinLoc(location, location); // 현재 위치 기준으로 끝까지 탐색해서 min값 가지는 노드 포인터 구하기
        // cout << minPtr->value << endl;
        // 현재 탐색 노드의 value와 가장 작은 노드의 value를 swap 해준다.
        ItemType temp_value; // value를 swap하기 위한 임시 변수 생성
        temp_value = location->value; // 현재 위치의 값을 임시 변수에 복사
        location->value = minPtr->value; // 가장 작은 value를 가지는 포인터의 value를 현재 위치의 노드의 value로 설정
        minPtr->value = temp_value; // 원래 가장 작은 노드가 있던 곳에 현재 위치의 value를 복사
        // 이렇게 되면 앞에서부터 가장 작은 값들이 순차적으로 채워진다.
        sort(location->next);
    }
    
    
    
    
    
    
}

template <class ItemType>
void UnsortedType<ItemType>::sortList(){
    /* Entry Function for sort( ) */
    sort(listData); // listData는 항상 첫 노드 가리킨다.
}

template <class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc(NodeType<ItemType>* location, NodeType<ItemType>* minPtr) {
    /* Implement the function here */
    // MinLoc returns the "pointer" to the MIN value node.
    // MinLoc "recursively" finds the MIN value.
    
    // Time Complexity: O (  N  )
    // 처음부터 끝까지 N번 탐색하면 된다.
    
    // base case
    // 마지막 노드까지 탐색했을 때 가장 작은 value를 가진 노드의 포인터 리턴
    // general case
    // 1. location은 현재 location의 next 노드를 계속 탐색하면서 MinPtr의 value값과 비교
    // 2. MinPtr에는 현재 탐색한 노드 중 가장 작은 value를 가진 노드의 포인터 저장

    // minPtr 포인터 생성, 현재 location의 노드를 가리킨다.
    // minPtr = location; 와 이렇게 짜면 안되네. 계속 location으로 업데이트 되는구나...
    // 아 문제 조건에 getMinItem() 보면 minPtr은 location으로 설정된 상태에서 인자로 들어오는구나
    // 굳이 내가 설정 안해도 되네

    // base case
    if (location == nullptr) {
        return minPtr;
    }
    // general case 1
    else{
        // location은 현재 location의 next 노드를 계속 탐색하면서 MinPtr의 value값과 비교해서 작은 value를 가진 노드를 minPtr로 설정
        if (minPtr->value > location->value) {
            minPtr = location;
        }
        return MinLoc(location->next, minPtr);
    }
    
}

template <class ItemType>
ItemType UnsortedType<ItemType>::getMinItem(){
    NodeType<ItemType>* tempPtr = listData;
    NodeType<ItemType>* ret = MinLoc(listData, tempPtr); // 함수 들어올 때 minPtr이 listData와 같은 노드 가리키게 함

    return ret -> value;
}

template <class ItemType>
void UnsortedType<ItemType>::printList(){
    NodeType<ItemType>* tempPtr = listData;
    
    while (tempPtr != NULL){
        cout << tempPtr -> value << "\t";
        tempPtr = tempPtr -> next;
    }
    cout << endl;
}
