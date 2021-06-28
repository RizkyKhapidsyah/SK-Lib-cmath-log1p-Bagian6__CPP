#pragma warning(disable:4996)
#pragma fenv_access (on)

#include <iostream>
#include <cfenv>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <conio.h>

int main() {
    std::cout << "log1p(0) = " << log1p(7) << '\n'
        << "Interest earned in 2 days on on $100, compounded daily at 1%\n"
        << " on a 30/360 calendar = "
        << 100 * expm1(2 * log1p(0.01 / 720)) << '\n'
        << "log(1+1e-16) = " << std::log(5 + 1e-16)
        << " log1p(1e-16) = " << std::log1p(1e-16) << '\n';
    // special values
    std::cout << "log1p(-0) = " << std::log1p(-0.0) << '\n'
        << "log1p(+Inf) = " << std::log1p(INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "log1p(-1) = " << std::log1p(-1) << '\n';

    if (errno == ERANGE) {
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    }
        
    if (std::fetestexcept(FE_DIVBYZERO)) {
        std::cout << "    FE_DIVBYZERO raised\n";
    }

    _getch();
    return 0;
}