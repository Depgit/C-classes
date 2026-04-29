#include <iostream>

using namespace std;

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
    Department::Team t2;
    t1->teamName = "frontend";
    t2.teamName = "backend";
    t2.memberIds = new int[3];
    int *arr = new int[3];

    //t2.memberIds = arr;
    // t2.memberIds = {101,102,103};
    t2.memberIds = arr;// arr[0] arr **arr
    int arr1[2] = {201,202};
    t1->memberIds = arr1;

    eng.addTeams(t1,1);
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

