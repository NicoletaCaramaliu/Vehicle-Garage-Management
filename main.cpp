#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Truck.h"
#include "VehicleType.h"
#include "garage.h"

#include <memory>
using namespace std;

int main() {
    /* Car c(2012, "BMW", 12000,"blue",7.3,"diesel",20000, true, false);
     Car c2(1000,"dfhg",3453,"red",7.3,"diesel",20000,true, true);

   Vehicle* vehicul=new Car(2012, "BMW", 12000,"blue",7.3,"diesel",20000, false );
     vehicul->afisareDotari();
     delete vehicul;

     c=c2;
     c.afisareDotari();
     cout<<c.getCondition();
     Bus b(2012, "BMW", 12000,"blue",30,200,7,3,11.3, true);
     Bus b2(20122, "BcdsMW", 123000,"bdvlue",10,400,5,2,13.3, false);
     b=b2;
     b.setSituation(true);
     cout<<b;
     cout<<b.verificaStarea();
     Vehicle *ob=new Car();
     cout<<*ob;*/

    int nr_vehicles=15, nr_cars=7, nr_buses=5, nr_trucks=3,garageCapacity=15;
    auto c1=make_shared<Car>(2020, "AUDI", 23000, "black", 8.7, "diesel", 40000, true, false);
    auto c2= make_shared<Car>(2010, "BMW",6000,"gray",9.7,"gasoline",140000, false, false);
    auto c3= make_shared<Car>(2022, "PORCHE",50000,"purple",11.3,"diesel",1000,true, false);
    auto c4= make_shared<Car>(2004, "DACIA",1000,"black",4.5,"gas",340000, false, true);
    auto c5= make_shared<Car>(2014, "Fiat 500",10000,"blue",8.1,"diesel",45000,true, false);
    auto c6= make_shared<Car>(2017, "OPEL",11000,"light blue",6.3,"gasoline",40000,true, true);
    auto c7= make_shared<Car>(2007, "VOLKSWAGEN",4500,"black",6.9,"diesel",240000, false, false);

    auto b1= make_shared<Bus>(2012, "MERCEDESS",12200, "black",45,210,6,3,10.2,false);
    auto b2= make_shared<Bus>(2005, "MERCEDESS",7500, "white",27,170,4,2,9.4,true);
    auto b3= make_shared<Bus>(2017, "MERCEDESS",13500, "gray",40,220,5,3,10.2,true);
    auto b4= make_shared<Bus>(2020, "MERCEDESS",16200, "black",60,210,6,3,13.2,false);
    auto b5= make_shared<Bus>(2009, "MERCEDESS",8200, "white",35,190,4,2,9.1, true);

    auto t1= make_shared<Truck>(2016,"KLEYN",30000,"red",true,5,4.5,2);
    auto t2= make_shared<Truck>(2021,"RENAULT",50000,"white",false, 3,5,1);
    auto t3= make_shared<Truck>(2009,"SCANIA",15000,"black", false,6,4.8,3);


  /*  Vehicle* v=new Car(2020, "AUDI", 23000, "black", 8.7, "diesel", 40000, true, false);
    Car* c=dynamic_cast<Car*>(v);
    if (c != nullptr) {
        cout<<"conversia a reusit\n";c->afisareDotari();
    } else {
        cout<<"conversia nu a reusit";
    }*/

    try {
    Garage::AddVehicle(c1); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try{
    Garage::AddVehicle(c2); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try{
    Garage::AddVehicle(c3); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try{
        Garage::AddVehicle(c4); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try{
    Garage::AddVehicle(c5); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try{
    Garage::AddVehicle(c6); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try{
    Garage::AddVehicle(c7); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try{
    Garage::AddVehicle(b1); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try{
        Garage::AddVehicle(b2); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try{
    Garage::AddVehicle(b3); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try{
    Garage::AddVehicle(b4); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try{
    Garage::AddVehicle(b5); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try{
    Garage::AddVehicle(t1); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try{
    Garage::AddVehicle(t2); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try{
    Garage::AddVehicle(t3); }
    catch (const VehicleAlreadyExistsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }


    int current_nr=9;
   /* Garage::ShowAllVehicles();
    Garage::ShowAllBrokenCars();
    Garage::ShowAllBuses();*/
    int o=1;
    do {
        cout
                << "Bine ati venit!\n Acesta este un garaj destinat masinilor, autobuzelor si camioanelor.\nIn garaj putem intorduce doar masinile intr-o stare de functionare buna"
                << ", autobuzele fara pasageri si camioanele fara marfa. \n Puteti accesa mai multe date ale garajului, precum si ce se afla in afara lui, cum ar fi:\n"
                << "1) Toate vehiculele din garaj\n2)Toate masinile din garaj\n3)Toate masinile stricate\n4)Autobuzele din garaj\n"
                << "5)Autobuzele care se afla pe traseu\n6)Camioanele din garaj\n7)Camioanele cu marfa\n8)Adaugati propria masina\n";

        int n;
        cout << "Introduceti optiunea:\n";
        cin >> n;
        switch (n) {
            case 1: {
                cout << "Vehiculele care se afla in garaj sunt in numar de: " << current_nr << "\n\n";
                Garage::ShowAllVehicles();
                break;
            }
            case 2: {
                cout << "Masinile care se afla in garaj sunt:\n\n";
                Garage::ShowAllCars();
                break;
            }
            case 3: {
                cout << "Masinile stricate sunt:\n\n";
                Garage::ShowAllBrokenCars();
                break;
            }
            case 4: {
                cout << "Autobuzele din garaj sunt:\n\n";
                Garage::ShowAllBuses();
                break;
            }
            case 5: {
                cout << "Autobuzele care se afla pe traseu sunt:\n\n";
                Garage::ShowOnRoadBuses();
                break;
            }
            case 6: {
                cout << "Camioanele din garaj sunt: \n";
                Garage::ShowAllTrucks();
                break;
            }
            case 7: {
                cout << "Camioanele incarcate sunt: \n";
                Garage::ShowLoadedTrucks();
                break;
            }
            case 8: {
                if (current_nr < garageCapacity) {
                    Car *c = Garage::AddOwnCar(shared_ptr<Car>());
                    if (c != nullptr) {
                        current_nr++;
                        auto newCar = make_shared<Car>(c->getFabrication_year(), c->getModel(), c->getPrice(),
                                                       c->getColour(), c->getFuelConsumption(),
                                                       c->getFuelType(), c->getKilometres(), c->getNav(),
                                                       c->getCondition());

                        Garage::AddVehicle(newCar);
                        cout
                                << "Masina dumneavoastra a fost adaugata cu succes. Va asteptam cat mai curand sa o aduceti la garajul nostru.\nDupa 2 zile rezervarea va fi amanata\n";
                    } else {
                        cout << "Datele introduse nu sunt corecte\n";
                        break;
                    }
                } else cout << "Nu mai exista loc in garaj\n";
                break;
            }
            default: {
                cout << "Multumim de vizionare! Va mai asteptam\n";
                return 0;
            }
        }

        cout << "Doriti sa continuati sa vizualizati datele despre vehicule?\n1)DA\n2)NU\n";
        cin >> o;
        if(o==2) cout << "Multumim de vizionare! Va mai asteptam\n";
    } while (o==1);
    return 0;
}
