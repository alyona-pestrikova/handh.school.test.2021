﻿// handh.school.test.2021.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>

using namespace std;

//функция, проверяющая, совпадает ли заданное значение col с одним из значений от 0 до k-1 в заданном массиве arr
int Mark(int* arr, int value, int n){
    int mark = 1;
    for (int i = 0; i < n; i++) {
        if (value == arr[i]) {
            mark = 0;
            break;
        }
    }

    return mark;
}

vector<vector<int>>SmartVec(int n) {
    int col;

    vector<vector<int>>Vec;
    Vec.resize(n);

    int* cols = new int[n]; //массив, который хранит длины n массивов
    int k = 0;

    for (int i = 0; i < n; i++) {
        col = rand() % 31 + 1; //Задаём ограничение на длину массива во избежание слишком долгой работы во время сортировки

        //отслеживание того, чтобы длины массивов были различны
        if (k != 0) {
            int marker = Mark(cols, col, k);
            while (marker == 0) {
                col = rand() % 31 + 1;
                marker = Mark(cols, col, k);
            }
        }

        cols[k++] = col;
        Vec[i].resize(col);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < Vec[i].size(); j++) {
            Vec[i][j] = rand();
        }
    }

    //сортировка массивов с чётным номером в порядке возрастания
    for (int i = 0; i < n - 2; i += 2) {
        for (int j = 0; j < Vec[i].size(); j++) {
            for (int s = Vec[i].size() - 1; s > 0; s--) {
                if (Vec[i][s] < Vec[i][s - 1]) {
                    swap(Vec[i][s], Vec[i][s - 1]);
                }
            }
        }
    }

    //сортировка массивов с нечётным номером в порядке убывания
    for (int i = 1; i < n - 1; i += 2) {
        for (int j = 0; j < Vec[i].size(); j++) {
            for (int s = Vec[i].size() - 1; s > 0; s--) {
                if (Vec[i][s] > Vec[i][s - 1]) {
                    swap(Vec[i][s], Vec[i][s - 1]);
                }
            }
        }
    }

    return Vec;
}

int main()
{
    int n, col;
    cin >> n;

    vector<vector<int>>Vec = SmartVec(n);

    //просто вывод массивов :)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < Vec[i].size(); j++) {
            cout << Vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
