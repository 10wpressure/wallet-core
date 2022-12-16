// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "Westend/Address.h"
#include "PublicKey.h"
#include "PrivateKey.h"
#include <gtest/gtest.h>
#include <vector>

namespace TW::Westend::tests {

TEST(WestendAddress, Valid) {
    // Substrate ed25519
    ASSERT_FALSE(Address::isValid("5FqqU2rytGPhcwQosKRtW1E3ha6BJKAjHgtcodh71dSyXhoZ"));
    // Polkadot ed25519
    ASSERT_FALSE(Address::isValid("15AeCjMpcSt3Fwa47jJBd7JzQ395Kr2cuyF5Zp4UBf1g9ony"));
    // Polkadot sr25519
    ASSERT_FALSE(Address::isValid("15AeCjMpcSt3Fwa47jJBd7JzQ395Kr2cuyF5Zp4UBf1g9ony"));
    // Bitcoin
    ASSERT_FALSE(Address::isValid("1ES14c7qLb5CYhLMUekctxLgc1FV2Ti9DA"));
    // Kusama ed25519
    ASSERT_FALSE(Address::isValid("FHKAe66mnbk8ke8zVWE9hFVFrJN1mprFPVmD5rrevotkcDZ"));
    // Kusama secp256k1
    ASSERT_FALSE(Address::isValid("FxQFyTorsjVsjjMyjdgq8w5vGx8LiA1qhWbRYcFijxKKchx"));
    // Kusama sr25519
    ASSERT_FALSE(Address::isValid("EJ5UJ12GShfh7EWrcNZFLiYU79oogdtXFUuDDZzk7Wb2vCe"));

    // Westend sr25519
    ASSERT_TRUE(Address::isValid("5FbtAUg6dhHWj5YbpbLFJBYgPJG3ekJghksvgskBNC7s3Yfv"));
    // Westend sr25519
    ASSERT_TRUE(Address::isValid("5DXm3vjyFAVVCkdgppsBAsn2AtqbHcxeTfYFGwibht1Aw97p"));
}

TEST(WestendAddress, FromPrivateKey) {
    auto privateKey = PrivateKey(parse_hex("0xe8133c8d3d143ebb3eaa90fdc20f29ffeb91215a5f8a6a5ee9596a4e0d0fab1a"));
    auto address = Address(privateKey.getPublicKey(TWPublicKeyTypeED25519));
    ASSERT_EQ(address.string(), "5H5qKsYuPQPw7s56fa6pbrgpNPKGucX8fkmQdAprouAZqtgz");
}

TEST(WestendAddress, FromPublicKey) {
    auto publicKey = PublicKey(parse_hex("0xde098e3fa1225fd434c373de74051c7286a22cb16a6f4ea8dcc8257b3ce9eac0"), TWPublicKeyTypeED25519);
    auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "5H5qKsYuPQPw7s56fa6pbrgpNPKGucX8fkmQdAprouAZqtgz");
}

TEST(WestendAddress, FromString) {
    auto address = Address("5H5qKsYuPQPw7s56fa6pbrgpNPKGucX8fkmQdAprouAZqtgz");
    ASSERT_EQ(address.string(), "5H5qKsYuPQPw7s56fa6pbrgpNPKGucX8fkmQdAprouAZqtgz");
}

} // namespace TW::Westend::tests
