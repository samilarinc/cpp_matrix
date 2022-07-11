#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <stdexcept>

using namespace std;

template <typename T>
class Operational1D{
    public:

    Operational1D(vector<vector<T>> vec)
    {
        height = vec.size();
        width = vec[0].size();
        shape.first = height;
        shape.second = width;
        T* temp = new T[height*width];
        
        for(size_t i = 0; i < height; i++){
            for(size_t j = 0; j < width; j++){
                temp[i * height + j] = vec[i][j];
            }
        }
        arr = temp;
    }

    Operational1D(vector<T> vec)
    {
        height = 1;
        width = vec.size();
        shape.first = height;
        shape.second = width;
        T* temp = new T[height*width];
        
        for(size_t j = 0; j < width; j++){
            temp[j] = vec[j];
        }
        arr = temp;
    }

    Operational1D(T* vec, size_t height, size_t width)
    {
        this->height = height;
        this->width = width;
        this->arr = vec;
        shape.first = height;
        shape.second = width;
    }

    size_t length()
    {
        return height * width;
    }

    T at(pair<size_t, size_t> p)
    {
        size_t i = p.first;
        size_t j = p.second;
        if(i >= height || j >= width){
            throw std::exception("Index out of bounds");
            return 0;
        }
        return arr[i * width + j];
    }
    
    void set(pair<size_t, size_t> p, T value)
    {
        size_t i = p.first;
        size_t j = p.second;
        if(i >= height || j >= width){
            throw std::exception("Index out of bounds");
            return;
        }
        arr[i * width + j] = value;
    }

    Operational1D at(size_t i)
    {
        vector<T> temp;
        for(size_t j = 0; j < width; j++){
            temp.push_back(arr[i * width + j]);
        }
        return Operational1D(temp);
    }

    void set(size_t i, vector<T> value)
    {
        for(size_t j = 0; j < width; j++){
            arr[i * width + j] = value[j];
        }
    }
    
    Operational1D addMatrix(Operational1D vec2)
    {
        T* temp = new T[height*width];
        if(vec2.width != width || vec2.height != height){
            throw std::exception("Matrix dimensions must agree!");
            return vec2;
        }
        for(size_t i = 0; i < height*width; i++){
            temp[i] = arr[i] + vec2.arr[i];
        }
        return Operational1D(temp, height, width);
    }

    Operational1D substractMatrix(Operational1D vec2)
    {
        T* temp = new T[height*width];
        if(vec2.width != width || vec2.height != height){
            throw std::exception("Matrix dimensions must agree!");
            return vec2;
        }
        for(size_t i = 0; i < height*width; i++){
            temp[i] = arr[i] - vec2.arr[i];
        }
        return Operational1D(temp, height, width);
    }

    Operational1D multiplyMatrix(Operational1D vec2)
    {
        T* temp = new T[height*width];
        if(vec2.width != width || vec2.height != height){
            throw std::exception("Matrix dimensions must agree!");
            return vec2;
        }
        for(size_t i = 0; i < height*width; i++){
            temp[i] = arr[i] * vec2.arr[i];
        }
        return Operational1D(temp, height, width);
    }

    Operational1D divideMatrix(Operational1D vec2)
    {
        T* temp = new T[height*width];
        if(vec2.width != width || vec2.height != height){
            throw std::exception("Matrix dimensions must agree!");
            return vec2;
        }
        for(size_t i = 0; i < height*width; i++){
            temp[i] = arr[i] / vec2.arr[i];
        }
        return Operational1D(temp, height, width);
    }

    Operational1D intdivideMatrix(Operational1D vec2)
    {
        T* temp = new T[height*width];
        if(vec2.width != width || vec2.height != height){
            throw std::exception("Matrix dimensions must agree!");
            return vec2;
        }
        for(size_t i = 0; i < height*width; i++){
            temp[i] = (int) (arr[i] / vec2.arr[i]);
        }
        return Operational1D(temp, height, width);
    }

    Operational1D atMatrix(Operational1D vec2)
    {
        T* temp = new T[vec2.width*height];
        if(width != vec2.height || height != vec2.width){
            throw std::exception("Matrix dimensions must agree!");
            return vec2;
        }
        for(size_t i = 0; i < height; i++){
            for(size_t q = 0; q < height; q++){
                T subtotal = 0;
                for(size_t j = 0; j < width; j++){
                    subtotal += arr[i*height + j] * vec2.arr[j*height+q];
                }
                temp[i*height + q] = subtotal;
            }
        }
        return Operational1D(temp, height, vec2.width);
    }

    Operational1D addConstant(T constant)
    {
        T* temp = new T[height*width];
        for(size_t i = 0; i < height*width; i++){
            temp[i] = arr[i] + constant;
        }
        return Operational1D(temp, height, width);
    }

    Operational1D subtractConstant(T constant)
    {
        T* temp = new T[height*width];
        for(size_t i = 0; i < height*width; i++){
            temp[i] = arr[i] - constant;
        }
        return Operational1D(temp, height, width);
    }

    Operational1D multiplyConstant(T constant)
    {
        T* temp = new T[height*width];
        for(size_t i = 0; i < height*width; i++){
            temp[i] = arr[i] * constant;
        }
        return Operational1D(temp, height, width);
    }

    Operational1D divideConstant(T constant)
    {
        T* temp = new T[height*width];
        for(size_t i = 0; i < height*width; i++){
            temp[i] = arr[i] / constant;
        }
        return Operational1D(temp, height, width);
    }

    Operational1D intdivideConstant(T constant)
    {
        T* temp = new T[height*width];
        for(size_t i = 0; i < height*width; i++){
            temp[i] = (int) (arr[i] / constant);
        }
        return Operational1D(temp, height, width);
    }

    string printMatrix()
    {
        string temp;
        for(size_t i = 0; i < height; i++){
            for(size_t j = 0; j < width; j++){
                temp += to_string(arr[i*width + j]) + " ";
            }
            temp += '\n';
        }
        return temp;
    }

    Operational1D T()
    {
        T* temp = new T[width*height];
        for(size_t i = 0; i < height*width; i++){
            temp[i/height + width*(i%height)] = arr[i];
        }
        return Operational1D(temp, width, height);
    }

    T det()
    {
        T determinant = 0;
        if(height != width){
            throw std::exception("Matrix is not square!");
            return 0;
        }
        else if(height == 1){
            return arr[0];
        }
        else if(height == 2){
            return arr[0]*arr[3] - arr[1]*arr[2];
        }
        else{
            vector<vector<T>> temp_vector(height-1, vector<T>(height-1, 0));
            Operational1D temp(temp_vector); 
            temp.width = height-1;
            temp.height = height-1;
            for(size_t i = 0; i < height; i++){
                for(size_t k = 1; k < height; k++){
                    for(size_t j = 0, q = 0; j < height; q++, j++){
                        if(i == j){
                            q--;
                            continue;
                        }
                        temp.arr[(k-1)*temp.height + q] = arr[k*height + j];
                    }
                }
                T temp_determinant = temp.det() * arr[i];
                temp_determinant = (i%2 == 0) ? temp_determinant : -temp_determinant;
                determinant += temp_determinant;
            }
        }
        return determinant;
    }

    Operational1D copy()
    {
        T* temp = new T[height*width];
        memcpy(temp, arr, height*width*sizeof(T));
        return Operational1D(temp, height, width);
    }

    T cofactor(size_t i, size_t j)
    {
        vector<vector<T>> temp(width - 1, vector<T>(height - 1, 0));
        for(size_t k = 0, m = 0; k < width; k++, m++){
            if(k == i){
                m--;
                continue;
            }
            for(size_t l = 0, q = 0; l < height; q++, l++){
                if(l == j){
                    q--;
                    continue;
                }
                temp[m][q] = arr[k*height + l];
            }
        }
        Operational1D temp2(temp);
        int sign = ((i+j)%2 == 0) ? 1 : -1;
        return temp2.det() * sign;
    }

    Operational1D adjoint()
    {
        vector<vector<T>> temp(height, vector<T>(width, 0));
        for(size_t i = 0; i < height; i++){
            for(size_t j = 0; j < width; j++){
                temp[i][j] = cofactor(i, j);
            }
        }
        return Operational1D(temp).T();
    }

    Operational1D inverse()
    {
        T determinant = det();
        if(determinant == 0){
            throw std::exception("Matrix is not invertible!\n");
            return Operational1D(arr, height, width);
        }
        else{
            return adjoint().multiplyConstant(1/determinant);
        }
    }

    T* arr;
    size_t width;
    size_t height;
    pair<size_t, size_t> shape;
};
