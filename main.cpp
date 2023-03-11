#include <iostream>
#include <cstring>

using namespace std;

class Car{
private:
    int fabrication_year;
    char *model;
    double price;
    int speed_per_hour;
    char *colour;
    double fuel_consumption;
    char *fuel_type;
    int kilometres;

public:
    ///constructor fara parametri
    Car()
    {
        cout<<"S-a apelat constructorul fara parametri "<<endl;
        fabrication_year=0;
        model=new char[strlen("Unknown")+1];
        strcpy(model,"Unknown");
        price=0;
        speed_per_hour=0;
        colour=new char[strlen("Unknown")+1];
        strcpy(colour,"Unknown");
        fuel_consumption=0;
        fuel_type=new char[strlen("Unknown")+1];
        strcpy(fuel_type,"Unknown");
        kilometres=0;
    }

    /// constructor cu parametri
    Car(int fabrication_year_, const char* model_, double price_, int speed_per_hour_,const char* colour_,double fuel_consumpion_, const char* fuel_type_, int kilometers_)
    {
        cout<<"S-a apelat constructorul cu parametri "<<endl;
        fabrication_year=fabrication_year_;
        size_t len = strlen(model_);
        model = new char[len + 1];
        strcpy(model, model_);
        price=price_;
        speed_per_hour=speed_per_hour_;
        size_t len1 = strlen(colour_);
        colour = new char[len1 + 1];
        strcpy(colour, colour_);
        fuel_consumption=fuel_consumpion_;
        size_t len2 = strlen(fuel_type_);
        fuel_type = new char[len2 + 1];
        strcpy(fuel_type, fuel_type_);
        kilometres=kilometers_;
    }
    ///Destructori
    ~Car() {
        delete[] model;
        delete[] colour;
        delete[] fuel_type;
    }

    Car(const Car &ob)  ///copy constructor
    {
        cout<<"S-a apelat constructorul de copiere "<<endl;
        fabrication_year=ob.fabrication_year;
        size_t len = strlen(ob.model);
        model = new char[len + 1];
        strcpy(model, ob.model);
        price=ob.price;
        speed_per_hour=ob.speed_per_hour;
        size_t len1 = strlen(ob.colour);
        colour = new char[len1 + 1];
        strcpy(colour, ob.colour);
        fuel_consumption=ob.fuel_consumption;
        size_t len2 = strlen(ob.fuel_type);
        fuel_type = new char[len2 + 1];
        strcpy(fuel_type, ob.fuel_type);
        kilometres=ob.kilometres;

    }

    void afisare()
    {
        cout<<"Year: "<<fabrication_year<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Colour: "<<colour<<endl;
        cout<<"Fuel consumption: "<<fuel_consumption<<endl;
        cout<<"Fuel type: "<<fuel_type<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Kilometres: "<<kilometres<<endl;
        cout<<"Speed per hour: "<<speed_per_hour<<endl;
    }

    void setFabricationYear(const int fabrication_year_)
    {
        fabrication_year=fabrication_year_;
    }
    void setModel(const char* model_)
    {
        size_t len=strlen(model_);
        model=new char[len+1];
        strcpy(model,model_);
    }
    void setPrice(const double price_)
    {
        price=price_;
    }
    void setSpeed(const int speed_)
    {
        speed_per_hour=speed_;
    }

    void setColour(const char* colour_)
    {
        size_t len=strlen(colour_);
        colour=new char[len+1];
        strcpy(colour,colour_);
    }
    void setFuelConsumption(const double fuel_consumpion_)
    {
        fuel_consumption=fuel_consumpion_;
    }
    void setFuelType(const char* fuel_type_)
    {
        size_t len=strlen(fuel_type_);
        fuel_type=new char[len+1];
        strcpy(fuel_type,fuel_type_);
    }
    void setKilometres(const int kilometres_)
    {
        kilometres=kilometres_;
    }
    int getFabrication_year() const;
    const char* getModel()
    {
        return model;
    }
    double getPrice() const
    {
        return price;
    }
    int getSpeedPerHour() const
    {
        return speed_per_hour;
    }
    const char* getColour() const
    {
        return colour;
    }
    double getFuelConsumpion() const
    {
        return fuel_consumption;
    }
    const char* getFuelType() const
    {
        return fuel_type;
    }
    int getKilometers() const
    {
        return kilometres;
    }

    ///rescrierea operatorilor
    /*--forma
     TipReturn operator+(const TipData2 &rhs) const {
    ...
    }
     */

    ///operatorul =
    Car& operator =(const Car &rhs)
    {
        delete[] model;
        delete[] colour;
        delete[] fuel_type;
        cout<<"S-a apelat operatorul ="<<endl;
        fabrication_year=rhs.fabrication_year;
        setModel(rhs.model);
        price=rhs.price;
        speed_per_hour=rhs.speed_per_hour;
        setColour(rhs.colour);
        fuel_consumption=rhs.fuel_consumption;
        setFuelType(rhs.fuel_type);
        kilometres=rhs.kilometres;

        return *this;
    }

    ///Operatorii == si !=

    bool operator ==(const Car &c)
    {
        return fabrication_year==c.fabrication_year && strcmp(model,c.model)==0 && price==c.price
        && speed_per_hour==c.speed_per_hour && strcmp(colour,c.colour)==0 && fuel_consumption==c.fuel_consumption
        && strcmp(fuel_type,c.fuel_type)==0 && kilometres==c.kilometres;
    }

    bool operator !=(const Car &c)
    {
        return fabrication_year!=c.fabrication_year || strcmp(model,c.model)!=0 || price!=c.price
               || speed_per_hour!=c.speed_per_hour || strcmp(colour,c.colour)!=0 || fuel_consumption!=c.fuel_consumption
               || strcmp(fuel_type,c.fuel_type)!=0 || kilometres!=c.kilometres;
    }


    ///Supraincarcarea operatorilor << si >>

    friend istream& operator>>(istream& in, Car& c1);
    friend ostream& operator<<(ostream& out, const Car& c1);


};

istream& operator>>(istream& in, Car& c1)
{
    in>>c1.fabrication_year>> c1.model>> c1.price>>c1.speed_per_hour>>
    c1.colour>>c1.fuel_consumption>>c1.fuel_type>>c1.kilometres;
    return in;
}

ostream& operator<<(ostream& out, const Car& c1) {
    out<<c1.fabrication_year<<" "<< c1.model << " " << c1.price << " " <<c1.speed_per_hour<<
    " "<<" "<< c1.colour<<" "<<c1.fuel_consumption<<" "<<c1.fuel_type<<" "<<c1.kilometres<<endl;
    return out;
}

int Car::getFabrication_year() const {
    return fabrication_year;
}



int main() {
  /*  Car c1(2012,"BMW",12000,300,"blue",7.3,"diesel",120000);
    c1.afisare();
    cout<<endl;
    Car c2(c1);
    c2.afisare();
    cout<<endl;
    c2.setFabricationYear(2020);
    c2.setModel("Fiat 500");
    c2.setPrice(15000);
    c2.setSpeed(240);
    c2.setColour("white");
    c2.setFuelConsumption(8.2);
    c2.setFuelType("gasoline");
    c2.setKilometres(75000);
    cout<<c2.getFabrication_year();
    c2.afisare();
    cout<<endl;
    cout<<" "<<c2.getModel();
    cout<<" "<<c2.getColour();
    cout<<" "<<c2.getFuelConsumpion();
    cout<<" "<<c2.getFuelType();
    cout<<" "<<c2.getKilometers();
    cout<<" "<<c2.getPrice();
    cout<<" "<<c2.getSpeedPerHour()<<endl;
    Car c3(2010,"Audi",8000,280,"black",6.8,"diesel",280000);
    c3.afisare();
    cout<<endl;
    c3=c1;
    c3.afisare();
    cout<<endl;
    Car c4;
    c4.afisare();
    cout<<endl;
    c4=c2;
    c4.afisare();cout<<endl;
    cout<<(c4==c3)<<endl;
    c4=c3;
    cout<<(c4==c3)<<endl;
    cout<<(c4!=c3)<<endl;
    c4=c2;
    cout<<(c4!=c3)<<endl;
    cout<<c4<<endl;
    Car c5;
    cin>>c5;
    cout<<c5;*/
}
