/*
================================================================================
         COMPLETE C++ CLASSES - DEEP UNDERSTANDING QUESTION BANK
         All OOP Concepts | Inheritance | Polymorphism | Encapsulation
         Abstraction | Virtual Functions | Memory | And More
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <typeinfo>
using namespace std;

// ============================================================================
//                         COLOR CODES FOR OUTPUT
// ============================================================================
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// ============================================================================
//                    FORWARD DECLARATIONS
// ============================================================================
void pauseAndContinue();
void printHeader(string title);
void printQuestion(int num, string question);
void printAnswer(string answer);
void printOutput(string output);
void printLesson(string lesson);
void printMemoryDiagram(string diagram);
void printWarning(string warning);

// ============================================================================
//                    SECTION 1: BASIC CLASS CONCEPTS
// ============================================================================

// ----- Q1: Basic Class and Object -----
class Car {
public:
    string brand;
    string color;
    int speed;

    void displayInfo() {
        cout << "Brand: " << brand
             << " | Color: " << color
             << " | Speed: " << speed << " km/h" << endl;
    }
};

void section1_BasicClass() {
    printHeader("SECTION 1: BASIC CLASS & OBJECTS");

    // Q1
    printQuestion(1,
        "What is a class and object?\n"
        "   Create a Car class with brand, color, speed\n"
        "   and display its information."
    );

    Car c1;
    c1.brand = "Toyota";
    c1.color = "Red";
    c1.speed  = 180;

    Car c2;
    c2.brand = "BMW";
    c2.color = "Black";
    c2.speed  = 250;

    cout << GREEN << "\n[Running Q1 Code...]" << RESET << endl;
    c1.displayInfo();
    c2.displayInfo();

    printLesson(
        "CLASS = Blueprint (like a house plan)\n"
        "   OBJECT = Real thing built from blueprint (actual house)\n"
        "   Each object has its OWN COPY of member variables\n"
        "   c1.speed and c2.speed are DIFFERENT memory locations"
    );

    printMemoryDiagram(
        "STACK MEMORY:\n"
        "   c1: [brand=Toyota][color=Red][speed=180]  <- own copy\n"
        "   c2: [brand=BMW][color=Black][speed=250]   <- own copy"
    );

    pauseAndContinue();
}

// ============================================================================
//                    SECTION 2: CONSTRUCTORS & DESTRUCTORS
// ============================================================================

class Battery {
    int percentage;
    string deviceName;
    static int totalBatteries;

public:
    // Default Constructor
    Battery() {
        percentage = 100;
        deviceName = "Unknown Device";
        totalBatteries++;
        cout << CYAN << "  [DEFAULT Constructor] " << deviceName
             << " battery created at " << percentage << "%" << RESET << endl;
    }

    // Parameterized Constructor
    Battery(string name, int pct) {
        deviceName = name;
        percentage = (pct >= 0 && pct <= 100) ? pct : 100;
        totalBatteries++;
        cout << CYAN << "  [PARAM Constructor] " << deviceName
             << " battery created at " << percentage << "%" << RESET << endl;
    }

    // Copy Constructor
    Battery(const Battery& other) {
        deviceName = other.deviceName + "_BACKUP";
        percentage = other.percentage;
        totalBatteries++;
        cout << CYAN << "  [COPY Constructor] Backup created from "
             << other.deviceName << RESET << endl;
    }

    // Destructor
    ~Battery() {
        totalBatteries--;
        cout << RED << "  [Destructor] " << deviceName
             << " battery destroyed. Remaining: "
             << totalBatteries << RESET << endl;
    }

    // Getter
    int getPercentage() const { return percentage; }
    string getName()    const { return deviceName; }

    // Static
    static int getTotal() { return totalBatteries; }

    void display() const {
        cout << "  " << deviceName << ": " << percentage << "%" << endl;
    }
};
int Battery::totalBatteries = 0;

void section2_Constructors() {
    printHeader("SECTION 2: CONSTRUCTORS & DESTRUCTORS");

    // Q2
    printQuestion(2,
        "What is a Default Constructor?\n"
        "   When is it called? What does it do?"
    );
    cout << GREEN << "\n[Running Q2 Code...]" << RESET << endl;
    {
        Battery b1;   // Default constructor
        b1.display();
    }
    printLesson(
        "Default Constructor:\n"
        "   -> Called AUTOMATICALLY when object is created with NO arguments\n"
        "   -> If you don't write one, compiler generates empty one\n"
        "   -> Once you write ANY constructor, compiler STOPS generating default"
    );

    pauseAndContinue();

    // Q3
    printQuestion(3,
        "What is a Parameterized Constructor?\n"
        "   Create battery with specific name and percentage.\n"
        "   Also show CONSTRUCTOR OVERLOADING."
    );
    cout << GREEN << "\n[Running Q3 Code...]" << RESET << endl;
    {
        Battery b1;                    // default
        Battery b2("iPhone", 85);      // parameterized
        Battery b3("Samsung", 45);     // parameterized
        cout << "\n  Total batteries: " << Battery::getTotal() << endl;
    }
    printLesson(
        "Parameterized Constructor:\n"
        "   -> Takes arguments to initialize with specific values\n"
        "   -> Multiple constructors = CONSTRUCTOR OVERLOADING\n"
        "   -> Compiler picks correct one based on arguments"
    );

    pauseAndContinue();

    // Q4
    printQuestion(4,
        "What is a Copy Constructor?\n"
        "   When is it called? Prove that it makes a SEPARATE copy."
    );
    cout << GREEN << "\n[Running Q4 Code...]" << RESET << endl;
    {
        Battery original("MacBook", 90);
        Battery backup = original;          // Copy constructor called!
        Battery backup2(original);          // Another way to call copy constructor

        cout << "\n  Original: " << original.getName()
             << " at " << original.getPercentage() << "%" << endl;
        cout << "  Backup  : " << backup.getName()
             << " at " << backup.getPercentage() << "%" << endl;
    }
    printLesson(
        "Copy Constructor:\n"
        "   -> Called when: Battery b2 = b1; OR Battery b2(b1);\n"
        "   -> Also called when passing object by VALUE to function\n"
        "   -> Also called when returning object by VALUE from function\n"
        "   -> Parameter MUST be const reference: (const Battery& other)\n"
        "   -> WHY const? So we don't accidentally modify original\n"
        "   -> WHY reference? Avoid infinite recursion!"
    );

    pauseAndContinue();

    // Q5
    printQuestion(5,
        "What is a Destructor? Prove LIFO order.\n"
        "   Show inner scope destruction before outer scope."
    );
    cout << GREEN << "\n[Running Q5 Code...]" << RESET << endl;
    {
        Battery outer("Outer-Device", 100);
        cout << "\n  --- entering inner scope ---" << endl;
        {
            Battery inner1("Inner-Device-1", 50);
            Battery inner2("Inner-Device-2", 30);
            cout << "  --- leaving inner scope ---" << endl;
        }
        cout << "  (inner scope ended)" << endl;
        cout << "  --- leaving outer scope ---" << endl;
    }
    printLesson(
        "Destructor:\n"
        "   -> Called AUTOMATICALLY when object goes out of scope\n"
        "   -> LIFO order: Last created = First destroyed\n"
        "   -> Used for cleanup: free memory, close files, etc.\n"
        "   -> ~ClassName() — no return type, no parameters\n"
        "   -> MAKE IT VIRTUAL if class is used as base class!"
    );

    pauseAndContinue();

    // Q6: Initializer List
    printQuestion(6,
        "What is a Constructor Initializer List?\n"
        "   When is it REQUIRED vs just preferred?"
    );

    class Point {
        const int x;     // const member
        const int y;     // const member
        int& ref;        // reference member
    public:
        int extra;
        // MUST use initializer list for const and reference members
        Point(int xVal, int yVal, int& r)
            : x(xVal), y(yVal), ref(r), extra(0) {
            // x = xVal;   // ❌ CANNOT assign to const inside body
            // ref = r;    // ❌ CANNOT rebind reference inside body
        }
        void show() {
            cout << "  Point(" << x << ", " << y << ")" << endl;
        }
    };

    cout << GREEN << "\n[Running Q6 Code...]" << RESET << endl;
    int num = 99;
    Point p(10, 20, num);
    p.show();

    printLesson(
        "Initializer List:\n"
        "   REQUIRED for:\n"
        "   -> const member variables (can't assign after creation)\n"
        "   -> reference member variables (must bind at creation)\n"
        "   -> base class constructors\n"
        "   -> members without default constructors\n"
        "   PREFERRED always: more efficient than body assignment"
    );

    pauseAndContinue();
}

// ============================================================================
//                    SECTION 3: ACCESS SPECIFIERS & ENCAPSULATION
// ============================================================================

class MedicalRecord {
private:
    string patientName;
    int age;
    string diagnosis;
    double billAmount;

protected:
    string doctorName;
    string ward;

public:
    MedicalRecord(string pName, int pAge, string doc, string w) {
        patientName = pName;
        age         = pAge;
        doctorName  = doc;
        ward        = w;
        diagnosis   = "Pending";
        billAmount  = 0.0;
    }

    // Setters with validation
    bool setDiagnosis(string diag) {
        if (diag.empty()) {
            cout << "  ERROR: Diagnosis cannot be empty!" << endl;
            return false;
        }
        diagnosis = diag;
        return true;
    }

    bool addBill(double amount) {
        if (amount < 0) {
            cout << "  ERROR: Bill amount cannot be negative!" << endl;
            return false;
        }
        billAmount += amount;
        return true;
    }

    // Getters
    string getPatientName() const { return patientName; }
    int    getAge()         const { return age; }
    double getBillAmount()  const { return billAmount; }

    void displayPublicInfo() const {
        cout << "  Patient : " << patientName << endl;
        cout << "  Age     : " << age         << endl;
        cout << "  Doctor  : " << doctorName  << endl;
        cout << "  Ward    : " << ward        << endl;
    }

    void displayFullRecord() const {
        displayPublicInfo();
        cout << "  Diagnosis: " << diagnosis  << endl;
        cout << "  Bill     : $" << billAmount << endl;
    }
};

class Specialist : public MedicalRecord {
    string specialization;

public:
    Specialist(string pName, int pAge, string doc,
               string w, string spec)
        : MedicalRecord(pName, pAge, doc, w),
          specialization(spec) {}

    void showSpecialistInfo() {
        // Can access protected members
        cout << "  Doctor: " << doctorName         << endl;
        cout << "  Ward  : " << ward               << endl;
        cout << "  Spec  : " << specialization      << endl;
        // cout << patientName;  // ERROR: private!
    }
};

void section3_Encapsulation() {
    printHeader("SECTION 3: ACCESS SPECIFIERS & ENCAPSULATION");

    // Q7
    printQuestion(7,
        "What are private, protected, and public?\n"
        "   Build a MedicalRecord system showing WHY we need\n"
        "   encapsulation and what each specifier allows."
    );
    cout << GREEN << "\n[Running Q7 Code...]" << RESET << endl;

    MedicalRecord record("John Doe", 35, "Dr. Smith", "ICU");
    record.displayPublicInfo();

    cout << "\n  --- Adding diagnosis and bill ---" << endl;
    record.setDiagnosis("Hypertension");
    record.addBill(500.0);
    record.addBill(-100.0);   // Will be rejected!
    record.addBill(200.0);

    cout << "\n  --- Full Record ---" << endl;
    record.displayFullRecord();

    // cout << record.patientName;   // ERROR: private
    // cout << record.doctorName;    // ERROR: protected
    cout << "\n  Accessed via getter: "
         << record.getPatientName() << endl;

    printLesson(
        "Access Specifiers:\n"
        "   PRIVATE   -> Only THIS class can access\n"
        "   PROTECTED -> This class + CHILD classes can access\n"
        "   PUBLIC    -> EVERYONE can access\n\n"
        "   WHY ENCAPSULATION?\n"
        "   -> Validation (can't set negative bill)\n"
        "   -> Protection (can't modify diagnosis directly)\n"
        "   -> Change internals without breaking external code"
    );

    pauseAndContinue();

    // Q8
    printQuestion(8,
        "Prove that protected works in child class but\n"
        "   not outside. Private NEVER accessible in child."
    );
    cout << GREEN << "\n[Running Q8 Code...]" << RESET << endl;

    Specialist spec("Jane Doe", 28, "Dr. Jones",
                    "Cardiology", "Heart Specialist");
    spec.showSpecialistInfo();

    printMemoryDiagram(
        "ACCESS TABLE:\n"
        "   Member         | Inside Class | Child Class | Outside\n"
        "   ---------------+--------------+-------------+--------\n"
        "   patientName    |     YES      |     NO      |   NO\n"
        "   doctorName     |     YES      |     YES     |   NO\n"
        "   getPatientName |     YES      |     YES     |   YES"
    );

    pauseAndContinue();

    // Q9: this pointer
    printQuestion(9,
        "What is the 'this' pointer?\n"
        "   Show: name conflict resolution + method chaining."
    );

    class Builder {
        string name;
        int floors;
        string material;
    public:
        Builder() : name(""), floors(0), material("") {}

        Builder& setName(string name) {
            this->name = name;  // this->name = member, name = param
            return *this;
        }
        Builder& setFloors(int floors) {
            this->floors = floors;
            return *this;
        }
        Builder& setMaterial(string material) {
            this->material = material;
            return *this;
        }
        void build() {
            cout << "  Building: " << name
                 << " | Floors: " << floors
                 << " | Material: " << material << endl;
        }
    };

    cout << GREEN << "\n[Running Q9 Code...]" << RESET << endl;
    Builder b;
    b.setName("Skyscraper")
     .setFloors(50)
     .setMaterial("Steel")
     .build();

    printLesson(
        "this Pointer:\n"
        "   -> Hidden pointer inside every non-static member function\n"
        "   -> Points to the CURRENT OBJECT calling the function\n"
        "   -> this->name = member variable\n"
        "   -> name alone = parameter (shadows member)\n"
        "   -> return *this = return current object (method chaining!)"
    );

    pauseAndContinue();
}

// ============================================================================
//                    SECTION 4: STATIC MEMBERS
// ============================================================================

class DatabaseConnection {
    static int activeConnections;
    static int totalCreated;
    static const int MAX_CONNECTIONS = 5;

    int connectionID;
    string connectionString;
    bool isActive;

public:
    DatabaseConnection(string connStr) {
        if (activeConnections >= MAX_CONNECTIONS) {
            cout << RED << "  ERROR: Max connections reached! ("
                 << MAX_CONNECTIONS << ")" << RESET << endl;
            isActive = false;
            connectionID = -1;
            connectionString = "REJECTED";
            return;
        }
        totalCreated++;
        connectionID     = totalCreated;
        connectionString = connStr;
        isActive         = true;
        activeConnections++;
        cout << GREEN << "  [CONN #" << connectionID << "] Connected to: "
             << connStr << " | Active: " << activeConnections
             << RESET << endl;
    }

    ~DatabaseConnection() {
        if (isActive) {
            activeConnections--;
            cout << RED << "  [CONN #" << connectionID
                 << "] Disconnected | Active: "
                 << activeConnections << RESET << endl;
        }
    }

    static int  getActiveConnections() { return activeConnections; }
    static int  getTotalCreated()      { return totalCreated; }
    static int  getMaxConnections()    { return MAX_CONNECTIONS; }
    bool        getIsActive()    const { return isActive; }
    int         getID()          const { return connectionID; }
};

int DatabaseConnection::activeConnections = 0;
int DatabaseConnection::totalCreated      = 0;

void section4_Static() {
    printHeader("SECTION 4: STATIC MEMBERS");

    // Q10
    printQuestion(10,
        "What is a static member variable?\n"
        "   Prove it's SHARED across all objects.\n"
        "   Build a connection pool with max limit."
    );
    cout << GREEN << "\n[Running Q10 Code...]" << RESET << endl;

    cout << "  Active: " << DatabaseConnection::getActiveConnections() << endl;

    DatabaseConnection* db1 = new DatabaseConnection("MySQL://localhost");
    DatabaseConnection* db2 = new DatabaseConnection("PostgreSQL://server");
    DatabaseConnection* db3 = new DatabaseConnection("MongoDB://cloud");

    cout << "\n  [Creating inner scope connections]" << endl;
    {
        DatabaseConnection db4("Redis://cache");
        DatabaseConnection db5("SQLite://local");
        DatabaseConnection db6("Oracle://enterprise"); // Should be rejected!

        cout << "\n  Peak active: "
             << DatabaseConnection::getActiveConnections() << endl;
    }
    cout << "\n  After inner scope: "
         << DatabaseConnection::getActiveConnections() << endl;

    delete db1;
    delete db2;
    delete db3;

    cout << "\n  Final Stats:" << endl;
    cout << "  Total ever created : "
         << DatabaseConnection::getTotalCreated() << endl;
    cout << "  Currently active   : "
         << DatabaseConnection::getActiveConnections() << endl;

    printLesson(
        "Static Members:\n"
        "   -> ONE COPY shared by ALL objects of the class\n"
        "   -> Exists even when NO objects exist\n"
        "   -> Access via ClassName::member (no object needed)\n"
        "   -> Static functions can ONLY access static members\n"
        "   -> Must INITIALIZE outside class: int DB::count = 0;\n"
        "   -> static const int can be initialized inside class"
    );

    pauseAndContinue();
}

// ============================================================================
//                    SECTION 5: INHERITANCE (ALL TYPES)
// ============================================================================

// ----- Base Classes -----
class Vehicle {
protected:
    string brand;
    int    year;
    double fuelLevel;

public:
    Vehicle(string b, int y) : brand(b), year(y), fuelLevel(100.0) {
        cout << CYAN << "  [Vehicle] " << brand << " created" << RESET << endl;
    }

    virtual void start() {
        cout << "  " << brand << ": Engine starting..." << endl;
    }

    void refuel(double amount) {
        fuelLevel = min(100.0, fuelLevel + amount);
        cout << "  Refueled! Level: " << fuelLevel << "%" << endl;
    }

    virtual void displayInfo() {
        cout << "  Brand: " << brand << " | Year: " << year
             << " | Fuel: " << fuelLevel << "%" << endl;
    }

    virtual string getType() { return "Vehicle"; }

    virtual ~Vehicle() {
        cout << RED << "  [Vehicle] " << brand << " destroyed" << RESET << endl;
    }
};

// Single Inheritance
class Car_V : public Vehicle {
    int doors;
    string fuelType;

public:
    Car_V(string b, int y, int d, string ft)
        : Vehicle(b, y), doors(d), fuelType(ft) {
        cout << CYAN << "  [Car] " << brand << " created" << RESET << endl;
    }

    void start() override {
        cout << "  " << brand << ": Car ignition! Vroom! 🚗" << endl;
    }

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "  Doors: " << doors << " | Fuel: " << fuelType << endl;
    }

    string getType() override { return "Car"; }

    ~Car_V() {
        cout << RED << "  [Car] " << brand << " destroyed" << RESET << endl;
    }
};

// Multilevel Inheritance
class ElectricCar : public Car_V {
    int batteryLevel;
    int range;

public:
    ElectricCar(string b, int y)
        : Car_V(b, y, 4, "Electric"), batteryLevel(100), range(400) {
        cout << CYAN << "  [ElectricCar] " << brand << " created" << RESET << endl;
    }

    void start() override {
        cout << "  " << brand << ": Electric motor ON! Silent start 🔋" << endl;
    }

    void charge(int percent) {
        batteryLevel = min(100, batteryLevel + percent);
        cout << "  Charging... Battery: " << batteryLevel << "%" << endl;
    }

    void displayInfo() override {
        Car_V::displayInfo();
        cout << "  Battery: " << batteryLevel
             << "% | Range: " << range << "km" << endl;
    }

    string getType() override { return "Electric Car"; }

    ~ElectricCar() {
        cout << RED << "  [ElectricCar] " << brand << " destroyed" << RESET << endl;
    }
};

// Multiple Inheritance
class GPS {
protected:
    double latitude;
    double longitude;

public:
    GPS(double lat, double lon) : latitude(lat), longitude(lon) {
        cout << CYAN << "  [GPS] Initialized" << RESET << endl;
    }

    void navigate() {
        cout << "  GPS: Navigating to ("
             << latitude << ", " << longitude << ")" << endl;
    }

    virtual ~GPS() {
        cout << RED << "  [GPS] System off" << RESET << endl;
    }
};

class SmartCar : public Car_V, public GPS {
    string aiAssistant;

public:
    SmartCar(string b, int y, double lat, double lon)
        : Car_V(b, y, 4, "Hybrid"), GPS(lat, lon),
          aiAssistant("AutoPilot") {
        cout << CYAN << "  [SmartCar] " << brand << " created" << RESET << endl;
    }

    void start() override {
        cout << "  " << brand << ": AI starting... All systems GO! 🤖" << endl;
    }

    void displayInfo() override {
        Car_V::displayInfo();
        cout << "  AI: " << aiAssistant
             << " | GPS: (" << latitude << ", " << longitude << ")" << endl;
    }

    string getType() override { return "Smart Car"; }

    ~SmartCar() {
        cout << RED << "  [SmartCar] " << brand << " destroyed" << RESET << endl;
    }
};

void section5_Inheritance() {
    printHeader("SECTION 5: ALL TYPES OF INHERITANCE");

    // Q11: Single Inheritance
    printQuestion(11,
        "SINGLE INHERITANCE:\n"
        "   Car inherits from Vehicle.\n"
        "   Show constructor order, inherited methods,\n"
        "   and what child CANNOT access."
    );
    cout << GREEN << "\n[Running Q11 Code...]" << RESET << endl;
    {
        Car_V myCar("Toyota", 2023, 4, "Petrol");
        cout << endl;
        myCar.start();
        myCar.refuel(20);   // Inherited from Vehicle
        myCar.displayInfo();
        // myCar.fuelLevel;    // ERROR: protected
        // myCar.brand;        // ERROR: protected (accessible inside class)
    }
    printLesson(
        "Single Inheritance:\n"
        "   -> Child gets ALL non-private members of parent\n"
        "   -> Constructor order: PARENT first, CHILD second\n"
        "   -> Destructor order: CHILD first, PARENT second\n"
        "   -> protected = parent and child can access, outside cannot\n"
        "   -> private = ONLY parent class itself can access"
    );
    pauseAndContinue();

    // Q12: Multilevel Inheritance
    printQuestion(12,
        "MULTILEVEL INHERITANCE:\n"
        "   Vehicle -> Car -> ElectricCar (3 levels)\n"
        "   Show the complete constructor/destructor chain."
    );
    cout << GREEN << "\n[Running Q12 Code...]" << RESET << endl;
    {
        ElectricCar tesla("Tesla", 2024);
        cout << endl;
        tesla.start();
        tesla.charge(15);
        tesla.refuel(0);     // From Vehicle (2 levels up!)
        tesla.displayInfo();
        cout << endl;
        cout << "  Type: " << tesla.getType() << endl;
    }
    printLesson(
        "Multilevel Inheritance:\n"
        "   Vehicle -> Car -> ElectricCar\n"
        "   Constructor: Vehicle -> Car -> ElectricCar (top to bottom)\n"
        "   Destructor : ElectricCar -> Car -> Vehicle (bottom to top)\n"
        "   ElectricCar can use ALL methods from BOTH Vehicle and Car"
    );
    pauseAndContinue();

    // Q13: Multiple Inheritance
    printQuestion(13,
        "MULTIPLE INHERITANCE:\n"
        "   SmartCar inherits from BOTH Car AND GPS.\n"
        "   Show how it gets methods from both parents."
    );
    cout << GREEN << "\n[Running Q13 Code...]" << RESET << endl;
    {
        SmartCar smartCar("Mercedes", 2024, 40.7128, -74.0060);
        cout << endl;
        smartCar.start();
        smartCar.navigate();  // From GPS
        smartCar.refuel(10);  // From Vehicle (through Car)
        smartCar.displayInfo();
    }
    printLesson(
        "Multiple Inheritance:\n"
        "   -> Class inherits from TWO or more classes\n"
        "   -> Gets all methods from ALL parents\n"
        "   -> Syntax: class Child : public Parent1, public Parent2\n"
        "   -> DANGER: Diamond Problem when both parents share\n"
        "              a common grandparent! Use 'virtual' inheritance"
    );
    pauseAndContinue();

    // Q14: Diamond Problem
    printQuestion(14,
        "THE DIAMOND PROBLEM:\n"
        "   Show ambiguity without virtual inheritance.\n"
        "   Fix it with virtual keyword."
    );

    struct PowerUnit {
        int power = 100;
        void showPower() {
            cout << "  Power: " << power << "W" << endl;
        }
    };

    struct HybridEngine : virtual public PowerUnit {
        void engineMode() {
            cout << "  Hybrid Engine Mode" << endl;
        }
    };

    struct ElectricEngine : virtual public PowerUnit {
        void electricMode() {
            cout << "  Electric Engine Mode" << endl;
        }
    };

    struct DualEngine : public HybridEngine, public ElectricEngine {
        void display() {
            engineMode();
            electricMode();
            showPower();   // ✅ No ambiguity (virtual inheritance)
            // Without 'virtual': ERROR! Which PowerUnit?
        }
    };

    cout << GREEN << "\n[Running Q14 Code...]" << RESET << endl;
    DualEngine de;
    de.display();
    de.power = 200;    // One copy of PowerUnit!
    de.showPower();

    printMemoryDiagram(
        "WITHOUT virtual:          WITH virtual:\n"
        "   DualEngine               DualEngine\n"
        "   /        \\               /        \\\n"
        "  HEngine  EEngine        HEngine  EEngine\n"
        "     |         |              \\      /\n"
        "  Power     Power            PowerUnit\n"
        "  (copy1)  (copy2)           (ONE copy)\n"
        "  AMBIGUOUS!                 NO AMBIGUITY!"
    );
    pauseAndContinue();

    // Q15: Inheritance Access Modes
    printQuestion(15,
        "INHERITANCE ACCESS MODES:\n"
        "   What changes when you use public/protected/private\n"
        "   inheritance? Show the effect."
    );

    class Base15 {
    public:    int pub    = 1;
    protected: int prot   = 2;
    private:   int priv   = 3;
    public:
        void show() {
            cout << "  pub=" << pub
                 << " prot=" << prot
                 << " priv=" << priv << endl;
        }
    };

    class PublicChild    : public    Base15 {
    public:
        void test() {
            cout << "  PUBLIC inh   : pub=" << pub
                 << " prot=" << prot << endl;
            // priv: NOT accessible
        }
    };

    class ProtectedChild : protected Base15 {
    public:
        void test() {
            cout << "  PROTECTED inh: pub=" << pub
                 << " prot=" << prot << endl;
        }
    };

    class PrivateChild   : private   Base15 {
    public:
        void test() {
            cout << "  PRIVATE inh  : pub=" << pub
                 << " prot=" << prot << endl;
        }
    };

    cout << GREEN << "\n[Running Q15 Code...]" << RESET << endl;

    PublicChild    pc;
    ProtectedChild prc;
    PrivateChild   pvc;

    pc.test();
    prc.test();
    pvc.test();

    cout << "\n  Outside access:" << endl;
    cout << "  pc.pub   = " << pc.pub << " (accessible)" << endl;
    // prc.pub  // ERROR: became protected
    // pvc.pub  // ERROR: became private

    printMemoryDiagram(
        "MODE           | pub becomes | prot becomes | priv\n"
        "public         | public      | protected    | never\n"
        "protected      | protected   | protected    | never\n"
        "private        | private     | private      | never\n"
        "Inheritance mode = CEILING on access level"
    );
    pauseAndContinue();
}

// ============================================================================
//                    SECTION 6: POLYMORPHISM
// ============================================================================

// Abstract base for polymorphism demo
class Shape {
protected:
    string color;
    static int totalShapes;

public:
    Shape(string c) : color(c) {
        totalShapes++;
    }

    // Pure virtual functions
    virtual double area()      = 0;
    virtual double perimeter() = 0;
    virtual void   draw()      = 0;
    virtual string getType()   = 0;

    // Regular virtual
    virtual void displayInfo() {
        cout << "  [" << getType() << "] Color: " << color
             << " | Area: "      << area()
             << " | Perimeter: " << perimeter() << endl;
    }

    static int getTotalShapes() { return totalShapes; }

    virtual ~Shape() { totalShapes--; }
};
int Shape::totalShapes = 0;

class Circle_S : public Shape {
    double radius;
public:
    Circle_S(double r, string c) : Shape(c), radius(r) {}

    double area()      override { return 3.14159 * radius * radius; }
    double perimeter() override { return 2 * 3.14159 * radius; }
    void   draw()      override {
        cout << "  Drawing Circle ⭕ r=" << radius
             << " color=" << color << endl;
    }
    string getType()   override { return "Circle"; }
};

class Rectangle_S : public Shape {
    double length, width;
public:
    Rectangle_S(double l, double w, string c)
        : Shape(c), length(l), width(w) {}

    double area()      override { return length * width; }
    double perimeter() override { return 2 * (length + width); }
    void   draw()      override {
        cout << "  Drawing Rectangle 🟥 "
             << length << "x" << width
             << " color=" << color << endl;
    }
    string getType()   override { return "Rectangle"; }
};

class Triangle_S : public Shape {
    double a, b, c_s;
public:
    Triangle_S(double a, double b, double c, string col)
        : Shape(col), a(a), b(b), c_s(c) {}

    double area() override {
        double s = (a + b + c_s) / 2;
        return sqrt(s * (s-a) * (s-b) * (s-c_s));
    }
    double perimeter() override { return a + b + c_s; }
    void   draw()      override {
        cout << "  Drawing Triangle 🔺 sides: "
             << a << "," << b << "," << c_s
             << " color=" << color << endl;
    }
    string getType()   override { return "Triangle"; }
};

  class Money {
        long long cents;  // store as cents to avoid float issues
        string currency;
    public:
        Money(double amount, string curr = "USD")
            : cents((long long)(amount * 100)), currency(curr) {}

        Money operator+(const Money& other) const {
            return Money(cents / 100.0 + other.cents / 100.0, currency);
        }
        Money operator-(const Money& other) const {
            return Money(cents / 100.0 - other.cents / 100.0, currency);
        }
        Money operator*(double factor) const {
            return Money((cents * factor) / 100.0, currency);
        }
        bool operator==(const Money& other) const {
            return cents == other.cents && currency == other.currency;
        }
        bool operator>(const Money& other) const {
            return cents > other.cents;
        }
        bool operator<(const Money& other) const {
            return cents < other.cents;
        }
        friend ostream& operator<<(ostream& out, const Money& m) {
            out << m.currency << " " << m.cents / 100.0;
            return out;
        }
    };


void section6_Polymorphism() {
    printHeader("SECTION 6: POLYMORPHISM (COMPILE-TIME & RUNTIME)");

    // Q16: Function Overloading
    printQuestion(16,
        "COMPILE-TIME POLYMORPHISM: Function Overloading\n"
        "   Same function name, different parameters.\n"
        "   Compiler picks at COMPILE time."
    );

    class MathEngine {
    public:
        int    add(int a, int b)              { return a + b; }
        double add(double a, double b)        { return a + b; }
        int    add(int a, int b, int c)       { return a + b + c; }
        string add(string a, string b)        { return a + b; }
        double add(int a, double b)           { return a + b; }

        void print(int x)    { cout << "  int: "    << x << endl; }
        void print(double x) { cout << "  double: " << x << endl; }
        void print(string x) { cout << "  string: " << x << endl; }
        void print(bool x)   { cout << "  bool: "
                                    << (x ? "true" : "false") << endl; }
    };

    cout << GREEN << "\n[Running Q16 Code...]" << RESET << endl;
    MathEngine me;
    cout << "  add(2,3)        = " << me.add(2, 3)           << endl;
    cout << "  add(2.5, 3.5)   = " << me.add(2.5, 3.5)       << endl;
    cout << "  add(1,2,3)      = " << me.add(1, 2, 3)         << endl;
    cout << "  add(Hi, World)  = " << me.add("Hi ", "World")  << endl;
    cout << "\n  print variations:" << endl;
    me.print(42);
    me.print(3.14);
    me.print("Hello");
    me.print(true);

    printLesson(
        "Function Overloading:\n"
        "   -> Same name, different parameter LIST\n"
        "   -> Compiler resolves at COMPILE TIME\n"
        "   -> Can differ in: type, number, or order of params\n"
        "   -> CANNOT overload on return type alone!\n"
        "   -> This is called STATIC BINDING or EARLY BINDING"
    );
    pauseAndContinue();

    // Q17: Operator Overloading
    printQuestion(17,
        "OPERATOR OVERLOADING:\n"
        "   Make custom objects work with +, -, *, ==, <<\n"
        "   Build a Money class that handles currency."
    );


    cout << GREEN << "\n[Running Q17 Code...]" << RESET << endl;
    Money price(19.99);
    Money tax(2.50);
    Money discount(3.00);

    cout << "  Price    : " << price    << endl;
    cout << "  Tax      : " << tax      << endl;
    cout << "  Discount : " << discount << endl;

    Money total = price + tax - discount;
    cout << "  Total    : " << total    << endl;

    Money doubled = price * 2;
    cout << "  Doubled  : " << doubled  << endl;

    cout << "\n  Comparisons:" << endl;
    cout << "  price > tax?  " << (price > tax  ? "YES" : "NO") << endl;
    cout << "  price == tax? " << (price == tax ? "YES" : "NO") << endl;

    printLesson(
        "Operator Overloading:\n"
        "   -> Operators are just functions: operator+, operator==\n"
        "   -> Member function: left operand is current object\n"
        "   -> Friend function: needed when left operand is NOT the class\n"
        "     (like cout << obj requires: friend ostream& operator<<)\n"
        "   -> Cannot overload: :: . .* sizeof typeid"
    );
    pauseAndContinue();

    // Q18: Runtime Polymorphism
    printQuestion(18,
        "RUNTIME POLYMORPHISM: Virtual Functions\n"
        "   Prove that WITH virtual = correct function called\n"
        "   WITHOUT virtual = wrong function called (base version)"
    );

    class NoVirtual {
    public:
        void speak() { cout << "  NoVirtual BASE speaks" << endl; }
    };
    class NoVirtualChild : public NoVirtual {
    public:
        void speak() { cout << "  NoVirtual CHILD speaks" << endl; }
    };

    class WithVirtual {
    public:
        virtual void speak() {
            cout << "  WithVirtual BASE speaks" << endl;
        }
        virtual ~WithVirtual() {}
    };
    class WithVirtualChild : public WithVirtual {
    public:
        void speak() override {
            cout << "  WithVirtual CHILD speaks" << endl;
        }
    };

    cout << GREEN << "\n[Running Q18 Code...]" << RESET << endl;

    cout << "\n  --- WITHOUT virtual (WRONG!) ---" << endl;
    NoVirtual* ptr1 = new NoVirtualChild();
    ptr1->speak();  // Calls BASE version! (static binding)
    delete ptr1;

    cout << "\n  --- WITH virtual (CORRECT!) ---" << endl;
    WithVirtual* ptr2 = new WithVirtualChild();
    ptr2->speak();  // Calls CHILD version! (dynamic binding)
    delete ptr2;

    cout << "\n  --- Direct object (always correct) ---" << endl;
    NoVirtualChild  d1; d1.speak();
    WithVirtualChild d2; d2.speak();

    printMemoryDiagram(
        "WITHOUT virtual:                WITH virtual:\n"
        "  ptr is Animal*                  ptr is Animal*\n"
        "  compiler sees: Animal           runtime sees: Dog object\n"
        "  calls: Animal::speak()          follows vptr to vtable\n"
        "  WRONG!                          calls: Dog::speak()\n"
        "  STATIC BINDING                  CORRECT!\n"
        "  (compile time)                  DYNAMIC BINDING (runtime)"
    );
    pauseAndContinue();

    // Q19: Pure Virtual & Abstract Class
    printQuestion(19,
        "PURE VIRTUAL & ABSTRACT CLASS:\n"
        "   Shape is abstract. Circle, Rectangle, Triangle\n"
        "   all implement it. Show polymorphic behavior."
    );
    cout << GREEN << "\n[Running Q19 Code...]" << RESET << endl;

    // Shape s;  // ERROR! Cannot instantiate abstract class

    vector<Shape*> canvas;
    canvas.push_back(new Circle_S(5.0,    "Red"));
    canvas.push_back(new Rectangle_S(4, 6,"Blue"));
    canvas.push_back(new Triangle_S(3,4,5,"Green"));
    canvas.push_back(new Circle_S(3.0,    "Yellow"));
    canvas.push_back(new Rectangle_S(10,2,"Purple"));

    cout << "\n  === Drawing All Shapes ===" << endl;
    for (Shape* s : canvas) {
        s->draw();
    }

    cout << "\n  === Shape Info ===" << endl;
    for (Shape* s : canvas) {
        s->displayInfo();
    }

    cout << "\n  Total shapes: " << Shape::getTotalShapes() << endl;

    double totalArea = 0;
    for (Shape* s : canvas) totalArea += s->area();
    cout << "  Total area  : " << totalArea << endl;

    for (Shape* s : canvas) delete s;

    printLesson(
        "Pure Virtual & Abstract Class:\n"
        "   -> virtual void func() = 0;  makes it pure virtual\n"
        "   -> Class with ANY pure virtual = ABSTRACT CLASS\n"
        "   -> CANNOT create object of abstract class\n"
        "   -> CAN create POINTER/REFERENCE to abstract class\n"
        "   -> Child MUST implement ALL pure virtual functions\n"
        "     (or child also becomes abstract)\n"
        "   -> This is how you define an INTERFACE in C++"
    );
    pauseAndContinue();

    // Q20: Virtual Destructor
    printQuestion(20,
        "VIRTUAL DESTRUCTOR — WHY IS IT CRITICAL?\n"
        "   Prove that without virtual destructor,\n"
        "   MEMORY LEAKS occur when using base pointer."
    );

    class BadBase {
    public:
        int* data;
        BadBase() {
            data = new int[100];
            cout << "  BadBase: allocated 100 ints" << endl;
        }
        ~BadBase() {           // NOT virtual!
            delete[] data;
            cout << "  BadBase: freed" << endl;
        }
    };

    class BadChild : public BadBase {
    public:
        int* extraData;
        BadChild() {
            extraData = new int[500];
            cout << "  BadChild: allocated 500 ints" << endl;
        }
        ~BadChild() {
            delete[] extraData;
            cout << "  BadChild: freed" << endl;
        }
    };

    class GoodBase {
    public:
        int* data;
        GoodBase() {
            data = new int[100];
            cout << "  GoodBase: allocated 100 ints" << endl;
        }
        virtual ~GoodBase() {  // VIRTUAL!
            delete[] data;
            cout << "  GoodBase: freed" << endl;
        }
    };

    class GoodChild : public GoodBase {
    public:
        int* extraData;
        GoodChild() {
            extraData = new int[500];
            cout << "  GoodChild: allocated 500 ints" << endl;
        }
        ~GoodChild() {
            delete[] extraData;
            cout << "  GoodChild: freed" << endl;
        }
    };

    cout << GREEN << "\n[Running Q20 Code...]" << RESET << endl;

    cout << "\n  --- BAD: No virtual destructor (MEMORY LEAK!) ---" << endl;
    BadBase* bad = new BadChild();
    delete bad;  // Only BadBase destructor called! 500 ints LEAKED!

    cout << "\n  --- GOOD: Virtual destructor (NO LEAK) ---" << endl;
    GoodBase* good = new GoodChild();
    delete good; // Both destructors called!

    printLesson(
        "Virtual Destructor RULE:\n"
        "   -> If class has ANY virtual function -> make destructor virtual\n"
        "   -> Without virtual destructor + base pointer = MEMORY LEAK\n"
        "   -> delete base_ptr calls ONLY base destructor (no virtual)\n"
        "   -> delete base_ptr calls child THEN base (with virtual)\n"
        "   -> ALWAYS: virtual ~BaseClass() {} in any base class"
    );
    pauseAndContinue();
}

// ============================================================================
//                    SECTION 7: FRIEND & SPECIAL CONCEPTS
// ============================================================================

void section7_FriendAndSpecial() {
    printHeader("SECTION 7: FRIEND FUNCTIONS & SPECIAL CONCEPTS");

    // Q21: Friend Function
    printQuestion(21,
        "FRIEND FUNCTION:\n"
        "   Two classes need to access each other's private data.\n"
        "   Show friend function and friend class."
    );

    class Wallet;  // Forward declaration

    class Transaction {
        double amount;
        string type;
    public:
        Transaction(double a, string t) : amount(a), type(t) {}
        double getAmount() const { return amount; }
        string getType()   const { return type; }
        friend class Wallet;
    };

    // class Wallet {
    //     double balance;
    //     string owner;
    //     vector<string> history;

    // public:
    //     Wallet(string o, double b) : owner(o), balance(b) {}

    //     // Friend function — not a member, but can access private
    //     friend void auditWallet(const Wallet& w);

    //     void processTransaction(const Transaction& t) {
    //         // Can access Transaction's private data (friend class)
    //         if (t.type == "DEBIT") {
    //             if (t.amount > balance) {
    //                 cout << "  Insufficient funds!" << endl;
    //                 return;
    //             }
    //             balance -= t.amount;
    //         } else {
    //             balance += t.amount;
    //         }
    //         history.push_back(t.type + ": $" + to_string(t.amount));
    //         cout << "  Transaction done. Balance: $" << balance << endl;
    //     }

    //     void showHistory() {
    //         cout << "  Transaction History for " << owner << ":" << endl;
    //         for (const string& h : history) {
    //             cout << "    " << h << endl;
    //         }
    //     }
    // };

    // // Friend function definition
    // auto auditWallet = [](const Wallet& w) {
    //     // Accessing PRIVATE members!
    //     cout << "  AUDIT - Owner: "   << w.owner
    //          << " | Balance: $"       << w.balance
    //          << " | Transactions: "   << w.history.size() << endl;
    // };

    // cout << GREEN << "\n[Running Q21 Code...]" << RESET << endl;

    // Wallet myWallet("Alice", 1000.0);
    // Transaction t1(200.0, "CREDIT");
    // Transaction t2(500.0, "DEBIT");
    // Transaction t3(900.0, "DEBIT");   // Should fail

    // myWallet.processTransaction(t1);
    // myWallet.processTransaction(t2);
    // myWallet.processTransaction(t3);
    // myWallet.showHistory();
    // auditWallet(myWallet);

    printLesson(
        "Friend:\n"
        "   -> friend function: NOT a member, but has private access\n"
        "   -> friend class: ALL methods of that class have private access\n"
        "   -> Friendship is NOT inherited\n"
        "   -> Friendship is NOT mutual (A friends B ≠ B friends A)\n"
        "   -> Friendship is NOT transitive\n"
        "   -> Use sparingly! It breaks encapsulation"
    );
    pauseAndContinue();

    // Q22: const Correctness
    printQuestion(22,
        "CONST CORRECTNESS:\n"
        "   Show const member function, const object,\n"
        "   and mutable keyword."
    );

    class Temperature {
        double celsius;
        mutable int accessCount;  // mutable = can change even in const function

    public:
        Temperature(double c) : celsius(c), accessCount(0) {}

        // Const function — PROMISES not to modify anything
        double getCelsius() const {
            accessCount++;  // OK because mutable!
            return celsius;
        }
        double getFahrenheit() const {
            accessCount++;
            return celsius * 9.0 / 5.0 + 32;
        }
        double getKelvin() const {
            accessCount++;
            return celsius + 273.15;
        }
        int getAccessCount() const { return accessCount; }

        // Non-const function
        void setCelsius(double c) {
            celsius = c;
            accessCount = 0;
        }
    };

    cout << GREEN << "\n[Running Q22 Code...]" << RESET << endl;

    Temperature t(100.0);
    cout << "  Celsius   : " << t.getCelsius()    << endl;
    cout << "  Fahrenheit: " << t.getFahrenheit() << endl;
    cout << "  Kelvin    : " << t.getKelvin()     << endl;
    cout << "  Accessed  : " << t.getAccessCount() << " times" << endl;

    const Temperature freezing(0.0);
    cout << "\n  Const object:" << endl;
    cout << "  Freezing C : " << freezing.getCelsius()    << endl;
    cout << "  Freezing F : " << freezing.getFahrenheit() << endl;
    // freezing.setCelsius(50);  // ERROR! Cannot call non-const on const obj

    printLesson(
        "Const Correctness:\n"
        "   -> const function: add 'const' after params: void func() const\n"
        "   -> const object: can ONLY call const member functions\n"
        "   -> const function cannot modify member variables\n"
        "   -> mutable: exception — CAN be modified even in const function\n"
        "   -> Use for: access counters, cache, lazy evaluation\n"
        "   -> RULE: Make getters const. They shouldn't modify state."
    );
    pauseAndContinue();

    // Q23: Object Slicing
    printQuestion(23,
        "OBJECT SLICING — A Tricky Problem!\n"
        "   Show what happens when you assign derived to base\n"
        "   without pointer/reference."
    );

    class Animal23 {
    public:
        string name;
        Animal23(string n) : name(n) {}
        virtual void speak() {
            cout << "  [Animal] " << name << " speaks" << endl;
        }
    };

    class Dog23 : public Animal23 {
    public:
        string breed;
        Dog23(string n, string b) : Animal23(n), breed(b) {}
        void speak() override {
            cout << "  [Dog] " << name
                 << " (" << breed << ") says WOOF!" << endl;
        }
    };

    cout << GREEN << "\n[Running Q23 Code...]" << RESET << endl;

    Dog23 myDog("Buddy", "Labrador");

    cout << "\n  Direct object call:" << endl;
    myDog.speak();

    cout << "\n  ⚠️ Object slicing (copy to base):" << endl;
    Animal23 sliced = myDog;   // Dog SLICED to Animal! breed is LOST!
    sliced.speak();            // Calls Animal version!
    // cout << sliced.breed;  // ERROR! breed doesn't exist in Animal

    cout << "\n  ✅ Pointer (no slicing):" << endl;
    Animal23* ptr = &myDog;    // Pointer — no slicing!
    ptr->speak();              // Calls Dog version (virtual dispatch)

    cout << "\n  ✅ Reference (no slicing):" << endl;
    Animal23& ref = myDog;     // Reference — no slicing!
    ref.speak();               // Calls Dog version

    printLesson(
        "Object Slicing:\n"
        "   -> Happens when Derived object copied to Base variable\n"
        "   -> The 'extra' derived data is SLICED/CUT OFF\n"
        "   -> Virtual dispatch no longer works on sliced object\n"
        "   -> FIX: Use POINTER (Animal*) or REFERENCE (Animal&)\n"
        "   -> This is why we always use Base* ptr = new Derived()!"
    );
    pauseAndContinue();

    // Q24: dynamic_cast
    printQuestion(24,
        "DYNAMIC_CAST — Safe Downcasting:\n"
        "   How to safely convert Base* to Derived*\n"
        "   and check if it succeeded."
    );

    class Media {
    public:
        string title;
        Media(string t) : title(t) {}
        virtual void play() = 0;
        virtual ~Media() {}
    };

    class Song : public Media {
    public:
        string artist;
        int    durationSec;
        Song(string t, string a, int d)
            : Media(t), artist(a), durationSec(d) {}
        void play() override {
            cout << "  🎵 Playing: " << title
                 << " by " << artist << endl;
        }
    };

    class Video : public Media {
    public:
        int    width, height;
        Video(string t, int w, int h)
            : Media(t), width(w), height(h) {}
        void play() override {
            cout << "  🎬 Playing: " << title
                 << " (" << width << "x" << height << ")" << endl;
        }
    };

    cout << GREEN << "\n[Running Q24 Code...]" << RESET << endl;

    vector<Media*> playlist;
    playlist.push_back(new Song("Blinding Lights", "Weeknd", 200));
    playlist.push_back(new Video("Tutorial", 1920, 1080));
    playlist.push_back(new Song("Shape of You", "Ed Sheeran", 234));
    playlist.push_back(new Video("Movie", 3840, 2160));

    cout << "\n  Playing all:" << endl;
    for (Media* m : playlist) {
        m->play();
    }

    cout << "\n  Finding only Songs:" << endl;
    for (Media* m : playlist) {
        Song* s = dynamic_cast<Song*>(m);  // Safe downcast
        if (s != nullptr) {                 // returns nullptr if wrong type
            cout << "  Found song: " << s->title
                 << " | Artist: " << s->artist
                 << " | Duration: " << s->durationSec << "s" << endl;
        }
    }

    cout << "\n  Finding only Videos:" << endl;
    for (Media* m : playlist) {
        Video* v = dynamic_cast<Video*>(m);
        if (v != nullptr) {
            cout << "  Found video: " << v->title
                 << " | Resolution: " << v->width
                 << "x" << v->height << endl;
        }
    }

    for (Media* m : playlist) delete m;

    printLesson(
        "dynamic_cast:\n"
        "   -> Safe way to downcast Base* to Derived*\n"
        "   -> Returns nullptr if the cast is WRONG type\n"
        "   -> Requires VIRTUAL function in base class (RTTI)\n"
        "   -> static_cast: no check, faster, dangerous\n"
        "   -> dynamic_cast: runtime check, safer, slight overhead\n"
        "   -> Use when you need to call Derived-specific methods"
    );
    pauseAndContinue();
}

// ============================================================================
//                    SECTION 8: MEMORY & ADVANCED CONCEPTS
// ============================================================================

void section8_Memory() {
    printHeader("SECTION 8: MEMORY, SIZEOF & VPTR");

    // Q25: Object Sizes
    printQuestion(25,
        "SIZE OF OBJECTS IN MEMORY:\n"
        "   How big is an empty class? A class with virtual?\n"
        "   Where does vptr fit in?"
    );

    class Empty {};
    class OneInt      { int x; };
    class TwoInts     { int x, y; };
    class WithString  { string s; };
    class WithVirtual { virtual void f() {} };
    class Inherited   : public WithVirtual { int x; };

    cout << GREEN << "\n[Running Q25 Code...]" << RESET << endl;
    cout << "  sizeof(Empty)      = " << sizeof(Empty)      << " bytes" << endl;
    cout << "  sizeof(OneInt)     = " << sizeof(OneInt)      << " bytes" << endl;
    cout << "  sizeof(TwoInts)    = " << sizeof(TwoInts)     << " bytes" << endl;
    cout << "  sizeof(WithString) = " << sizeof(WithString)  << " bytes" << endl;
    cout << "  sizeof(WithVirtual)= " << sizeof(WithVirtual) << " bytes (has vptr!)" << endl;
    cout << "  sizeof(Inherited)  = " << sizeof(Inherited)   << " bytes" << endl;
    cout << "  sizeof(int*)       = " << sizeof(int*)         << " bytes (pointer)" << endl;
    cout << "  sizeof(int)        = " << sizeof(int)          << " bytes" << endl;
    cout << "  sizeof(double)     = " << sizeof(double)       << " bytes" << endl;

    printMemoryDiagram(
        "Empty class: 1 byte  (so each object has unique address)\n"
        "WithVirtual: 8 bytes (hidden vptr added by compiler)\n"
        "vptr = virtual pointer -> points to vtable\n"
        "vtable = table of function pointers for virtual functions\n\n"
        "Dog object in memory:\n"
        "  [vptr (8 bytes)] -> Dog's vtable -> speak(), ~Dog()\n"
        "  [name  (string)] \n"
        "  [age   (4 bytes)]\n"
        "  [breed (string)] <- Dog-specific\n"
        "  myPet (Animal*) on stack -> points to this heap block"
    );
    pauseAndContinue();

    // Q26: Stack vs Heap
    printQuestion(26,
        "STACK vs HEAP MEMORY:\n"
        "   Show the difference, when each is used,\n"
        "   and what Animal* myPet = new Dog() really means."
    );

    class Resource {
        string name;
        int*   data;
    public:
        Resource(string n, int size) : name(n) {
            data = new int[size];  // Allocates on HEAP
            cout << "  [" << name << "] Created, data at: " << data << endl;
        }
        void use() {
            cout << "  [" << name << "] Using resource" << endl;
        }
        ~Resource() {
            delete[] data;
            cout << "  [" << name << "] Destroyed, memory freed" << endl;
        }
    };

    cout << GREEN << "\n[Running Q26 Code...]" << RESET << endl;

    cout << "\n  --- STACK allocation (automatic) ---" << endl;
    {
        Resource r1("StackResource", 100);   // On stack
        r1.use();
        cout << "  r1 is at (stack): " << &r1 << endl;
    }  // r1 automatically destroyed here!
    cout << "  r1 already gone!" << endl;

    cout << "\n  --- HEAP allocation (manual) ---" << endl;
    Resource* r2 = new Resource("HeapResource", 100);  // On heap
    r2->use();
    cout << "  r2 ptr is at (stack): " << &r2 << endl;
    cout << "  r2 obj is at (heap) : " << r2  << endl;
    delete r2;        // Must manually delete!
    r2 = nullptr;     // Good habit!

    printMemoryDiagram(
        "Animal* myPet = new Dog('Buddy', 3);\n\n"
        "  STACK:                HEAP:\n"
        "  ┌──────────┐         ┌─────────────────────┐\n"
        "  │  myPet   │         │  Dog Object          │\n"
        "  │ 0xHEAP───┼────────►│  vptr -> Dog vtable  │\n"
        "  │ (8 bytes)│         │  name = 'Buddy'      │\n"
        "  └──────────┘         │  age  = 3            │\n"
        "                       │  breed = ???          │\n"
        "                       └─────────────────────┘\n\n"
        "  myPet sees Animal part only (pointer type = Animal*)\n"
        "  vptr makes virtual calls go to Dog's methods"
    );
    pauseAndContinue();
}

// ============================================================================
//                    SECTION 9: TRICKY EXAM QUESTIONS
// ============================================================================

class ParentS {
    public:
        static int count;
        ParentS() { count++; }
        ~ParentS() { count--; }
        static int getCount() { return count; }
    };
    int ParentS::count = 0;

void section9_TrickyQuestions() {
    printHeader("SECTION 9: TRICKY EXAM QUESTIONS - PREDICT THE OUTPUT");

    // Q27
    printQuestion(27,
        "TRICKY Q1: What is the output?\n"
        "   Constructor + Destructor order with member objects."
    );

    class Engine {
        string type;
    public:
        Engine(string t) : type(t) {
            cout << "  Engine(" << type << ") created" << endl;
        }
        ~Engine() {
            cout << "  Engine(" << type << ") destroyed" << endl;
        }
    };

    class Wheel {
        int num;
    public:
        Wheel(int n) : num(n) {
            cout << "  Wheel(" << num << ") created" << endl;
        }
        ~Wheel() {
            cout << "  Wheel(" << num << ") destroyed" << endl;
        }
    };

    class Truck {
        Engine engine;
        Wheel  wheel1;
        Wheel  wheel2;
    public:
        Truck() : engine("Diesel"), wheel1(1), wheel2(2) {
            cout << "  Truck created" << endl;
        }
        ~Truck() {
            cout << "  Truck destroyed" << endl;
        }
    };

    cout << GREEN << "\n[Running Q27 Code...]" << RESET << endl;
    cout << "  --- Creating Truck ---" << endl;
    {
        Truck t;
        cout << "  --- Using Truck ---" << endl;
    }
    cout << "  --- After scope ---" << endl;

    printAnswer(
        "Order:\n"
        "   CREATE: Engine -> Wheel(1) -> Wheel(2) -> Truck body\n"
        "           (members in DECLARATION order, then own body)\n"
        "   DESTROY: Truck body -> Wheel(2) -> Wheel(1) -> Engine\n"
        "            (EXACT REVERSE of creation order)"
    );
    pauseAndContinue();

    // Q28
    printQuestion(28,
        "TRICKY Q2: Without virtual — what gets called?"
    );

    class A28 {
    public:
        void show()         { cout << "  A::show()" << endl; }
        virtual void vShow(){ cout << "  A::vShow()" << endl; }
    };

    class B28 : public A28 {
    public:
        void show()          { cout << "  B::show()" << endl; }
        void vShow() override{ cout << "  B::vShow()" << endl; }
    };

    cout << GREEN << "\n[Running Q28 Code...]" << RESET << endl;

    B28  obj;
    A28* ptr = &obj;
    A28& ref = obj;

    cout << "  obj.show()  -> "; obj.show();    // B (direct)
    cout << "  ptr->show() -> "; ptr->show();   // A (no virtual, ptr type)
    cout << "  ref.show()  -> "; ref.show();    // A (no virtual, ref type)

    cout << endl;
    cout << "  obj.vShow()  -> "; obj.vShow();   // B (direct)
    cout << "  ptr->vShow() -> "; ptr->vShow();  // B (virtual! runtime)
    cout << "  ref.vShow()  -> "; ref.vShow();   // B (virtual! runtime)

    printAnswer(
        "Without virtual: pointer/reference TYPE decides\n"
        "With virtual:    object TYPE decides (runtime)"
    );
    pauseAndContinue();

    // Q29
    printQuestion(29,
        "TRICKY Q3: Can abstract class have constructor?\n"
        "   Can you have non-pure virtual in abstract class?"
    );

    class AbstractBase {
        string sharedData;
    public:
        // ✅ Abstract class CAN have constructor!
        AbstractBase(string data) : sharedData(data) {
            cout << "  AbstractBase constructor with: " << data << endl;
        }

        virtual void mustImplement() = 0;   // Pure virtual

        // ✅ Abstract class CAN have non-pure virtual!
        virtual void optional() {
            cout << "  AbstractBase::optional() - sharedData: "
                 << sharedData << endl;
        }

        // ✅ Abstract class CAN have regular functions!
        void regularFunc() {
            cout << "  AbstractBase::regularFunc()" << endl;
        }

        virtual ~AbstractBase() {
            cout << "  AbstractBase destructor" << endl;
        }
    };

    class Concrete : public AbstractBase {
    public:
        Concrete() : AbstractBase("SharedValue") {
            cout << "  Concrete constructor" << endl;
        }
        void mustImplement() override {
            cout << "  Concrete::mustImplement()" << endl;
        }
        ~Concrete() {
            cout << "  Concrete destructor" << endl;
        }
    };

    cout << GREEN << "\n[Running Q29 Code...]" << RESET << endl;
    // AbstractBase ab("test");  // ERROR! Can't instantiate abstract
    Concrete c;
    c.mustImplement();
    c.optional();         // Uses base version
    c.regularFunc();

    printAnswer(
        "YES! Abstract class CAN have:\n"
        "   -> Constructor (called when child is created)\n"
        "   -> Non-pure virtual functions (optional override)\n"
        "   -> Regular functions\n"
        "   -> Data members\n"
        "   It CANNOT be instantiated directly. That's the only rule."
    );
    pauseAndContinue();

    // Q30
    printQuestion(30,
        "TRICKY Q4: What happens with static in inheritance?\n"
        "   Is static shared between parent and child?"
    );



    class ChildS : public ParentS {
    public:
        ChildS() : ParentS() {}
    };

    cout << GREEN << "\n[Running Q30 Code...]" << RESET << endl;
    cout << "  Initial: " << ParentS::getCount() << endl;

    ParentS p1, p2;
    cout << "  After 2 Parents: " << ParentS::getCount() << endl;

    ChildS  c1, c2, c3;
    cout << "  After 3 Children: " << ParentS::getCount() << endl;
    cout << "  Via Child access : " << ChildS::getCount()  << endl;

    printAnswer(
        "Static IS shared between parent and child!\n"
        "   -> Child inherits parent's static member\n"
        "   -> Both ParentS::count and ChildS::count are SAME variable\n"
        "   -> Creating a child also triggers parent constructor\n"
        "   -> So the static count includes BOTH parent and child objects"
    );
    pauseAndContinue();

    // Q31
    printQuestion(31,
        "TRICKY Q5: Overriding vs Overloading vs Hiding.\n"
        "   What is function hiding? How is it different?"
    );

    class Base31 {
    public:
        virtual void func(int x) {
            cout << "  Base::func(int) = " << x << endl;
        }
        void func(string s) {
            cout << "  Base::func(string) = " << s << endl;
        }
    };

    class Child31 : public Base31 {
    public:
        // This OVERRIDES Base::func(int)
        void func(int x) override {
            cout << "  Child::func(int) = " << x * 2 << endl;
        }
        // This HIDES Base::func(string)!
        void func(double d) {
            cout << "  Child::func(double) = " << d << endl;
        }
    };

    cout << GREEN << "\n[Running Q31 Code...]" << RESET << endl;
    Child31 child;
    Base31* ptr31 = &child;

    ptr31->func(5);          // Child::func(int) — OVERRIDING (virtual)
    ptr31->func("hello");    // Base::func(string) — via base pointer
    child.func(10);          // Child::func(int)
    child.func(3.14);        // Child::func(double) — own version
    // child.func("world"); // ❌ HIDDEN! Child hid Base's string version

    // To access hidden base version:
    child.Base31::func("world");  // Explicitly call base version

    printAnswer(
        "Three different things:\n"
        "   OVERRIDING: Same signature, virtual in base -> runtime dispatch\n"
        "   OVERLOADING: Same name, different params -> compile time\n"
        "   HIDING: Child defines function with same name (different sig)\n"
        "           -> HIDES all base versions with that name!\n"
        "           -> Use Base::func() to explicitly call hidden version"
    );
    pauseAndContinue();
}

// ============================================================================
//                    SECTION 10: COMPLETE MINI PROJECT
// ============================================================================

// Abstract base
class LibraryItem {
protected:
    string title;
    string id;
    bool   isCheckedOut;
    string checkedOutBy;
    static int totalItems;

public:
    LibraryItem(string t, string i)
        : title(t), id(i), isCheckedOut(false), checkedOutBy("") {
        totalItems++;
    }

    virtual bool checkOut(string person) {
        if (isCheckedOut) {
            cout << "  '" << title << "' already checked out by "
                 << checkedOutBy << endl;
            return false;
        }
        isCheckedOut  = true;
        checkedOutBy  = person;
        cout << "  ✅ '" << title << "' checked out by " << person << endl;
        return true;
    }

    virtual bool returnItem() {
        if (!isCheckedOut) {
            cout << "  '" << title << "' was not checked out!" << endl;
            return false;
        }
        cout << "  ✅ '" << title << "' returned by " << checkedOutBy << endl;
        isCheckedOut = false;
        checkedOutBy = "";
        return true;
    }

    virtual void displayInfo() const = 0;
    virtual string getType()   const = 0;

    string getTitle() const { return title; }
    string getID()    const { return id; }
    bool   available()const { return !isCheckedOut; }

    static int getTotalItems() { return totalItems; }

    friend ostream& operator<<(ostream& out, const LibraryItem& item) {
        out << "[" << item.getType() << "] "
            << item.title << " (ID: " << item.id << ")"
            << (item.isCheckedOut ? " [CHECKED OUT by " + item.checkedOutBy + "]"
                                  : " [AVAILABLE]");
        return out;
    }

    virtual ~LibraryItem() { totalItems--; }
};
int LibraryItem::totalItems = 0;

class Book_L : public LibraryItem {
    string author;
    int    pages;
    string genre;

public:
    Book_L(string t, string id, string auth, int pg, string gen)
        : LibraryItem(t, id), author(auth), pages(pg), genre(gen) {}

    void displayInfo() const override {
        cout << "  📚 BOOK: " << title   << endl;
        cout << "     ID    : " << id     << endl;
        cout << "     Author: " << author << endl;
        cout << "     Pages : " << pages  << endl;
        cout << "     Genre : " << genre  << endl;
        cout << "     Status: " << (isCheckedOut
                                    ? "Out (by " + checkedOutBy + ")"
                                    : "Available") << endl;
    }

    string getType() const override { return "Book"; }
};

class DVD_L : public LibraryItem {
    string director;
    int    durationMin;
    string rating;

public:
    DVD_L(string t, string id, string dir, int dur, string rat)
        : LibraryItem(t, id), director(dir),
          durationMin(dur), rating(rat) {}

    void displayInfo() const override {
        cout << "  🎬 DVD: " << title      << endl;
        cout << "     ID      : " << id    << endl;
        cout << "     Director: " << director << endl;
        cout << "     Duration: " << durationMin << " min" << endl;
        cout << "     Rating  : " << rating << endl;
        cout << "     Status  : " << (isCheckedOut
                                      ? "Out (by " + checkedOutBy + ")"
                                      : "Available") << endl;
    }

    string getType() const override { return "DVD"; }
};

class Magazine_L : public LibraryItem {
    int    issueNumber;
    string month;

public:
    Magazine_L(string t, string id, int issue, string mon)
        : LibraryItem(t, id), issueNumber(issue), month(mon) {}

    // Magazines can only be read in-library
    bool checkOut(string person) override {
        cout << "  ❌ Magazines cannot be checked out! Read in-library only." << endl;
        return false;
    }

    void displayInfo() const override {
        cout << "  📰 MAGAZINE: " << title << endl;
        cout << "     ID    : " << id      << endl;
        cout << "     Issue : " << issueNumber << endl;
        cout << "     Month : " << month   << endl;
        cout << "     Status: IN-LIBRARY ONLY" << endl;
    }

    string getType() const override { return "Magazine"; }
};

class Library {
    vector<LibraryItem*> collection;
    string               libraryName;
    static int           totalCheckouts;

public:
    Library(string name) : libraryName(name) {
        cout << "\n  🏛️ Library '" << libraryName << "' opened!" << endl;
    }

    void addItem(LibraryItem* item) {
        collection.push_back(item);
        cout << "  Added: " << *item << endl;
    }

    bool checkOutItem(string id, string person) {
        for (LibraryItem* item : collection) {
            if (item->getID() == id) {
                if (item->checkOut(person)) {
                    totalCheckouts++;
                    return true;
                }
                return false;
            }
        }
        cout << "  ❌ Item ID " << id << " not found!" << endl;
        return false;
    }

    bool returnItem(string id) {
        for (LibraryItem* item : collection) {
            if (item->getID() == id)
                return item->returnItem();
        }
        cout << "  ❌ Item ID " << id << " not found!" << endl;
        return false;
    }

    void showAll() const {
        cout << "\n  === " << libraryName << " Collection ===" << endl;
        for (LibraryItem* item : collection) {
            cout << "  " << *item << endl;
        }
        cout << "  Total items: " << LibraryItem::getTotalItems() << endl;
    }

    void showAvailable() const {
        cout << "\n  === Available Items ===" << endl;
        for (LibraryItem* item : collection) {
            if (item->available()) {
                item->displayInfo();
                cout << endl;
            }
        }
    }

    void showByType(string type) const {
        cout << "\n  === " << type << "s ===" << endl;
        for (LibraryItem* item : collection) {
            if (item->getType() == type) {
                item->displayInfo();
                cout << endl;
            }
        }
    }

    static int getTotalCheckouts() { return totalCheckouts; }

    ~Library() {
        cout << "\n  🏛️ Library '" << libraryName << "' closing..." << endl;
        for (LibraryItem* item : collection) {
            delete item;
        }
        cout << "  Total checkouts ever: " << totalCheckouts << endl;
        cout << "  Library closed!" << endl;
    }
};
int Library::totalCheckouts = 0;

void section10_MiniProject() {
    printHeader("SECTION 10: COMPLETE MINI PROJECT — LIBRARY SYSTEM");

    printQuestion(32,
        "BUILD A LIBRARY MANAGEMENT SYSTEM using ALL concepts:\n"
        "   -> Abstract class (LibraryItem)\n"
        "   -> Inheritance (Book, DVD, Magazine)\n"
        "   -> Polymorphism (virtual displayInfo, checkOut)\n"
        "   -> Encapsulation (private data, controlled access)\n"
        "   -> Static members (totalItems, totalCheckouts)\n"
        "   -> Operator overloading (<<)\n"
        "   -> Override behavior (Magazine can't be checked out)\n"
        "   -> vector<LibraryItem*> (polymorphic collection)"
    );

    cout << GREEN << "\n[Running Q32 — Library System...]" << RESET << endl;

    Library lib("City Central Library");

    lib.addItem(new Book_L("The Great Gatsby",    "B001",
                           "F. Scott Fitzgerald", 180, "Classic"));
    lib.addItem(new Book_L("Clean Code",          "B002",
                           "Robert Martin",       464, "Tech"));
    lib.addItem(new DVD_L ("Inception",           "D001",
                           "Christopher Nolan",   148, "PG-13"));
    lib.addItem(new DVD_L ("The Matrix",          "D002",
                           "Wachowskis",          136, "R"));
    lib.addItem(new Magazine_L("National Geographic", "M001", 245, "January"));
    lib.addItem(new Magazine_L("Tech Monthly",    "M002", 89,  "March"));

    lib.showAll();

    cout << "\n  === Checkout Operations ===" << endl;
    lib.checkOutItem("B001", "Alice");
    lib.checkOutItem("D001", "Bob");
    lib.checkOutItem("M001", "Charlie");  // Should fail!
    lib.checkOutItem("B001", "Diana");    // Already out!
    lib.checkOutItem("B002", "Eve");
    lib.checkOutItem("XYZ",  "Frank");    // Not found!

    lib.showAll();

    cout << "\n  === Returning Items ===" << endl;
    lib.returnItem("B001");
    lib.returnItem("D001");

    lib.showAvailable();
    lib.showByType("Book");

    cout << "  Total checkouts so far: "
         << Library::getTotalCheckouts() << endl;

    printLesson(
        "This project used:\n"
        "   ✅ Abstract class    — LibraryItem (can't instantiate)\n"
        "   ✅ Pure virtual      — displayInfo() = 0, getType() = 0\n"
        "   ✅ Inheritance       — Book/DVD/Magazine : LibraryItem\n"
        "   ✅ Override          — Each class has own displayInfo\n"
        "   ✅ Polymorphism      — vector<LibraryItem*> stores all types\n"
        "   ✅ Encapsulation     — private data, controlled checkOut\n"
        "   ✅ Static members    — totalItems, totalCheckouts\n"
        "   ✅ Operator overload — operator<< for printing\n"
        "   ✅ Virtual destructor— proper cleanup chain\n"
        "   ✅ Method override   — Magazine overrides checkOut behavior"
    );
}

// ============================================================================
//                    HELPER FUNCTION IMPLEMENTATIONS
// ============================================================================

void pauseAndContinue() {
    cout << "\n" << YELLOW
         << "  ──────────────────────────────────────────" << endl
         << "  Press ENTER to continue to next question..."
         << RESET << endl;
    cin.ignore();
    cin.get();
    cout << endl;
}

void printHeader(string title) {
    int width = 60;
    string border(width, '=');
    cout << "\n" << BOLD << BLUE << border << endl;
    int padding = (width - title.length()) / 2;
    cout << string(padding, ' ') << title << endl;
    cout << border << RESET << endl << endl;
}

void printQuestion(int num, string question) {
    cout << BOLD << YELLOW
         << "❓ Q" << num << ": " << question
         << RESET << endl;
}

void printAnswer(string answer) {
    cout << "\n" << GREEN
         << "✅ ANSWER:\n  " << answer
         << RESET << endl;
}

void printOutput(string output) {
    cout << CYAN
         << "📺 OUTPUT:\n" << output
         << RESET << endl;
}

void printLesson(string lesson) {
    cout << "\n" << MAGENTA
         << "💡 LESSON:\n  " << lesson
         << RESET << endl;
}

void printMemoryDiagram(string diagram) {
    cout << "\n" << CYAN
         << "🧠 MEMORY:\n" << diagram
         << RESET << endl;
}

void printWarning(string warning) {
    cout << "\n" << RED
         << "⚠️  WARNING: " << warning
         << RESET << endl;
}

// ============================================================================
//                              MAIN MENU
// ============================================================================

void showMenu() {
    cout << BOLD << BLUE
         << "\n╔══════════════════════════════════════════════╗\n"
         << "║     C++ CLASSES — COMPLETE QUESTION BANK    ║\n"
         << "╠══════════════════════════════════════════════╣\n"
         << "║  1.  Basic Class & Objects              (Q1) ║\n"
         << "║  2.  Constructors & Destructors       (Q2-6) ║\n"
         << "║  3.  Encapsulation & Access          (Q7-9)  ║\n"
         << "║  4.  Static Members                   (Q10)  ║\n"
         << "║  5.  All Types of Inheritance        (Q11-15)║\n"
         << "║  6.  Polymorphism (All Types)        (Q16-20)║\n"
         << "║  7.  Friend & Special Concepts       (Q21-24)║\n"
         << "║  8.  Memory & sizeof                  (Q25-26)║\n"
         << "║  9.  Tricky Exam Questions           (Q27-31)║\n"
         << "║  10. Mini Project (Library System)    (Q32)  ║\n"
         << "║  0.  Run ALL sections                        ║\n"
         << "║  99. Exit                                    ║\n"
         << "╚══════════════════════════════════════════════╝\n"
         << RESET;
    cout << "\n  Enter choice: ";
}

int main() {
    cout << BOLD << GREEN
         << "\n╔══════════════════════════════════════════════╗\n"
         << "║   WELCOME TO C++ CLASSES DEEP DIVE          ║\n"
         << "║   Complete OOP Question Bank                 ║\n"
         << "║   Learn by Questions — Understand by Doing  ║\n"
         << "╚══════════════════════════════════════════════╝\n"
         << RESET;

    int choice = 0;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:  section1_BasicClass();      break;
            case 2:  section2_Constructors();    break;
            case 3:  section3_Encapsulation();   break;
            case 4:  section4_Static();          break;
            case 5:  section5_Inheritance();     break;
            case 6:  section6_Polymorphism();    break;
            case 7:  section7_FriendAndSpecial();break;
            case 8:  section8_Memory();          break;
            case 9:  section9_TrickyQuestions(); break;
            case 10: section10_MiniProject();    break;
            case 0:
                section1_BasicClass();
                section2_Constructors();
                section3_Encapsulation();
                section4_Static();
                section5_Inheritance();
                section6_Polymorphism();
                section7_FriendAndSpecial();
                section8_Memory();
                section9_TrickyQuestions();
                section10_MiniProject();
                break;
            case 99:
                cout << GREEN
                     << "\n  Thanks for learning C++ OOP!"
                     << "\n  Keep coding! 🚀\n"
                     << RESET << endl;
                break;
            default:
                cout << RED << "  Invalid choice!" << RESET << endl;
        }

    } while (choice != 99);

    return 0;
}