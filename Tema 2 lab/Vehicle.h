#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include <cstring>
#include <string>
#include <iostream>
#include "VehicleType.h"
using namespace std;


///EXCEPTION PRICE FOR THE NEW CAR

class InvalidPriceException : public exception {
public:
    const char* what() const throw() {
        return "Invalid price for the vehicle.";
    }
};

class Vehicle {
private:
    int fabrication_year;
    string model;
    double price;
    string colour;

public:
    virtual void afisareDotari() const=0;  ///Functie virtuala

    ///constr de init
    Vehicle(int fabrication_year, const string &model, double price, const string &colour);
    Vehicle(const Vehicle &ob);  ///copy constructor

    ///constr fara param
    Vehicle()=default;

    ///SETTERI
    void setFabricationYear(int fabrication_year);
    void setModel(string &model);
    void setPrice(const double price);
    void setColour(string &colour);

    ///getteri

    int getFabrication_year() const;
    const string &getModel() const;
    double getPrice() const;
    const string &getColour() const;

    ///operatorul =
    Vehicle& operator=(const Vehicle& v);

    ///destructor
    ~Vehicle() = default;

    ///functii virtuale pure
    virtual VehicleType GetVehicleType() const =0;

    virtual bool operator==(const Vehicle& other) const = 0;


    ///OPERATORUL <<
    friend ostream& operator<<(ostream &os, const Vehicle& v);

    /// verifică starea vehiculului-fct virtuala pura
    virtual bool verificaStarea() const = 0;
};


#endif //_VEHICLE_H_