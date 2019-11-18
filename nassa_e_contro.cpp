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
    //nassa = 0/3-12/15-19-26-32/35
    //contro nassa = 2-4/7-18/21-22/25-28/29 

    std::array<short, 17> cavalli{{0,3,12,15,32,35,4,7,18,21,22,25,28,29}};
    std::array<short, 3> pieno{{2,19,26}};
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

    int maxperdita;
    int balance=0;
    int win=0;
    int loss=0;
    for (short &estratto : serie)
    {
        
        bool bIsCavallo = std::find(std::begin(cavalli), std::end(cavalli), estratto) != std::end(cavalli);
        bool bIsPieno = std::find(std::begin(pieno), std::end(pieno), estratto) != std::end(pieno);

        if (bIsPieno)
        {
            balance+=250;
            win++;
        }
        else if (bIsCavallo) 
        {
            balance+=70;
            win++;
        }
        else
        { 
            balance-=100;
            loss++;
        }
    }
    std::cout << sFilename;
    std::cout << " Win:" << std::setw(5)<<win<< " Loss:" <<std::setw(5)<< loss;
    std::cout <<std::setw(5)<< " Balance:" << balance << std::endl;
    return 0;
}
