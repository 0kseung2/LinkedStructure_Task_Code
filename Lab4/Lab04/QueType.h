//
//  QueType.h
//  Lab04
//
//  Created by Jeman Park on 2024/04/02.
//

#ifndef QUETYPE_H
#define QUETYPE_H


#include <iostream>
using namespace std;


template <class ItemType>
class QueType {

private:
    ItemType* data;
    int front;
    int rear;
    int maxQueue;

public:
    QueType(int maxQue);
    void enqueue(ItemType value);
    void dequeue(ItemType& value);

    void rotateFirstItem();

    ItemType min_dequeue();

    void clear();

    int length() const;

    bool isFull() const;
    bool isEmpty() const;
    void Print();
};


template<class ItemType>
QueType<ItemType>::QueType(int maxQue)
{
    maxQueue = maxQue + 1;
    front = maxQueue - 1;
    rear = maxQueue - 1;
    data = new int[maxQueue];
}


template<class ItemType>
bool QueType<ItemType>::isEmpty() const
{
    return (rear == front);
}

template<class ItemType>
bool QueType<ItemType>::isFull() const
{

    return ((rear + 1) % maxQueue == front);
}


template<class ItemType>
void QueType<ItemType>::rotateFirstItem()
{
    /* Implement the function here (Exercise 4-1) */
    // This "rotates" the first item of the queue and returns NOTHING.
    // "rotate" means to move the first item to the last place.
    // For example:
    //   Que: [ 1    2    3    4    5     ]
    //       rotateFirstItem()
    //   Que: [ 2    3    4    5    1     ]

    // HINT: You can call "other member functions" of QueType here.

    if (isEmpty()) {
        return;
    }

    front = (front + 1) % maxQueue;
    ItemType temp = data[front];
    enqueue(temp);

}


template<class ItemType>
int QueType<ItemType>::length() const
{
    /* Implement the function here (Exercise 4-2) */
    // This function returns the length of the queue.
    // If the queue is EMPTY, return 0;
    // if Que: [ 1    2    3   ]
    //       length() returns 3
    // if Que: [  ]
    //       length() returns 0

    int len = 0;


    if (front < rear) {
        len = rear - front;
        return len;
    }
    else {
        int ret = front - rear;
        len = maxQueue - ret;
        return len;
    }

}

template<class ItemType>
void QueType<ItemType>::clear()
{
    front = maxQueue - 1;
    rear = maxQueue - 1;
}

template<class ItemType>
void QueType<ItemType>::enqueue(ItemType value)
{
    if (isFull()) {
        cout << "[ERROR] QUEUE is FULL" << endl;
        return;
    }

    rear = (rear + 1) % maxQueue;
    data[rear] = value;
}

template<class ItemType>
void QueType<ItemType>::dequeue(ItemType& value)
{
    if (isEmpty()) {
        cout << "[ERROR] QUEUE is EMPTY" << endl;
        return;
    }

    front = (front + 1) % maxQueue;
    value = data[front];
}



template<class ItemType>
ItemType QueType<ItemType>::min_dequeue()
{
    if (isEmpty()) {
        return -1;
    }

    /* Implement the function here (Exercise 4-3) */
    // This function extracts and returns the minimum value from the queue.
    // If the queue is EMPTY, return -1;
    // if Que: [ 5    33    1    13    50     ]
    //       min_dequeue() returns 1 and the updated Que is:
    //    Que: [ 5    33    13    50     ]

    ItemType min = data[(front + 1)%maxQueue];  // 최솟값 저장 변수 생성
    int dexnum = 0; // 최솟갑 저장 변수의 위치 변수 생성

    if (front < rear) { // front가 rear보다 앞에 위치한 경우

        for (int i = front + 1; i < rear + 1; i++) { // front 다음 칸부터 rear까지 탐색

            if (data[i] < min) {
                min = data[i]; // 최솟값 찾아서 변수에 복사해준다.
            }
        }

        for (int i = 0; i < maxQueue; i++) { // 전체 큐 탐색
            if (min == data[i]) { //  최솟값의 위치가 확인되면 최솟값 저장 변수에 위치를 복사해준다.
                dexnum = i;
            }
        } // 3



        for (int i = dexnum; i > front; i--) { // [R, 5, 33, 1, 13, 50] -> [  , R, 5, 33, 13, 50]
            data[i] = data[i - 1];// i = 3, 2, 1

        } // 앞을 뒤로 당기기
        front++;

        return min; // 이까지는 크게 문제되는 건 없어 보임
    }
    else { // front가 rear보다 뒤에 위치한 경우 근데 이경우가 있잖아 [1, 5, 44, 33, 11, R]
        int back = 0; // 뭘 의미하는 변수지 ????
        for (int i = 0; i < rear + 1; i++) { // 큐의 맨앞부터 rear까지 탐색
            if (data[i] <= min) {
                min = data[i]; // min보다 작은 요소값이 있으면 min에 대입
            }
        }
        // 근데 front가 큐 끝에 있으면 맨 앞부터 rear까지 탐색하는 거랑 똑같은 거 아닌가?
        if (front != maxQueue - 1) {
            for (int i = front + 1; i < maxQueue; i++) { // front 다음 칸부터 큐의 맨마지막까지 탐색
                if (data[i] <= min) {
                    min = data[i]; // min보다 작은 요소값이 있으면 min에 대입
                    back++;
                }
            } // 최솟값 찾음
        }

        if (back == 0) { // min 값이 큐의 맨앞부터 rear까지 있는 경우
            for (int i = 0; i < rear + 1; i++) {
                if (min == data[i]) {
                    dexnum = i;
                }
            }
        }
        else {
            if (front != maxQueue - 1) {
                for (int i = front + 1; i < maxQueue; i++) { // min값이 front 다음 칸부터 큐의 맨마지막칸 안에 있는 경우
                    if (min == data[i]) {
                        dexnum = i;
                    }
                }
            }
        }
        // 이까지는 맞아 확실해

        if (dexnum == maxQueue-1) { // min값이 큐의 마지막 위치에 있는 경우, [3, 55, 13, R, 6, 1], 자동으로 front는 끝이 아니다.
            for (int k = maxQueue-1; k > front; k--) {
                data[k] = data[k-1];
            }
            front++;
        }
        else if(rear!=0){
            for (int l = dexnum; l < rear; l++) { // 그렇지 않은 경우, [3, 1, 55, 44, 33, R, 6, 10]
                data[l] = data[l + 1];
            }
            rear--; // 근데 만약 [1, R, 44, 33, 55]라면? 
        }
        else {//[1,     ,R, 44, 33, 55]
            rear = maxQueue - 1;
        }

        return min;

    }

}


template<class ItemType>
void QueType<ItemType>::Print() {

    if (isEmpty()) {
        std::cout << "[EMPTY QUEUE] " << endl;
        return;
    }

    std::cout << "[ ";

    int i = front;

    do {
        i = (i + 1) % maxQueue;
        cout << data[i] << "\t";
    } while (i != rear);


    std::cout << " ]";
    std::cout << std::endl;
}


#endif