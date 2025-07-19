//password generator

// this little game gives the user a generated password

// how to run:
//cd PasswordGenerator
//clang++ PassGen.cpp -o PassGen
//./PassGen


#include <iostream>
#include <cstdlib>
#include <ctime>

std::string GenPass(int length) {
    std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    std::string password = "";

    for (int i = 0; i < length; i++) {
        password += chars[rand() % chars.length()];
    }

    return password;
}

int main() {
    srand(time(0));
    int length;
    std::cout << "Enter password length: ";
    std::cin >> length;

    std::cout << "Generated password: " << GenPass(length) << "\n";

    return 0;
}
