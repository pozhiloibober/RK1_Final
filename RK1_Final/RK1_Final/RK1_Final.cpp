// RK1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <Vector>
#include <String>


#include <stdio.h>
#include <List>

#include <map>
#include <tuple>
#include <string>
#include <fstream>

#include <iostream>
#include <cmath>
#include "rk.h"
using namespace std;
char* convertDecToBin(int number) {                               //task2
    static char binNumb[32];
    memset(binNumb, 0x00, 32);

    for (int i = 0; i < 32; i++) {
        binNumb[i] = ((number & 1 << (i - 32))) ? 0x31 : 0x30;
    }



    return binNumb;
}

char* convertBinToHex(const char* binNum)
{
    static char hexNum[8];
    memset(hexNum, 0x00, 8);

    for (int i = 7; i >= 0; i--) {  //task3
        int a = 0;
        for (int j = 0; j < 4; j++) {
            if (binNum[i * 4 + j] == '1') {
                a += pow(2, 3 - j);
                cout << pow(2, 3 - j) << "  " << a << endl;
            }
        }

        if (a < 10) {
            hexNum[i] = '0' + a;
        }
        if (a >= 10)
            hexNum[i] = 'A' + a - 10;
    }
    cout << hexNum;
    return hexNum;
}
void buildTree(int height) {  //task4
    int b = 1;
    for (int i = 0; i < height; i++)
    {
        int k = height - i;
        for (int j = k; j > 0; j--)
            cout << " ";
        for (int m = b; m > 0; m--)
        {
            cout << "*";
        }
        b += 2;
        cout << endl;
    }
}

void WorkWithFile::readFromFile(const char* fileName) {// task1
    ifstream file(fileName);
    int i = 0;
    file.seekg(0, ios::end);
    size = file.tellg();
    file.seekg(0);
    dataOfFile = new char[size + 1];
    while (!file.eof()) {
        file >> dataOfFile[i];
        if (dataOfFile[i] == '\n') {
            i--;
        }
        if (!file.eof()) {
        }
        i++;
    }
    file.close();
}
void WorkWithFile::prepareTestFile(const char* fileName) {
    ofstream file(fileName, ios::trunc);
    file.close();
}

WorkWithFile::WorkWithFile() {
    char* dataOfFile;
    int size = 0;
    readFromFile("test.txt");
}
WorkWithFile::~WorkWithFile() {
    delete[] dataOfFile;
}

void WorkWithFile::writeStatInfoToFile(const char* outFile) {
    prepareTestFile(outFile);
    int k = 1;
    vector<pair<int, int> > pair;
    pair.push_back({ dataOfFile[0], 1 });
    for (int i = 1; i < size; i++) {
        bool check = false;
        for (int j = 0; j < k; j++) {
            if (dataOfFile[i] == (char)pair.at(j).first) {
                pair.at(j).second++;
                check = true;
            }
        }
        if (check == false) {
            k++;
            pair.push_back({ dataOfFile[i], 1 });
        }
    }
    ofstream file(outFile, ios::app);
    for (int i = 0; i < k; i++) {
        file << (char)pair.at(i).first << "\t" << pair.at(i).second << endl;
    }
    file.close();
}

std::vector<std::pair<int, float> > averStr2DArray(const float* ar, int colCount, int rowCount)//task5
{

    std::vector<std::pair<int, float> > vr(rowCount);
    for (int i = 0; i < rowCount; i++) {
        float c = 0;
        for (int j = 0; j < colCount; j++) {
            c += ar[i * colCount + j] / colCount;
        }
        vr.at(i) = { i + 1, c };
    }
    return vr;
}

LinkedList::LinkedList() {
    Node* Head = nullptr;
    Node* Tail = nullptr;
}
LinkedList::~LinkedList() {
    Node* temp = Tail;
    do {
        temp = temp->prev;
        delete[] temp->next;
    } while (Head != temp);
    delete[] temp;
}

void LinkedList::push_back(int nameNode) {
    Node* temp = new Node;
    if ((Head == nullptr) || (Tail == nullptr)) {
        Head = temp;
        Tail = temp;
    }
    temp->nameNode = nameNode;
    temp->prev = Tail;
    Tail->next = temp;
    Tail = temp;
}
void LinkedList::writeToFileFromTail() {
    Node* temp = Tail;
    ofstream file("taskList1.txt");
    do {
        file << temp->nameNode;
        temp = temp->prev;
    } while (temp != Head);
    file << Head->nameNode;
    file.close();
}
void LinkedList::writeToFileFromHead() {
    Node* temp = Head;
    ofstream file("taskList2.txt");
    do {
        file << temp->nameNode;
        temp = temp->next;
    } while (temp != Tail);
    file << Tail->nameNode;
    file.close();
}

//task7
void LinkedList::insert(int nameNode, int position) {
    Node* temp = new Node;
    Node* cur = Head;
    if ((Head == nullptr) || (Tail == nullptr)) {
        Head = temp;
        Tail = temp;
        cur = temp;
        cur->nameNode = nameNode;
    }
    else {
        for (int i = 0; i < position - 1; i++) {
            cur = cur->next;
        }
        Node* a;

        a = cur->next;
        cur->next = temp;
        temp->next = a;
        temp->prev = cur;
        temp->next->prev = temp;
        temp->nameNode = nameNode;
    }
}

int main()
{
    cout << convertDecToBin(5);
}

