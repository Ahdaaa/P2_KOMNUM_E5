#include <iostream>
#include <math.h>
#include <vector>
#include <array>

using namespace std;

double function(double x){ // masukkan fungsi integral disini
    return 1/x;
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
   
    int rowIndex = 1, colIndex = 1;
    vector<double> store;
    double res;

    for (int i = 0; i < iteration; i++){
        int temp = rowIndex;
        for (int j = 0; j < temp; j++){
            int size = store.size();
        
            if (colIndex == 1){ // lakukan operasi CTR jika indeks kolom 1
                store.push_back(CTR(upperBound, lowerBound, rowIndex)); // simpan value ke dalam vector, nantinya digunakan untuk romberg
            }
            else { // jika lebih dari 1, maka lakukan operasi romberg
                res = romberg(store.at(size-rowIndex), store.at(size-1), colIndex);
                store.push_back(res);
            }

            if (colIndex == rowIndex) {
                ++rowIndex;
                colIndex = 1;}
            else ++colIndex;
        }
    }

   for (int i = 0; i < store.size(); i++){
        cout << store.at(i) << endl;
   }
}