// Distributed under the MIT software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.
#include <algsxmss.h>
#include <xmss.h>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include <misc.h>

// Direct access to XMSS-Reference
#include "randombytes.h"

namespace {
    TEST(XMSS_Reference, Correct_Linking) {
        unsigned char tmp[100];

        randombytes(tmp, 100);

        EXPECT_EQ(1, 1);
    }
}