#include <sstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <list>
using namespace std;

int main(int argc, char *argv[])
{
    // your code goes here
    std::array<short, 17> red{{1, 3, 5, 7, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36}};
    std::list<short> serie;
    ifstream inFile;
    if (argc!=2)
    {
        std::cerr<<"example: roulette serie.txt"<<std::endl;
        return -1;
    }

    std::string sFilename(argv[1]);
    inFile.open(sFilename);
    if (!inFile)
    {
        std::cerr << "Unable to open file datafile.txt";
        exit(1); // call system to stop
    }
    int x;
    while (inFile >> x)
    {
        //std::cout<<x<<std::endl;
        serie.push_back(x);
    }
    inFile.close();

    bool strategia1 = true;
    int counterStrategia2 = 0;
    int balance = 0;
    int maxbetmartingala = 0;
    bool bOldIsRed = false;
    int loss = 0;
    int win = 0;
    int pareggio = 0;
    for (short &estratto : serie)
    {
        bool bIsRed = std::find(std::begin(red), std::end(red), estratto) != std::end(red);
        if (strategia1) //sestina
        {
            if ((estratto > 0) && (estratto <= 30))
            {
                ++balance;
                //std::cout << estratto << " A " << std::setw(4) << balance << std::endl;
                ++win;
            }
            else
            {
                balance -= 5;
                ++loss;
                strategia1 = false;
                counterStrategia2 = 0;
                //std::cout << estratto << " B " << std::setw(4) << balance << std::endl;
            }
        }
        else //red black martingala
        {
            if ((estratto == 0) || (bOldIsRed == bIsRed))
            {
                balance += (-5) * std::pow(2, counterStrategia2);
                ++loss;
                //std::cout << estratto << " C " << std::setw(4) << balance << std::endl;
                ++counterStrategia2;
                if (maxbetmartingala < counterStrategia2)
                    maxbetmartingala = counterStrategia2;
            }
            else
            {
                balance += (5) * std::pow(2, counterStrategia2);
                pareggio++;
                //std::cout << estratto << " D " << std::setw(4) << balance << std::endl;
                strategia1 = true;
                counterStrategia2 = 0;
            }
        }
        if (estratto != 0) // se è zero prendo il colore precedente
            bOldIsRed = bIsRed;
    }
    std::cout << sFilename;
    std::cout << " Win:" << std::setw(5)<<win<< " Loss:" <<std::setw(5)<< loss;
    std::cout << " pareggio:" << std::setw(5)<<pareggio;
    std::cout << " Max_bet_martingala: ("<<std::setw(2)<<maxbetmartingala+1<<")=";
    std::cout <<std::setw(5)<< 5 * std::pow(2, maxbetmartingala);
    std::cout <<std::setw(5)<< " Balance:" << balance << std::endl;
    return 0;
}
