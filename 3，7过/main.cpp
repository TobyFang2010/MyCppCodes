#include <iostream>
using namespace std;

int start() {
    int num1;
    cout << "请先输入一个非负整数作为起始数" << endl << ">>>";
    cin >> num1;
    if (num1 < 0) {
        cout << "你输入的是一个不合法的数，我们默认按零开始。" << endl;
        return 0;
    }
    return num1;
}

int check(int number) {
    if (number % 10 == 3 || number % 10 == 7 || 
        number % 3 == 0 || number % 7 == 0) {
        return 0;
    } else {
        return number;
    }
}

void play(int startNum) {
    int currentNum = startNum;
    int rightTime = 0; // 初始化
    
    while (true) {
        currentNum++; // 只递增一次
        cout << check(currentNum) << endl;
        currentNum++;
        int expected = check(currentNum);
        
        // cout << "当前数字: " << currentNum << endl;
        cout << ">>>";
        
        int userInput;
        cin >> userInput;
        
        if (userInput != expected) {
            cout << "错了，正确答案是" << expected << "！" << endl;
            cout << "你连续答对了" << rightTime << "次" << endl;
            break;
        } else {
            rightTime++;
        }
    }
}

int main() {
    bool firstTime = true;
    
    while (true) {
        if (firstTime) {
            cout << "欢迎来玩3，7过游戏！本游戏考验你的反应能力。" << endl;
            cout << "你需要在数为3或7的倍数或尾数为3或7时说过，即在本程序中输入0" << endl;
            firstTime = false;
        }
        
        int startNum = start();
        cout << "出现\">>>\"的时候就可以开始输入了" << endl;
        play(startNum);
        
        cout << "是否再玩一次？(1-是, 0-否): ";
        int choice;
        cin >> choice;
        if (choice == 0) break;
    }
    
    return 0;
}