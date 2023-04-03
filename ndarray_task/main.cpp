#include "ndarray.h"
#include <iostream>


using namespace std;

int main() {

    std::vector<int> s = {2, 3};
    std::vector<int> d = {2, 4, 3, 8, 9, 10};
    NDArray <int> c(s, d);

    NDArray <int> arr_with_zeros(5);

    NDArray <int> arr_with_ones(5, {}, 1);

    cout << "NDArray <int> c(s, d); \t\t\t result: " << c << endl; // 2 4 3 8 9 10
    cout << "NDArray <int> arr_with_zeros(5); \t result: " << arr_with_zeros << endl; // 0 0 0 0 0
    cout << "NDArray <int> arr_with_ones(5, {}, 1); \t result: " << arr_with_ones << endl; // 1 1 1 1 1
    
    c.rand_data();
    cout << "c.rand_data(); \t\t\t\t result: " << c << endl; //random

    NDArray<float> first({2,2}, {2.6, 4.3, 3.1, 5.76});
    NDArray<float> second({2,2}, {9.2, 7.4, 8.1, 6});

    NDArray <float> result;

    cout << "\nNDArray<float> first({2,2}, {2.6, 4.3, 3.1, 5.76});" << endl;
    cout << "NDArray<float> second({2,2}, {9.2, 7.4, 8.1, 6});\n" << endl;
    result = first + second; // 11.8 11.7 11.2 11.76
    cout << "first + second = " << result << endl;

    result = second - first; // 6.6 3.1 5 0.24
    cout << "first - second = " <<  result << endl;

    result = first * second; // 23.92 31.82 25.11 34.56
    cout <<  "first * second = " << result << endl;

    result = first / second; // 0.282609 0.581081 0.382716 0.96
    cout <<  "first / second = " << result << endl;

    result = second.transpose(); // 9.2 8.1 7.4 6
    cout << "second.transpose() \t\t result: " << result << endl;

    result = first.matrix_multi(second); // 55.74 46.86 71.144 59.67
    cout <<  "first.matrix_multi(second) \t result: " << result << endl;

    float min = first.min(); // 2.6
    float max = first.max(); //5.76
    float mean = first.mean(); //3.94
    cout << "first.min() \t result: " << min << "\n" << "first.max() \t result: " << max << "\n" << "first.mean() \t result: "<< mean << endl;
}
