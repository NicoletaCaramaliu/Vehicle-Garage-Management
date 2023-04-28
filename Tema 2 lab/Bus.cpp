#include "Bus.h"

///CONSTRUCTOR PARAMETRIZAT- APELAREA CONSTR DIN CLASA DE BAZA
Bus::Bus(int fabrication_year,const string &model,double price,const string &colour,int capacity, int max_speed, double length, double width, double fuel_consumption,bool used) :
Vehicle(fabrication_year,model,price,colour),capacity(capacity),max_speed(max_speed),length(length),width(width),fuel_consumption(fuel_consumption),used(used)
{/*cout << "Bus constructor called" << endl;*/}


///SETTERI
void Bus::setCapacity(int capacity)
{
    Bus::capacity=capacity;
}
void Bus::setMaxSpeed(int max_speed)
{
    Bus::max_speed= max_speed;
}
void Bus::setLenght(double lenght)
{
    Bus::length=lenght;
}
void Bus::setWidth(double width)
{
    Bus::width=width;
}
void Bus::setFuelCons(double fuel_consumption)
{
    Bus::fuel_consumption=fuel_consumption;
}
void Bus::setSituation(bool used)
{
    Bus::used=used;
}

///GETTERI
int Bus::getCapacity() const
{
    return capacity;
}
int Bus::getMaxSpeed() const
{
    return max_speed;
}
double Bus::getLenght() const
{
    return length;
}
double Bus::getWidth() const
{
    return width;
}
double Bus::getFuelCons() const
{
    return fuel_consumption;
}
bool Bus::getSituation() const
{
    return used;
}


void Bus::afisareDotari() const
{
    cout<<"DOTARI AUTOBUZ\n"<<"An fabricatie: "<<getFabrication_year()<<"\n"
        <<"Culoare: "<<getColour()<<"\n"
        <<"Model: "<<getModel()<<"\n"
        <<"Pret: "<<getPrice()<<"\n"
        <<"Capacitate: "<<getCapacity()<<"\n"
        <<"Viteza maxima: "<<getMaxSpeed()<<"\n"
        <<"Lungime: "<<getLenght()<<"\n"
        <<"Latime: "<<getWidth()<<"\n"
        <<"Consum: "<<getFuelCons()<<"\n"
        <<"Autobuzul  ";
    if(used)cout<<"are locuri ocupate\n\n";
    else cout<<"este gol\n\n";
}

///GET VEHICLE TYPE
VehicleType Bus::GetVehicleType() const {
    return VehicleType::Bus;
}

///OPERATOR =
Bus& Bus::operator=(const Bus& b)
{
    if(this!=&b)
    {
        this->Vehicle::operator=(b);
        capacity=b.capacity;
        max_speed=b.max_speed;
        length=b.length;
        width=b.width;
        fuel_consumption=b.fuel_consumption;
        used=b.used;
    }
    return *this;
}

///OP <<
ostream& operator<<(ostream& os,const Bus& b)
{
    os<<static_cast<const Vehicle&>(b);
    os<<"Capacitate: "<<b.capacity<<"\n"
      <<"Viteza maxima: "<<b.max_speed<<"\n"
      <<"Lungime: "<<b.length<<"\n"
      <<"Latime: "<<b.width<<"\n"
      <<"Consum: "<<b.fuel_consumption<<"\n"
      <<"Autobuzul  ";
    if(b.used)cout<<"are locuri ocupate\n\n";
    else cout<<"este gol\n\n";

    return os;
}

///verificare nr bilete ramase
bool Bus::verificaStarea() const
{
    return used;
}

///OPERATOR ==
bool Bus::operator==(const Vehicle& other) const
{
    return 1;
}