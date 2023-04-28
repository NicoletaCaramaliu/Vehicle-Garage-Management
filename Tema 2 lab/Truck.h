#ifndef _TRUCK_H
#define _TRUCK_H
#include "Vehicle.h"
#include <iostream>
using namespace std;

class Truck: public Vehicle
{
private:
    bool loaded;
    double weight, height;
    int nr_trailers;
public:
    ///Constructor cu parametri
    Truck(int fabrication_year, const string &model, double price, const string &colour,bool loaded, double weight, double height, int nr_trailers);

    ///Constructor fara param
    Truck()=default;

    ///SETTERI
    void setLoaded(bool loaded);
    void setWeight(double weight);
    void setHeight(double height);
    void setNrTrailers(int nr_trailers);


    ///GETTERI
    bool getLoaded() const;
    double getWeight() const;
    double getHeight() const;
    int getNrTrailers() const;

    ///AFISARE DOTARI-FCT VIRTUALA PURA
    void afisareDotari() const override;

    ///GetVehicleType
    VehicleType GetVehicleType() const override;

    ///OP =
   Truck& operator=(const Truck& t);

    ///OP <<
    friend ostream& operator<<(ostream& os,const Truck& t);

    ///OPERATOR ==
    bool operator==(const Vehicle& other) const override;

    ///verify if the truck is empty
    bool verificaStarea() const override;
};

#endif //_TRUCK_H
