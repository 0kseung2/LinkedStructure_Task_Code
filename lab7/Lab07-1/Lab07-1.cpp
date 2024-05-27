#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main() {
	UnsortedType<int> listData;

	listData.appendItem(14);
    listData.appendItem(3);
    listData.appendItem(7);
    listData.appendItem(12);
    listData.appendItem(16);
    listData.appendItem(8);
    
    listData.printList();
    // 8    16    12    7    3    14
        
    
    int item = 7;
    if(listData.findItemRecursive(item)){
        cout << "[findItemRecursive]: " << item << " Found!" << endl;
    }
    else{
        cout << "[findItemRecursive]: " << item << " NOT Found!" << endl;
    }
    // [findItemRecursive]: 7 Found!
    
    item = 12;
    if(listData.findItemRecursive(item)){
        cout << "[findItemRecursive]: " << item << " Found!" << endl;
    }
    else{
        cout << "[findItemRecursive]: " << item << " NOT Found!" << endl;
    }
    // [findItemRecursive]: 12 Found!
    
    item = 8;
    if(listData.findItemRecursive(item)){
        cout << "[findItemRecursive]: " << item << " Found!" << endl;
    }
    else{
        cout << "[findItemRecursive]: " << item << " NOT Found!" << endl;
    }
    // [findItemRecursive]: 8 Found!
    
    
    cout << "[minItem]: " << listData.getMinItem() << endl;
    // [minItem]: 3
    
    listData.removeItem(3);
    listData.printList();
    // 8    16    12    7    14
    
    cout << "[minItem]: " << listData.getMinItem() << endl;
    // [minItem]: 7
    
    
    listData.sortList();
    listData.printList();
    // 7    8    12    14    16
    
	return 0;
}
