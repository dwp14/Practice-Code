#include <iostream>
#include "TemplateFunction.hpp"

using namespace std;

int main() {
    Calculator<int> calc1(2,3);
    calc1.display();
    Calculator<double> calc2(2.0,3.0);
    calc2.display();

    return 0;
}