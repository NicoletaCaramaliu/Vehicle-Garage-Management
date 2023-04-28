#ifndef _GARAGE_H_
#define _GARAGE_H_

#include "Vehicle.h"
#include "Bus.h"
#include "Car.h"
#include <memory>
#include <vector>

using namespace std;

///EXCEPTIE

class VehicleAlreadyExistsException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Vehicle already exists in the garage";
    }
};

class Garage{
private:

    static vector<shared_ptr<Vehicle>> brokenCars;
    static vector<shared_ptr<Vehicle>> OnRoadBuses;
    static vector<shared_ptr<Vehicle>> LoadedTrucks;

public:
    static vector<shared_ptr<Vehicle>> garageVehicles;
    static void AddVehicle( shared_ptr<Vehicle>);
    static Car *AddOwnCar(const shared_ptr<Car>& ptr);
    static void ShowAllVehicles();
    static void ShowAllCars();
    static void ShowAllBuses();
    static void ShowAllTrucks();
    static void ShowLoadedTrucks();
    static void ShowAllBrokenCars();
    static void ShowOnRoadBuses();

};

#endif //_GARAGE_H_