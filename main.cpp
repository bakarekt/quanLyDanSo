#include <iostream>
using namespace std;

void swap(int a[2], int b[2]){
    for (int k = 0; k < 2; k++) {
        int temp = a[k];
        a[k] = b[k];
        b[k] = temp;
    }
}

int partition(int years[][2], int low, int high){
    int pivot = years[high][1];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if (years[j][1] < pivot){
            i++;
            swap(years[i], years[j]);
        }
    }
    swap(years[i + 1], years[high]);
    return i + 1;
}

void quickSort(int years[][2], int low, int high){
    if (low < high){
        int pi = partition(years, low, high);
        quickSort(years, low, pi - 1);
        quickSort(years, pi + 1, high);
    }
}

void yearsWithSameBirths(int years[][2], int n) {
    for (int i = 0; i < n; i++) {
        bool found = 0;
        int currentPeople = years[i][1];

        for (int j = i + 1; j < n; j++) {
            if (years[j][1] == currentPeople) {
                if (!found) {
                    cout <<  years[i][0];
                    found = true;
                }
                cout << ", " << years[j][0];
            }
        }

        if (found) {
            cout << " voi " << years[i][1] << " nguoi." << endl;
        }
    }
}

int main() {
    int years[][2] = {
        {1920, 19}, {1921, 77}, {1922, 40}, {1923, 90}, {1924, 2}, {1925, 25},
        {1926, 54}, {1927, 17}, {1928, 79}, {1929, 6}, {1930, 44}, {1931, 24},
        {1932, 14}, {1933, 4}, {1934, 95}, {1935, 47}, {1936, 66}, {1937, 48},
        {1938, 23}, {1939, 98}, {1940, 15}, {1941, 86}, {1942, 25}, {1943, 50},
        {1944, 9}, {1945, 29}, {1946, 64}, {1947, 3}, {1948, 67}, {1949, 4},
        {1950, 90}, {1951, 81}, {1952, 74}, {1953, 34}, {1954, 98}, {1955, 13},
        {1956, 87}, {1957, 96}, {1958, 56}, {1959, 90}, {1960, 49}, {1961, 85},
        {1962, 94}, {1963, 66}, {1964, 19}, {1965, 95}, {1966, 47}, {1967, 42},
        {1968, 65}, {1969, 87}, {1970, 11}
    };
    
    int size = sizeof(years) / sizeof(years[0]);

    quickSort(years, 0, size - 1);

    cout << "Nam co nhieu nguoi sinh ra nhat: " << endl;
    for (int i = 0; i < size; i++) {
        if(years[i][1] == years[size - 1][1]) {
            cout << years[i][0] << ", ";
        }
    }
    cout << "voi " << years[size - 1][1] << " nguoi\n";

    cout << "Nam co it nguoi sinh ra nhat: " << endl;
    for (int i = 0; i < size; i++) {
        if(years[i][1] == years[0][1]) {
            cout << years[i][0] << ", ";
        }
    }
    cout << "voi " << years[0][1] << " nguoi\n";

    cout << "Cac nam co cung so luong nguoi sinh ra: " << endl;
    yearsWithSameBirths(years, size);

    return 0;
}
