#include <iostream>
#include <cmath>
#include <map>
#include <chrono>

int main(){
	std::map <int, int> my_map;

    for (int i{}; i <= 7; i++)
    {
	my_map.clear();

	int amount = std::pow(10, i);

	auto begin = std::chrono::high_resolution_clock::now();

	for(int j{}; j < amount; j++)
	{
        my_map.insert({j, j});
    	}

	auto finish = std::chrono::high_resolution_clock::now();

		

	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - begin);
	double b = (2 * sizeof(int) * my_map.size() + sizeof(my_map)) / 1024.0;
	std::cout << elapsed_ms.count() << " " << (2 * sizeof(int) * my_map.size() + sizeof(my_map)) / 1024.0 << " "; //kb
    }
    std::cout << std::endl;
	return 0;
}


