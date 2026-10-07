#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class student
{
private:
    int id;
    string name;
    double grade;

public:
    void print()
    {
        cout << id << "|" << name << "|" << grade << endl;
    }
    // constructor bedy Initialization values ll variables gwa el private
    student(int s_id, string s_name, double s_grade)
    {
        id = s_id;
        name = s_name;
        grade = s_grade;
    }

    int getId() { return id; }
    string getName() { return name; }
    double getGrade() { return grade; }
};

void sortbygrade(vector<student> &students)
{ // & 3shan a8er trteb el main
    if (students.empty())
    {
        cout << "Not found any students to sort!\n";
        return; // btnhy el funct w trg3 ll main
    }

    // 3shan a3rf el 7gm
    int n = students.size();
    // Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // hqarn drgt el student b ell b3do
            if (students[j].getGrade() < students[j + 1].getGrade())
            {

                swap(students[j], students[j + 1]);
            }
        }
    }
    // h3rd b3d eltrteb
    for (int i = 0; i < n; i++)
    {
        cout << "Rank" << i + 1 << ":\n";
        students[i].print();
    }
}

int main()
{

    vector<student> students;
    int choice;

    do
    {
        cout << "\n----- Student Grades System -----\n";
        cout << "1. Add Student.\n";
        cout << "2. Display Students.\n";
        cout << "3. Sort by Grade (Descending) & Show Ranks.\n";
        cout << "4. Linear Search by Name.\n";
        cout << "5. Binary Search by ID.\n";
        cout << "6. Statistics (Highest, Lowest, Average).\n";
        cout << "7. Exit.\n";
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        { // ba5d el data
            int id;
            string name;
            double grade;

            cout << "Enter Id:";
            cin >> id;
            cout << "Enter Name:";
            cin.ignore(); // btndf el buffer
            getline(cin, name);
            cout << "Enter Grade:";
            cin >> grade;

            student s(id, name, grade);
            students.push_back(s); // 3shan ya5d el data e7tha f el vector 3ltol
            break;
        }

        case 2:
        {
            // lw el vector fady
            if (students.empty())
            {
                cout << "There is no students\n";
            }
            else
            {
                for (int i = 0; i < students.size(); i++)
                {
                    students[i].print(); // bnady funct el print ll student
                }
            }
            break;
        }

        case 3:
        {
            sortbygrade(students);
            break;
        }

        // liner search by name
        case 4:
        {
            // check lw fadya
            if (students.empty())
            {
                cout << "Students not found\n";
                break;
            }

            string searchName;
            cout << "Enter name to search: ";
            cin.ignore();
            getline(cin, searchName);

            int comparisons = 0; // 3dd elmoqarnat
            bool found = false;

            // loop llmoqarna
            for (int i = 0; i < students.size(); i++)
            {
                comparisons++;

                if (students[i].getName() == searchName)
                {
                    cout << "Student Found!\n";
                    students[i].print();
                    cout << "Comparisons count:" << comparisons << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Student not found!\n";
                cout << "Comparisons count: " << comparisons << endl;
            }
            break;
        }

        case 5:
        {
            // Binart search by ID
            // check lw fady
            if (students.empty())
            {
                cout << "Students not found\n";
                break;
            }

            int searchid;
            cout << "Enter student id:";
            cin >> searchid;

            // hrtb el id bnfs Bubble sort case 3
            int n = students.size();
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (students[j].getId() > students[j + 1].getId())
                    {
                        swap(students[j], students[j + 1]);
                    }
                }
            }
            int low = 0;                    // elbdaya
            int high = students.size() - 1; // elnhaya
            int comparisons = 0;            // 3dd elmoqarnat
            bool found = false;             // lw l2eto

            while (low <= high)
            {

                int mid; // elmtost
                mid = low + (high - low) / 2;
                comparisons++;

                if (students[mid].getId() == searchid)
                {
                    cout << "student:";
                    students[mid].print();
                    cout << "Comparisons:" << comparisons << endl;
                    found = true;
                    break;
                }

                if (searchid < students[mid].getId())
                { // lw a2l mn elmtlob

                    high = mid - 1; // b7rk elnhaya
                }
                else
                {                  // lw el id akbr
                    low = mid + 1; // b7rk elbdaya
                }
            }

            if (!found)
            { // lw msh mwgod
                cout << "Student not found!\n";
                cout << "Comparisons count: " << comparisons << endl;
            }
            break;
        }

        case 6:
        { // Statistics ll grade
            // check lw fadya
            if (students.empty())
            {
                cout << "Students not found\n";
                break;
            }
            // h7fz el index bta3 el a3la w a2l student 3shan a print 3ltol
            int highestidx = 0;
            int lowestidx = 0;
            double sum = 0; // 3shan a7sb beh el mid

            // h7sb el sum
            for (int i = 0; i < students.size(); i++)
            {
                sum += students[i].getGrade(); // bgm3 el grades

                // lw el currrent student a3la mn el a3la
                if (students[i].getGrade() > students[highestidx].getGrade())
                {
                    highestidx = i; // h updet el i
                }

                // lw el current a2l mn el a2l
                if (students[i].getGrade() < students[lowestidx].getGrade())
                {
                    lowestidx = i; // h updet el i
                }
            }
            // m7sb el mid
            double average = sum / students.size();

            // h PRINT el students
            cout << "Highest student:";
            students[highestidx].print();
            cout << "Lowest student:";
            students[lowestidx].print();
            cout << "Average grade:" << average << endl;

            break;
        }

        // Exit
        case 7:

            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 7);
    return 0;
}