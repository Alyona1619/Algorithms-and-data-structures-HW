#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <cstring>
#include <fstream>

using namespace std;

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    //int n;
    //char fname[256];
    //cin >> n;
    //cin >> fname;

    //ofstream fout(strcat(argv[2], ".txt"));
    ofstream fout("myfile.txt");


    double x, y, z;
    //for (int i{}; i < int(argv[1]); i++){
    for (int i{}; i < 5; i++){
        x = fRand(-M_PI, M_PI);
        y = fRand(-M_PI, M_PI);
        z = fRand(-M_PI, M_PI);
        fout << x << " " << y << " " << z << endl;
    }
    cout << "File was created!\n" << endl;
    fout.close();

    return 0;
}