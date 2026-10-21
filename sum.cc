#include<iostream>
#include<fstream>

int main(){
    
    int a;
    int b;

    std::ifstream fin("data.txt");
    std::ofstream fout("sums.txt");
    while(fin >> a >> b)
    {
        int c = a + b;
        //std::cout << a << " + " << b << " = " << c << std::endl;
        fout << c << std::endl;
    }
    fout.close();
    fin.close();
}