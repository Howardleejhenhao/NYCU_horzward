#include <bits/extc++.h>
using namespace __gnu_pbds;
 
gp_hash_table<int, int> mp; // map
cc_hash_bable<int, int> mp2;

tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> s; // set

int main(){
    // Insert some entries into s.
    s.insert(12); s.insert(505);
    // The order of the keys should be: 12, 505.
    assert(*s.find_by_order(0) == 12);
    assert(*s.find_by_order(3) == 505);
    // The order of the keys should be: 12, 505.
    assert(s.order_of_key(12) == 0);
    assert(s.order_of_key(505) == 1);
    // Erase an entry.
    s.erase(12);
    // The order of the keys should be: 505.
    assert(*s.find_by_order(0) == 505);
    // The order of the keys should be: 505.
    assert(s.order_of_key(505) == 0);
    cout << s.size() << endl;
}
// 一種變形寫法

tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> s;
void solve()
{
    s.insert({x, i});
    s.erase(s.lower_bound({x, 0}));
    cout << s.order_of_key({x, 0}) + 1 << '\n';
    cout << s.find_by_order(x - 1) -> first << '\n';
    cout << prev(s.lower_bound({x, 0})) -> first << '\n';
    cout << s.lower_bound({x + 1, 0}) -> first << '\n';
}
