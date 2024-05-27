//
//  CheckMatching.cpp
//  Lab03
//
//  Created by Jeman Park on 2024/03/26.
//

#include "checkMatching.h"

bool checkMatching(char string[], int length){
    StackType<char> tempStack;
    
    /* Implement the function here (Lab 03-1) */
    // This function checks if the "string" has MATCHED parentheses USING STACK
    // There are three kinds of parentheses (), [], {} and they are NOT INTERCHANGEABLE
    // For example,
    // "()" --> True
    // "(())" --> True
    // "()()" --> True
    // "())" --> False
    // "(()" --> False
    // "(]" --> False
    // "([])" --> True
    // "({}()[])" --> True
    // Ignore all non-parenthesis characters.
    // "(abc)" --> True
    // "((abc)" --> False
    // it returns true, if it has MATCHED parentheses
    // Otherwise it returns false.
    
    
    // for(int i = 0; i < length; i++){
    //     if(string[i] ....... ){

    // �Ʒ� 6���� ������ �����ؾߵ�
    // ���� ��ȣ�� Push
    // ������ ��ȣ�� Pop
    // ��ȣ�� �ƴ� ���ڸ� continue
    // ���� ��ȣ ������ �´µ�, ��ȣ ����� �ٸ��� false
    // ������ ��ȣ �� Pop �ߴµ� ���ڿ��� ���� ������ false
    // ������ ��ȣ �� Pop �ϱ� ���� ���ڿ��� ��� �Ǹ� false

    // tempStack�� ���ڸ� ������ ��ȣ�� push�ȴ�."(({[(["
    for (int i = 0; i < length;i++) {
        // ���� ��ȣ�� Push
        if (string[i] == '(' || string[i] == '[' || string[i] == '{') {
            tempStack.push(string[i]);
        }
        // �����̶� ������ ��ȣ�� ���ƾ��� pop�� ����. �ƴϸ� pop�� �� �ʿ䰡 �����ϱ�. ������ �״��� �켱�����̴�.
        else if (string[i] == ')') {
            if (tempStack.pop() == '(') { // ������ ��ȣ�� Pop
                // ������ ��ȣ �� Pop �ϱ� ���� ���ڿ��� ��� �Ǹ�(������ ��ȣ������ �� ���� ���) 
                //false�� �����ϴµ� false�� ��ȣ�� �ٸ��Ƿ� if���� ������ false�� �ȴ�.
                continue; // pop �� �ڿ� �״��� ��ȣ�� ����. continue�ص� i�� �����Ѵ�.
            }
            else {
                return false;
            }
        }
        else if (string[i] == ']'){ 
            if (tempStack.pop() == '[') { // ������ ��ȣ�� Pop
                // ������ ��ȣ �� Pop �ϱ� ���� ���ڿ��� ��� �Ǹ�(������ ��ȣ������ �� ���� ���) 
                //false�� �����ϴµ� false�� ��ȣ�� �ٸ��Ƿ� if���� ������ false�� �ȴ�.
                continue; // pop �� �ڿ� �״��� ��ȣ�� ����.
            }
            else {
                return false;
            }
        }
        else if (string[i] == '}') {
            if (tempStack.pop() == '{') { // ������ ��ȣ�� Pop
                // ������ ��ȣ �� Pop �ϱ� ���� ���ڿ��� ��� �Ǹ�(������ ��ȣ������ �� ���� ���) 
                //false�� �����ϴµ� false�� ��ȣ�� �ٸ��Ƿ� if���� ������ false�� �ȴ�.
                continue; // pop �� �ڿ� �״��� ��ȣ�� ����.
            }
            else {
                return false;
            }
        }
        else {
            continue; // ��ȣ�� �ƴ� ���ڸ� continue
        }
    }
    // ������ ��ȣ �� Pop �ߴµ� ���ڿ��� ���� ������ false "((())" ���� ��ȣ ������ �� ���� ���
    if (tempStack.size() > 0) {
        return false;
    }
    return true;

}
