

#ifndef WORM_BASIC_H
#define WORM_BASIC_H

#include <vector>

namespace Worm {
namespace Common {

#ifdef DOUBLE_PRECISION
#define Real double
#else
#define Real float
#endif

}
}

#endif