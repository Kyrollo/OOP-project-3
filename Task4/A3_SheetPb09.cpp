
#include <bits/stdc++.h>
using namespace std;

template <class T>

class myset
{
private:
    int size, capacity;
    T *data;

public:
    int getSize()
    {
        return size;
    }

    myset(int cap = 2)
    {
        capacity = cap;
        size = 0;
        data = new T[capacity];
    }

    ~myset()
    {
        delete[] data;
    }

    T &operator[](int indx)
    {
        if (indx > size - 1)
        {
            cout << "An error has occured, index out of range." << endl;
            exit(-1);
        }
        return data[indx];
    }

    void push_back(T item)
    {
        bool con;
        for (int i = 0; i < size; i++)
        {
            if (data[i] == item)
            {
                con = true;
                break;
            }
            else
                con = false;
        }
        if (size < capacity && con == false)
        {
            data[size++] = item;
        }
        else if (size >= capacity && con == false)
        {
            cout << "Resizing to " << capacity * 2 << endl;
            T *newdata = new T[capacity * 2];
            capacity *= 2;

            for (int i = 0; i < size; i++)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            newdata = nullptr;
            data[size++] = item;
        }
    }

    void pop_back()
    {
        T *newdata = new T[capacity];
        size -= 1;
        for (int i = 0; i < size; i++)
        {
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
        newdata = nullptr;
    }

    bool is_exist(T item)
    {
        bool con;
        for (int i = 0; i < size; i++)
        {
            if (data[i] == item)
            {
                con = true;
                break;
            }
            else
                con = false;
        }
        return con;
    }

    void clear()
    {
        int newsize = size;
        for (int i = 0; i < newsize; i++)
        {
            pop_back();
        }
    }

    T begin()
    {
        return data[0];
    }

    T end()
    {
        return data[size - 1];
    }

    bool operator==(const myset<T> &other)
    {
        int maxsize;
        if (size > other.size)
        {
            maxsize = size;
        }
        else
            maxsize = other.size;

        bool con = true;
        for (int i = 0; i < maxsize; i++)
        {
            if (data[i] != other.data[i])
            {
                con = false;
                // cout << data[i] << " " << other.data[i] << "\n";
                break;
            }
            else
            {
                con = true;
                // cout << data[i] << " " << other.data[i] << "\n";
            }
        }
        return con;
    }

    bool empty()
    {
        if (size == 0)
        {
            return true;
        }
        else
            return false;
    }

    T &operator=(const T &other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < other.size; i++)
            {
                data[i] = other.data[i];
            }
        }
        else
        {
            cout << "Cannot delete self" << endl;
        }
    }
};

int main()
{
    myset<string> vec(1);
    vec.push_back((string) "samer");
    vec.push_back((string) "medhat");
    vec.push_back((string) "medhat");
    vec.push_back((string) "medhat");
    vec.push_back((string) "medhat");
    vec.push_back((string) "medhat");
    vec.push_back((string) "medhat");
    vec.push_back((string) "milad");
    myset<string> vec2(1);
    vec2.push_back((string) "marco");
    vec2.push_back((string) "marco");
    vec2.push_back((string) "marco");
    vec2.push_back((string) "kamal");
    vec2.push_back((string) "sadik");
    cout << vec.is_exist("marco")<<endl;
    cout << vec2.is_exist("marco")<<endl;
    for (int i = 0; i < vec.getSize(); i++)
    {
        cout << vec[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < vec2.getSize(); i++)
    {
        cout << vec2[i] << endl;
    }
    return 0;
}
