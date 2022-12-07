// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here MAY BE LOST.
// Generated one-time (codegen/bin/cointests)
//

#include "TestUtilities.h"
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <gtest/gtest.h>


TEST(TWWestendCoinType, TWCoinType) {
    const auto coin = TWCoinTypeWestend;
    const auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(coin));
    const auto id = WRAPS(TWCoinTypeConfigurationGetID(coin));
    const auto name = WRAPS(TWCoinTypeConfigurationGetName(coin));
    const auto txId = WRAPS(TWStringCreateWithUTF8Bytes("0x970819ba6853c30700ef58782ed51758ab686c360d937c80b1e71b27d8683fcf"));
    const auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(coin, txId.get()));
    const auto accId = WRAPS(TWStringCreateWithUTF8Bytes("5EufDnKtpwUNdamQqT76HUBEd3Lw1Jqrs1qdDggQ85FmMKou"));
    const auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(coin, accId.get()));

    assertStringsEqual(id, "westend");
    assertStringsEqual(name, "Westend");
    assertStringsEqual(symbol, "WND");
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(coin), 12);
    ASSERT_EQ(TWCoinTypeBlockchain(coin), TWBlockchainWestend);
    ASSERT_EQ(TWCoinTypeP2shPrefix(coin), 0x0);
    ASSERT_EQ(TWCoinTypeStaticPrefix(coin), 0x0);
    assertStringsEqual(txUrl, "https://westend.subscan.io/extrinsic/0x970819ba6853c30700ef58782ed51758ab686c360d937c80b1e71b27d8683fcf");
    assertStringsEqual(accUrl, "https://westend.subscan.io/account/5EufDnKtpwUNdamQqT76HUBEd3Lw1Jqrs1qdDggQ85FmMKou");
}
