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

// Subclass: Coach
class Coach : public Person {
protected:
    string license;

public:
    Coach(string name, int age, string license) : Person(name, age), license(license) {}
    void displayRole() override {
        cout << left << setw(10) << "[Coach] " << name << " | Age: " << age << " | License: " << license << endl;
    }
};

// Subclass: Player
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

// Subclass: Staff
class Staff : public Person {
private:
    string role;

public:
    Staff(string name, int age, string role) : Person(name, age), role(role) {}
    void displayRole() override {
        cout << left << setw(10) << "[Staff] " << name
             << " | Age: " << age
             << " | Role: " << role << endl;
    }
};

// Factory interface
class PersonFactory {
public:
    virtual unique_ptr<Person> createPerson() = 0;
};

// Coach factory
class CoachFactory : public PersonFactory {
private:
    string name;
    int age;
    string license;

public:
    CoachFactory(string name, int age, string license)
        : name(name), age(age), license(license) {}

    unique_ptr<Person> createPerson() override {
        return make_unique<Coach>(name, age, license);
    }
};

// Player factory
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
        return make_unique<Player>(name, age, number, position);
    }
};

// Staff factory
class StaffFactory : public PersonFactory {
private:
    string name;
    int age;
    string role;

public:
    StaffFactory(string name, int age, string role)
        : name(name), age(age), role(role) {}

    unique_ptr<Person> createPerson() override {
        return make_unique<Staff>(name, age, role);
    }
};

// Menu
void menuInput(vector<unique_ptr<Person>>& team) {
    int choice;
    while (true) {
        cout << "\n=== Tambah Anggota Tim FC Cakrawala Muda ===\n";
        cout << "1. Tambah Head Coach\n";
        cout << "2. Tambah Player\n";
        cout << "3. Tambah Staff\n";
        cout << "4. Tampilkan Semua\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        cin.ignore(); // flush newline

        if (choice == 0) break;

        string name, position, role, license;
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
            cout << "Nomor punggung: ";
            cin >> number;
            cin.ignore();
            cout << "Posisi (e.g. Forward, Midfielder): ";
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
            cout << "Peran: ";
            getline(cin, role);
            {
                StaffFactory sf(name, age, role);
                team.push_back(sf.createPerson());
            }
            break;

        case 4:
            cout << "\n=== Daftar Anggota Tim ===\n";
            for (auto& p : team) {
                p->displayRole();
            }
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }
    }
}

int main() {
    vector<unique_ptr<Person>> team;
    menuInput(team);

    cout << "\n=== Terima kasih telah menggunakan sistem FC Cakrawala Muda ===\n";
    return 0;
}
