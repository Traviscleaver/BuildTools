#include <iostream>
#include <string.h>
#include <unordered_map>

enum Grades{AP=433,A=400,AM=367,BP=333,B=300,BM=267,CP=233,C=200,CM=167,F=0,Q=-1};

Grades stringToEnum(const std::string& gradeValue) {
    static const std::unordered_map<std::string, Grades> gradeMap = {
        {"A+", Grades::AP},
        {"A", Grades::A},
        {"A-", Grades::AM},
        {"B+", Grades::BP},
        {"B", Grades::B},
        {"B-", Grades::BM},
        {"C+", Grades::CP},
        {"C", Grades::C},
        {"C-", Grades::CM},
        {"F", Grades::F},
    };
    auto it = gradeMap.find(gradeValue);
    if (it != gradeMap.end()) {
        return it->second;
    } else {
        return Grades::Q;
     }
}
void CalculateGrade() {
    float totalGrades = 0;
    float totalCredits = 0;
    float tempCredits = 0;
    std::string tempGradeOriginal;
    Grades tempGrade;
    float tempGradeFinal;
    bool validInput;
    bool continueProgram = true;
    while (continueProgram) {

        std::cout << "Please enter a letter grade from A - F:  ";
        std::cin >> tempGradeOriginal;
        tempGrade = stringToEnum(tempGradeOriginal);

        if (tempGradeOriginal.size() == 2) {
            if (tempGradeOriginal[1] == '-') {tempGradeOriginal[1] = 'M';}
            if (tempGradeOriginal[1] == '+') {tempGradeOriginal[1] = 'P';}}

        if(tempGrade == -1) {
            validInput = false;
            std::cout << "Invalid Input..Please Try Again..";
        }

        if (validInput) {
            tempGradeFinal = tempGrade;
            tempGradeFinal = tempGradeFinal/100;
            std::cout << "How many credits is this course:  ";
            std::cin >> tempCredits;
            totalCredits += tempCredits;
            totalGrades += tempGradeFinal*tempCredits;
            std::cout << "\n" << totalCredits << '\n' << std::endl;
            std::cout << totalGrades << '\n' << std::endl;

            std::cout << "Would you like to add another course(Y or N):  ";
            char addAnother;
            std::cin >> addAnother;

            if (addAnother == 'Y') {
                continueProgram = true;
            }
            else {
                continueProgram = false;
                std::cout << "\nYour Current GPA Is: " << totalGrades/totalCredits << std::endl;
            }

        }
        else {
            exit(0);
        }
    }
}


void planGPA() {

    float currentGPA, currentCredits, totalGrade, wantedGPA, creditsRemaining, gradeNeeded;

    std::cout << "\nWhat is your current GPA: ";
    std::cin >> currentGPA;
    std::cout << "\nHow many credits have you taken: ";
    std::cin >> currentCredits;
    totalGrade = currentGPA * currentCredits;
    std::cout << "\nWhat GPA do you want to achieve: ";
    std::cin >> wantedGPA;
    std::cout << "\nHow many remaining credits do you have: ";
    std::cin >> creditsRemaining;

    gradeNeeded = wantedGPA + (wantedGPA*currentCredits - totalGrade)/creditsRemaining;
    std::cout << "\nYou need an average grade of: " << gradeNeeded << ". in order to reach a GPA of " << wantedGPA;

}

int main () {
    bool continueProgram = true;
    while (continueProgram) {
        std::cout  << "\n\n*****Welcome to the CGPA Calculator*****" << std::endl;

        int startOption;

        std::cout << "1. Calculate Grade Average.\n";
        std::cout << "2. Plan Your GPA.\n";
        std::cout << "3. Quit Program.\n";
        std::cout << "What would you like to do: ";
        std::cin >> startOption;


        switch(startOption) {
            case 1: CalculateGrade(); break;
            case 2: planGPA(); break;
            case 3: {
                std::cout << "\nQuitting Program..." << std::endl;
                std::exit(0);
            }
            default: {
                std::cout << "\nInvalid Input...Quitting Program";
                std::exit(0);
            }
        }
    }
    
}