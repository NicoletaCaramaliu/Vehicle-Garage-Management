#include "Vehicle.h"
using namespace std;

///Constr de init
Vehicle::Vehicle(int fabrication_year, const string &model, double price, const string &colour):
        fabrication_year(fabrication_year), model(model), colour(colour){
        if(price<=0)throw InvalidPriceException();
        this->price=price;
    /*cout << "Vehicle constructor called" << endl;*/};


///copy constructor
Vehicle::Vehicle(const Vehicle &ob)
{
    fabrication_year=ob.fabrication_year;
    model=ob.model;
    price=ob.price;
    colour=ob.colour;
}

///SETTERI
void Vehicle::setFabricationYear(int fabrication_year)
{
    Vehicle::fabrication_year=fabrication_year;
}

void Vehicle::setModel(string &model)
{
    Vehicle::model=model;
}

void Vehicle::setPrice(const double price)
{
    Vehicle::price=price;
}
void Vehicle::setColour(string &colour)
{
    Vehicle::colour=colour;
}

///GETTERI
int Vehicle::getFabrication_year() const
{
    return fabrication_year;
}
const string &Vehicle::getModel() const
{
    return model;
}
double Vehicle::getPrice() const
{
    return price;
}

const string &Vehicle::getColour() const
{
    return colour;
}

///OPERATORUL=

Vehicle &Vehicle::operator=(const Vehicle &v)
        {
            if(this!=&v)
            {
                fabrication_year=v.fabrication_year;
                model=v.model;
                price=v.price;
                colour=v.colour;
            }
            return *this;
        }

///OPERATORUL <<
ostream& operator<<(ostream &os, const Vehicle& v)
{
    os<<"An fabricatie: "<<v.fabrication_year<<"\n"
      <<"Culoare: "<<v.colour<<"\n"
      <<"Model: "<<v.model<<"\n"
      <<"Pret: "<<v.price<<"\n";
    return os;
}