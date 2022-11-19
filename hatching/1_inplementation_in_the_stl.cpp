#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{ // crewation
    unordered_map<string, int> m;
    // insorsion;
    //    tarika 1
    pair<string, int> p = {"chetan", 1};
    m.insert(p);
    // tarika 2
    m["mera"] = 1;

    // ***********************************************************// find;********************************************************************************************************************************************
    /// tarika 1
    cout << m["mera"] << endl;
    cout << m.at("mera") << endl;
    // note if there is not any entry of m["mera"] it will create it and initialize with the 0;

    // size
    cout << m.size() << endl;
    // to check the presence
    cout << m.count("bro") << endl; // if there is any entry is regarding the bro so it will freturn 1 otherwise 0
    // errase
    m.erase("love");
    // if we  want to iterate the whole  map
    // tarika 1
    for (auto i : m)

    {
        cout << i.first << " " << i.second << endl;
    }
    // tarika 2
    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
}