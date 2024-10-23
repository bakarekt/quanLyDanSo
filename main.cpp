#include <iostream>
using namespace std;

void printYears(int data[][2], int size, int births) {
    for (int i = 0; i < size; i++) {
        if (data[i][1] == births) {
            cout << "Nam: " << data[i][0] << ", so luong sinh la: " << births << endl;
        }
    }
}

int findMaxYear(int data[][2], int size) {
    int maxBirths = data[0][1];
    for (int i = 1; i < size; i++) {
        if (data[i][1] > maxBirths) {
            maxBirths = data[i][1];
        }
    }
    return maxBirths;
}

int findMinYear(int data[][2], int size) {
    int minBirths = data[0][1];
    for (int i = 1; i < size; i++) {
        if (data[i][1] < minBirths) {
            minBirths = data[i][1];
        }
    }
    return minBirths;
}

void yearsWithSameBirths(int data[][2], int n) {
    for (int i = 0; i < n; i++) {
        bool found = 0;
        int currentPeople = data[i][1];

        for (int j = i + 1; j < n; j++) {
            if (data[j][1] == currentPeople) {
                if (!found) {
                    cout <<  data[i][0];
                    found = true;
                }
                cout << ", " << data[j][0];
            }
        }

        if (found) {
            cout << " voi " << data[i][1] << " nguoi." << endl;
        }
    }
}

int main() {
    int populationData[][2] = {
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
    
    int size = sizeof(populationData) / sizeof(populationData[0]);

    int maxBirths = findMaxYear(populationData, size);
    int minBirths = findMinYear(populationData, size);

    cout << "Cac nam co so luong sinh lon nhat: " << endl;
    printYears(populationData, size, maxBirths);

    cout << "Cac nam co so luong sinh nho nhat: " << endl;
    printYears(populationData, size, minBirths);

    cout << "Cac nam co cung so luong nguoi sinh ra: " << endl;
    yearsWithSameBirths(populationData, size);

    return 0;
}
