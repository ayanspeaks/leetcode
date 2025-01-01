#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <set>
#include <iomanip>

using namespace std;


struct Wire {
    int x1, y1, x2, y2;
};


struct Point {
    int x, y;

   
    bool operator<(const Point& other) const {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};


bool doIntersect(Wire w1, Wire w2, Point& intersectionPoint) {
   
    int a1 = w1.y2 - w1.y1;
    int b1 = w1.x1 - w1.x2;
    int c1 = a1 * w1.x1 + b1 * w1.y1;

    
    int a2 = w2.y2 - w2.y1;
    int b2 = w2.x1 - w2.x2;
    int c2 = a2 * w2.x1 + b2 * w2.y1;

    int determinant = a1 * b2 - a2 * b1;

    if (determinant == 0) {
        return false;
    } else {
        
        double x = (double)(b2 * c1 - b1 * c2) / determinant;
        double y = (double)(a1 * c2 - a2 * c1) / determinant;

        
        if (min(w1.x1, w1.x2) - 1e-6 <= x && x <= max(w1.x1, w1.x2) + 1e-6 &&
            min(w1.y1, w1.y2) - 1e-6 <= y && y <= max(w1.y1, w1.y2) + 1e-6 &&
            min(w2.x1, w2.x2) - 1e-6 <= x && x <= max(w2.x1, w2.x2) + 1e-6 &&
            min(w2.y1, w2.y2) - 1e-6 <= y && y <= max(w2.y1, w2.y2) + 1e-6) {
            
            intersectionPoint.x = (int)round(x);
            intersectionPoint.y = (int)round(y);
            return true;
        } else {
            
            return false;
        }
    }
}

int computeCountOneSide(int x1, int y1, int x2, int y2) {
    int count = max(abs(x2 - x1), abs(y2 - y1));
    return max(1, count);
}

int main() {
    int N;
    cin >> N;
    vector<Wire> wires(N);

    
    for (int i = 0; i < N; ++i) {
        cin >> wires[i].x1 >> wires[i].y1 >> wires[i].x2 >> wires[i].y2;
    }

    cin.ignore(); 

    
    string animalData;
    getline(cin, animalData);
    map<string, int> animalThresholds;
    stringstream ss(animalData);
    string token;
    int totalAnimals = 0;
    while (ss >> token) {
        size_t pos = token.find(':');
        if (pos != string::npos) {
            string name = token.substr(0, pos);
            int threshold = stoi(token.substr(pos + 1));
            animalThresholds[name] = threshold;
            totalAnimals++;
        }
    }

    
    string animalTouched;
    getline(cin, animalTouched);

    
    map<Point, set<int>> intersectionPoints;

    
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            Point intersection;
            if (doIntersect(wires[i], wires[j], intersection)) {
                intersectionPoints[intersection].insert(i);
                intersectionPoints[intersection].insert(j);
            }
        }
    }

    
    int totalVoltage = 0;
    for (const auto& item : intersectionPoints) {
        Point intersection = item.first;
        const set<int>& wiresAtPoint = item.second;
        vector<int> counts;

        
        for (int wireIndex : wiresAtPoint) {
            Wire w = wires[wireIndex];

            
            if (!(w.x1 == intersection.x && w.y1 == intersection.y)) {
                int count1 = computeCountOneSide(intersection.x, intersection.y, w.x1, w.y1);
                counts.push_back(count1);
            }
            if (!(w.x2 == intersection.x && w.y2 == intersection.y)) {
                int count2 = computeCountOneSide(intersection.x, intersection.y, w.x2, w.y2);
                counts.push_back(count2);
            }
        }

        if (counts.empty()) {
            
            counts.push_back(1); 
        }

        
        int minCount = *min_element(counts.begin(), counts.end());

        
        int voltageAtPoint = wiresAtPoint.size() * minCount;

        
        totalVoltage += voltageAtPoint;
    }

    
    bool animalDies = false;
    if (animalThresholds.find(animalTouched) != animalThresholds.end()) {
        int threshold = animalThresholds[animalTouched];
        if (totalVoltage >= threshold) {
            animalDies = true;
        }
    }

    
    int animalsThatDie = 0;
    for (const auto& item : animalThresholds) {
        if (totalVoltage >= item.second) {
            animalsThatDie++;
        }
    }

    
    double probability = (double)animalsThatDie / totalAnimals;

    
    cout << (animalDies ? "Yes" : "No") << endl;
    cout << fixed << setprecision(2) << probability;

    return 0;
}