#pragma once


#define TASKS_RK1_H
#include <List>
#include <tuple>
#include <list>
#include <map>
#include <string>
#include <iostream>
#include<Vector>
using namespace std;
//task1
class WorkWithFile {//task1
private:
    char* dataOfFile;
    void readFromFile(const char* fileName);	//функция чтения из файла
    void prepareTestFile(const char* fileName);	//функция для создания тестового файла
    int size;

public:
    WorkWithFile();
    ~WorkWithFile();

    void writeStatInfoToFile(const char* outFile);
};

char* convertDecToBin(int number);//task2

char* convertBinToHex(const char* binNum);//task3
void buildTree(int height);//task4
std::vector<std::pair<int/*номер строки*/, float /*среднее значение*/>> averStr2DArray(const float* ar, int colCount, int rowCount);//task5

//task6
struct Node {
    Node* next;
    Node* prev;
    int nameNode;
    static int countNodes;   //    ???
};

class LinkedList {
private:
    Node* Head;
    Node* Tail;
public:
    LinkedList();
    ~LinkedList();

    void push_back(int nameNode);
    void writeToFileFromTail();
    void writeToFileFromHead();


    //task7
    void insert(int nameNode, int pos);
};