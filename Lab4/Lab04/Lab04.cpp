//
//  Lab04_1.cpp
//  Lab04
//
//  Created by Jeman Park on 2024/04/02.
//

#include <iostream>
#include "QueType.h"
using namespace std;



int main(int argc, const char* argv[]) {
    QueType<int> Que(5);
    int ret = 0;

    /*                    */
    /*  Exercise 4-1 test */
    /*                    */

    cout << " [Exercise 4-1] " << endl;
    Que.enqueue(1);
    Que.enqueue(2);
    Que.enqueue(3);
    Que.enqueue(4);
    Que.enqueue(5);
    Que.Print();
    // [ 1    2    3    4    5     ]

    Que.rotateFirstItem();
    Que.Print();
    // [ 2    3    4    5    1     ]


    /*                          */
    /* End of Exercise 4-1 test */
    /*                          */


    Que.clear();


    /*                    */
    /*  Exercise 4-2 test */
    /*                    */
    cout << " [Exercise 4-2] " << endl;
    Que.enqueue(10);
    Que.enqueue(20);
    Que.enqueue(30);
    Que.enqueue(40);
    Que.enqueue(50);
    Que.Print();
    // [ 10    20    30    40    50     ]

    cout << "[LENGTH]: " << Que.length() << endl;
    // [LENGTH]: 5

    Que.dequeue(ret);
    cout << "[DEQUEUED]: " << ret << endl;
    Que.dequeue(ret);
    cout << "[DEQUEUED]: " << ret << endl;
    Que.dequeue(ret);
    cout << "[DEQUEUED]: " << ret << endl;
    //    [DEQUEUED]: 10
    //    [DEQUEUED]: 20
    //    [DEQUEUED]: 30
    cout << "[LENGTH]: " << Que.length() << endl;
    // [LENGTH]: 2

    Que.enqueue(60);
    cout << "[LENGTH]: " << Que.length() << endl;
    // [LENGTH]: 3


    /*                          */
    /* End of Exercise 4-2 test */
    /*                          */


    Que.clear();


    /*                    */
    /*  Exercise 4-3 test */
    /*                    */
    cout << " [Exercise 4-3] " << endl;
    Que.enqueue(5);
    Que.enqueue(33);
    Que.enqueue(1);
    Que.enqueue(13);
    Que.enqueue(50);
    Que.enqueue(100);
    // [ERROR] QUEUE is FULL
    Que.Print();
    // [ 5    33    1    13    50     ]

    cout << "[MIN_DEQUEUED]: " << Que.min_dequeue() << endl;
    Que.Print();
    // [MIN_DEQUEUED]: 1
    // [ 5    33    13    50     ]

    Que.enqueue(20);
    // [ERROR] QUEUE is FULL
    Que.enqueue(12);
    // [ 5    33    13    50    20     ]
    Que.Print();


    Que.dequeue(ret);
    cout << "[DEQUEUED]: " << ret << endl;
    Que.dequeue(ret);
    cout << "[DEQUEUED]: " << ret << endl;
    Que.dequeue(ret);
    cout << "[DEQUEUED]: " << ret << endl;
    Que.dequeue(ret);
    cout << "[DEQUEUED]: " << ret << endl;
    //    [DEQUEUED]: 5
    //    [DEQUEUED]: 33
    //    [DEQUEUED]: 13
    //    [DEQUEUED]: 50
    Que.Print();
    //    [ 20     ]

    Que.enqueue(100);
    Que.enqueue(10);
    Que.enqueue(13);
    Que.Print();
    // [ 20    100    10    13     ]

    cout << "[MIN_DEQUEUED]: " << Que.min_dequeue() << endl;
    Que.Print();
    //    [MIN_DEQUEUED]: 10
    //    [ 20    100    13     ]


    cout << "[MIN_DEQUEUED]: " << Que.min_dequeue() << endl;
    // [MIN_DEQUEUED]: 13
    cout << "[MIN_DEQUEUED]: " << Que.min_dequeue() << endl; // [20, 100]
    // [MIN_DEQUEUED]: 20
    cout << "[MIN_DEQUEUED]: " << Que.min_dequeue() << endl; // [100]
    // [MIN_DEQUEUED]: 100
    cout << "[MIN_DEQUEUED]: " << Que.min_dequeue() << endl;
    // [MIN_DEQUEUED]: -1

    Que.Print();
    // [EMPTY QUEUE]   

    /*                          */
    /* End of Exercise 4-3 test */
    /*                          */

    return 0;
}
