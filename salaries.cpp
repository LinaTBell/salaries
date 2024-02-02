#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    // Open the input file
    ifstream inputFile("SalaryData.txt");

    // Check if the file is opened successfully
    if (!inputFile) {
        cerr << "Error opening input file 'SalaryData.txt'" << endl;
        return 1;
    }

    // Open the output file
    ofstream outputFile("SalaryOut.txt");

    // Check if the file is opened successfully
    if (!outputFile) {
        cerr << "Error opening output file 'SalaryOut.txt'" << endl;
        return 1;
    }

    // Process each line in the input file
    string firstName, lastName;
    double currentSalary, payIncrease, updatedSalary;

    while (inputFile >> lastName >> firstName >> currentSalary >> payIncrease) {
        // Calculate the updated salary
        updatedSalary = currentSalary + (currentSalary * payIncrease / 100.0);

        // Write the output to the output file
        outputFile << fixed << setprecision(2);
        outputFile << firstName << " " << lastName << " " << updatedSalary << endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "Data has been processed and written to 'SalaryOut.txt'" << endl;

    return 0;
}