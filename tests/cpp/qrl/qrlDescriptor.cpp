// Distributed under the MIT software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.
#include <cstdint>
#include <qrlDescriptor.h>
#include "gtest/gtest.h"

namespace {

    TEST(QRL_Descriptor, checkAttributes1) {
        QRLDescriptor desc(
                eHashFunction::SHA2_256,
                eSignatureType::XMSS,
                10);

        EXPECT_TRUE(desc.getHashFunction() == eHashFunction::SHA2_256);
        EXPECT_TRUE(desc.getHashFunction() != eHashFunction::SHAKE_128);
        EXPECT_TRUE(desc.getSignatureType() == eSignatureType::XMSS);

        EXPECT_EQ(10, desc.getHeight());

        std::vector<uint8_t> expected_descriptor_bytes{0x00, 0x05};
        EXPECT_EQ(expected_descriptor_bytes, desc.getBytes());
    }

    TEST(QRL_Descriptor, checkAttributes2) {
        QRLDescriptor desc(
                eHashFunction::SHAKE_128,
                eSignatureType::XMSS,
                16);

        EXPECT_TRUE(desc.getHashFunction() != eHashFunction::SHA2_256);
        EXPECT_TRUE(desc.getHashFunction() == eHashFunction::SHAKE_128);
        EXPECT_TRUE(desc.getSignatureType() == eSignatureType::XMSS);
        EXPECT_EQ(16, desc.getHeight());

        std::vector<uint8_t> expected_descriptor_bytes{0x01, 0x08};
        EXPECT_EQ(expected_descriptor_bytes, desc.getBytes());
    }

    TEST(QRL_Descriptor, checkAttributesFromBytes) {
        QRLDescriptor desc = QRLDescriptor::fromBytes(0x01, 0x08);

        EXPECT_TRUE(desc.getHashFunction() != eHashFunction::SHA2_256);
        EXPECT_TRUE(desc.getHashFunction() == eHashFunction::SHAKE_128);
        EXPECT_TRUE(desc.getSignatureType() == eSignatureType::XMSS);
        EXPECT_EQ(16, desc.getHeight());

        std::vector<uint8_t> expected_descriptor_bytes{0x01, 0x08};
        EXPECT_EQ(expected_descriptor_bytes, desc.getBytes());
    }

}