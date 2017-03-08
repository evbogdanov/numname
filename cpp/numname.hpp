#ifndef numname_hpp
#define numname_hpp

#include <string>
using std::string;

namespace numname {
////////////////////////////////////////////////////////////////////////////////

class NumName {
private:
    // Member variables
    unsigned long long _num;

    // Constants
    static const unsigned long long QUINTILLION = 1000000000000000000;
    static const unsigned long long QUADRILLION = 1000000000000000;
    static const unsigned long long    TRILLION = 1000000000000;
    static const unsigned long long     BILLION = 1000000000;
    static const unsigned long long     MILLION = 1000000;
    static const unsigned long long    THOUSAND = 1000;
    static const unsigned long long     HUNDRED = 100;
    
    // Private methods
    string get_unit_name(unsigned long long) const;
    string get_0_9(unsigned long long) const;
    string get_10_19(unsigned long long) const;
    string get_0_99(unsigned long long) const;
    string get_units(unsigned long long, unsigned long long) const;
    
public:
    NumName(unsigned long long num = 0) : _num(num) {};
    string get_name() const;
    string get_name(unsigned long long) const;
};

////////////////////////////////////////////////////////////////////////////////
}
    
#endif // numname_hpp
