//
//  MergeList.cpp
//  Lab02
//
//  Modified by Jeman Park on 2023/03/19.
//

#include "MergeList.h"


SortedType MergeList(SortedType list1, SortedType list2){

    SortedType result;

    /* Implement the function here (Lab 02-2 (3)) */
    // This function merges two sorted lists (list1 and list2) and returns merged sorted list
    // For example, if list1 = [1, 3, 4, 5] and list2 = [2, 3, 10, 14]
    // This function will return [1, 2, 3, 3, 4, 5, 10, 14]
    // 
    // Hint: This function is the client function, which means that this function is not a member function of SortedType
    // Thus, you cannot directly access private member variable "data" of SorteType
    // You may need to use public member method "getItem( )" to access "data"

    for (int i = 0; i < list1.size(); i++) {
        result.insertItem(list1.getItem(i));
    }
    for (int i = 0; i < list2.size(); i++) {
        result.insertItem(list2.getItem(i));
    }






    
    return result;
}
