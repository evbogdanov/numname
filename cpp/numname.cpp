#include "numname.hpp"
using numname::NumName;

// PUBLIC
// -----------------------------------------------------------------------------

string
NumName::get_name()
const
{
    return get_name(_num);
}

string
NumName::get_name(unsigned long long num)
const
{
    if (num >= QUINTILLION) return "error";
    if (num <= 99)          return get_0_99(num);
    return get_units(num, QUADRILLION);
}

// PRIVATE
// -----------------------------------------------------------------------------

string
NumName::get_unit_name(unsigned long long unit)
const
{
    switch (unit) {
    case QUADRILLION: return "quadrillion";
    case TRILLION:    return "trillion";
    case BILLION:     return "billion";
    case MILLION:     return "million";
    case THOUSAND:    return "thousand";
    case HUNDRED:     return "hundred";
    default:          return "";
    }
}

string
NumName::get_0_9(unsigned long long num)
const
{
    switch (num) {
    case 0:  return "zero";
    case 1:  return "one";
    case 2:  return "two";
    case 3:  return "three";
    case 4:  return "four";
    case 5:  return "five";
    case 6:  return "six";
    case 7:  return "seven";
    case 8:  return "eight";
    case 9:  return "nine";
    default: return "";
    }
}

string
NumName::get_10_19(unsigned long long num)
const
{
    switch (num) {
    case 10: return "ten";
    case 11: return "eleven";
    case 12: return "twelve";
    case 13: return "thirteen";
    case 14: return "fourteen";
    case 15: return "fifteen";
    case 16: return "sixteen";
    case 17: return "seventeen";
    case 18: return "eighteen";
    case 19: return "nineteen";
    default: return "";
    }
}

string
NumName::get_0_99(unsigned long long num)
const
{
    if (num <= 9)               return get_0_9(num);
    if (num >= 10 && num <= 19) return get_10_19(num);
    
    string ten;
    switch (num / 10) {
    case 2:
        ten = "twenty";
        break;
    case 3:
        ten = "thirty";
        break;
    case 4:
        ten = "forty";
        break;
    case 5:
        ten = "fifty";
        break;
    case 6:
        ten = "sixty";
        break;
    case 7:
        ten = "seventy";
        break;
    case 8:
        ten = "eighty";
        break;
    case 9:
        ten = "ninety";
        break;
    default:
        ten = "";
        break;
    }
    
    const unsigned long long rem = num % 10;
    if (rem != 0) return ten + "-" + get_0_9(rem);
    
    return ten;
}

string
NumName::get_units(unsigned long long num, unsigned long long unit)
const
{
    string name      = "";
    string unit_name = get_unit_name(unit);
    
    // Something wrong
    if (unit_name == "") return name;
    
    const unsigned long long div = num / unit;
    const unsigned long long rem = num % unit;
    
    if (div != 0) {
        if (unit == HUNDRED) name = get_0_9(div);
        else                 name = get_units(div, HUNDRED);
        name += " " + unit_name;
    }
    
    if (div != 0 && rem != 0) name += " ";
    
    if (rem != 0) {
        if (unit == HUNDRED)       name += get_0_99(rem);
        else if (unit == THOUSAND) name += get_units(rem, HUNDRED);
        else                       name += get_units(rem, unit / THOUSAND);
    }
    
    return name;
}
