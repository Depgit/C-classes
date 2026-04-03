#include <iostream>

using namespace std;



// if , else if then else
// #define ll long long
// #if , #ifdef , #ifndef
// if (condition) execute
// #if 0 false
// #if 1 true run
//
// #if 0/1
// #elif 0/1
// #endif
//
// if() code part ander hota h
// #endif
//
//




// struct dep { struct { struct }} void f() ;
// dep::nested
// dep d ; d.f();
// d.nested (x)
// d::nested (x)
//
//


#if 1
struct Student {
    string name;
    int age;
    float gpa;
};

int main() {
    // Student s2 ={};
    // int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    // std::cout <<s2.name<<" inside string "<<s2.age  << std::endl;
    Student s1 = {"Alice", 20, 3.8};
    Student* ptr = &s1;

    // a) Direct access (s1.__)
    // b) Pointer with arrow (ptr->__)
    // c) Pointer with dereference ((*ptr).__)


    return 0;
}
#endif

#if 0
struct Product {
    string name;
    double price;
};

int main() {
    Product inventory[3] = {
        {"Laptop", 999.99},
        {"Mouse", 29.99},
        {"Keyboard", 79.99}
    };

    // TASK: Calculate total price using:
    // a) Traditional for loop with index
    // b) Range-based for loop (auto)
    // c) Pointer arithmetic

    return 0;
}
#endif


#if 0
struct Address {
    string city;
    int zipcode;
};

struct Employee {
    string name;
    Address addr;
    Address* addrPtr;
};

int main() {
    Address office = {"New York", 10001};
    Employee emp = {"John", {"Boston", 02101}, &office};
    Employee* empPtr = &emp;

    // TASK: What is the output of each line?
    cout << emp.addr.city << endl;           // Line 1: ?
    cout << emp.addrPtr->zipcode << endl;    // Line 2: ?
    cout << empPtr->addr.city << endl;       // Line 3: ?
    cout << empPtr->addrPtr->city << endl;   // Line 4: ?

    return 0;
}
#endif

#if 0
struct GPS {
    double latitude;
    double longitude;
};

struct Location {
    string name;
    GPS coordinates;
};

struct Branch {
    int id;
    Location loc;
};

struct Company {
    string companyName;
    Branch headquarters;
    Branch* branches;
    int branchCount;
};

int main() {
    Branch allBranches[2] = {
        {1, {"Downtown", {40.7128, -74.0060}}},
        {2, {"Uptown", {40.7831, -73.9712}}}
    };

    Company corp = {
        "TechCorp",
        {0, {"Main HQ", {40.7589, -73.9851}}},
        allBranches,
        2
    };

    Company* cPtr = &corp;

    // TASK: Fill in the blanks to access the latitude of:

    // a) Headquarters (using corp directly)
    double lat1 = ;

    // b) Headquarters (using cPtr)
    double lat2 = ;

    // c) First branch's latitude (using corp.branches)
    double lat3 = ;

    // d) Second branch's latitude (using cPtr)
    double lat4 = ;

    cout<<lat1<<endl<<lat2<<endl<<lat3<<endl<<lat4<<endl;

    return 0;
}
#endif

#if 0
int main() {
    int value = 42;
    int* p1 = &value;
    int** p2 = &p1;
    int*** p3 = &p2;

    // TASK: What does each expression evaluate to?

    cout << value << endl;      // a) ?
    cout << *p1 << endl;        // b) ?
    cout << **p2 << endl;       // c) ?
    cout << ***p3 << endl;      // d) ?
    cout << *p2 == p1 << endl;  // e) ?
    cout << **p3 == p1 << endl; // f) ?

    // BONUS: Modify 'value' to 100 using only p3
    _______ = 100;

    return 0;
}
#endif

#if 0
struct Node {
    int data;
    Node* next;
};

int main() {
    Node n3 = {30, nullptr};
    Node n2 = {20, &n3};
    Node n1 = {10, &n2};

    Node* ptr = &n1;
    Node** pptr = &ptr;

    // TASK: Access n3's data in 5 different ways:

    cout << _________________ << endl;  // Using n1
    cout << _________________ << endl;  // Using ptr
    cout << _________________ << endl;  // Using pptr
    cout << _________________ << endl;  // Using n2
    cout << _________________ << endl;  // Direct

    return 0;
}
#endif

#if 0
struct Department {
    string name;
    int employeeCount;

    struct Team {
        string teamName;
        int* memberIds;
        int size;

        void printMembers() {
            for(int i = 0; i < size; i++) {
                cout << memberIds[i] << " ";
            }
            cout << endl;
        }
    };

    Team* teams;
    int teamCount;

    // Constructor
    Department(string n, int count) : name(n), employeeCount(count) {
        teams = nullptr;
        teamCount = 0;
    }

    void addTeams(Team* t, int tc) {
        teams = t;
        teamCount = tc;
    }

    void displayAll() {
        cout << "Department: " << name << endl;
        for(int i = 0; i < teamCount; i++) {
            cout << "  Team: " << teams[i].teamName << " - Members: ";
            teams[i].printMembers();
        }
    }
};

int main() {
    // TASK: Complete the code to:
    // 1. Create a Department called "Engineering" with 50 employees
    // 2. Create 2 teams with the following data:
    //    - "Backend": member IDs {101, 102, 103}
    //    - "Frontend": member IDs {201, 202}
    // 3. Add teams to department and display all

    // Your code here:

    return 0;
}

// DETAILS
int main() {
    // Create department
    Department eng("Engineering", 50);

    // Create member arrays
    int backendIds[] = {101, 102, 103};
    int frontendIds[] = {201, 202};

    // Create teams array
    Department::Team allTeams[2] = {
        {"Backend", backendIds, 3},
        {"Frontend", frontendIds, 2}
    };

    // Add teams and display
    eng.addTeams(allTeams, 2);
    eng.displayAll();

    // Alternative using pointers:
    Department* engPtr = &eng;
    cout << "\nAccessing via pointer:" << endl;
    cout << engPtr->teams[0].teamName << endl;
    cout << engPtr->teams[0].memberIds[0] << endl;

    return 0;
}

#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

struct Skill {
    string name;
    int level;  // 1-10
};

struct Person {
    string name;
    Skill* skills;
    int skillCount;
    Person* mentor;  // Self-referential
};

struct Team {
    string teamName;
    Person** members;  // Array of pointers to Person
    int memberCount;

    Person* leader;
};

struct Division {
    string divisionName;
    Team* teams;
    int teamCount;

    // Find person with highest skill level in specific skill
    Person* findExpert(const string& skillName) {
        Person* expert = nullptr;
        int maxLevel = 0;

        for(int t = 0; t < teamCount; t++) {
            for(int m = 0; m < teams[t].memberCount; m++) {
                Person* p = teams[t].members[m];
                for(int s = 0; s < p->skillCount; s++) {
                    if(p->skills[s].name == skillName &&
                       p->skills[s].level > maxLevel) {
                        maxLevel = p->skills[s].level;
                        expert = p;
                    }
                }
            }
        }
        return expert;
    }
};

int main() {
    // Pre-built data
    Skill skills1[] = {{"C++", 9}, {"Python", 7}};
    Skill skills2[] = {{"C++", 6}, {"Java", 8}};
    Skill skills3[] = {{"Python", 10}, {"ML", 9}};

    Person alice = {"Alice", skills1, 2, nullptr};
    Person bob = {"Bob", skills2, 2, &alice};
    Person charlie = {"Charlie", skills3, 2, &alice};

    Person* team1Members[] = {&alice, &bob};
    Person* team2Members[] = {&charlie};

    Team teams[] = {
        {"Core", team1Members, 2, &alice},
        {"Research", team2Members, 1, &charlie}
    };

    Division techDiv = {"Technology", teams, 2};
    Division* divPtr = &techDiv;

    /* ========== TASKS ========== */

    // TASK 1: Print Alice's first skill name using divPtr
    // (Navigate: divPtr -> teams[0] -> members[0] -> skills[0] -> name)
    cout << "Task 1: " << _________________________ << endl;

    // TASK 2: Print Bob's mentor's name using divPtr
    cout << "Task 2: " << _________________________ << endl;

    // TASK 3: Print the team leader's name of "Research" team
    cout << "Task 3: " << _________________________ << endl;

    // TASK 4: Find and print the Python expert's name
    Person* pythonExpert = _________________________;
    cout << "Task 4: " << pythonExpert->name << endl;

    // TASK 5: Using range-based loop, print all team names
    cout << "Task 5: ";
    for(________________________) {
        cout << _________ << " ";
    }
    cout << endl;

    // TASK 6: Using pointer arithmetic, print all of Charlie's skills
    cout << "Task 6: ";
    for(Skill* s = _______; s < _______; _______) {
        cout << _______ << "(" << _______ << ") ";
    }
    cout << endl;

    return 0;
}
#endif

#if 0
struct X {
    int a;
    struct Y {
        int b;
        int* c;
    } y;
    Y* yPtr;
};

int main() {
    int val = 100;
    X x = {1, {2, &val}, nullptr};
    x.yPtr = &x.y;

    X* xp = &x;
    X** xpp = &xp;

    cout << x.y.b << endl;                    // 1) ?
    cout << *x.y.c << endl;                   // 2) ?
    cout << x.yPtr->b << endl;                // 3) ?
    cout << *x.yPtr->c << endl;               // 4) ?
    cout << xp->yPtr->b << endl;              // 5) ?
    cout << (*xpp)->y.b << endl;              // 6) ?
    cout << (*xpp)->yPtr->b << endl;          // 7) ?
    cout << *(*xpp)->yPtr->c << endl;         // 8) ?

    *x.y.c = 200;
    cout << val << endl;                       // 9) ?

    (*xpp)->yPtr->b = 999;
    cout << x.y.b << endl;                     // 10) ?

    return 0;
}
#endif

#if 0
int main() {

    return 0;
}
#endif
