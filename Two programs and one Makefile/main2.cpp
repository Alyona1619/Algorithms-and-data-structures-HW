#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string line;
 
    //ifstream fin(argv[1]);
    ifstream fin("myfile.txt");

    double x, y, z;
    if (fin.is_open())
    {
        cout << "Angles: " << endl;
        while ((fin >> x) && (fin >> y) && (fin >> z))
        {
            double angle;
            angle = 2 * sin(x) * sin(y) + cos(z);
            cout << angle << endl;
        }
    }
    fin.close(); 
    
    return 0;
}