#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

class Operational1D{
    public:

    Operational1D(vector<vector<double>> vec)
    {
        height = vec.size();
        width = vec[0].size();
        shape.first = height;
        shape.second = width;
        double* temp = new double[height*width];
        
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                temp[i * height + j] = vec[i][j];
            }
        }
        arr = temp;
    }

    Operational1D(vector<double> vec)
    {
        height = 1;
        width = vec.size();
        shape.first = height;
        shape.second = width;
        double* temp = new double[height*width];
        
        for(int j = 0; j < width; j++){
            temp[j] = vec[j];
        }
        arr = temp;
    }

    Operational1D(double* vec, int height, int width)
    {
        this->height = height;
        this->width = width;
        this->arr = vec;
        shape.first = height;
        shape.second = width;
    }

    double at(pair<int, int> p)
    {
        int i = p.first;
        int j = p.second;
        if(i >= height || j >= width){
            cout << "Error: Index out of bounds" << endl;
            return 0;
        }
        return arr[i * width + j];
    }
    
    void set(pair<int, int> p, double value)
    {
        int i = p.first;
        int j = p.second;
        if(i >= height || j >= width){
            cout << "Error: Index out of bounds" << endl;
            return;
        }
        arr[i * width + j] = value;
    }

    Operational1D at(int i)
    {
        vector<double> temp;
        for(int j = 0; j < width; j++){
            temp.push_back(arr[i * width + j]);
        }
        return Operational1D(temp);
    }

    void set(int i, vector<double> value)
    {
        for(int j = 0; j < width; j++){
            arr[i * width + j] = value[j];
        }
    }
    
    Operational1D addMatrix(Operational1D vec2)
    {
        double* temp = new double[height*width];
        if(vec2.width != width || vec2.height != height){
            printf("Matrix dimensions must agree!");
            exit(1);
        }
        for(int i = 0; i < height*width; i++){
            temp[i] = arr[i] + vec2.arr[i];
        }
        return Operational1D(temp, height, width);
    }

    Operational1D substractMatrix(Operational1D vec2)
    {
        double* temp = new double[height*width];
        if(vec2.width != width || vec2.height != height){
            printf("Matrix dimensions must agree!");
            exit(1);
        }
        for(int i = 0; i < height*width; i++){
            temp[i] = arr[i] - vec2.arr[i];
        }
        return Operational1D(temp, height, width);
    }

    Operational1D multiplyMatrix(Operational1D vec2)
    {
        double* temp = new double[height*width];
        if(vec2.width != width || vec2.height != height){
            printf("Matrix dimensions must agree!");
            exit(1);
        }
        for(int i = 0; i < height*width; i++){
            temp[i] = arr[i] * vec2.arr[i];
        }
        return Operational1D(temp, height, width);
    }

    Operational1D divideMatrix(Operational1D vec2)
    {
        double* temp = new double[height*width];
        if(vec2.width != width || vec2.height != height){
            printf("Matrix dimensions must agree!");
            exit(1);
        }
        for(int i = 0; i < height*width; i++){
            temp[i] = arr[i] / vec2.arr[i];
        }
        return Operational1D(temp, height, width);
    }

    Operational1D intdivideMatrix(Operational1D vec2)
    {
        double* temp = new double[height*width];
        if(vec2.width != width || vec2.height != height){
            printf("Matrix dimensions must agree!");
            exit(1);
        }
        for(int i = 0; i < height*width; i++){
            temp[i] = (int) (arr[i] / vec2.arr[i]);
        }
        return Operational1D(temp, height, width);
    }

    Operational1D atMatrix(Operational1D vec2)
    {
        double* temp = new double[vec2.width*height];
        if(width != vec2.height || height != vec2.width){
            printf("Multiplication requirements not satisfied!");
            exit(1);
        }
        for(int i = 0; i < height; i++){
            for(int q = 0; q < height; q++){
                double subtotal = 0;
                for(int j = 0; j < width; j++){
                    subtotal += arr[i*height + j] * vec2.arr[j*height+q];
                }
                temp[i*height + q] = subtotal;
            }
        }
        return Operational1D(temp, height, vec2.width);
    }

    Operational1D addConstant(double constant)
    {
        double* temp = new double[height*width];
        for(int i = 0; i < height*width; i++){
            temp[i] = arr[i] + constant;
        }
        return Operational1D(temp, height, width);
    }

    Operational1D subtractConstant(double constant)
    {
        double* temp = new double[height*width];
        for(int i = 0; i < height*width; i++){
            temp[i] = arr[i] - constant;
        }
        return Operational1D(temp, height, width);
    }

    Operational1D multiplyConstant(double constant)
    {
        double* temp = new double[height*width];
        for(int i = 0; i < height*width; i++){
            temp[i] = arr[i] * constant;
        }
        return Operational1D(temp, height, width);
    }

    Operational1D divideConstant(double constant)
    {
        double* temp = new double[height*width];
        for(int i = 0; i < height*width; i++){
            temp[i] = arr[i] / constant;
        }
        return Operational1D(temp, height, width);
    }

    Operational1D intdivideConstant(double constant)
    {
        double* temp = new double[height*width];
        for(int i = 0; i < height*width; i++){
            temp[i] = (int) (arr[i] / constant);
        }
        return Operational1D(temp, height, width);
    }

    string printMatrix()
    {
        string temp;
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                temp += to_string(arr[i*width + j]) + " ";
            }
            temp += '\n';
        }
        return temp;
    }

    Operational1D T()
    {
        double* temp = new double[width*height];
        for(int i = 0; i < height*width; i++){
            temp[i/height + width*(i%height)] = arr[i];
        }
        return Operational1D(temp, width, height);
    }

    double det()
    {
        double determinant = 0;
        if(height != width){
            printf("Matrix is not square!\n");
            return -1;
        }
        else if(height == 1){
            return arr[0];
        }
        else if(height == 2){
            return arr[0]*arr[3] - arr[1]*arr[2];
        }
        else{
            vector<vector<double>> tempo(height-1, vector<double>(height-1, 0));
            Operational1D temp(tempo); 
            temp.width = height-1;
            temp.height = height-1;
            for(int i = 0; i < height; i++){
                for(int k = 1; k < height; k++){
                    for(int j = 0, q = 0; j < height; q++, j++){
                        if(i == j){
                            q--;
                            continue;
                        }
                        temp.arr[(k-1)*temp.height + q] = arr[k*height + j];
                    }
                }
                determinant += pow(-1, i) * arr[i] * temp.det();
            }
        }
        return determinant;
    }

    Operational1D copy()
    {
        double* temp = new double[height*width];
        for(int i = 0; i < height*width; i++){
            temp[i] = arr[i];
        }
        return Operational1D(temp, height, width);
    }

    double cofactor(int i, int j)
    {
        vector<vector<double>> temp(width - 1, vector<double>(height - 1, 0));
        for(int k = 0, m = 0; k < width; k++, m++){
            if(k == i){
                m--;
                continue;
            }
            for(int l = 0, q = 0; l < height; q++, l++){
                if(l == j){
                    q--;
                    continue;
                }
                temp[m][q] = arr[k*height + l];
            }
        }
        Operational1D temp2(temp);
        int sign = pow(-1, i+j);
        return temp2.det() * sign;
    }

    Operational1D adjoint()
    {
        vector<vector<double>> temp(height, vector<double>(width, 0));
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                temp[i][j] = cofactor(i, j);
            }
        }
        return Operational1D(temp).T();
    }

    Operational1D inverse()
    {
        double determinant = det();
        if(determinant == 0){
            printf("Matrix is not invertible!\n");
            exit(1);
        }
        else{
            return adjoint().multiplyConstant(1/determinant);
        }
    }


    double* arr;
    size_t width;
    size_t height;
    pair<size_t, size_t> shape;
};
