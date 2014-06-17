bool isConvex(const vector<point>& P) {
	const size_t sz = P.size();
	if(sz <= 3) return false;
	if(!ccw(P[sz - 2], P[0], P[1])) return false;
	for(size_t i = 0; i < sz - 2; i++) {
		if(!ccw(P[i], P[i+1], P[i+2])) {
			return false;
		}
	}
	return true;
}
