// Copyright (c) 2022 Chris Di Bert All rights reserved.
// .
// Created by: Chris Di Bert
// Date: Nov.18, 2022
// This program calculates the natural log of 2 using
// the alternating harmonic series up to the user's term

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

/* Calculates the percentage accuracy of the user's input
relative to the true value of the natural log of 2*/
double accuracyPerc(double sum) {
    const double NATLOG2 = 0.69314718056;
    double result = 100 - abs((NATLOG2 - sum) / NATLOG2 * 100);
    return result;
}

int main() {
    char restart = ' ';

    do {
        // Declaring & initializing variables
        int counter, termsInt, sign = -1, precisionInt;
        double sum = 0, fraction = 0;
        std::string termsStr, wait, sumStr, precisionStr;

        // Gets the decimal precision for the sum
        std::cout << "Enter the number of decimal places you want displayed: ";
        std::cin >> precisionStr;

        // Checks if there is a decimal in precisionStr
        if (precisionStr.find('.') != std::string::npos) {
            std::cout << "You must enter a whole number.\n";
            std::cout << "Enter any key to restart.\n";
            continue;
        }

        // Tries casting precisionStr to an integer
        try {
            precisionInt = std::stoi(precisionStr);
        } catch (...) {
            std::cout << "You must enter a number.\n";
            std::cout << "Enter any key to restart: ";
            std::cin >> wait;
            continue;
        }

        if (precisionInt < 0) {
            std::cout << "You must enter a positive number.\n";
            std::cout << "Enter any key to restart: ";
            std::cin >> wait;
            continue;
        }

        /* Asks the user for the number of terms
        they would like to be computed */
        std::cout << "Enter the number of terms to be calculated: ";
        std::cin >> termsStr;

        // Checks if there is a decimal in the user's number
        if (termsStr.find('.') != std::string::npos) {
            std::cout << "You must enter a whole number.\n";
            std::cout << "Enter any key to restart.\n";
            continue;
        }

        // Tries casting termStr to a whole number
        try {
            termsInt = std::stoi(termsStr);
        }

        /*Exception thrown if the user did not enter a
        number*/
        catch (...) {
            std::cout << "You must enter a number.\n";
            std::cout << "Enter any key to restart: ";
            std::cin >> wait;
            continue;
        }

        /* Gets the user to restart if a negative number was
        entered*/
        if (termsInt <= 0) {
            std::cout << "You must enter a positive value.\n";
            std::cout << "Enter any key to restart: ";
            std::cin >> wait;
            continue;
        }

        // Prints the beginning of the equation
        std::cout << "ln(2) = ";

        /* Body code executed until counter is equal to
        the user's term number*/
        for (counter = 1; counter <= termsInt; counter++) {
            // Used to determine if the term will be positive or negative
            sign *= -1;

            // Calculates the sum

            fraction = 1.0 / counter;
            sum += sign * fraction;

            /* Displays alternating harmonic series. If statements are used
            to determine the sign that needs to be displayed*/
            if (counter == 1) {
                std::cout << counter << " ";
            } else if (counter % 2 == 0) {
                std::cout << "- 1/" << counter << " ";
            } else {
                std::cout << "+ 1/" << counter << " ";
            }
        }

        // Outputs the sum to the user
        std::cout << "\nln(2) = " << std::setprecision(precisionInt)
        << sum << "\n";

        // Outputs accuracy of the sum
        std::cout << ">> Value is ~" << accuracyPerc(sum)
         << "% accurate to the true value of ln2.\n";

        // Outputs true value of ln(2)
        std::cout << "(True value of ln(2) = 0.69314718056)\n";

        // Asks the user if they want to restart
        std::cout
            << "Enter 'q' to quit, enter anything else to restart: ";
        std::cin >> restart;
    } while (restart != 'q');
}
