// Learning C++ Coding

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Printing "Hello, World! and a simple introduction" to the console
    cout << "Hello, World!\n\n";
    cout << "In this file, I'll be learning how to code in C++ while doing multiple assingments attempting Level A & B in the Self Learning Assignment 1.\n";
    cout << "___________________________________________________________________________________________________________________________________________________________________________\n\n";
    
    // Defining the Different Data Types
    cout << "Data Types:\n\n";
    cout << "1. 'int'/'integer' is used to indicate integer numbers such as 1, 5, 10, 20, etc..\n";
    cout << "2. 'float' or 'double' are both used to floating-point numbers of which have decomals and exponentials. However, it is better to use double as it 'double' the byte size of   'float' making it more precise. An exmaple can be such as '17.38'.\n";
    cout << "3. 'bool'/'boolean' is used to identify a boolean value, which can either be 'True' or 'False'.\n";
    cout << "4. 'char'/'character' is used to identify a single character such as 'a', 'F', or '?'.\n";
    cout << "5. 'void'/'empty' is used to identify the absensce of data. In other words it means there is no 'value' and has no need to return any value. \n\n";
    cout << "___________________________________________________________________________________________________________________________________________________________________________\n\n";

    // Defining Unary Operators with Examples
    int x = 5;
    cout << "Unary Operators:\n\n";
    cout << "'++' means increase the value of a variable by 1.\n";
    cout << "'--' means decrease the value of a variable by 1.\n";
    cout << "Note: When a unary operator is used, it takes the last calculated integer of the value and not necessarily the first value of the variable.\n\n";
    cout << "x = " << x << endl << "\n";
    cout << "++x = " << ++x << endl;
    cout << "--x = " << --x << endl;
    cout << "--x = " << --x << endl;
    cout << "x = " << x << endl << "\n";
    cout << "___________________________________________________________________________________________________________________________________________________________________________\n\n";
    
    // Defining Arithmetic Operations with Examples
    int a = 5, b = 10;
    cout << "Arithmetic Operators:\n\n";
    cout << "'+' means add two variables by each other.\n";
    cout << "'-' means subtract two variables by each other.\n";
    cout << "'*' means multiply two variables by each other.\n";
    cout << "'/' means divide two variables by each other.\n";
    cout << "'%' is the modulus which means that it returns the remainder of a division.\n\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl << "\n";
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "a % b = " << a % b << endl << "\n";
    cout << "___________________________________________________________________________________________________________________________________________________________________________\n\n";
    
    // Defining Relational Operations with Examples
    int c = 15, d = 20;
    cout << "Rational Operators:\n\n";
    cout << "'==' means two variables are equal to each other.\n";
    cout << "'!=' means two variables are not equal to each other.\n";
    cout << "'<' means one variable is less than the other variable.\n";
    cout << "'>' means one variable is more than the other variable.\n";
    cout << "'<=' means one variable is less than or equal to another variable.\n";
    cout << "'>=' means one variable is greater than or equal to another variable.\n";
    cout << "Note: The outcome is given in '0' when the statement is false and '1' when the statement is true.\n\n";
    cout << "c = " << c << endl;
    cout << "d = " << d << endl << "\n";
    cout << "c == d is " << (c == d) << endl;
    cout << "c != d is " << (c != d) << endl;
    cout << "c < d is " << (c < d) << endl;
    cout << "c > d is " << (c > d) << endl;
    cout << "c <= d is " << (c <= d) << endl;
    cout << "c >= d is " << (c >= d) << endl << "\n";
    cout << "___________________________________________________________________________________________________________________________________________________________________________\n\n";
    
    // Defining the Use of the Standard Math Library with Examples
    double e = 16.0;
    cout << "Use of the Standard Math Library <cmath>:\n\n";
    cout << "'sqrt'/'square root' means taking the square root of a variable.\n";
    cout << "'log'/'natural' means taking the natural log of a variable.\n";
    cout << "Note: since the variable is places in a 'double', the output of the math equation can be in decimals or can be exponential.\n\n";
    cout << "e = " << e << endl << "\n";
    cout << "sqrt(" << e << ") = " << sqrt(e) << endl;
    cout << "log(" << e << ") = " << log(e) << endl << "\n";
    cout << "___________________________________________________________________________________________________________________________________________________________________________\n\n";
    
    // Defining the Use of the Iomanip Library with Examples
    double π = 3.14159265359;
    cout << "Use of the Iomanip Library <iomanip>:\n\n";
    cout << "'setprecision(x)' means setting the precison for any floating-point value and returning thre value to a set decmial place. Whatever is set as 'x' will be the decimal place\n";
    cout << "Note: since the variable is places in a 'double', the output of the math equation can be in decimals or can be exponential.\n\n";
    cout << "π = " << π << endl << "\n";
    cout << "π (rounded to 2 decimal places) = " << fixed << setprecision(3) << π << endl;
    cout << "___________________________________________________________________________________________________________________________________________________________________________\n\n";

    // Having a Conversation with a User Using this Code
    int age;
    float height;
    char initial;
    int w1, w2, x1, x2, y1, y2, z1, z2, answer;
    string name;

    cout << "Hello, My name is Bob!\n";
    cout << "What is your name? \n";
    getline(cin, name);

    cout << "Pleased to meet you, " << name << "! How old are you? \n";
    cin >> age;

    cout << "And what is your height in cm? \n";
    cin >> height;

    cout << "And what is your first initial? \n";
    cin >> initial >> fixed >> setprecision(2);

    cout << "Sweet " << name << ", as a " << age << " year old you are quite young and still have a long time ahead of you. I wish I was your height. With your height of " << height << " you can easily be a     basketball player. P.S. your first initial of " << initial << " is pretty cool.\n\n\n";
    
    cout << "Let me ask you a set of easy mathematical questions. Don't use a calculator.\n\n";
    
    w1 = 15;
    w2 = 38;
    cout << w1 << " + " << w2 << " = ";
    cin >> answer;
    if (answer == w1 + w2) {
        cout << "Your answer is correct :)\n";
    } else {
        cout << "Your answer is wrong :(\n\n";
    }

    x1 = 12;
    x2 = 9;
    cout << x1 << " - " << x2 << " = ";
    cin >> answer;
    if (answer == x1 - x2) {
        cout << "Your answer is correct :)\n";
    } else {
        cout << "Your answer is wrong :(\n\n";
    }
    
    y1 = 7;
    y2 = 11;
    cout << y1 << " * " << y2 << " = ";
    cin >> answer;
    if (answer == y1 * y2) {
        cout << "Your answer is correct :)\n";
    } else {
        cout << "Your answer is wrong :(\n\n";
    }

    z1 = 20;
    z2 = 4;
    cout << z1 << " / " << z2 << " = ";
    cin >> answer;
    if (answer == z1 / z2) {
        cout << "Your answer is correct :)\n";
    } else {
        cout << "Your answer is wrong :(\n\n";
    }

    return 0;
}
