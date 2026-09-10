#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    const int N = 101; // 100 subintervals (N points)
    const double x_min = 0.0;
    const double x_max = 1.0;
    const double h = (x_max - x_min) / (N - 1);

    std::vector<double> x(N);
    std::vector<double> u(N);

    // Compute x and u(x) values
    for (int i = 0; i < N; ++i) {
        x[i] = x_min + i * h;
        // Exact solution: u(x) = 1 - (1 - e^-10)*x - e^(-10*x)
        u[i] = 1.0 - (1.0 - std::exp(-10.0)) * x[i] - std::exp(-10.0 * x[i]);
    }

    // Open output file
    std::ofstream outfile("data.txt");
    if (!outfile.is_open()) {
        std::cerr << "Error opening file data.txt for writing.\n";
        return 1;
    }

    // Configure formatting: scientific notation with 6 decimal places
    outfile << std::scientific << std::setprecision(6);

    // Write x and u(x) to file in two columns
    for (int i = 0; i < N; ++i) {
        outfile << std::setw(16) << x[i] 
                << std::setw(16) << u[i] << "\n";
    }

    outfile.close();
    std::cout << "Successfully wrote " << N << " points to data.txt\n";

    return 0;
}