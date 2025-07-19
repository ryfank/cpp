// xor_encrypt.cpp 

//takes input file and encrypts it giving the user a key

//how to run:
//cd CybsecProjects
// g++ xor_encrypt.cpp -o xor_encrypt
//./xor_encrypt plaintext.txt encrypted.bin mykey
//./xor_encrypt encrypted.bin decrypted.txt mykey


#include <iostream>
#include <fstream>
#include <vector>

void xorData(std::vector<char>& data, const std::string& key) {
    size_t keyLen = key.size();
    for (size_t i = 0; i < data.size(); i++) {
        data[i] ^= key[i % keyLen];
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: xor_cipher <inputfile> <outputfile> <key>\n";
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::string key = argv[3];

    std::ifstream fin(inputFile, std::ios::binary);
    if (!fin) {
        std::cerr << "Cannot open input file\n";
        return 1;
    }
    std::vector<char> data((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
    fin.close();

    xorData(data, key);

    std::ofstream fout(outputFile, std::ios::binary);
    if (!fout) {
        std::cerr << "Cannot open output file\n";
        return 1;
    }
    fout.write(data.data(), data.size());
    fout.close();

    std::cout << "Operation complete.\n";
    return 0;
}
