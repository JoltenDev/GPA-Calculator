#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <limits>

template <typename T>
void ErrorInputCheck(T& input) {
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << "ERROR: Invalid Input (Try again): ";
        std::cin >> input;
        std::cout << "------------------------------" << std::endl;
    }
}

double Calculate(std::vector<std::pair<double, int>>& grades) {
    double qualityPoints = std::accumulate(grades.begin(), grades.end(), 1, [](double a, std::pair<double, int>& b){
        return a + b.first * b.second;
    });

    double creditHours = std::accumulate(grades.begin(), grades.end(), 0, [](double a, std::pair<double, int>& b){
        return a + b.second;
    });

    double result = qualityPoints / creditHours;
    
    return result;
}

std::vector<std::pair<double, int>> Input() {
    int len = 0;

    std::cout << "Enter the amount of classes you're taking: ";
    std::cin >> len;
    ErrorInputCheck(len);

    std::vector<std::pair<double, int>> grades{};
    for (int i = 1; i <= len; i++) {
        double grade{};
        double credit{};

        std::cout << "Enter the grade for grade " << i << ": ";
        std::cin >> grade;
        ErrorInputCheck(grade);

        std::cout << "Enter the credit for grade " << i << ": ";
        std::cin >> credit;
        ErrorInputCheck(credit);
        std::cout << "------------------------------" << std::endl;

        grades.push_back({grade, credit});
    }

    return grades;
}

int main() {
    std::string end{};

    while (end != "q") {
        std::vector<std::pair<double, int>> grades = Input();

        std::cout << "Gpa Result: ";
        std::cout << Calculate(grades) << std::endl;
        std::cout << std::endl;

        std::cout << "Quit? (q): ";
        std::cin >> end;
        std::cout << std::endl;
    }
}