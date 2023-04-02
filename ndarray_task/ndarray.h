#include <iostream>
#include <vector>
#include <ctime>

template <typename T> class NDArray {

    private:
       
        std::vector<int> shape;
        int len;
        std::vector<T> array;

    public:

        NDArray(){
            shape = {};
            len = 0;
            array = {};
        }

        NDArray(int sh, std::vector<T> data = {}, int fill = 0) {
            shape.push_back(sh);
            len = sh;

            if (data.empty()) {
                if (fill == 0)
                    array = std::vector<T>(len, 0);
                else 
                    array = std::vector<T>(len, 1);
            } else {
                array = data;
            }
            //for (int i{}; i <= len; i++)
            //    array.push_back(data);
        };

        NDArray(std::vector<int> sh, std::vector<T> data = {}, int fill = 0){
            len = 1;
            for (auto v : sh) {
                len *= v;
                shape.push_back(v);
            }

            if (data.empty()) {
                if (fill == 0)
                    array = std::vector<T>(len, 0);
                else 
                    array = std::vector<T>(len, 1);
            } else {
                array = data;
            }
            //for (int i{}; i <= len; i++)
            //    array.push_back(data);
        };

        void rand_data(){
            srand(time(NULL));
            array.clear();
            for (int i{}; i < len; i++) {
                T x = rand();
                array.push_back(x);
            }
        };

        NDArray<T>& operator += (const NDArray<T>& arr) {
            assert(shape == v.shape);
            for (int i{}; i < len; i++) 
                array[i] += arr.array[i];
            return *this;
        }

        NDArray<T>& operator + (const NDArray<T>& arr) {
            return NDArray(*this) += arr;
        }

        NDArray<T>& operator *= (const NDArray<T>& arr) {
            assert(shape == arr.shape);
            for (int i = 0; i < len; i++)
                array[i] *= arr.array[i];
            return *this;
    }

        NDArray<T> operator * (const NDArray<T>& arr) const {
            NDArray<T> res(*this);
            return res *= arr;
        }

        NDArray<T> operator -() const {
            NDArray<T> res(*this);
            return res *= -1;
        }

        NDArray<T>& operator -= (const NDArray<T>& arr) {
            return (*this += (-v))
        }

        NDArray<T>& operator - (const NDArray<T>& arr) {
            NDArray<T> res(*this);
            return res -= v;
        }

        friend std::ostream& operator << (std::ostream& out, const NDArray& arr) {
            for (auto v: arr.array){
                out << v << ' ';
            }
            out << std::endl;
            return out;
        };

};        
