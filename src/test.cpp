#include "tests.hpp"

int main(int argc, char** argv) {
    ft::vector<int>::iterator iter;
    ft::vector<int>::const_iterator const_iter;
    // should works
    const_iter = iter;
    // should not
    // iter = const_iter;
	if (argc != 2 )
	{
		std::cerr << "Usage: ./test some_data" << std::endl;
		std::cerr << "Provide a some_data please" << std::endl;
		return 1;
	}
    std::string data = argv[1];
    if (data.length() < 5){
		std::cerr << "data length must be 5 at least" << std::endl;
		return 1;
    }
    std::cout << "\t" << "My vector" << "\t" << "Std vector" << std::endl;

    vector_test(data);
    stack_test(data);
    map_test(data);
    return 0;
}

