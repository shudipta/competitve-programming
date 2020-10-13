/* 
# 13117 - ACIS, A Contagious vIruS

https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=5028&mosmsg=Submission+received+with+ID+25611251

## Category

2D Geometry, Lines, Segment

## Soln.

- Given polygon has n points and n sides too.
- Each side is denoted by (x_i, y_i) and (x_i+1, y_i+1); where 0 ≤ i < n.
  Special case is when i = n - 1.
  In which case the side is denot d by (x_n-1, y_n-1) and (x_0, y_0).
- Consider each side as a single line segement.
  A line segment is denoted by two points a and b.
- For each segment find the smallest distance of the current segment
  from REDIS point (x_r, y_r).
- The minimum of such distances is the final result (radius of the largest circle).
- All we need an algorithm or our own logic to find the smallest distance
  from a point to a line segments. One can easily find such algorithm on the web.
- Do a linear loop and find the smallest distance from point O to a line segment s.
  3 cases possible.
  - Case 01:
            o .   |
               \  |
                \ |__ Angle oab > 90 degree
                 \|__|____________
                  a               b
            smallest distance is length of oa.
  - Case 02:
                                  | o .
                                  |  /
         Angle oba > 90 degree  __| /
                   ____________|__|/
                  a               b       
            smallest distance is length of ob.
  - Case 03:
                        o .

                                    Angle oab ≤ Angle oba ≤ 90 degree
                   _______________
                  a               b
            smallest distance is perpendicular from o on ab
  Here, I have used vector calculation for the above algorithm.
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cassert>
#include <iomanip>

using namespace std;

const double EPS = 1e-9;
const int X_LIMIT = 50;
const int Y_LIMIT = 50;
const int N_MIN = 3;
const int N_MAX = 16;

#define AIN(x, a, b) assert((a) <= (x) && (x) <= (b))

struct Vector {
    int x, y;

    Vector(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    
    void input() {
        cin >> this->x >> this->y;
        AIN((int)this->x, 0, X_LIMIT);
        AIN((int)this->y, 0, Y_LIMIT);
    }

    // vector from a to b using syntax, b - a
    Vector operator -(const Vector& p) const {
        return Vector(p.x - this->x, p.y - this->y);
    }

    // dot product of vectors a and b using syntax, a * b
    int operator *(const Vector& p) const {
        return (this->x * p.x + this->y * p.y);
    }

    // cross product of vectors a and b using syntax, a % b
    int operator %(const Vector& p) const {
        return (this->x * p.y - p.x * this->y);
    }

    // abs returns the absolute value of the vector
    double abs() const {
        return sqrt(*this * *this);
    }
};

// (p . q), dot product of vectors p and q, where
//      p = oa, vector from o to a (o -> a)
//      q = ob, vector from o to b (o -> b)
int dotProduct(Vector o, Vector a, Vector b) {
    Vector p = a - o;
    Vector q = b - o;

    return (p * q);
}

// (p X q), cross product of vectors p and q, where
//      p = oa, vector from o to a (o -> a)
//      q = ob, vector from o to b (o -> b)
int crossProduct(Vector o, Vector a, Vector b) {
    Vector p = a - o;
    Vector q = b - o;

    return (p % q);
}

struct Segment
{
    /* data */
    Vector a, b;

    Segment(Vector a=Vector(), Vector b=Vector()) {
        this->a = a; this->b = b;
    }

    void input() {
        a.input();
        b.input();
    }

    double nearestDistanceFrom(Vector o) {
        if (dotProduct(a, b, o) < 0.0)
            return (a - o).abs();
        if (dotProduct(b, a, o) < 0.0)
            return (b - o).abs();
        return fabs(crossProduct(a, b, o)) / (a - b).abs();
    }
};

struct Acis {
    int n;
    Vector redis;
    vector<Vector> poly;

    Acis(int n=0) {
        this->n = n;
    }

    void input() {
        string nStr;
        cin >> nStr;
        if (nStr[0] == '*')
            return;

        n = stoi(nStr, nullptr, 10);

        AIN(this->n, N_MIN, N_MAX);
        redis.input();
        poly = vector<Vector>(n, Vector());
        for (int i = 0; i < n; i++) {
            poly[i].input();
        }
    }

    double findRadius() {
        double res = 1e9;
        poly.push_back(poly[0]);
        for (int i = 0; i < n; i++) {
            res = min(res, Segment(poly[i], poly[i + 1]).nearestDistanceFrom(redis));
        }

        return res;
    }
};


int main() {
    while (true) {
        Acis acis = Acis();
        acis.input();
        if (acis.n == 0) {
            break;
        }

        printf("%.3lf\n", acis.findRadius());
    }

    return 0;
}

/*
Sample Input
12
2 2
0 1
1 1
2 0
3 0
3 1
4 2
3 3
3 4
2 4
1 3
0 3
1 2
4
2 2
0 2
2 0
4 2
2 4
*
Sample Output
1.000
1.414
*/
