//
//  Lab02_3.cpp
//  Lab02
//
//  Modified by Jeman Park on 2023/03/19.
//

#include <iostream>
#include "SortedType.h"
#include "MergeList.h"

using namespace std;


int main() {
    
    SortedType s_list1, s_list2, s_list3;

    /* Feel free to edit codes below (test with more cases) */

    s_list1.insertItem(3);
    s_list1.insertItem(6);
    s_list1.insertItem(7);
    s_list1.insertItem(20);
    s_list1.insertItem(14);
    s_list1.insertItem(1);
    s_list1.insertItem(8);
    s_list1.PrintList();
    // Correct Output: [1 3 6 7 8 14 20 ]
    
    s_list2.insertItem(6);
    s_list2.insertItem(8);
    s_list2.insertItem(2);
    s_list2.insertItem(15);
    s_list2.PrintList();
    // Correct Output: [2 6 8 15 ]
    
    s_list3 = MergeList(s_list1, s_list2);
    s_list3.PrintList();
    // Correct Output: [1 2 3 6 6 7 8 8 14 20 ]
    
    
    return 0;
}
