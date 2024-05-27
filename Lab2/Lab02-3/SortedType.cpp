//
//  SortedType.cpp
//  Lab02
//
//  Modified by Jeman Park on 2023/03/19.
//


#include<iostream>
#include "SortedType.h"

using namespace std;

SortedType::SortedType()
{
    length = 0;
}


int SortedType::size()
{
    return length;
}

bool SortedType::isFull()
{
    return (length == MAX_ITEMS);
}

bool SortedType::isEmpty()
{
    return (length == 0);
}



void SortedType::insertItem(ItemType value){
    if (isFull( )){
        cout << "[ERROR] List is FULL" << endl;
        return;
    }
    int location = 0;
    while (location < length){
        if(value > data[location]){
            location ++;
        }
        else{
            break;
        }
    }
    
    for ( int i = length; i > location; i-- ){
        data[ i ] = data[i-1];
    }
    data[location] = value;
    length ++;
}

void SortedType::removeItem(ItemType value){
    if (isEmpty( )){
        cout << "[ERROR] List is EMPTY" << endl;
        return;
    }
    int location = 0;
    while (location < length){
        if(value > data[location]){
            location ++;
        }
        else{
            break;
        }
    }
    for ( int i = location + 1; i < length; i++ ){
        data[i-1] = data[i];
    }
    length --;
}


void SortedType::clear( ){
    length = 0;
}

ItemType SortedType::getItem(int pos){
    if (pos >= length){
        cout << "[ERROR] Invalid Position (pos >= length)" << endl;
        return -1;
    }
    
    return data[pos];
}


bool SortedType::findItem(ItemType & item){
    int location = 0;
    
    while(location < length){
        if(data[location] == item){
            item = data[location];
            return true;
        }
        location ++;
    }
    return false;
}

void SortedType::PrintList()
{
    if(length == 0){
        cout << "[EMPTY LIST]" << endl;;
        return;
    }
    cout << "[";
    for(int i=0; i < length; i++){
        cout << data[i] << " ";
    }
    cout << "]" << endl;
}
