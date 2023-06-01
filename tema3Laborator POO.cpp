#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

///clasa de generat id uri
class IDGenerator {
private:
    static int counter;

public:
    static int generateID() {
        return ++counter;
    }
};

int IDGenerator::counter = 0;


enum class VehicleType {
    Car,
    Bus
};


class InvalidPriceException : public exception {
public:
    const char* what() const throw() {
        return "Pret invalid pentru vehicul.";
    }
};

class InvalidFuelTypeException : public exception {
public:
    const char* what() const throw() {
        return "Combustibil invalid pentru vehicul.";
    }
};

class Vehicle {
private:
    int fabrication_year;
    string model;
    double price;
    string colour;
    int id;

public:

    ///metoda clone virtuala
    virtual Vehicle* clone() const = 0;

    ///constr parametrizat
    Vehicle(int fabrication_year, const string &model, double price, const string &colour):fabrication_year(fabrication_year)
    ,model(model),price(price),colour(colour){}

    ///constr de init
    Vehicle(){
        fabrication_year=0;
        model="";
        price=0;
        colour="";
        id=IDGenerator::generateID();
    };
    Vehicle(const Vehicle &ob);  ///copy constructor


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


    ///OPERATORUL << virtualizat
    virtual ostream& afisare(ostream& os);
    friend ostream& operator<<(ostream &os, Vehicle& v)
    {
        return v.afisare(os);
    }

    /// verifică starea vehiculului-fct virtuala pura
    virtual bool verificaStarea() const = 0;


    ///citire
    virtual istream& citire(istream& os);
    friend istream& operator<<(istream &is, Vehicle& v)
    {
        return v.citire(is);
    }

    int getId() const;
};

///citire
istream& Vehicle::citire(istream& is)
{
    cout<<"An fabricatie: ";is>>fabrication_year;
    cout<<"Culoare: ";is>>colour;
    cout<<"Model: ";is>>model;
    cout<<"Pret: ";is>>price;
    if(price<0)throw InvalidPriceException();

    return is;

}

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
ostream& Vehicle::afisare(ostream &os)
{
    os<<"An fabricatie: "<<fabrication_year<<"\n"
      <<"Culoare: "<<colour<<"\n"
      <<"Model: "<<model<<"\n"
      <<"Pret: "<<price<<"\n";
    return os;
}

int Vehicle::getId() const {
    return id;
}


class Car: public Vehicle
{
private:
    double fuel_consumption;
    string fuel_type;
    int kilometres;
    bool navigation;
    bool broken;
public:

    ///constr param
    Car(int fabrication_year, const string &model, double price, const string &colour,
        double fuel_consumption, const string &fuel_type,int kilometres, bool navigation,bool broken):
            Vehicle(fabrication_year,model,price,colour),fuel_consumption(fuel_consumption),fuel_type(fuel_type),
            kilometres(kilometres),navigation(navigation),broken(broken){}

    ///clone
    Car* clone() const override {
        return new Car(*this);
    }

    ///constr fara param
    Car(): Vehicle(),fuel_consumption(0),fuel_type(""),kilometres(0),navigation(0),broken(0){};

    ///SETTERI
    void setFuelConsumption(double fuel_consumption);
    void setFuelType(const string &fuel_type);
    void setKm(int kilometres);
    void setNavigation(bool navigation);
    void setConditin(bool broken);

    ///GETTERI
    double getFuelConsumption() const;
    const string &getFuelType() const;
    int getKilometres() const;
    bool getNav() const;
    bool getCondition() const;


    ///OP =
    Car& operator=(const Car& c);

    ///GetVehicleType
    VehicleType GetVehicleType() const override;

    ///OPERATOR <<
    ostream& afisare(ostream& os) override;
    friend ostream& operator<<(ostream &os,Car& c)
    {
        return c.afisare(os);
    };

    ///OPERATOR ==
    bool operator==(const Vehicle& other) const override;

    ///verifica starea
    bool verificaStarea() const override;

    ///citire
    istream& citire(istream& is) override;
    friend istream& operator>>(istream& is,Car& c)
    {
        return c.citire(is);
    }

};

///citire

istream& Car::citire(istream &is) {
    Vehicle::citire(is);
    cout<<"Consum: ";is >> fuel_consumption;
    cout<<"Tip combustibil: ";is >> fuel_type;
    cout<<"Kilometri: ";is >> kilometres;
    cout<<"Navigatie: ";is >> navigation;
    cout<<"Sticata: ";is >> broken;
    is.ignore();

    if(fuel_type!="benzina"&&fuel_type!="motorina"&&fuel_type!="electric")throw InvalidFuelTypeException();

    return is;
}

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
ostream& Car::afisare(ostream& os)
{
    os<<"DOTARI MASINA\n"<<"An fabricatie: "<<getFabrication_year()<<"\n"
        <<"Culoare: "<<getColour()<<"\n"
        <<"Model: "<<getModel()<<"\n"
        <<"Pret: "<<getPrice()<<"\n"
        <<"Consum: "<<getFuelConsumption()<<"\n"
        <<"Tip combustibil: "<<getFuelType()<<"\n"
        <<"Km parcursi: "<<getKilometres()<<"\n"
        <<"Navigatie: ";
    if(getNav())os << "Da" << "\n";
    else os<<"Nu"<<"\n";
    os<<"Conditie: ";
    if(getCondition())os << "Stricata" << "\n\n";
    else os<<"Buna"<<"\n\n";

    return os;
}

///GET VEHICLE TYPE
VehicleType Car::GetVehicleType() const {
    return VehicleType::Car;
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

class Bus:public Vehicle
{
private:
    int capacity, max_speed;
    double length, width, fuel_consumption;
    bool used;
    vector <string> routes;
public:
    ///clone
    Bus* clone() const override {
        return new Bus(*this);
    }

    ///constr de init
    Bus(int fabrication_year, const string &model, double price, const string &colour,int capacity,int max_speed,double length,double width,double fuel_consumption,bool used);

    ///constr fara param
    Bus()=default;

    ///SETTERI
    void setCapacity(int capacity);
    void setMaxSpeed(int max_speed);
    void setLenght(double lenght);
    void setWidth(double width);
    void setFuelCons(double fuel_consumption);
    void setSituation(bool used);

    ///GETTERI
    int getCapacity() const;
    int getMaxSpeed() const;
    double getLenght() const;
    double getWidth() const;
    double getFuelCons() const;
    bool getSituation() const;

    ///GetVehicleType
    VehicleType GetVehicleType() const override;

    ///OP =
    Bus& operator=(const Bus& b);

    ///OP <<
    ostream& afisare(ostream& os) override;
    friend ostream& operator<<(ostream& os, Bus& b) {
        return b.afisare(os);
    };

    ///OPERATOR ==
    bool operator==(const Vehicle& other) const override;

    ///verify if the bus is empty
    bool verificaStarea() const override;

    ///citire
    istream& citire(istream& is) override;
    friend istream& operator>>(istream& is, Bus& b)
    {
        return b.citire(is);
    }
};

///afisare
ostream& Bus::afisare(ostream& os)
{
    os << "DOTARI AUTOBUZ\n"
         << "An fabricatie: " << getFabrication_year() << "\n"
         << "Culoare: " << getColour() << "\n"
         << "Model: " << getModel() << "\n"
         << "Pret: " << getPrice() << "\n"
         << "Capacitate: " << getCapacity() << "\n"
         << "Viteza maxima: " << getMaxSpeed() << "\n"
         << "Lungime: " << getLenght() << "\n"
         << "Latime: " << getWidth() << "\n"
         << "Consum: " << getFuelCons() << "\n"
         << "Folosit: ";
    if (getSituation())
        os << "Da" << "\n";
    else
        os << "Nu" << "\n";
    os << "Rute: ";
    for (const string& route : routes)
    {
        os << route << " ";
    }
    os<< "\n\n";

    return os;
}
///CONSTRUCTOR PARAMETRIZAT- APELAREA CONSTR DIN CLASA DE BAZA
Bus::Bus(int fabrication_year,const string &model,double price,const string &colour,int capacity, int max_speed, double length, double width, double fuel_consumption,bool used) :
        Vehicle(fabrication_year,model,price,colour),capacity(capacity),max_speed(max_speed),length(length),width(width),fuel_consumption(fuel_consumption),used(used)
{/*cout << "Bus constructor called" << endl;*/}

///citire
istream& Bus::citire(istream& is)
{
    Vehicle::citire(is);
    cout << "Capacitate: ";
    is >> capacity;
    cout << "Viteza maxima: ";
    is >> max_speed;
    cout << "Lungime: ";
    is >> length;
    cout << "Latime: ";
    is >> width;
    cout << "Consum: ";
    is >> fuel_consumption;
    cout << "Folosit (1 - Da, 0 - Nu): ";
    is >> used;


    return is;
}


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



// Funcție șablon care afișează un vector de obiecte
template<typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& element : vec) {
        std::cout << *element << " ";
    }
    std::cout << std::endl;
}

// Clasă șablon pentru o cutie generică
template<typename T>
class Box {
private:
    T content;

public:
    Box(const T& item) : content(item) {}

    void displayContent() const {
        std::cout << "Box content: " << content << std::endl;
    }
};



int main() {
    ///operatorul <<, exceptii, id generat automat
    /*
    try {
        Bus *b = new Bus();
        cin >> *b;
        cout << *b;
        cout << b->getId()<<endl;

        Car* c=new Car();
        cin>>*c;
        cout<<*c;
        cout<<c->getId()<<endl;
    } catch (const InvalidPriceException &e) {
        cout << "Exceptie prinsa: " << e.what() << endl;
    }
    catch (const InvalidFuelTypeException &e){
    cout << "Exceptie prinsa: " << e.what() << endl;
    }
*/
    ///facem un vector de vehicule n vechicule

    vector <shared_ptr<Vehicle>> v;

    cout<<"Introduceti nr vechicule: ";
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Introduceti tip vehicul: \n1.Masina\n2.Autobuz\n";
        int tip;
        cin>>tip;
        if(tip==1)
        {
            Car *c=new Car();
            cin>>*c;
            v.push_back(make_shared<Car>(*c));
        }
        if(tip==2)
        {
            Bus* b=new Bus();
            cin>>*b;
            v.push_back(make_shared<Bus>(*b));
        }
    }

    ///afisam vectorul
    printVector(v);


    ///metoda clone

    Vehicle* vehicle = new Car(2020, "AUDI", 23000, "black", 8.7, "diesel", 40000, true, false);
    Vehicle* clonedVehicle = vehicle->clone();
    cout<<*clonedVehicle;

    Vehicle* vehicle2 = new Bus(2012, "MERCEDESS",12200, "black",45,210,6,3,10.2,false);
    Vehicle* clonedVehicle2 = vehicle2->clone();
    cout<<*clonedVehicle2;

}
