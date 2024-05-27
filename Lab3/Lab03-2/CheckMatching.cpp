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

    // 아래 6가지 조건을 만족해야됨
    // 왼쪽 괄호면 Push
    // 오른쪽 괄호면 Pop
    // 괄호가 아닌 문자면 continue
    // 양쪽 괄호 개수는 맞는데, 괄호 모양이 다르면 false
    // 오른쪽 괄호 다 Pop 했는데 문자열이 남아 있으면 false
    // 오른쪽 괄호 다 Pop 하기 전에 문자열이 비게 되면 false

    // tempStack는 문자를 제외한 괄호만 push된다."(({[(["
    for (int i = 0; i < length;i++) {
        // 왼쪽 괄호면 Push
        if (string[i] == '(' || string[i] == '[' || string[i] == '{') {
            tempStack.push(string[i]);
        }
        // 왼쪽이랑 오른쪽 괄호가 같아야지 pop을 하지. 아니면 pop을 할 필요가 없으니깐. 개수는 그다음 우선순위이다.
        else if (string[i] == ')') {
            if (tempStack.pop() == '(') { // 오른쪽 괄호면 Pop
                // 오른쪽 괄호 다 Pop 하기 전에 문자열이 비게 되면(오른쪽 괄호개수가 더 많은 경우) 
                //false를 리턴하는데 false는 괄호랑 다르므로 if문의 조건은 false가 된다.
                continue; // pop 한 뒤에 그다음 괄호로 간다. continue해도 i는 증가한다.
            }
            else {
                return false;
            }
        }
        else if (string[i] == ']'){ 
            if (tempStack.pop() == '[') { // 오른쪽 괄호면 Pop
                // 오른쪽 괄호 다 Pop 하기 전에 문자열이 비게 되면(오른쪽 괄호개수가 더 많은 경우) 
                //false를 리턴하는데 false는 괄호랑 다르므로 if문의 조건은 false가 된다.
                continue; // pop 한 뒤에 그다음 괄호로 간다.
            }
            else {
                return false;
            }
        }
        else if (string[i] == '}') {
            if (tempStack.pop() == '{') { // 오른쪽 괄호면 Pop
                // 오른쪽 괄호 다 Pop 하기 전에 문자열이 비게 되면(오른쪽 괄호개수가 더 많은 경우) 
                //false를 리턴하는데 false는 괄호랑 다르므로 if문의 조건은 false가 된다.
                continue; // pop 한 뒤에 그다음 괄호로 간다.
            }
            else {
                return false;
            }
        }
        else {
            continue; // 괄호가 아닌 문자면 continue
        }
    }
    // 오른쪽 괄호 다 Pop 했는데 문자열이 남아 있으면 false "((())" 왼쪽 괄호 개수가 더 많은 경우
    if (tempStack.size() > 0) {
        return false;
    }
    return true;

}
