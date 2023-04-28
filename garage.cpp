#include "garage.h"
#include "VehicleType.h"
#include "Car.h"
#include "Bus.h"
#include <vector>

using namespace std;



vector<shared_ptr<Vehicle>> Garage::garageVehicles;
vector<shared_ptr<Vehicle>> Garage::brokenCars;
vector<shared_ptr<Vehicle>> Garage::OnRoadBuses;
vector<shared_ptr<Vehicle>> Garage::LoadedTrucks;


///ADAUGA PROPRIA MASINA IN GARAJ
Car * Garage::AddOwnCar(const shared_ptr<Car>&) {
    int anFabr,km;
    string model, color,fuel_type;
    double price, fuelCons;
    bool nav,broken;
    int money;
    cout<<"Introduceti specificatiile masinii dumneavoastra si suma detinuta pentru a verifica daca se incadreaza in garaj\nPentru a introduce masina in garaj aveti nevoie de o suma de 500 RON si masina sa fie in conditie buna\n";
    cout<<"DOTARI MASINA\n"<<"An fabricatie: ";cin>>anFabr;
    cout<<"\nCuloare: ";cin>>color;
    cout<<"\nModel: ";cin>>model;
    cout<<"\nPret: ";cin>>price;
    try {
        if(price<=0)throw InvalidPriceException();
    }
    catch (const InvalidPriceException& e) {
        cout << "Error: " << e.what() << endl;
        return nullptr;
    }
    cout<<"\nConsum: ";cin>>fuelCons;
    cout<<"\nTip combustibil: ";cin>>fuel_type;
    cout<<"\nKm parcursi: ";cin>>km;
    cout<<"\nNavigatie: ";cin>>nav;
    cout<<"\nConditie: ";cin>>broken;
    cout<<"\nSuma detinuta: ";cin>>money;
    if(broken==0 && money>=500)
    {
        Vehicle* v=new Car(anFabr,model,price,color,fuelCons,fuel_type,km,nav,broken);
        Car* c=dynamic_cast<Car*>(v);
        return c;
    }
    else cout<<"Masina dumneavoastra nu indeplineste conditiile necesare pt a fi introdusa in garaj\n";
    return nullptr;
}

///IN GARAJ ADAUGAM DOAR MASINILE INTR-O STARE BUNA, AUTOBUZELE GOALE SI CAMIOANELE......
void Garage::AddVehicle( shared_ptr<Vehicle> vehicle) {

    for (auto const &v: garageVehicles) {
        if (v == vehicle) {
            throw VehicleAlreadyExistsException();
        }
    }
    for (auto const &v: brokenCars) {
        if (v == vehicle) {
            throw VehicleAlreadyExistsException();
        }}
    for (auto const &v: OnRoadBuses) {
        if (v == vehicle) {
            throw VehicleAlreadyExistsException();
        }
    }
    for (auto const &v: LoadedTrucks) {
        if (v == vehicle) {
            throw VehicleAlreadyExistsException();
        }
    }
    if(vehicle->verificaStarea() == 0)garageVehicles.push_back(vehicle);
    else {
        if (vehicle->GetVehicleType() == VehicleType::Car) brokenCars.push_back(vehicle);
        else {
            if (vehicle->GetVehicleType() == VehicleType::Bus) OnRoadBuses.push_back(vehicle);
            else if (vehicle->GetVehicleType() == VehicleType::Truck) LoadedTrucks.push_back(vehicle);
        }
    }
}


///AFISAM VEHICULELE DIN GARAJ
void Garage::ShowAllVehicles() {
    for (const auto& vehicle : Garage::garageVehicles)
    {
        vehicle->afisareDotari();
    }
}
///AFISAM MASINILE DIN GARAJ
void Garage::ShowAllCars() {
    for (const auto &vehicle: Garage::garageVehicles)
        if (vehicle->GetVehicleType()==VehicleType::Car) {
            vehicle->afisareDotari();}

}
///AFISAM AUTOBUZELE DIN GARAJ
void Garage::ShowAllBuses() {
    for (const auto &vehicle: Garage::garageVehicles)
        if (vehicle->GetVehicleType()==VehicleType::Bus) {
            vehicle->afisareDotari();}
}

///AFISAM AUTOBUZELE DE PE TRASEU
void Garage::ShowOnRoadBuses() {
    for (const auto &bus: Garage::OnRoadBuses)
        if (bus->GetVehicleType()==VehicleType::Bus) {
            bus->afisareDotari();}
}
///AFISAM CAMIOANELE DIN GARAJ
void Garage::ShowAllTrucks() {
    for (const auto &truck: Garage::garageVehicles) {
        if(truck->GetVehicleType()==VehicleType::Truck)
            truck->afisareDotari();
    }
}
///AFISAM CAMIOANELE INCARCATE
void Garage::ShowLoadedTrucks()
{
    for(const auto& truck: Garage::LoadedTrucks)
        truck->afisareDotari();
}

///AFISAM MASINILE STRICATE
void Garage::ShowAllBrokenCars() {
    for (const auto &car: Garage::brokenCars)
        car->afisareDotari();

}











