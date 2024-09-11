#include <cstdint>
#include <cstring>
#include <iostream>

class ArrayHandler {
private:
    char* _array;
    char _max;
    char _min;
    long long int* _arrayIndex;
    long long int _size;
    long long int _count;
    bool _fullAlf = false;

    void GetArrayIndex(){
        int values = 0;
        long long int i = 0;
        while((values != 100) && (i != _count)){
            if(_arrayIndex[_array[i]] == -1){
                _arrayIndex[_array[i]] = i;
                values++;
            }
            i++;
        }
        _fullAlf = true;
    }

public:
    ArrayHandler(long long int size = 10){
        _size = size;
        _array = new char[_size];
        _max = -128;
        _min = 127;
        _count = 0;
        _arrayIndex = new long long int[100];
        for(int i = 0; i < 100; i++){
            _arrayIndex[i] = -1;
        }
    }
    void Append(char new_element){
        if (_count == _size) {
            _size = _size * 2;
            char* new_arr = new char[_size];
            std::memcpy(new_arr, _array, _count*sizeof(char));
            delete [] _array;
            _array = new_arr;
        }
        _array[_count] = new_element;
        _count++;
        if(_max < new_element){
            _max = new_element;
        }
        else if(_min > new_element){
            _min = new_element;
        }
    }
    int GetMax(){
        return _max;
    }
    int GetMin(){
        return _min;
    }

    int GetIndexElem(int elem){
        if(_fullAlf == false){
            GetArrayIndex();
        }
        return _arrayIndex[elem];
    }
    ~ArrayHandler() {
        delete [] _array;
        delete [] _arrayIndex;
    }

    friend std::ostream& operator<<(std::ostream& os, const ArrayHandler& arr) {
        for (size_t i = 0; i < arr._size; i++) {
            os << arr._array[i] << std::endl;
        }
        return os;
    }

};