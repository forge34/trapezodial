// Trapezoidal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "fparser.hh"


using namespace std;

double trapezoidal(string fn,double lower, double upper, double n) {
    FunctionParser function;

    function.Parse(fn, "x");
    double x = lower;
    double h = (upper - lower) / n;


    double result = 0;

    for (int i = 1; i < n ; i++) {
        x += h;
        result += function.Eval(&x);
    }

    result =  (function.Eval(&lower) + function.Eval(&upper) + (2 * result) ) * h/2;
    return result;
}


int main()
{
    string s;
    double lower=0, upper=0, n=0;

    cout << "Enter function : ";
    cin >> s;

    cout << "Enter lower bound : ";
    cin >> lower;

    cout << "Enter upper bound : ";
    cin >> upper;

    cout << "Enter n: ";
    cin >> n;

    cout << "Result is : " << trapezoidal(s, lower, upper, n) << endl;;
    return 0;
}

