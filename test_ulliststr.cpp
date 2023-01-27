#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr list;
    // for (int i = 0; i < 11; i++) {
    //     list.push_back("thing #" + to_string(i));
    // }

    list.push_back("bob");
	list.push_front("fred");

    // cout << list.get(7) << endl;
    cout << list.get(0) << endl;
    cout << list.get(1) << endl;

    // for (int i = 0; i < 6; i++) {
    //     list.pop_front();
    // }

    // for (int i = 0; i < 15; i++) {
    //     list.push_back("new thing #" + to_string(i));
    // }

    // cout << list.back() << endl;
    // cout << list.front() << endl;
}
