#ifndef TEMPFUNC_HPP
#define TEMPFUNC_HPP

#include <iostream>

// Find largest among two numbers using function template
template <typename T>
T findMax(T input1, T input2) {
    if(input1 > input2)
        return input1;
    else
        return input2;
}

// Swap data using function template
template <typename T>
void swapData(T input1, T input2) {
    T temp = input1;
    input1 = input2;
    input2 = temp;
}

// Simple calculator using class template
template <typename T>
class Calculator {
    T num1;
    T num2;
    public:
        Calculator();
        Calculator(T num1,T num2);
        T getNum1() {return num1;};
        void setNum1(T num1) {this->num1 = num1;};
        T getNum2() {return num2;};
        void setNum2(T num2) {this->num2 = num2;};
        void display();
};

template <typename T>
Calculator<T>::Calculator() {
    num1 = 0;
    num2 = 0;
}

template <typename T>
Calculator<T>::Calculator(T num1,T num2) {
    this->num1 = num1;
    this->num2 = num2;
}

template <typename T>
void Calculator<T>::display() {
    std::cout << "Addition: " << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
    std::cout << "Substraction: " << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
    std::cout << "Multiplication: " << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
    std::cout << "Division: " << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
}

#endif