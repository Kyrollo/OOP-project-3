#include <bits/stdc++.h>

using namespace std;

template <class T>
class KMVector{
    private:
        int size, capacity;
        T* data;
    public:
        // Constructors and Big 4
        KMVector(int cap = 2){
            capacity = cap;
            size = 0;
            data = new T[capacity];
        }
        KMVector(T* newdata, int n){
            capacity = n;
            size = n;
            data = new T[capacity];
            for(int i = 0; i < n; i++){
                   data[i] = newdata[i];
            }
        }
        XYVector (const KMVector& other){
            cout <<"..";
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for(int i = 0; i < other.Size; i++){
                   data[i] = other.data[i];
            }
            cout << size  << " "<< capacity << "\n";
        }
        ~KMVector(){
            delete[] data;
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
        T& operator=(const T&& other){
            cout << "..";
            if(this != &other){
                delete[] data;
                size = move(other.size);
                capacity = move(other.capacity);
                data = new T[capacity];
                for(int i = 0; i < other.size; i++){
                    data[i] = move(other.data[i]);
                }
                other.size = 0;
                other.capacity = 0;
                delete[] other.data;
            }
            return *this;
        }

        // Access operations
        T& operator[](int indx){
            if(indx > size-1){
                cout << "An error has occurred, index out of range." << endl;
                exit(-1);
            }
            return data[indx];
        }

        // Modifying operations
        void push_back(T item){
            if(size < capacity){
                data[size++] = item;
            }
            else{
                T* newdata = new T[capacity+1];
                capacity++;

                for(int i = 0; i < size; i++){
                    newdata[i] = data[i];
                }
                delete[] data;
                data = newdata;
                newdata = nullptr;
                data[size++] = item;
            }
        }
        void pop_back(){
            T* newdata = new T[capacity];
            capacity--;
            size--;
            for(int i = 0; i < size; i++){
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            newdata = nullptr;
        }
        void erase(int itr){
            if (itr <= capacity){
                T* newdata = new T[capacity];
                for(int i = 0; i < size; i++){
                    if (i == itr){
                        newdata[i] = data[i+1];
                    }
                    else{
                        newdata[i] = data[i];
                    }
                }
                capacity--;
                size--;
                delete[] data;
                data = newdata;
                newdata = nullptr;
            }
            else{
                cout << "An error has occurred, index out of range.\n";
            }
        }
        void erase(int itr1, int itr2){
            if (itr1 < capacity && itr2 < capacity && itr1 >= 0 && itr2 >=0 && itr1 <= itr2){
                T* newdata = new T[capacity];
                int n = (itr2 - itr1 + 1);
                for(int i = 0; i < size; i++){
                    if (i < itr1){
                        newdata[i] = data[i];
                    }
                    else if (i > itr2){
                        newdata[i-n] = data[i];
                    }
                }
                capacity -= n;
                size -= n;
                delete[] data;
                data = newdata;
                newdata = nullptr;
            }
            else{
                cout << "An error has occurred, index out of range.\n";
                exit(1);
            }
        }
        void clear(){
            size = 0;
            delete[] data;
        }
        void insert(int itr, T item){
            T* newdata = new T[capacity];
            for(int i = 0; i < size; i++){
                if (i == itr){
                    newdata[i] = item;
                }
                else{
                    newdata[i] = data[i];
                }
            }
            delete[] data;
            data = newdata;
            newdata = nullptr;
        }

        // Iterators

        // Comparison operations
        bool operator==(const KMVector<T>& other){
            if (size != other.size){
                return false;
            }
            else{
                for(int i = 0; i < size; i++){
                    if (data[i] != other.data[i]){
                            return false;
                    }
                }
                return true;
            }
        }
        bool operator<(const KMVector<T>& other){
            if (size < other.size){
                return true;
            }
            else{
                for(int i = 0; i < size; i++){
                    if (data[i] != other.data[i]){
                            if (data[i] < other.data[i]){
                                return true;
                            }
                    }
                }
                return false;
            }
        }


        int Size(){
            return size;
        }
        int Capacity(){
            return capacity;
        }
        int resize(){
            cout << "Resizing to " << capacity*2 << endl;
            T* newdata = new T[capacity*2];
            capacity *= 2;

            for(int i = 0; i < size; i++){
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            newdata = nullptr;
        }
        bool empty(){
            if (size == 0){
                return true;
            }
            else {
                return false;
            }
        }

        friend ostream& operator << (ostream& out, KMVector<T> vec){
            for(int i = 0; i < vec.Size(); i++){
                cout << vec[i] << "\n";
            }
        }
};

int main(){
    //int arr[5] = {"1, "2", "3", "4", "5"};
    KMVector <int> vec(1);

    vec.push_back((int) 1);
    vec.push_back((int) 2);
    cout << vec;
    vec.resize();
    cout << "\n";
    cout << vec;
    //vec.insert(0, (string) "Heroooo");
    //vec.clear();
    //cout << vec;

    //cout << vec2;
    /*
    vec.push_back((string) "Neehaw");
    vec.push_back((string) "Bonjour");
    vec.push_back((string) "Guten Tag");
    vec.push_back((string) "Salam Alykum");
    vec.push_back((string) "Hola");
    vec[0] = "Hellooooo";*/

    //cout << vec2;
    /*
    KMVector <string> vec2;
    vec2 = vec;
    vec2[0] = "Salam Alykum231";

    for(int i = 0; i < vec2.Size(); i++){
        cout << vec2[i] << endl;
    }*/
}
