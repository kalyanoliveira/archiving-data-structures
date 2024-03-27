#include <iostream>

#include "complete-bt.hpp"

int main(void) {
    CompleteBT<int> cbt;

    *cbt.get_root() = 7;

    std::cout << *cbt.get_root() << std::endl;

    cbt.add_last(8);
    cbt.add_last(9);

    std::cout << cbt.position_has_left(cbt.get_root()) << std::endl;
    
	return 0;
}
