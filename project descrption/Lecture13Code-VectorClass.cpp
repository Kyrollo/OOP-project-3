// A program to demo a template vector class
// Author: Yusef Elzayat
// 13 Nov 2022

#include <bits/stdc++.h>

using namespace std;

template <class T>
class YousefVector{
    private:
        int size, capacity;
        T* data;
    public:
        YousefVector(int cap = 2){
            capacity = cap;
            size = 0;
            data = new T[capacity];
        }
        ~YousefVector(){
            delete[] data;
        }
        T& operator[](int indx){
            if(indx > size-1){
                cout << "An error has occured, index out of range." << endl;
                exit(-1);
            }
            return data[indx];
        }
        void push_back(T item){
            if(size < capacity){
                data[size++] = item;
            }
            else{
                cout << "Resizing to " << capacity*2 << endl;
                T* newdata = new T[capacity*2];
                capacity *= 2;

                for(int i = 0; i < size; i++){
                    newdata[i] = data[i];
                }
                delete[] data;
                data = newdata;
                newdata = nullptr;
                data[size++] = item;
            }
        }
        int getSize(){
            return size;
        }
        T& operator=(const T& other){
            if(this != &other){
                delete[] data;
                size = other.size;
                capacity = other.capacity;
                data = new T[capacity];
                for(int i = 0; i < other.size; i++){
                    data[i] = other.data[i];
                }
            }
            else{
                cout << "Cannot delete self" << endl;
            }
        }



};

int main(){
    YousefVector <string> vec(1);
    vec.push_back((string) "Hello");
    vec.push_back((string) "Neehaw");
    vec.push_back((string) "Bonjour");
    vec.push_back((string) "Guten Tag");
    vec.push_back((string) "Salam Alykum");
    vec.push_back((string) "Hola");
    vec[0] = "Hellooooo";

    for(int i = 0; i < vec.getSize(); i++){
        cout << vec[i] << endl;
    }
    cout << endl << endl;
    YousefVector <string> vec2;
    vec2 = vec;
    vec2[0] = "Salam Alykum231";

    for(int i = 0; i < vec2.getSize(); i++){
        cout << vec2[i] << endl;
    }
}
