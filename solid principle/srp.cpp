#include<bits/stdc++.h>
using namespace std;

class BreadBaker{

 public:
  void bakeBread() { cout<<"Baking high-quality bread..."; }


  void manageInventory() { cout<<"Managing inventory..."; }


  void orderSupplies() { cout<<"Ordering supplies..."; }


  void serveCustomer() { cout<<"Serving customers..."; }


  void cleanBakery() { cout<<"Cleaning the bakery..."; }
 };
 // here in the one class we have multiple work like baking the bread , managing inventory , ordering supplies ets
 // it violets the srp(single responsibility principle) 
 // srp tells us like one class have only one responsibility ,means there should only one reason to change to the code
class BreadBaker2{
 public :
  void bakeBread() { cout<<"Baking high-quality bread..."; }
};

// Class for managing inventory
class InventoryManager {
 public :
  void manageInventory() { cout<<"Managing inventory..."; }
};

// Class for ordering supplies
class SupplyOrder {
 public :
  void orderSupplies() { cout<<"Ordering supplies..."; }
};

// Class for serving customers
class CustomerService {
 public :
  void serveCustomer() { cout<<"Serving customers..."; }
};

// Class for cleaning the bakery
class BakeryCleaner {
 public :
  void cleanBakery() { cout<<"Cleaning the bakery..."; }
};

// here we follow the srp principle ,
 int main(){
     BreadBaker2*baker = new BreadBaker2();
    InventoryManager*inventoryManager = new InventoryManager();
    SupplyOrder*supplyOrder = new SupplyOrder();
    CustomerService*customerService = new CustomerService();
    BakeryCleaner*cleaner = new BakeryCleaner();
    // Each class focuses on its specific responsibility
    baker->bakeBread();
    inventoryManager->manageInventory();
    supplyOrder->orderSupplies();
    customerService->serveCustomer();
    cleaner->cleanBakery();
 }