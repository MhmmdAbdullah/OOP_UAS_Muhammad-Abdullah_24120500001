#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
using namespace std;

// Abstract base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}
    virtual void displayRole() = 0;
    virtual ~Person() {}
};

// Coach
class Coach : public Person {
private:
    string license;

public:
    Coach(string name, int age, string license)
        : Person(name, age), license(license) {}

    void displayRole() override {
        cout << left << setw(10) << "[Coach] " << name
             << " | Age: " << age
             << " | License: " << license << endl;
    }
};

// Player
class Player : public Person {
private:
    int number;
    string position;

public:
    Player(string name, int age, int number, string position)
        : Person(name, age), number(number), position(position) {}

    void displayRole() override {
        cout << left << setw(10) << "[Player]" << name
             << " | Age: " << age
             << " | No: " << number
             << " | Pos: " << position << endl;
    }
};

// Staff
class Staff : public Person {
private:
    string role;

public:
    Staff(string name, int age, string role)
        : Person(name, age), role(role) {}

    void displayRole() override {
        cout << left << setw(10) << "[Staff] " << name
             << " | Age: " << age
             << " | Role: " << role << endl;
    }
};

// Abstract Factory
class PersonFactory {
public:
    virtual unique_ptr<Person> createPerson() = 0;
    virtual ~PersonFactory() {}
};

// CoachFactory
class CoachFactory : public PersonFactory {
private:
    string name;
    int age;
    string license;

public:
    CoachFactory(string name, int age, string license)
        : name(name), age(age), license(license) {}

    unique_ptr<Person> createPerson() override {
        return unique_ptr<Person>(new Coach(name, age, license));
    }
};

// PlayerFactory
class PlayerFactory : public PersonFactory {
private:
    string name;
    int age;
    int number;
    string position;

public:
    PlayerFactory(string name, int age, int number, string position)
        : name(name), age(age), number(number), position(position) {}

    unique_ptr<Person> createPerson() override {
        return unique_ptr<Person>(new Player(name, age, number, position));
    }
};

// StaffFactory
class StaffFactory : public PersonFactory {
private:
    string name;
    int age;
    string role;

public:
    StaffFactory(string name, int age, string role)
        : name(name), age(age), role(role) {}

    unique_ptr<Person> createPerson() override {
        return unique_ptr<Person>(new Staff(name, age, role));
    }
};

// Menu input
void menuInput(vector<unique_ptr<Person>>& team) {
    int choice;
    while (true) {
        cout << "\n=== Tambah Anggota Tim FC Cakrawala Muda ===\n";
        cout << "1. Tambah Head/Asisten Coach\n";
        cout << "2. Tambah Player\n";
        cout << "3. Tambah Staff\n";
        cout << "4. Tampilkan Semua\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string name, license, role, position;
        int age, number;

        switch (choice) {
        case 1:
            cout << "Nama Coach: ";
            getline(cin, name);
            cout << "Usia: ";
            cin >> age;
            cin.ignore();
            cout << "Lisensi: ";
            getline(cin, license);
            {
                CoachFactory cf(name, age, license);
                team.push_back(cf.createPerson());
            }
            break;

        case 2:
            cout << "Nama Player: ";
            getline(cin, name);
            cout << "Usia: ";
            cin >> age;
            cout << "Nomor Punggung: ";
            cin >> number;
            cin.ignore();
            cout << "Posisi: ";
            getline(cin, position);
            {
                PlayerFactory pf(name, age, number, position);
                team.push_back(pf.createPerson());
            }
            break;

        case 3:
            cout << "Nama Staff: ";
            getline(cin, name);
            cout << "Usia: ";
            cin >> age;
            cin.ignore();
            cout << "Peran Staff: ";
            getline(cin, role);
            {
                StaffFactory sf(name, age, role);
                team.push_back(sf.createPerson());
            }
            break;

        case 4:
            cout << "\n=== Daftar Anggota Tim FC Cakrawala Muda ===\n";
            for (auto& p : team) {
                p->displayRole();
            }
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }
    }
}

// Main
int main() {
    vector<unique_ptr<Person>> team;
    menuInput(team);
    cout << "\nTerima kasih telah menggunakan sistem FC Cakrawala Muda!\n";
    return 0;
}
