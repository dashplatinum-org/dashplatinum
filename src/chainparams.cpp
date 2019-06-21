// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "random.h"
#include "util.h"
#include "utilstrencodings.h"
#include <assert.h>
#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
// HERE
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256("0x000000aad3c4d81fc98cec4a59c90fb1963c6fdbe5486c9604ddef36605067a6"))
    (1, uint256("0x0000011befd54f51949a8b7e8f87e1519c5f870584ee5b5f1ee37c3447ee20c0"))
    (2, uint256("0x00000252859c1d91e5bef46322708e0227ef546c3d068129f966e78f14bdd08c"))
    (3, uint256("0x00000eba24649f462c8c2325bb0b9b291040b43b3ff690da5b71affc154e4162"))
    (5, uint256("0x0000085e9dd4c2e7f2a477d98342aa3bb637dc24eadfc3887e764ecac85cf63c"))
    (10, uint256("0x00000735ce8d849c88b26c93c4a68a6337b00064e216d7162140ac2df85cdf85"))
    (50, uint256("0x0000002873a058cc67a1898e0e251c94a17d6c1a7831cad9198ced09dc3fb22a"))
    (100, uint256("0x00000069260d292edcb1d5e720ce7daf4858e99de184a6f3637a33a65235ae1f"))
    (150, uint256("0x0000001deabcc1267ddeab37f923439454dfcc1b2223dfbae41d0f50c3367043"))
    (160, uint256("0x000002224c164a9c497b2cbdc178896c07adba25aaf44b7aa8340a0d01a94809"))
    (200, uint256("0x0000025f33acec62e39f8d651a50ad4946bd3a1241a3a6078ec50aa0d3401b12"))
    (251, uint256("0xc9d41bace3d9c580fa08b5247e6d269f5f5a04bb4a7545f12ee5d2d29a3c6039"))
    (300, uint256("0x6a1675a3aebf1b2ad1a8687ffad2bc093ca544555bdd1d0b1b20b50ea38bbcc4"))
    (400, uint256("0x2669c3403445bd76b7b713c3fba2b4859c87a2c475ef72661bdbd450900b0d03"))
    (500, uint256("0x00b6fed93f6dc2af5a5819417e8d286c20ed7dc4a346ff1edc10e0d60cc9aa38"))
    (1000, uint256("0xf51681be33869f71ab26903afc672a24fd95997e573dc23461d53ba4f8909f47"))
    (1931, uint256("0xc85bae92ad229eeac021736fcc74b56a4fbb516cb6c3b893961fa31b99a1ef63"))
    (6348, uint256("0xe5d9f9d343e40e144a7115ecf8fc113b43d9be23b72c695ba06eee47bcca9083"))
    (6400, uint256("0xaa4b5cc358c172dae31f71d5f97a30e1592c2558faef5b1baa33ea8b2f033042"))
    (38668, uint256("0x72379eb7cb255c4a417093b082cb8d04f87f7d712a5f3a331847e66234a596ba"))
    (60750, uint256("0x3fdd0ad48a0f18755334d4b21b303e3451c865fe38f753b30748b4228259b4af"));
    
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1561065911, // * UNIX timestamp of last checkpoint block
    130608,          // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1549215595,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x00"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1549210595,
    0,
    100};
class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        pchMessageStart[0] = 0xd3;
        pchMessageStart[1] = 0x1a;
        pchMessageStart[2] = 0x3d;
        pchMessageStart[3] = 0xe4;
        vAlertPubKey = ParseHex("04ccf3a78f6bf2c015651fcbf147c2412fc52c2ccfb6d6bed85627a73ee9a4a9204dafaca4e4e7fe57e448ccd6d859daafa9b2135e5aeff198dc1d50130d40801b");
        nDefaultPort = 22583;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 122862;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetSpacing = 3 * 60;
        nTargetTimespan = 60 * 40; 
        nLastPOWBlock = 200;
        nMaturity = 40;
        nMasternodeCountDrift = 20;
        nModifierUpdateBlock = 700;
        nMaxMoneyOut = 19700000 * COIN;

        const char* pszTimestamp = "bitcoin block heigth 561363 https://www.blockchain.com/pt/btc/block/0000000000000000000e5d1344dffcfc1ab88b217eec83b3d9ab3f33325668aa";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 50 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04af18d9d18d56836918a6cc818a440b23af2d03bd6d6f38da7a15e3ec57aacf20df28da5b18790e973356d8bdc9e126a76bd107ee0adfa99bb41a2794ed5d723d") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1549217595;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 299300;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000000aad3c4d81fc98cec4a59c90fb1963c6fdbe5486c9604ddef36605067a6"));
        assert(genesis.hashMerkleRoot == uint256("0xc398fca03cbbbf92ba04b3b55f1368b9470a77e4bdcfab996291e2d228684584"));


        vSeeds.push_back(CDNSSeedData("sed1", "sed1.dashplatinum.org"));
        vSeeds.push_back(CDNSSeedData("sed2", "sed2.dashplatinum.org"));
        vSeeds.push_back(CDNSSeedData("sed3", "sed3.dashplatinum.org"));
        vSeeds.push_back(CDNSSeedData("sed4", "sed4.dashplatinum.org"));
        vSeeds.push_back(CDNSSeedData("sed5", "sed5.dashplatinum.org"));
        vSeeds.push_back(CDNSSeedData("sed6", "sed6.dashplatinum.org"));
        vSeeds.push_back(CDNSSeedData("sed7", "sed7.dashplatinum.org"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,76);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,16);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,204);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x05).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "04ccd7d09f9e948a79bdc7eac0f66efe78eae83d4f4ddee624f082edb9849fc4c08239ff8fb10a597c283f5edf3f6cf9a891c313569e8c48864bfe245537ae58ea";
        strObfuscationPoolDummyAddress = "XpXcMcbc49umKR3rtjQKVpBs1esVQG1ciH";
        nStartMasternodePayments =  genesis.nTime + 86400; 
   }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x45;
        pchMessageStart[1] = 0x76;
        pchMessageStart[2] = 0x65;
        pchMessageStart[3] = 0xba;
        vAlertPubKey = ParseHex("04ec434ea7af53f94d9e9b7912dbf111b0f34711386527db41f558cb823ba8ef31694255d92e1a75325956c83982e0dc536a6dd208dbfa4c629d0952881cab1870");
        nDefaultPort = 32583;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetSpacing = 3 * 60;  
        nTargetTimespan = 60 * 40;
        nLastPOWBlock = 200;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 51197;
        nMaxMoneyOut = 21000000 * COIN;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1549215595;
        genesis.nNonce = 39490;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000c31b827ccd84ff2ce68a1c0e838d0c396603368cd67cf8dc9896a0d67c0"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        fRequireRPCPassword = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04ccd98ac73cd806db48f384744920ed8ee43cbe38a2e548bd5b2acfae9f891330ebc45e04f3dc1c98931cfb2d6399fb50cd2c6b64c2c0c3fe47e50287bba25a39";
        strObfuscationPoolDummyAddress = "XpXcMcbc49umKR3rtjQKVpBs1esVQG1ciH";
        nStartMasternodePayments = genesis.nTime + 86400;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
 class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; 
        nTargetSpacing = 1 * 60;
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1549210595;
        genesis.nBits = 0x207fffff;
        nDefaultPort = 51476;
        genesis.nNonce = 3;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x4feb309798d608a2a62432ee561a4778675bb94e8966ec326f3fe53ab883e8e1"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
