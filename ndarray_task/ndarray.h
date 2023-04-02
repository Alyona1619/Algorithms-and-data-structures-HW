#include <iostream>
#include <vector>
#include <time.h>
#include <cassert>
#include <climits>

template <typename T> class NDArray {

    private:
       
        std::vector<int> shape;
        int dimsAmount;
        int len;
        std::vector<T> array;

    public:

        NDArray() = default;

        NDArray(int sh, std::vector<T> data = {}) {
            shape.push_back(sh);
            len = sh;

            if (data.empty()) {
                array = std::vector<T>(len, 0);
            } else {
                array = data;
            }
            //for (int i{}; i <= len; i++)
            //    array.push_back(data);
        };

        NDArray(std::vector<int>* sh, std::vector<T> data = {}){
            len = 1;
            for (auto v : *sh) {
                len *= v;
                shape.push_back(v);
            }

            if (data.empty()) {
                array = std::vector<int>(len, 0);
            } else {
                array = data;
            }
            //for (int i{}; i <= len; i++)
            //    array.push_back(data);
        };

        friend std::ostream& operator << (std::ostream& out, const NDArray& arr) {
            for (auto v: arr.array){
                out << v << ' ';
            }
            out << std::endl;
            return out;
        };

};
