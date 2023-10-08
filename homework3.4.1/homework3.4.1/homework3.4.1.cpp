#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;
public:
    Address(std::string city, std::string street, int houseNumber, int apartmentNumber) {
        this->city = city;
        this->street = street;
        this->houseNumber = houseNumber;
        this->apartmentNumber = apartmentNumber;
    }

    std::string getOutputAddress() {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }
};

int main() {
    int n;
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");

    if (fin.is_open()) {
       fin >> n;
        Address** addresses = new Address * [n];

        for (int i = 0; i < n; i++) {
            std::string city, street;
            int houseNumber, apartmentNumber;
            fin.ignore(256, '\n');
            std::getline(fin, city);
            std::getline(fin, street);
            fin >> houseNumber;
            fin >> apartmentNumber;

            addresses[i] = new Address(city, street, houseNumber, apartmentNumber);
        }

        fin.close();

       fout << n << std::endl;

        for (int i = n - 1; i >= 0; i--) {
            std::string outputAddress = addresses[i]->getOutputAddress();
            fout << outputAddress << std::endl;

            delete addresses[i];
        }

        delete[] addresses;

        fout.close();
    }
    else {
        std::cout << "Не удалось открыть файл" << std::endl;
    }

    return 0;
}