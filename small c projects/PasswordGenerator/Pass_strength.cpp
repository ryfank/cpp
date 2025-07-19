//password strength 

//tell it a password and it will determine whether the users
// password is strong or not 
// will rate the strength from 0 - 5

//how to run: 
//g++ Pass_strength.cpp -o Pass_strength
//./Pass_strength



#include <iostream>
#include <string>
#include <cctype>

int checkPassStrength(const std::string& pw) {
    int score = 0;

    if (pw.length() >= 8) score++;
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    for (char c : pw) {
        if (std::islower(c)) hasLower = true;
        else if (std::isupper(c)) hasUpper = true;
        else if (std::isdigit(c)) hasDigit = true;
        else hasSpecial = true;
    }
    if (hasLower) score++;
    if (hasUpper) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    return score;
}

int main() {
    std::string password;
    std::cout << "Enter password to check strength: ";
    std::getline(std::cin, password);

    int score = checkPassStrength(password);
    std::cout << "Password strength score (0-5): " << score << std::endl;

    if (score < 3)
        std::cout << "Weak password. Try adding uppercase, digits, special chars and length >=8.\n";
    else
        std::cout << "Good password strength!\n";

    return 0;
}
