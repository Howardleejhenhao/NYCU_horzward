bool inLine(const Pt& p, const Line& li){
    return collinearity(li.st, li.ed, p) && (li.st - p) * (li.ed - p) < 0;
}

bool inLine(const Pt& p, const Line& li){
    return collinearity(li.st, li.ed, p) && (li.st - p) * (li.ed - p) < EPS;
}