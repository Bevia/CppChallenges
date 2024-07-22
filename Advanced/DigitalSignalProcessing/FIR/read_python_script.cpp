#include <iostream>
#include <cstdlib>   // for std::system

int main() {
    std::string python_script = "./Advanced/DigitalSignalProcessing/fir_response.py";
    int ret = std::system(("python3 " + python_script).c_str());
    if (ret != 0) {
        std::cerr << "Error: Failed to execute python script. Return code: " << ret << std::endl;
        return 1;
    } else {
        std::cout << "Python script executed successfully." << std::endl;
    }
    return 0;
}
