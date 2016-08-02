#include <iostream>
#include <vector>
using namespace std;

class Test {
    public:
        Test(int i): m(i) {
        }
        ~Test() {
            cout << "destructor "<< m <<endl;
        }
        int m;
};

int main(int argc, char *argv[]) {
    vector<Test> v;
    for (int i = 0; i < 5; ++i) {
        v.push_back(Test(i));
    }

    vector<Test>::iterator it;
#if 0
    // wrong
    for (it = v.begin(); it != v.end();) {
        v.erase(it++);
    }
#else
    // correct
    for (it = v.begin(); it != v.end(); ) {
        if (1) {
            it = v.erase(it);
        } else {
            ++it;
        }
    }
#endif
    cout << "over" << endl;
    return 0;
}
