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


#if 0
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
    Student* ptr = &s1;// ptr[0x45] ------> s1[0x10]
    std::cout <<s1.name  << std::endl;

    // int *ptr = &x;//   *-> value ---> &address
    // *ptr = 15;
    // ptr = &y;
    //
    // *ptr => vlaue
    (*ptr).name = "bob";
    // ptr.name = "bob";
    // a) Direct access (s1.__)
    // b) Pointer with arrow (ptr->__)
    // *ptr = s1{"bob"};
    std::cout <<s1.name  << std::endl;
    // c) Pointer with dereference ((*ptr).__)
    ptr->name = "dragon";

    std::cout <<s1.name  << std::endl;
    return 0;
}
#endif

#if 0
struct Product {
    string name;
    double price;
};

int main() {
    // int arr[2] = > 2 size int type array
    // dep d[2] => 2 size ka dep obj array ---. dep d ->[dep]  ===> dep d[2] ==> [d[0]] , [d[1]]

    // int arr[2][3] = {{1,2,3},{3,4,5}};
    // std::cout <<arr[0][1]  << std::endl;
// Product{name,price};
//Product{name,price};
//
    Product inventory[3] = {
        {"Laptop", 999.99},
        {"Mouse", 29.99},
        {"Keyboard", 79.99}
    };

    // std::cout <<inventory[0][1] << std::endl;

    // a) Traditional for loop with index
    // Product inven[3];
    // for(int i=0;i<3;i++){
        // std::cout <<"input for " << i << "th Product i.e. \n name and price "  << std::endl;
        // std::cin >> inven[i].name;
        // std::cin >> inven[i].price;
    // }

    // b) Range-based for loop (auto)
    // [[],[],[],[].......[]] ---> [[], [],[i],[]......[]]
    // int arr[10]; for(int i : arr)std::cout << i  << std::endl;
    // Product pro[3]; input Product ;
    // [ { name , price}, {name , price }, {name , price}]
    // a = 5;
    // std::cout <<a  << std::endl;
    // std::cout <<5  << std::endl;

    for(auto &i : inventory){
        std::cout <<i.name << " "<< i.price << std::endl;
    }
    // int arr[10];
    // arr ==> *arr
    // question ki kya me 10 len to kya me for se 5 tk hi iterate
    // me ye chahta hu ki me n *ptr se iterate 5 len tk hi
    // for(int i=0;i<2;i++)std::cout <<inventory[i].name<<" "<<inventory[i].price  << std::endl;
    // int arr[12];
    // int *p = arr;
    Product *p = inventory;
//    p = p + 1 ;



    // c) Pointer arithmetic
 //   p->0x45(let)-> p + 1 -> p + sizeof(p) ---> p0x77
// inventory(0x45) -> [{0x45},   {0x77} ,   {0x109}];
//                      ^
//                      p
//                                  ^
//                                  p         ^
//                                            p
//
//x => x + 4*i  => 0x4 , 0x8, 0x12 , 0x16 => arr[3] ==> arr[0] + 3*4; == 0x4 + 3*4 => 0x16
   // for(address p; p < &p + (3*32); p += 32)
    for(Product *p = inventory;p < inventory+1;p = p + 1){
        std::cout <<p->name<<" "<<p->price  << std::endl;
    }

    return 0;
}
#endif


#if 0
struct Address {
    string city;
    int zipcode;
};

const struct Employee {
   string name;
   Address addr;
   Address* addrPtr;
   Employee(){
         name = "john",
         addr = (Address){"Boston", 123123};
         addrPtr = &addr;
   }

} emp;
// line emp = &ox45 emp ()-> constructor
int main() {
    Address office = {"New York", 10001};
    // Employee emp = (Employee){"John", {"Boston", 02101}, &office};
     Employee emp1 = Employee{};
    // emp.addr.city = "New York";
    // emp type -> const struct Employee -> &emp = const struct Employee *
    // Employee -> struct Employee
    // Employee *empPtr = > struct Employee *
    //
    // Employee * empPtr = &emp;
    // struct Employee *  ===> const struct Emloyee *
    // const struct Employee * ===> const struct Employee *
    const Employee * empPtr = &emp;

    const Employee *const empPtr1 = &emp;
    // empPtr1 = &emp1;
    // const struct Employee * const empPtr1 () ==> const struct Employee *
    // const a = 5;
    //

    cout << emp.addr.city << endl;           // Line 1: ?
    // cout << emp.addrPtr->zipcode << endl;    // Line 2: ?
    // cout << empPtr->addr.city << endl;       // Line 3: ?
    // cout << empPtr->addrPtr->city << endl;   // Line 4: ?

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
// structure no significance
int main() {
     Branch allBranches[2] = {
         {1, {"Downtown", {40.7128, -74.0060}}},
         {2, {"Uptown", {40.7831, -73.9712}}}
     };

//   Branch allBranches = new Branch{};
//   allBranches = Branch{
//       1,{"Downtown", {40.7128,-74.0060}}
//   };
// arr[2] => &arr => arr
// int arr => &arr;
    Company corp = {
        "TechCorp",
        {0, {"Main HQ", {40.7589, -73.9851}}},
        allBranches,
        2
    };

    Company* cPtr = &corp;
// int *p => p->a;--> (*p).a --->  (p[0]).a
// corp.heatquart.loc.lat/long
    // a) branches (using corp directly)
    // double lat1 = (corp.branches[1]).loc.coordinates.latitude;  //allBranches[0].corp.lat;
    double lat2 = (cPtr->headquarters).loc.coordinates.latitude;
    std::cout <<lat2  << std::endl;
    // b) Headquarters (using cPtr)
    // double lat2 = ;

    // c) First branch's latitude (using corp.branches)
    // double lat3 = ;

    // d) Second branch's latitude (using cPtr)
    // double lat4 = ;

    // cout<<lat1<<endl<<lat2<<endl<<lat3<<endl<<lat4<<endl;

    return 0;
}
#endif

#if 0
int main() {
    int value = 42;
    int* p1 = &value;
    int** p2 = &p1;
    int*** p3 = &p2;


    cout << value << endl;      // a) ?
    cout << *p1 << endl;        // b) ?
    cout << **p2 << endl;       // c) ?
    cout << ***p3 << endl;      // d) ?
    cout << (*p2 == p1) << endl;  // e) ?
    cout << (**p3 == p1) << endl; // f) ?

    // BONUS: Modify 'value' to 100 using only p3
    ***p3 = 100;
    std::cout <<value  << std::endl;
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
    std::cout <<n1.next->next->data  << std::endl;
    std::cout <<ptr->next->next->data  << std::endl;
//     cout << _________________ << endl;  // Using n1
//     cout << _________________ << endl;  // Using ptr
//     cout << _________________ << endl;  // Using pptr
//     cout << _________________ << endl;  // Using n2
//     cout << _________________ << endl;  // Direct

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
//     Department(string n, int count) : name(n), employeeCount(count) {
//         teams = nullptr;
//         teamCount = 0;
//     }
     Department(string n, int count){
         name = n;
         employeeCount = count;teams = nullptr; teamCount = 0;
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

// Deparment eng(string n, int count){
//     return Deparment;
// }
// struct Team {
//     string name;
//     Team(string n){
//         name = n;
//     }
// };

int main() {

    // 1. Create a Department called "Engineering" with 50 employees
    // 2. Create 2 teams with the following data:
    //    - "Backend": member IDs {101, 102, 103}
    //    - "Frontend": member IDs {201, 202}
    // 3. Add teams to department and display all

    // Your code here:

//      Deparment Engineer(string n, int count){
//          name = n,employeeCount = 50;
//      };
     Department eng = Department("Engineering", 50);
    //int x = 5;
    //dep *d = &x;
     //Department *eng1 = new Department("Engineering", 50);
   // Department eng2 = Department{};
    // dep frontend = dep("frontend");
    // dep backend = dep("backend");
    //int  x =  5;
    // dep x = dep("frontend");
    // string y = "backend";

     // Team struct { }

    Department::Team *t1;
    Department::Team *t2;
    t1->teamName = "frontend";
    t2->teamName = "backend";
    // t2->memberIds = new int[3];
    int *arr = new int[3];

    //t2.memberIds = arr;
    t2->memberIds = new int[3]{101,102,103};
    // t2.memberIds = arr;// arr[0] arr **arr
    // int arr1[2] = {201,202};
    // t1->memberIds = arr1;

    eng.addTeams(t2,1);
    eng.displayAll();

    //t2.memberIds = 101;
//     //t2.memberIds++;
//     t2.memberIds = 102;
//     t2.memberIds++;
//     t2.memberIds = 103;
//
    // eng();
    //float y = 10.2345;
    // int x = int(y);
    return 0;
}
#endif

#if 0
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

#if 1
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

    std::cout << divPtr->teams[0].members[0]->mentor->name << std::endl; // Bob's mentor is Alice
    cout<< divPtr->teams[1].members[0]->skills[1].level<<endl;
    //  cout<< divPtr->teams[0].leader->name<<endl;
    //  Person* pythonExpert = divPtr->findExpert("Python");
    //  cout << pythonExpert->name << endl;

    //  cout<<"Team names: ";
// divPtr->teams
    // TASK 1: Print Alice's first skill name using divPtr
    // (Navigate: divPtr -> teams[0] -> members[0] -> skills[0] -> name)
    // cout << "Task 1: " << _________________________ << endl;

    // TASK 2: Print Bob's mentor's name using divPtr
    // cout << "Task 2: " << _________________________ << endl;

    // TASK 3: Print the team leader's name of "Research" team
    // cout << "Task 3: " << _________________________ << endl;

    // TASK 4: Find and print the Python expert's name
    // Person* pythonExpert = _________________________;
    // cout << "Task 4: " << pythonExpert->name << endl;

    // TASK 5: Using range-based loop, print all team names
    // cout << "Task 5: ";
//     for(________________________) {
//         cout << _________ << " ";
//     }
//     cout << endl;
//
//     // TASK 6: Using pointer arithmetic, print all of Charlie's skills
//     cout << "Task 6: ";
//     for(Skill* s = _______; s < _______; _______) {
//         cout << _______ << "(" << _______ << ") ";
//     }
//     cout << endl;

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
