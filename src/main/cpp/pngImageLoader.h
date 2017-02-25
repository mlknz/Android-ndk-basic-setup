#ifndef __PNG_IMAGE_LOADER__
#define __PNG_IMAGE_LOADER__
#include <cstdint>
#include <string>

class AAssetManager;

struct ImageData {
  int img_width, img_height;
  uint8_t* pixels;

  virtual ~ImageData() {};
};

inline
bool IsPowerOfTwo(int n) {
  // http://www.exploringbinary.com/ten-ways-to-check-if-an-integer-is-a-power-of-two-in-c/
  return (n & (n - 1)) == 0;
}

inline
int NextPowerOfTwo(int n) {
  // Explanation : http://stackoverflow.com/questions/1322510/given-an-integer-how-do-i-find-the-next-largest-power-of-two-using-bit-twiddlin
  if (n < 0) {
    return 0;
  }
  n--;
  n |= n >> 1;   // Divide by 2^k for consecutive doublings of k up to 32,
  n |= n >> 2;   // and then or the results.
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n++;           // The result is a number of 1 bits equal to the number
                 // of bits in the original number, plus 1. That's the
                 // next highest power of 2.
  return n;
}

// Loads a PNG image from the asset directory
// Note that this REQUIRES that fname has a power-of-two size
ImageData* FromAssetPNGFile(AAssetManager* mgr, const std::string& fname);


#endif
