bool collinearity(const Pt& a, const Pt& b, const Pt& c){
    return (b - a) ^ (c - a) == 0;
}

bool collinearity(const Pt& a, const Pt& b, const Pt& c){
    return (b - a) ^ (c - a) < EPS;
}