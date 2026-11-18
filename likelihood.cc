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

double prob(const std::vector<int>& data, double mu)
{
    double likelihood = 1.0;

    for(int k : data)
    {
            likelihood *= poisson(mu, k);
    }
    
    return likelihood;
}

double nll(const std::vector<int>& data, double mu)
{
    double likelihood = 0.0;

    for(int k : data)
    {
            likelihood += log(poisson(mu, k));
    }
    
    return -2*likelihood;
}

double lambda(const std::vector<int>& data, double mu)
{
    double saturated = 0.0;
    for(int k: data)
    {
        if(k != 0)
        {
            saturated += log(poisson(k, k));
        }
        
    }
    return nll(data, mu) + 2*saturated;
}


int main(){
    
    int number;
    double mean = 3.11538;
    std::vector<int> data;

    std::ifstream fin("sums.txt");
    while(fin >> number)
    {
        data.push_back(number);
    }
    fin.close();

    std::cout << prob(data, mean) << std::endl;


    std::ofstream fout("likelihood.txt");
    for(double mu = 0.0; mu <= 6; mu += 0.01)
    {
        fout << mu << " " << prob(data, mu) << std::endl;
    }
    fout.close();

    std::ofstream fout2("nll.txt");
    for(double mu = 0.01; mu <= 6; mu += 0.01)
    {
        fout2 << mu << " " << nll(data, mu) << std::endl;
    }
    fout2.close();

    std::ofstream fout3("deltanll.txt");
    for(double mu = 0.0; mu <= 6; mu += 0.001)
    {
        fout3 << mu << " " << nll(data, mu) - nll(data, mean) << std::endl;
    }
    fout3.close();

    std::ofstream fout4("lambda.txt");
    for(double mu = 0.0; mu <= 6; mu += 0.01)
    {
        fout4 << mu << " " << lambda(data, mu) << std::endl;
    }
    fout4.close();

    std::cout << lambda(data, mean) << std::endl;

    std::cout << (lambda(data, mean) - 233)/ sqrt(2*233) << std::endl;

}
