#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <vector>
using namespace std;

bool iterationDone = false;

bool double_equals(double a, double b, double epsilon = 0.001){
    //cek dua variable double bernilai sama dengan pembulatan 0.001
    return abs(a - b) < epsilon;
}

double function(double x){ // masukkan fungsi integral disini
    return 1.75 * pow(x, 1.75);
}

double getH(double boundDiff, int rowIndex){ // H untuk operasi CTR
    double H = boundDiff / (pow(2, rowIndex-1));
    return H;
}

double romberg(double r1, double r2, int colIndex){ // general romberg solution
    double res = ((pow(4, colIndex-1) * r2) - r1) / (pow(4, colIndex-1) - 1);
    return res;
}

double CTR(double upperBound, double lowerBound, int rowIndex){ // composite trapezoidal rule
    double boundDiff = upperBound - lowerBound;
    double h = getH(boundDiff, rowIndex); 
    double res = function(lowerBound) + function(upperBound);

    double x = lowerBound + h;
    while(x != upperBound){
        res += 2 * function(x);
        x += h;
    }

    return (h/2)*res;
}

int main(){
    double lowerBound, upperBound;
    int iteration;

    cout << "Input integral lower bound:"; // batas bawah integeral
    cin >> lowerBound;
    cout << "Input integral upper bound:"; // batas atas integral
    cin >> upperBound;
    cout << "Input iteration: "; // jumlah baris matriks
    cin >> iteration;
   
    
    vector<double> store;
    double res;

    store.push_back(CTR(upperBound, lowerBound, 1));
    for (int rowIndex = 2; rowIndex <= iteration; rowIndex++){
        
        for (int colIndex = 1; colIndex <= rowIndex; colIndex++){
            int size = store.size();
        
            if (colIndex == 1){ // lakukan operasi CTR jika indeks kolom 1
                store.push_back(CTR(upperBound, lowerBound, rowIndex)); // simpan value ke dalam vector, nantinya digunakan untuk romberg
            }
            else { // jika lebih dari 1, maka lakukan operasi romberg
                res = romberg(store.at(size-rowIndex), store.at(size-1), colIndex);
                store.push_back(res);
            }
        }
        if(double_equals(store.at(store.size()-1), store.at(store.size()-rowIndex-1))){ 
            break;
        }
    }
    cout << store.at(store.size()-1) << endl;
    
    
}
