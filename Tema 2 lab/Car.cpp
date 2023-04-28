#include "Car.h"


///CONSTRUCTOR PARAMETRIZAT- APELAREA CONSTR DIN CLASA DE BAZA
Car::Car(int fabrication_year, const string &model, double price, const string &colour, double fuel_consumption,
         const string &fuel_type, int kilometres, bool navigation, bool broken): Vehicle(fabrication_year,model,price,colour)
         ,fuel_consumption(fuel_consumption),fuel_type(fuel_type),kilometres(kilometres),navigation(navigation),broken(broken){/*cout << "Car constructor called" << endl;*/}



///SETTERI
void Car::setFuelType(const string &fuel_type)
{
    Car::fuel_type=fuel_type;
}
void Car::setFuelConsumption(double fuel_consumption)
{
    Car::fuel_consumption=fuel_consumption;
}
void Car::setKm(int kilometres)
{
    Car::kilometres=kilometres;
}
void Car::setNavigation(bool navigation)
{
    Car::navigation=navigation;
}
void Car::setConditin(bool broken)
{
    Car::broken=broken;
}

///GETTERI

double Car::getFuelConsumption() const
{
    return fuel_consumption;
}
const string &Car::getFuelType() const
{
    return fuel_type;
}
int Car::getKilometres() const
{
    return kilometres;
}
bool Car::getNav() const
{
    return navigation;
}
bool Car::getCondition() const
{
    return broken;
}
/// OPERATORUL =
Car& Car::operator=(const Car& c)
{
    if(this!=&c)
    {
        this->Vehicle::operator=(c);
        fuel_consumption = c.fuel_consumption;
        fuel_type = c.fuel_type;
        kilometres = c.kilometres;
        navigation = c.navigation;
        broken=c.broken;
    }
    return *this;
}
///AFISARE DOTARI
void Car::afisareDotari() const
{
    cout<<"DOTARI MASINA\n"<<"An fabricatie: "<<getFabrication_year()<<"\n"
    <<"Culoare: "<<getColour()<<"\n"
    <<"Model: "<<getModel()<<"\n"
    <<"Pret: "<<getPrice()<<"\n"
    <<"Consum: "<<getFuelConsumption()<<"\n"
    <<"Tip combustibil: "<<getFuelType()<<"\n"
    <<"Km parcursi: "<<getKilometres()<<"\n"
    <<"Navigatie: ";
    if(getNav())cout << "Da" << "\n";
    else cout<<"Nu"<<"\n";
    cout<<"Conditie: ";
    if(getCondition())cout << "Stricata" << "\n\n";
    else cout<<"Buna"<<"\n\n";
}

///GET VEHICLE TYPE
VehicleType Car::GetVehicleType() const {
    return VehicleType::Car;
}

///OPERATORUL<<
ostream& operator<<(ostream &os, const Car& c)
{
    os << static_cast<const Vehicle&>(c);
    os<<"Consum: "<<c.fuel_consumption<<"\n"
      <<"Tip combustibil: "<<c.fuel_type<<"\n"
      <<"Km parcursi: "<<c.kilometres<<"\n"
      <<"Navigatie: ";
    if (c.navigation) {
        os << "Da" << "\n";
    } else { os << "Nu" << "\n" ;}
    os<< "Conditie: ";
    if(c.broken)os << "Stricata" << "\n\n";
    else os<<"Buna"<<"\n\n";
    return os;
}

bool Car::verificaStarea() const
{
    return broken;
}

///operatorul ==
bool Car::operator==(const Vehicle& other) const
{
    if (auto car = dynamic_cast<const Car*>(&other)) {
        return this == &other || (this->broken == car->broken && this->navigation == car->navigation && this->kilometres == car->kilometres
                                  && this->fuel_type == car->fuel_type && this->fuel_consumption == car->fuel_consumption && this->getPrice() == car->getPrice()
                                  && this->getFabrication_year() == car->getFabrication_year() && this->getColour() == car->getColour() && this->getModel() == car->getModel());
    }
    return false;
}