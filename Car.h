#ifndef _CAR_H_
#define _CAR_H_
#include "Vehicle.h"
using namespace std;

class Car: public Vehicle
{
private:
    double fuel_consumption;
    string fuel_type;
    int kilometres;
    bool navigation;
    bool broken;
public:
    ///CONSTR DE INITIALIZARE
    Car(int fabrication_year, const string &model, double price, const string &colour,
        double fuel_consumption, const string &fuel_type,int kilometres, bool navigation,bool broken);

    ///constr fara param
    Car()=default;

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

    ///AFISARE DOTARI-FCT VIRTUALA PURA
    void afisareDotari() const override;

    ///OP =
    Car& operator=(const Car& c);

    ///GetVehicleType
    VehicleType GetVehicleType() const override;

    ///OPERATOR <<
    friend ostream& operator<<(ostream &os, const Car& c);

    ///OPERATOR ==
    bool operator==(const Vehicle& other) const override;

    ///verifica starea
    bool verificaStarea() const override;



};



#endif //_CAR_H_
