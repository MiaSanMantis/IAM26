#include<iostream>
#include<fstream>
#include<cmath>

int main(){

    double a;
    int n = 0;
    double sum = 0.0;
    //double sum2 = 0.0;

    std::ifstream fin("sums.txt");
    while(fin >> a)
    {
        sum += a;
        //sum2 += a*a;
        ++n;
    }
    fin.close();

    double mean = sum / n;
    std::cout << mean << std::endl;

    //double mean2 = sum2 / n;
    //std::cout << mean2 << std::endl;

    //double var2 = mean2 - mean*mean;
    //std::cout << var2 << std::endl;


    double sum_var = 0.0;

    fin.open("sums.txt");
    while(fin >> a)
    {
        sum_var += std::pow(a - mean, 2);
    }
    fin.close();

    double Var = sum_var / n;
    std::cout << Var << std::endl;

    double sigma = sqrt(Var);
    std::cout << sigma << std::endl;

}