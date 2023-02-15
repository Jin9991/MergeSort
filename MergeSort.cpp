

#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"

using namespace std;
int comparisons = 0;
vector<Employee> syainhyo;


void merge(vector<Employee>& a, int p, int q, int r) {
    int nL = q - p + 1;
    int nR = r - q;
    //Employee** L = new Employee*[nL];
    //Employee** R = new Employee*[nR];
    vector<Employee> L(nL);
    vector<Employee> R(nR);
    for (int i = 0; i <= nL - 1; i++) {
        L[i] = a[p + i];
 
    }
    
    for (int j = 0; j <= nR - 1; j++) {
        R[j] = a[q + j + 1];
    }
    int i = 0;
    int j = 0;
    int k = p;
    while (i < nL && j < nR) {
        comparisons++;
        if (L[i].getId() <= R[j].getId()) {
            a[k] = L[i];
            i = i + 1;
        }
        else {
            a[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i < nL) {
        comparisons++;
        a[k] = L[i];
        i = i + 1;
        k = k + 1;
    }
    while (j < nR) {
        comparisons++;
        a[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
}


void mergeSort(vector<Employee>& a, int p, int r ) {
    if (p >= r) {
        return;
    }
    int q = (p + r) / 2;
    mergeSort(a, p, q);
    mergeSort(a, q + 1, r);
    merge(a, p, q, r);
    for (int k = 0; k < syainhyo.size(); k++) {//pritn out ID
        cout << syainhyo[k].getId() << " ";
    }
    cout << "\n";
}


int main(int argc, char** argv)
{
    if (argc == 1) {
        cout << "You forgot the command line parameter" << endl;
        exit(0);
    }

    ifstream ifs;
    ifs.open(argv[1], ios::in);
    if (!ifs) {
        cout << "could not find file " << argv[1] << endl;
        exit(0);
    }

    string yi;
    getline(ifs, yi);
    int n = stoi(yi);



    for (int i = 0; i < n; i++) {
        string name;
        int id;
        int age;
        string job;
        int year;
        
        getline(ifs, name, '|');
        getline(ifs, yi, '|');
        id = stoi(yi);
        getline(ifs, yi, '|');
        age = stoi(yi);
        getline(ifs, job, '|');
        getline(ifs, yi);
        year = stoi(yi);

        Employee syachiku = Employee(name, id, age, job, year);

        syainhyo.push_back(syachiku);
    }

    /*for (auto p : syainhyo) {
        p->pirntState();
    }*/

    

    mergeSort(syainhyo,0,n-1);
    




    //syainhyo[high].printResult();
    //cout << "at index " << high << " after " << comparison << " comparisons." << endl;
    //goukei += comparison;


    cout << "It tooks " << comparisons << " comparisons to sort the list." << endl; // the average 

    ofstream ofs;
    ofs.open("C:/Users/Jhin/source/repos/MergeSort/MergeSort/output.txt");
    ofs << "This is MergeSort output file. TY \n";
    for (auto p : syainhyo) {
        ofs << p.getName() << " | " << p.getId() << " | " << p.getAge() << " | " << p.getJob() << " | " << p.getYear() << endl;
    }
    ofs.close();


}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file