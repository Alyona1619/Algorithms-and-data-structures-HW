#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
#include <numeric>

// change assert to if
// add div

//add operators for each element by one number
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
            assert(shape == arr.shape);
            for (int i{}; i < len; i++){
                array[i] += arr.array[i];
            }
            return *this;
        };

        NDArray<T> operator + (const NDArray<T>& arr) const{
            return NDArray<T>(*this) += arr;
        };

        NDArray<T>& operator *= (const NDArray<T>& arr) {
            assert(shape == arr.shape);
            for (int i{}; i < len; i++){
                array[i] *= arr.array[i];
            }
            return *this;
        };

        NDArray<T> operator * (const NDArray<T>& arr) const {
            return NDArray<T>(*this) *= arr;
        };

        // NDArray<T> operator *= (T a) { //  на число
        //     std::cout << a <<"00000000" << std::endl;
        //     for (int i{}; i < len; i++){
                
        //         //std::cout << array[i] << "!" << std::endl;
        //         array[i] *= a;
                
        //         std::cout << array[i] <<"!!!" << std::endl;
        //     }
        //     return *this;
        // };

        // NDArray<T> operator -() const {
        //     return NDArray<T>(*this) *= -1;
        // };

        NDArray<T>& operator -= (const NDArray<T>& arr) {
            assert(shape == arr.shape);
            for (int i{}; i < len; i++){
                array[i] -= arr.array[i];
            }
            return *this;
        };

        NDArray<T> operator - (const NDArray<T>& arr) const{
            return NDArray<T>(*this) -= arr;
        };


        NDArray<T>& operator /= (const NDArray<T>& arr) {
            assert(shape == arr.shape);
            for (int i{}; i < len; i++)
                array[i] /= arr.array[i];
            return *this;
        };

        NDArray<T> operator / (const NDArray<T>& arr) const {
            return NDArray<T>(*this) /= arr;
        };

        NDArray<T>& operator = (const NDArray<T>& arr) {
            array.clear();
            len = arr.len;
            shape = arr.shape;
            if (arr.array.empty()) 
                return *this;
            for (int i{}; i < len; i++)
                array.push_back(arr.array[i]);
            return *this;
        };

        friend std::ostream& operator << (std::ostream& out, const NDArray& arr) {
            for (auto v: arr.array){
                out << v << ' ';
            }
            out << std::endl;
            return out;
        };

        T& operator() (int i) {
            assert((i < len));
            return array[i];
        };


        T& operator() (int i, int j) {
            assert(i < shape[0]);
            assert(j < shape[1]);
            return array[i * shape[1] + j];
        };

        NDArray<T>& transpose(){
            NDArray<T> res({shape[1], shape[0]});
            for (int i{}; i < shape[0]; i++) {
                for (int j{}; j < shape[1]; j++) {
                    res(j, i) = (*this)(i, j);
                }
            }
            *this = res;
            return *this;
        };

        NDArray<T> matrix_multi(const NDArray<T> arr){
            assert(shape[1] == arr.shape[0]);
            assert(shape[0] == arr.shape[1]);

            NDArray<T> res({shape[0], arr.shape[1]});
            NDArray<T> clon;
            clon = arr;
            clon.transpose();

            for (int k{}; k < shape[0]; k++) {
                for (int i{}; i < clon.shape[0]; i++) {
                    T n = 0;
                    for (int j{}; j < shape[1]; j++) {
                        n += (*this)(k, j) * clon(i, j);
                    }
                    res(k, i) = n;
                }
            }
            return res;
        };

        T min(){
            if (array.empty()){
                return 0;
            }
            else{
                T min = array[0];
                for (auto i : array)
                    if (i < min)
                        min = i;
                return min;
            }
        };

        T max() {
            if (array.empty()){
                return 0;
            }
            else{
                T max = array[0];
                for (auto i : array)
                    if (i > max)
                        max = i;
                return max;
            }
        };

        T mean(){
            if (array.empty()){
                return 0;
            }
            else{
                T mean = std::accumulate(array.begin(), array.end(), 0.0) / array.size();
                return mean;
            }
        };

};              
