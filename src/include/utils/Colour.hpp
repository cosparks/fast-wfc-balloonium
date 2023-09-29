#ifndef FAST_WFC_UTILS_Colour_HPP_
#define FAST_WFC_UTILS_Colour_HPP_

#include <functional>

/**
 * Represent a 24-bit rgb Colour.
 */
struct Colour {
    unsigned char r, g, b;

    bool operator==(const Colour& c) const noexcept {
        return r == c.r && g == c.g && b == c.b;
    }

    bool operator!=(const Colour& c) const noexcept { return !(c == *this); }
};

/**
 * Hash function for Colour.
 */
namespace std {
    template <> class hash<Colour> {
    public:
        size_t operator()(const Colour& c) const {
            return (size_t)c.r + (size_t)256 * (size_t)c.g +
                (size_t)256 * (size_t)256 * (size_t)c.b;
        }
    };
} // namespace std

#endif // FAST_WFC_UTILS_Colour_HPP_
