#include <bits/stdc++.h>
using namespace std;

// Abstract Product
class Burger {
public:
    virtual void prepare() = 0; // pure virtual function
    virtual ~Burger() {}        // virtual destructor
};

// Concrete Products
class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Basic Burger" << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Standard Burger" << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Premium Burger" << endl;
    }
};

// Factory
class BurgerFactory {
public:
    Burger* createBurger(const string &type) {
        if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        }
        return nullptr; // safe return if no match
    }
};

int main() {
    string type = "standard";
    BurgerFactory* bf = new BurgerFactory();
    Burger* b = bf->createBurger(type);

    if (b) {
        b->prepare();
    } else {
        cout << "Invalid burger type!" << endl;
    }

    delete b;  // free memory
    delete bf; // free memory
    return 0;
}
