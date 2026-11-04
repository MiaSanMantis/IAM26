#include<vector>
#include<iostream>
#include<fstream>
#include<cmath>


double poisson(double mu, int k)
{
    double numerator = std::pow(mu, k) * std::exp(-mu);
    double demoninator = std::tgamma(k + 1);
    return numerator / demoninator;

}


int main(){

    double number;
    int n = 0;
    double sum = 0.0;
    std::vector<int> counts(11);

    std::ifstream fin("sums.txt");
    while(fin >> number)
    {
        sum += number;
        ++n;
        counts.at(number) += 1;
    }
    fin.close();

    double mean = sum / n;

    std::cout << n << std::endl;
    std::cout << mean << std::endl;
    
    for(unsigned int k = 0; k < counts.size(); ++k){
        std::cout << k << ":" << counts[k] << std::endl; 
    }

    std::ofstream fout("hist.txt");

    for(unsigned int k = 0; k < counts.size(); ++k)
    {
        fout << k << " " << counts[k] << std::endl;
    }
    fout.close();


    std::ofstream fout2("histpoi.txt");

    for(unsigned int k = 0; k < counts.size(); ++k)
    {
        double prediction = n * poisson(mean, k);
        fout2 << k << " " << counts[k] << " " << prediction << std::endl;
    }
    fout2.close();

}
