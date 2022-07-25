#include <pybind11/pybind11.h>
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

int add(int i, int j)
{
    return i + j;
}

int n_length(int n)
{
    auto str = std::to_string(n);
    return str.length();
}

double binom(int n, int k) { return 1 / ((n + 1) * std::beta(n - k + 1, k + 1)); }

void pascal(int m)
{
    if(m > 16){
        std::cout<<"aus optischen Gruenden, bitte eine Zahl < 16 waehlen."<<std::endl;
        return;
    }
    double t_length = 0;
    double t = 0;
    std::cout << "Pascal's triangle:\n";
    for (int n = 0; n < m; ++n)
    {
        t = n_length((int) binom(m, n));
        //std::cout << "binom("<<m<<","<<n<<") = "<<binom(m, n)<<std::endl;
        std::cout << std::string(100  - 5 * n, ' ');
        for (int k = 0; k < n; ++k)
        {
            
            std::cout << std::setw(9) << binom(n, k) << ' ';
        }
        std::cout << '\n';
    }
}

PYBIND11_MODULE(example, m)
{
    m.doc() = "example", "pybind11 example plugin";

    m.def("add", &add, "A function which adds two numbers");
    m.def("pascal", &pascal, "Print the Pascal triangle using the Beta function to compute the binomial coefficient");
}