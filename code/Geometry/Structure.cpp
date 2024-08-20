using TYPE = int;
struct Pt { 
    TYPE x, y; 
};

struct Line{ 
    Pt st, ed; 
};

struct Circle{ 
    Pt o; // center
    TYPE r; // radius
};

struct poly{
    int n; // n 邊形
    vector<Pt> pts; 
};