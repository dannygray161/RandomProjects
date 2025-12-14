#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // Required to format the output using I/O manipulators

using namespace std;

int main() {
    // 1. Declare and open the file streams.
    // 'ifstream' is for reading (Input File Stream)
    // 'ofstream' is for writing (Output File Stream)

    ifstream inputFile("FahrenheitTemperature.txt");
    ofstream outputFile("CelsiusTemperature.txt");

    // Check for critical errors: if either file failed to open. Cant write if not open.
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open FahrenheitTemperature.txt for reading. Check the file path and existence." << endl;
        return 1; // Return a non-zero value to signal an error
    }

    if (!outputFile.is_open()) {
        cerr << "Error: Could not open CelsiusTemperature.txt for writing." << endl;
        // Since we couldn't write, close the input file before exiting.
        inputFile.close();
        return 1;
    }

    // 2. Process data line by line.
    string cityName;
	int fahrenheitTemp; // Use 'int' as we'd rather read whole numbers for temperature calculation.

    // Loop through the input file as long as data can be successfully read.
    // The '>>' operator automatically reads the first word into cityName and the next integer into fahrenheitTemp.
    // This loop handles exactly six cities if the file is correctly formatted. Formatting is important, not coding this 'bug' out
    while (inputFile >> cityName >> fahrenheitTemp) {

        // Conversion Formula: C = (F - 32) * 5/9

        // KEY: Use a 'double' for the conversion to ensure floating-point math.
        // Also, explicitly use '5.0 / 9.0' or '5 / 9.0' to force floating-point division, 
        // as '5 / 9' in C++ integer math would result in 0.

        double celsiusTemp = (fahrenheitTemp - 32) * (5.0 / 9.0);

        // 3. Write the results to the output file.
        // We use 'fixed' and 'setprecision(2)' to format the Celsius temperature neatly
        outputFile << cityName << " "
            << fixed << setprecision(2) << celsiusTemp << endl;
    }

    // 4. Close both files once the work is complete.
    // This releases the resources and flushes the buffer, ensuring the output file is saved.
    inputFile.close();
    outputFile.close();

    cout << "Temperature conversion for all cities is complete." << endl;
    cout << "Results saved to CelsiusTemperature.txt" << endl;

    return 0; // Return 0 to signal successful execution
}