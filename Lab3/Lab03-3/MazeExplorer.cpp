//
//  CheckMatching.cpp
//  Lab03
//
//  Created by Jeman Park on 2024/03/26.
//

#include "MazeExplorer.h"

void printLocation(location point) {
    cout << "[" << point.row << "][" << point.col << "]" << endl;
}

bool mazeExplorer(char map[][MAZE_SIZE], location entryPoint, location exitPoint) {


    StackType<location> tempStack; // location 타입의 객체가 tempStack 배열에 저장된다. [][]
    tempStack.push(entryPoint);

    /* Implement the function here (Lab 03-1) */
    // This function explores "map" to find the path from "entryPoint" to "exitPoint" using STACK
    // it should prints all visited points.
    // it returns true, if it successfully finds the path
    // otherwise, it returns false
    // When there are multiple possible paths from the current point, the priority is "upward ↑" -> "rightward →" -> "downward ↓" -> "leftward ←"
    //
    // For details, check the PDF slides!

    // 스택에 entryPoint가 쌓아진 상태
    // entryPoint를 pop 해야됨
    // 좌표값이 0인지 1인지 탐색
    // 좌표값이 1인 location은 스택에 쌓으면 안됨
    // 좌표값이 0인 location은 위, 오, 아, 왼 순서로 탐색해야 하므로, 스택에는 왼, 아, 오, 위 순으로 쌓아져야 됨.
    while (true) {
        location current_coordinate = tempStack.pop(); // 현재 좌표, top에 있는 좌표
        printLocation(current_coordinate); // 현재 좌표 위치 출력
        map[current_coordinate.row][current_coordinate.col] = '.'; // 탐색한 좌표 값을 '.'으로 바꿔줌
        // 만약 현재 좌표가 탈출좌표와 같으면 true 반환
        if (current_coordinate.row == exitPoint.row && current_coordinate.col == exitPoint.col) {
            return true;
        }
        // 상하좌우 좌표 가져옴
        if (map[current_coordinate.row][current_coordinate.col - 1] == '0') {
            location next_point(current_coordinate.row, current_coordinate.col - 1); // 현재 좌표에서 왼쪽 좌표 가져옴
            tempStack.push(next_point);
        }
        if (map[current_coordinate.row + 1][current_coordinate.col] == '0') {
            location next_point(current_coordinate.row + 1, current_coordinate.col); // 현재 좌표에서 아래쪽 좌표 가져옴
            tempStack.push(next_point);
        }
        if (map[current_coordinate.row][current_coordinate.col + 1] == '0') {
            location next_point(current_coordinate.row, current_coordinate.col + 1); // 현재 좌표에서 오른쪽 좌표 가져옴
            tempStack.push(next_point);
        }
        if (map[current_coordinate.row - 1][current_coordinate.col] == '0') {
            location next_point(current_coordinate.row - 1, current_coordinate.col); // 현재 좌표에서 위쪽 좌표 가져옴
            tempStack.push(next_point);
        }
        // 만약 4좌표가 다 0인 경우 전부 순서대로 스택에 쌓아짐
        // 그리고 top에 있는 좌표 기준으로 또 상하좌우 4개의 좌표를 탐색해야됨

        // 탈출 좌표에 가기 전에 스택이 비워지게 되면 false 반환 -> 더이상 갈 곳이 없다는 뜻이므로
        if (tempStack.isEmpty()) {
            return false;
        }
    }








}