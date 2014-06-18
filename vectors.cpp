struct point {
    double x, y;
    point() {x = 0; y = 0;}
    point(double _x, double _y) {x = _x; y = _y;}
};

struct vec {
    double x, y;
    vec(double _x, double _y) {x = _x; y = _y;}
};

vec toVector(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

//Skalieren
vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s);
}

//Verschieben
point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}

//Quadrat der euklidischen Norm
double normSquared(vec v) {
    return v.x * v.x + v.y * v.y;
}

//Skalarprodukt
double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}

//Kreuzprodukt
double cross(vec a, vec b) {
    return (a.x * b.y - a.y * b.x);
}

//CCW-Test
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

//Kollinear-Test
const double EPS = 1e-9;
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

//Winkel zwischen drei Punkten (in RAD)
double angle(point a, point o, point b) {
    vec oa = toVec(o, a);
    vec ob = toVec(o, b);
    
    return acos(dot(oa, ob) /
                sqrt(normSquared(oa) * normSquared(ob)));
}