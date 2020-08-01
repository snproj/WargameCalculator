#include <iostream>
#include <string>
using namespace std;

int  weird_points_calculator(int x, int bonus, double scale)
{
    int a = x;
    do
    {
        x = x * scale;
    } while (x < a * bonus);
    cout << "WEIRD POINTS CALC: " << x << endl;

    return x;
}

int* weird_points_calculator_array(int x[], int range, int bonus, double scale)
{
    int* arr = new int;
    for (int i = 0; i < range; i++)
    {
        int elem = weird_points_calculator(x[i], bonus, scale);
        arr[i] = elem; // type?
    }
    cout << endl;
    return arr;

}

int magnitude(int x)
{
    int i = 0;
    while (x > 10)
    {
        x = x / 10;
        i++; 
    }

    return i;
}