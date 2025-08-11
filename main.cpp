#include <systemc.h>

SC_MODULE(Hello_SystemC) {
    SC_CTOR(Hello_SystemC) {
        SC_THREAD(print_message);
    }
    void print_message() {
        cout << "Hello, SystemC!" << endl;
    }
};

int sc_main(int argc, char* argv[]) {
    Hello_SystemC hello("hello");
    sc_start();
    return 0;
}
