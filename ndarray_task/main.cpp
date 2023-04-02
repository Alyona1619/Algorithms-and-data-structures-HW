#include "ndarray.h"
#include <iostream>


using namespace std;

int main() {
    NDArray <int> empt;

    std::vector<int> s = {2, 3};
    std::vector<float> d = {2.5, 4, 3.2, 8.1, 9, 10.4};
    NDArray <float> c(s, d);

    NDArray <int> arr_with_zeros(5);

    NDArray <int> arr_with_ones(5, {}, 1);

    NDArray <int> arr_with_random(5, {}, 2);

    cout << c << endl;
    cout << arr_with_zeros << endl;
    cout << arr_with_ones << endl;
    
    c.rand_data();
    cout << c << endl;

    

}
