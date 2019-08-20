#include <ctime> 
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort std::generate
#include <random>


int main() {
    std::mt19937 mt_rand(time(0));
    std::vector<int> gigi(6);

    std::cout << "Numeri Superenalotto" << std::endl;

    for (auto i : {0,0,0,0})
    {
        std::generate (gigi.begin(), gigi.end(), [&mt_rand] { return (mt_rand() % 90) + 1; });
        std::sort (gigi.begin(), gigi.end());
        for (auto& j : gigi)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}
