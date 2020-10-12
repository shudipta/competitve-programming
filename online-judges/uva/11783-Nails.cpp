/* 
# Nails

http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2883

## Category

2D Geometry, Lines, Segment

## Soln.

- Consider each sticks as a single segement
- All we need an algorithm or our own logic to check intersection of two line segments
  One can easily find such algorithm on the web.
- Do N^2 loop and check for intersection of segment_i and segement_j
  - if intersects, then count as a nail
  - if for any segment no intersection is found then count 2 nails
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <iomanip>

using namespace std;

const double EPS = 1e-9;
const int X_LIMIT = 1000;
const int Y_LIMIT = 1000;
const int N_MIN = 0;
const int N_MAX = 1000;

#define AIN(x, a, b) assert((a) <= (x) && (x) <= (b))

struct Vector {
    double x, y;

    Vector(double x = 0.0, double y = 0.0) {
        this->x = x;
        this->y = y;
    }
    
    void input() {
        cin >> this->x >> this->y;
        AIN((double)this->x, 0, X_LIMIT);
        AIN((double)this->y, 0, Y_LIMIT);
    }

    // vector from a to b using syntax, b - a
    Vector operator -(const Vector& p) const {
        return Vector(p.x - this->x, p.y - this->y);
    }

    // cross product of vectors a and b using syntax, a % b
    double operator %(const Vector& p) const {
        return (this->x * p.y - p.x * this->y);
    }
};

// (p X q), cross product of vectors p and q, where
//      p = oa, vector from o to a (o -> a)
//      q = ob, vector from o to b (o -> b)
double crossProduct(Vector o, Vector a, Vector b) {
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

    bool onSegment(Vector o){
        if (fabs(crossProduct(o, a, b)) < EPS
            && (min(a.x, b.x) < EPS + o.x && o.x < EPS + max(a.x, b.x))
            && (min(a.y, b.y) < EPS + o.y && o.y < EPS + max(a.y, b.y)))
            return true;

        return false;
    }

    bool isIntersectWith(Segment segment) {
        double e = crossProduct(segment.a, a, b); // VCP(VB(a, c), VB(a, b));
        double f = crossProduct(segment.b, a, b); // VCP(VB(a, d), VB(a, b));
        double g = crossProduct(a, segment.a, segment.b); // VCP(VB(c, a), VB(c, d));
        double h = crossProduct(b, segment.a, segment.b); // VCP(VB(c, b), VB(c, d));

        if (e * f + EPS < 0.0 && g * h + EPS < 0.0)
            return true;
        if(fabs(e) < EPS && this->onSegment(segment.a))
            return true;
        if(fabs(f) < EPS && this->onSegment(segment.b))
            return true;
        if(fabs(g) < EPS && segment.onSegment(a))
            return true;
        if(fabs(h) < EPS && segment.onSegment(b))
            return true;
        
        return false;
    }
};

struct Nails {
    int n;
    vector<Segment> sticks;
    vector<bool> isNotAlone;

    Nails(int n=0) {
        this->n = n;
    }

    void input() {
        cin >> this->n;
        AIN(this->n, N_MIN, N_MAX);
        
        sticks = vector<Segment>(n, Segment(Vector(0, 0), Vector(0, 0)));
        isNotAlone = vector<bool>(n, false);
        
        for (int i = 0; i < n; i++) {
            sticks[i].input();
        }
    }

    int countNails() {
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sticks[i].isIntersectWith(sticks[j]))
                    res++, isNotAlone[i] = isNotAlone[j] = true;
            }

            res += 2 * !isNotAlone[i];
        }

        return res;
    }
};


int main() {
    while (true) {
        Nails nails = Nails();
        nails.input();
        if (nails.n == 0) {
            break;
        }

        cout << nails.countNails() << endl;
    }

    return 0;
}

/*
3
0 0 3 0
1 1 3 3
1 2 2 2
3
0 0 3 0
1 1 0 0
1 0 2 2
3
1 1 2 2
0 0 5 0
0 1 0 5
0
==========
3
2
6
*/
