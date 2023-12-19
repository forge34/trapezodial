#include <iostream>
#include <vector>
#include "fparser.hh"

using namespace std;

double trapezoidal(string fn, double lower, double upper, double n) {
    FunctionParser function;

    function.Parse(fn, "x");
    double x = lower;
    double h = (upper - lower) / n;

    double result = 0;

    for (int i = 1; i < n; i++) {
        x += h;
        result += function.Eval(&x);
    }

    result = (function.Eval(&lower) + function.Eval(&upper) + (2 * result)) * h / 2;

    int error = function.EvalError();

    if (error > 0) {
        throw std::invalid_argument("Invalid value for x");
    }

    return result;
}


int main()
{
    string s;
    double lower = 0, upper = 0, n = 0;
    string hasDecimal;

    cout << "Enter function : ";
    cin >> s;

    cout << "Enter lower bound : ";
    cin >> lower;

    cout << "Enter upper bound : ";
    cin >> upper;

    cout << "Enter n: ";
    cin >> n;

    cout << "with decimal or no decimal (yes/no) : ";
    cin >> hasDecimal;

    if ( n < 0 ) {
        cout << "N is less than zero";
        return 0;
    }

    try {
        if (hasDecimal == "no")
            cout << "Result is : " << int(trapezoidal(s, lower, upper, n)) << endl;

        else if (hasDecimal == "yes") {
            cout << "Result is : " << trapezoidal(s, lower, upper, n) << endl;
        }

    }
   catch (const std::invalid_argument& e){
       cout << e.what();
    }

    return 0;
}