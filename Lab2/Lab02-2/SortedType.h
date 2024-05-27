//
//  SortedType.h
//  Lab02
//
//  Modified by Jeman Park on 2023/03/19.
//

#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#define MAX_ITEMS 30

typedef int ItemType;

using namespace std;

class SortedType 
{
private:
    ItemType data[MAX_ITEMS];
    int length;
    
public:
    SortedType();
    void        insertItem(ItemType value);
    void        removeItem(ItemType value);
    void        clear( );
    
    int         size( );
    bool        isFull( );
    bool        isEmpty( );
    ItemType    getItem(int pos);
    bool        findItem(ItemType & item);
    int         BinarySearch(ItemType item);
    int         BinarySearchNearest(ItemType item);

    void PrintList();
};

#endif
