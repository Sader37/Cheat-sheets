// Constructors. Abstract parts of interface. Polymorphic logic using pointers.
class Monster {
protected:
    int AP = 0;
public:
    explicit Monster(int ap): AP(ap) {};
    virtual void attack() = 0;
    void set_AP(int am);
};


void Monster::set_AP(int am) {
    AP = am;
};

class Ninja : public Monster {
public:
    explicit Ninja(int ap): Monster(ap) {};
    void attack() {
        cout << "Ninja is attacking with Attack Power of " << AP << "." << endl;
    }
};

class Slime : public Monster {
public:
    explicit Slime(int ap): Monster(ap) {};
    void attack() {
        cout << "Slime is attacking with Attack Power of " << AP << "." << endl;
    }
};
//Ninja a(12);
//Slime b(4);
//Monster* ptr1 = &a;
//Monster* ptr2 = &b;
//ptr1->attack(); // or a.attack();
//ptr2->attack(); // or b.attack();
