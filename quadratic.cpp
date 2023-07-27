#include <iostream>
#include <cmath>
#include <array>

using namespace std;

array<double,2> quadratic(int a,int b, int c) {
    double formula = pow(b,2)-4*a*c;
    double root = sqrt(formula);
    double x1 = -b+root;
    double x2 = -b-root;
    array<double,2> values = {x1/2,x2/2};
    return values;
}

int main() {
    int a,b,c;
    printf("Quadratic formula example is ax^2+bx+c \n");
    printf("Value of a \n");
    cin >> a;
    printf("Value of b \n");
        cin >> b;
    printf("Value of c \n");
        cin >> c;

    array<double,2> values = quadratic(a,b,c);

    cout << "First value is "<<to_string(values[0])<<endl;
    cout << "Second value is "<<to_string(values[1])<<endl;
    return 0;
}