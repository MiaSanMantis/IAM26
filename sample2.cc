#include<iostream>
#include<fstream>
#include<cmath>

int main(){

    std::ifstream fin1("sums.txt");
    std::ifstream fin2("sums.txt");
    std::ofstream fout_mean("means.txt");
    std::ofstream fout_var("variances.txt");
    std::ofstream fout_var_bess("bessel_variances.txt");

    const int n = 9;
    const int blocks = 26;

    for(int j = 0; j < blocks; ++j)
    {
        double a;
        double sum = 0.0;

        for(int i = 0; i < n; i++)
        {
            fin1 >> a;
            sum += a;
        }

        double mean = sum / n;
        fout_mean << mean << std::endl;


        double sum_var = 0.0; 

        for(int i = 0; i < n; i++)
        {
            fin2 >> a;
            sum_var += std::pow(a - mean, 2);
        }

        double var = sum_var / n;
        double var_bess = sum_var / (n - 1);
        fout_var << var << std::endl;
        fout_var_bess << var_bess << std::endl;

    }
    fin1.close();
    fin2.close();
    fout_mean.close();
    fout_var.close();
    fout_var_bess.close();


    double a;
    int m1 = 0;
    int m2 = 0;
    int m3 = 0;
    double sum_mean = 0.0;
    double sum_var = 0.0;
    double sum_var_bess = 0.0;

    std::ifstream fin3("means.txt");
    std::ifstream fin4("variances.txt");
    std::ifstream fin5("bessel_variances.txt");

    while(fin3 >> a)
    {
        sum_mean += a;
        ++m1;
    }
    while(fin4 >> a)
    {
        sum_var += a;
        ++m2;
    }
    while(fin5 >> a)
    {
        sum_var_bess +=a;
        ++m3;
    }

    fin3.close();
    fin4.close();
    fin5.close();

    double mean_mean = sum_mean / m1;
    std::cout << mean_mean << std::endl;

    double mean_var = sum_var / m2;
    std::cout << mean_var << std::endl;

    double mean_var_bess = sum_var_bess / m3;
    std::cout << mean_var_bess << std::endl;



    std::ifstream fin6("means.txt"); 
    double sum_sq_diff_means = 0.0;

    while(fin6 >> a)
    {
        sum_sq_diff_means += std::pow(a - mean_mean, 2);
    }
    fin6.close();

    double std_dev_of_means = sqrt(sum_sq_diff_means / m1);

    std::cout << std_dev_of_means << std::endl;
}
