//
//  UnsortedType.h
//  Lab02
//
//  Modified by Jeman Park on 2023/03/19.
//

#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#define MAX_ITEMS 30

typedef int ItemType;

class UnsortedType 
{
private:
    ItemType data[MAX_ITEMS];
    int length;
    
public:
    UnsortedType( );
    void        appendItem(ItemType value);
    void        insertItem(int pos, ItemType value);
    void        removeItem(ItemType value);
    void        updateItem(int pos, ItemType new_value);
    void        clear( );
    
    int         removeItemsEndingWith(int endDigit);
    
    int         size( );
    bool        isFull( );
    bool        isEmpty( );
    ItemType    getItem(int pos);
    bool        findItem(ItemType & item);

    void PrintList();
};


#endif
