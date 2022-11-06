// Реализация хеш-таблицы в C++

#include <iostream>
#include <list>
#include "HashNode.h"
using namespace std;


int main()
{
    int key[] = { 1, 2, 3, 4, 5, 6, 5 };
    int data[] = {18,  123, 432, 523, 43, 423, 111 };
    int size = sizeof(key) / sizeof(key[0]);


    SeparateChaining <int> h(size);

    for (int i = 0; i < size; i++)
        h.insert(key[i], data[i]);
    h.Delete(1);
    h.Delete(5);


    h.PrintStructure();

    int key1[] = { 1, 2, 3, 4, 3, 5, 2, 7, 8};
    char data1[] = { 'a','b','c','d','r','2','l','u','i' };
    int size1 = sizeof(key1) / sizeof(key1[0]);
    
    SeparateChaining <char> c(size1);
    
    for (int i = 0; i < size1; i++)
        c.insert(key1[i], data1[i]);
    c.Delete(1);
    c.Delete(2);
    cout << "Search Result: " << c.search(4) << endl;
    
    c.PrintStructure();

    float data2[] = { 17.7, 12.6, 1.1, 2.2, 3.3, 4.4, 5.5,6.6,7.7,8.8, 9.9, 10.1, 11.2, 13.2, 14.6};
    int key2[] = { 1,  3, 2, 4, 6, 2, 4, 5, 8, 22, 12, 7, 8, 9, 0 };
    int size2 = sizeof(key2) / sizeof(key2[0]);


    SeparateChaining <float> s(size2);

    for (int i = 0; i < size2; i++)
        s.insert(key2[i], data2[i]);
    cout << "Search Result: " << s.search(1) << endl;
    cout << "Search Result: " << s.search(5) << endl;
    cout << "Search Result: " << s.search(22) << endl;
    cout << "Search Result: " << s.search(2) << endl;
    cout << "Search Result: " << s.search(3) << endl;

    s.Delete(1);
    s.Delete(5);
    s.Delete(22);
    s.Delete(2);
    s.Delete(3);

    s.PrintStructure();
}