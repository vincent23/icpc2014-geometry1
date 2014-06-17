bool inPolygon(point pt, const vector<point>& P) {
	if(P.size() <= 3) return false;
	double sum = 0;
	for(size_t i = 0; i < P.size() - 1; i++) {
		const double phi = angle(P[i], pt, P[i+1]);
		if(ccw(pt, P[i], P[i+1])) {
			sum += phi;
		} else {
			sum -= phi;
		}
	}
	return abs((abs(sum) - 2 * PI) < EPS;
}
