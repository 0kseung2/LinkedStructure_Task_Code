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

int SortedType::BinarySearch(ItemType item){
   
    int ret = -1;
    /* Implement the function here (Lab 02-2 (1)) */
    // This function performs "binary search" on the sorted list
    // It returns the "index" if "value" exists
    // Otherwise, it returns -1 
    // For example, suppose that test_sorted_list = [ 1, 3, 4, 10, 12, 14]
    // BinarySearch(4) will return (2)  -- (the index of "4" is [2])
    // BinarySearch(5) will return (-1) -- ("5" does not exist)
    
    int mid;
    int first = 0;
    int last = length - 1;
    while (first <= last) {
        mid = (first + last) / 2;
        if (item < data[mid]) {
            last = mid - 1;
        }
        else if (item > data[mid]) {
            first = mid + 1;
        }
        else if (item == data[mid]) {
            return mid;
        }
        else {
            break;
        }
    }










    
    return ret;
}

int SortedType::BinarySearchNearest(ItemType item){
    int nearest = -1;
    
    /* Implement the function here (Lab 02-2 (2)) */
    // This function is very similar to "BinarySearch" above 
    // it also performs "binary search" on the sorted list
    // It returns the "index" if "value" exists (same as the above)
    // But BinarySearchNearest will return the index of the element nearest to "item" 
    // For example, suppose that test_sorted_list = [ 1, 3, 4, 10, 12, 14]
    // BinarySearch(3) will return (1)  -- (the index of "3" is [1]) -- Same as above
    // BinarySearch(5) will return (2) -- ("5" is between 4 (test_sorted_list[2])and 10 (test_sorted_list[3]))
    //                                    SInce 5 is closer to 4 than 10, it returns the index of "4" [2]
    

    int mid;
    int first = 0;
    int last = length - 1;
    while (first <= last) {
        mid = (first + last) / 2;
        if (item < data[mid]) {
            last = mid - 1;
        }
        else if (item > data[mid]) {
            first = mid + 1;
        }
        else if (item == data[mid]) {
            return mid;
        }
        else {
            break;
        }
    }
    // first > last �� ���
    // data[last] < item < data[first]

    if (item < data[length - 1] && item > data[0]) { // item�� data�� ����� �ִ񰪰� �ּڰ� ���̿� �ִ� ���
        if (data[first] - item > item - data[last]) {
            nearest = last;
        }
        else { // �� ������ �ݴ� ����̰ų�, �� ����� ���� ���� ���
            nearest = first;
        }
    }
    else if (item > data[length - 1]) { // item�� data�� ����� �ִ񰪺��� ū ���
        nearest = length - 1;
    }
    else if (item < data[0]) { // iteml�� data�� ����� �ּڰ����� ���� ���
        nearest = 0;
    }


/*
    if (data[first] - item > item - data[last]) {
        nearest = last;
    }
    else if(item > data[first]) { // item�� ����Ʈ�� ���� ���̿� ���� �ʰ� ����Ʈ�� ��� ���ڵ麸�� ū ���
        nearest = first - 1;
    }
    else { // �� ������ �ݴ� ����̰ų�, �� ����� ���� ���� ���
        nearest = first;
    }
*/




    
    return nearest;

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
