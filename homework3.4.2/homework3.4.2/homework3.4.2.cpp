#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;
public:
    Address(std::string city, std::string street, int houseNumber, int apartmentNumber) : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    std::string getOutputAddress() {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }

    std::string getCity() {
        return city;
    }
};

void sortAddresses(Address** addresses, int size) {
    std::sort(addresses, addresses + size, [](Address* a, Address* b) {
        return a->getCity() < b->getCity();
        });
}

int main() {
    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

    int n;
    inputFile >> n;

    Address** addresses = new Address * [n];

    for (int i = 0; i < n; i++) {
        std::string city, street;
        int houseNumber, apartmentNumber;

        inputFile.ignore();
        std::getline(inputFile, city);
        std::getline(inputFile, street);
        inputFile >> houseNumber >> apartmentNumber;

        addresses[i] = new Address(city, street, houseNumber, apartmentNumber);
    }

    sortAddresses(addresses, n);

    outputFile << n << std::endl;

    for (int i = 0; i < n; i++) {
        outputFile << addresses[i]->getOutputAddress() << std::endl;
    }

    for (int i = 0; i < n; i++) {
        delete addresses[i];
    }
    delete[] addresses;

    inputFile.close();
    outputFile.close();

    return 0;
}
