#ifndef _BUS_H_
#define _BUS_H_
#include "Vehicle.h"
#include <vector>
using namespace std;



class Bus:public Vehicle
{
private:
    int capacity, max_speed;
    double length, width, fuel_consumption;
    bool used;
    vector <string> routes;
public:
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

    ///AFISARE DOTARI-FCT VIRTUALA PURA
    void afisareDotari() const override;

    ///GetVehicleType
    VehicleType GetVehicleType() const override;

    ///OP =
    Bus& operator=(const Bus& b);

    ///OP <<
    friend ostream& operator<<(ostream& os,const Bus& b);

    ///OPERATOR ==
    bool operator==(const Vehicle& other) const override;

    ///verify if the bus is empty
    bool verificaStarea() const override;



};



#endif //_BUS_H_