#pragma once
#include <string>
#include <vector>

#include "Order.h"
#include "Customer.h"

class BaseAction;
class Volunteer;

// Warehouse responsible for Volunteers, Customers Actions, and Orders.


class WareHouse {

    public:
        WareHouse(const string &configFilePath);
        void start();
        void addOrder(Order* order);
        void addAction(BaseAction* action);
        void addVolunteer(Volunteer* volunteer); //new method that adds a volunteer to the warehouse
        void addCustomer(Customer* customer); //new method that adds a customer to the warehouse
        Customer &getCustomer(int customerId) const;
        Volunteer &getVolunteer(int volunteerId) const;
        Order &getOrder(int orderId) const;
        const vector<BaseAction*> &getActions() const;
        void close();
        void open();
        
		//new methods
		void getUserCommand(); //assist start() method
		int getCustomerCounter();
        int getVolunteerCounter();
        int getOrderCounter();
        vector<Order*> &getPendingOrders(); 
        vector<Order*> &getCompletedOrders(); 
        vector<Order*> &getinProcessOrders(); 
        vector<Customer*> &getCustomers(); 
        vector<Volunteer*> &getVolunteers(); 
        
		//rule of 5
		~WareHouse();//destructor
        WareHouse(const WareHouse &other);//copy constructor
        WareHouse &operator=(const WareHouse &other);//copy assignment operator
        WareHouse&operator=(WareHouse &&other); //move assignment operator
        WareHouse(WareHouse &&other);////move constructor
        void getUserCommand();  //new method that gets the user command
        void deleteAll(); //new method that deletes all the objects in the warehouse
    private:
        bool isOpen;
        vector<BaseAction*> actionsLog;
        vector<Volunteer*> volunteers;
        vector<Order*> pendingOrders;
        vector<Order*> inProcessOrders;
        vector<Order*> completedOrders;
        vector<Customer*> customers;
        int customerCounter=0; //For assigning unique customer IDs
        int volunteerCounter=0; //For assigning unique volunteer IDs
        int orderCounter=0; //For assigning unique order IDs, new field
};
