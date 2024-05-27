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
    // item�� �������� �ʴ� ��찡 worst���̽�, ����� ������ N�� �϶� N�� Ž���ؾ� �Ѵ�.
    
    // edge case
    // ����ִ� ���� �ȴٷ�� ��

    // base case
    // 1. item�� ������ ���(locaion->value==item) 2. item�� �������� �ʴ� ���(location==nullptr)
    // general case
    // ����ؼ� location�� ���� location�� ����Ű�� ����� ���� ��带 ����Ű���� �Ѵ�.

    // base case 1
    if (location->value == item) {
        return true;
    }
    // base case 2
    // item�� ã�� ���ؼ� location�� nullptr���� ������ ��
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
    // location�� ������ ��带 �Ѿ�� �Լ� ����
    // general case
    // 1. location�� ��ĭ�� ��� Ž��(nullptr �� ������)
    // 2. ���� location �������� sorting�ϱ�
    
    if (location == nullptr) {
        return;
    }
    else {
        NodeType<ItemType>* minPtr = MinLoc(location, location); // ���� ��ġ �������� ������ Ž���ؼ� min�� ������ ��� ������ ���ϱ�
        // cout << minPtr->value << endl;
        // ���� Ž�� ����� value�� ���� ���� ����� value�� swap ���ش�.
        ItemType temp_value; // value�� swap�ϱ� ���� �ӽ� ���� ����
        temp_value = location->value; // ���� ��ġ�� ���� �ӽ� ������ ����
        location->value = minPtr->value; // ���� ���� value�� ������ �������� value�� ���� ��ġ�� ����� value�� ����
        minPtr->value = temp_value; // ���� ���� ���� ��尡 �ִ� ���� ���� ��ġ�� value�� ����
        // �̷��� �Ǹ� �տ������� ���� ���� ������ ���������� ä������.
        sort(location->next);
    }
    
    
    
    
    
    
}

template <class ItemType>
void UnsortedType<ItemType>::sortList(){
    /* Entry Function for sort( ) */
    sort(listData); // listData�� �׻� ù ��� ����Ų��.
}

template <class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc(NodeType<ItemType>* location, NodeType<ItemType>* minPtr) {
    /* Implement the function here */
    // MinLoc returns the "pointer" to the MIN value node.
    // MinLoc "recursively" finds the MIN value.
    
    // Time Complexity: O (  N  )
    // ó������ ������ N�� Ž���ϸ� �ȴ�.
    
    // base case
    // ������ ������ Ž������ �� ���� ���� value�� ���� ����� ������ ����
    // general case
    // 1. location�� ���� location�� next ��带 ��� Ž���ϸ鼭 MinPtr�� value���� ��
    // 2. MinPtr���� ���� Ž���� ��� �� ���� ���� value�� ���� ����� ������ ����

    // minPtr ������ ����, ���� location�� ��带 ����Ų��.
    // minPtr = location; �� �̷��� ¥�� �ȵǳ�. ��� location���� ������Ʈ �Ǵ±���...
    // �� ���� ���ǿ� getMinItem() ���� minPtr�� location���� ������ ���¿��� ���ڷ� �����±���
    // ���� ���� ���� ���ص� �ǳ�

    // base case
    if (location == nullptr) {
        return minPtr;
    }
    // general case 1
    else{
        // location�� ���� location�� next ��带 ��� Ž���ϸ鼭 MinPtr�� value���� ���ؼ� ���� value�� ���� ��带 minPtr�� ����
        if (minPtr->value > location->value) {
            minPtr = location;
        }
        return MinLoc(location->next, minPtr);
    }
    
}

template <class ItemType>
ItemType UnsortedType<ItemType>::getMinItem(){
    NodeType<ItemType>* tempPtr = listData;
    NodeType<ItemType>* ret = MinLoc(listData, tempPtr); // �Լ� ���� �� minPtr�� listData�� ���� ��� ����Ű�� ��

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
