using TYPE = int;
struct Pt {
    TYPE x, y;
    Pt(TYPE _x = 0, TYPE _y = 0):x(_x), y(_y) {}
    
    Pt operator+(const Pt &a){
        return Pt(x + a.x, y + a.y);
    }
    Pt operator-(const Pt &a){
        return Pt(x - a.x, y - a.y);
    }
    Pt operator*(const TYPE &a){
        return Pt(x * a, y * a);
    }
    Pt operator/(const TYPE &a){
        return Pt(x / a, y / a);
    }
    TYPE operator*(const Pt &a){ //計算幾何程式碼中內積通常用*表示
        return x * a.x + y * a.y;
    }
    TYPE operator^(const Pt &a){ //計算幾何程式碼中外積通常用^表示
        return x * a.y - y * a.x;
    }
    bool operator<(const Pt &a) const { // 判斷兩點座標 先比 x 再比 y
        return x < a.x || (x == a.x && y < a.y);
    }
};