#include "Truck.h"
#include <iostream>
///CONSTRUCTOR CU PARAMETRI
Truck::Truck(int fabrication_year, const string &model, double price, const string &colour,bool loaded, double weight,double height, int nr_trailers) :Vehicle(fabrication_year,model,price,colour),
loaded(loaded),weight(weight),height(height),nr_trailers(nr_trailers){}

///SETTERI

void Truck::setLoaded(bool loaded)
{
    Truck::loaded=loaded;
}
void Truck::setWeight(double weight)
{
    Truck::weight=weight;
}
void Truck::setHeight(double height)
{
    Truck::height=height;
}
void Truck::setNrTrailers(int nr_trailers)
{
    Truck::nr_trailers=nr_trailers;
}

///GETTERI
bool Truck::getLoaded() const
{
    return loaded;
}
double Truck::getWeight() const
{
    return weight;
}
double Truck::getHeight() const
{
    return height;
}
int Truck::getNrTrailers() const
{
    return nr_trailers;
}

///AFISARE DOTARI-FCT VIRTUALA PURA
void Truck::afisareDotari() const
{
    cout<<"DOTARI CAMION\n"
    <<"An fabricatie: "<<getFabrication_year()<<"\n"
        <<"Culoare: "<<getColour()<<"\n"
        <<"Model: "<<getModel()<<"\n"
        <<"Pret: "<<getPrice()<<"\n"
        <<"Greutate: "<<getWeight()<<"\n"
        <<"Inaltime: "<<getHeight()<<"\n"
        <<"Nr remorci: "<<getNrTrailers()<<"\n"
        <<"Inacrat: ";
    if(getLoaded())cout<<"DA\n\n";
    else cout<<"NU\n\n";
}

///GetVehicleType
VehicleType Truck::GetVehicleType() const
{
    return VehicleType::Truck;
}
///OP =
Truck& Truck::operator=(const Truck& t)
{
    if (this!=&t)
    {
        this->Vehicle::operator=(t);
        loaded=t.loaded;
        weight=t.weight;
        height=t.height;
        nr_trailers=t.nr_trailers;
    }
    return *this;
}



ostream &operator<<(ostream &os, const Truck &t) {
    os<<static_cast<const Vehicle&>(t);
    os<<"Greutate: "<<t.weight<<"\n"
      <<"Inaltime: "<<t.height<<"\n"
      <<"Nr remorci: "<<t.nr_trailers<<"\n"
      <<"Inacrat: ";
    if(t.loaded)cout<<"DA\n\n";
    else cout<<"NU\n\n";
    return os;
}

///verify if the truck is empty
bool Truck::verificaStarea() const
{
    return loaded;
}

///OPERATOR ==
bool Truck::operator==(const Vehicle& other) const
{
    return 1;
}