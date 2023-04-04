#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//Abstractnyi class dlya devaisov
class Device {
protected:
    string creator;
    string model;
    int quantity;
    double price;
    string color;

public:
    Device(string creator, string model, int quantity, double price, string color) {
        this -> creator = creator;
        this -> model = model;
        this -> quantity = quantity;
        this -> price = price;
        this -> color = color;
    }

    virtual void Print() = 0; 

    string getCreator() const { return creator; }
    string getModel() const { return model; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    string getColor() const { return color; }
};

//Class dlya telephona (docherniy dlya devaysov)
class Phone : public Device {
private:
    int year;

public:
    Phone(string creator, string model, int quantity, double price, string color, int year)
        : Device(creator, model, quantity, price, color) {
        this->year = year;
    }

    void Print() {
        cout << "Mobile Phone: " << getCreator() << ", " << getModel() << ", " << getQuantity() << ", " << getPrice() << ", " << getColor() << ", " << year << endl;
    }

    int getYear() const { return year; }
};

//Class dlya noutbuka (docherniy dlya devaysov)
class Laptop : public Device {
private:
    string type;

public:
    Laptop(string creator, string model, int quantity, double price, string color, string type)
        : Device(creator, model, quantity, price, color) {
        this->type = type;
    }

    void Print() {
        cout << "Laptop: " << getCreator() << ", " << getModel() << ", " << getQuantity() << ", " << getPrice() << ", " << getColor() << ", " << type << endl;
    }

    string getType() const { return type; }
};

//Class dlya plansheta (docherniy dlya devaysov)
class Tablet : public Device {
private:
    int size;

public:
    Tablet(string creator, string model, int quantity, double price, string color, int size)
        : Device(creator, model, quantity, price, color) {
        this->size = size;
    }

    void Print() {
        cout << "Tablet: " << getCreator() << ", " << getModel() << ", " << getQuantity() << ", " << getPrice() << ", " << getColor() << ", " << size << endl;
    }

    int getSize() const { return size; }
};

//Sam spisok devaisov
class DeviceList {
private:
    vector<Device*> devices;

public:
    void AddDev(Device* device) {
        devices.push_back(device);
    }

    void DeleteDevCreator(string creator) {
        devices.erase(remove_if(devices.begin(), devices.end(), [&](Device* device) {
            return device->getCreator() == creator;
            }), devices.end());
    }

    void PrintDev() {
        for (auto device : devices) {
            device->Print();
        }
    }
};

//Vse vysovy tut
void main() {
    Laptop Asus ("Asus", "TUF", 1, 21000, "black", "Gaming");

    DeviceList citrus;
    citrus.PrintDev();
};

