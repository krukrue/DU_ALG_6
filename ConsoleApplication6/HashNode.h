#pragma once
#include <iostream>
#include <list>
using namespace std;

template<typename T>
class SeparateChaining
{
public:
    int capacity;
    list<T>* table; // misto struct HashTable

    SeparateChaining(int V);
    void insert(int key, T data);
    void Delete(int key);
    T search(int key);
    bool isSet(int n) // kontrolujeme zda byl list nainizilizovan
    {
        int i;
        if (n == 1 || n == 0)
        {
            return false;
        }
        for (i = 2; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    int getSet(int n) // velikost pole
    {
        if (n % 2 == 0)
        {
            n++;
        }
        while (!isSet(n))
        {
            n += 2;
        }
        return n;
    }

    int hashFunction(int key)
    {
        return (key % capacity); // bereme index pro nas prvek metodou deleni klice na kapacitu
    }
    void PrintStructure();
};

template<typename T>
SeparateChaining <T>::SeparateChaining(int c) // konstruktor 
{
    int size = getSet(c);  // velikost 
    this->capacity = size; // kapacita
    table = new list<T>[capacity]; // novy list
}

template<typename T>
void SeparateChaining <T>::insert(int key, T data)
{
    int index = hashFunction(key); // bereme index nasiho prvku
    table[index].push_back(data); // push podle indexu
}

template<typename T>
void SeparateChaining <T>::Delete(int key) 
{
    int index = hashFunction(key); // bereme index nasiho prvku

    for (auto i = table[index].begin();
        i != table[index].end(); i++)
    {
        table[index].erase(i); // odstranime retezec z listu
        break;

    }

}


template<typename T>
void SeparateChaining <T>::PrintStructure() // vypis kazdeho prvku
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}
template<typename T>
inline T SeparateChaining<T>::search(int key) // plny pruchod list a porovnani s klicem, ktery hledame
{
    for (int i = 0; i < capacity; i++)
    {
        for (auto x : table[i])
            if (key == i) {
                return x;
            }
    }
}
