#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double f(int x){
    const double PI = 3.1415926535897;
    double rads = x*PI/180.0;
    return 100*sin(rads);
}

int main()
{
    ofstream fout;
    fout.open("funSinewave.txt");
    if(!fout){
        cout << "File not opened. Try again";
        return -1;
    }
    for(double y(0.0), degrees(0.0) ; degrees<=360 ; degrees+=1.0){
        y = f(degrees);
        cout << degrees << '\t' << y << endl;
        fout << degrees << '\t' << y << endl;
    }

    fout.close();
    cout << "programm vollendet \n";


    return 0;
}
