// Copyright (c) 2011-2016 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
//TODO Currency-specific address prefix
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 1;
//TODO Choose maturity period for your currency
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 60;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;

//TODO Specify total number of available coins
//TODO ((uint64_t)(-1)) equals to 18446744073709551616 coins
//TODO or you can define number explicitly UINT64_C(858986905600000000)
const uint64_t MONEY_SUPPLY                                  = UINT64_C(2100000000000000);
const uint64_t GENESIS_BLOCK_REWARD                          = (MONEY_SUPPLY / 100) * 3;
const unsigned EMISSION_SPEED_FACTOR                         = 21;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

//TODO Define number of blocks for block size median calculation
const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 100000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
//TODO Define number of digits
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
//TODO Define minimum fee for transactions
const uint64_t MINIMUM_FEE                                   = 100000;
const uint64_t DEFAULT_DUST_THRESHOLD                        = MINIMUM_FEE;

//TODO Define preferred block's target time
const uint64_t DIFFICULTY_TARGET                             = 120; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
//TODO There are options to tune CryptoNote's difficulty retargeting function.
//TODO We recommend not to change it.
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        =  20 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

//TODO Put here the name of your currency
const char     CRYPTONOTE_NAME[]                             = "xcicoin";
const char     GENESIS_COINBASE_TX_HEX[]                     = "013c01ff000980e08d84ddcb01026b2cde3765d6cdf755f7658e0206b5e5953dca86d137759e197a14adf34fe4d180e08d84ddcb01025a18fef09799c6aeb36049f072893f9d9ee304207da261138ea92c14579e76b180e08d84ddcb010243528844284528117df3bb177c631fe665e9e7dee58e5124629371f8ff06011580e08d84ddcb010217ba9d3ffc450e76a327de8267e568badbf93fb19ad29a4dab9071b3f80f531580e08d84ddcb010222df24c3972b038dc43abb9d06d4629679c46b07764f2c086c7e651792c370bf80e08d84ddcb0102c718b92e423f175864f7579ae52608c9a96eea3c3fa2ce6c7abdeafdcc9d6a8f80e08d84ddcb0102428e93d03158ab1d9123731f62333698288fef05fb30c045cbc540051ff98b8380e08d84ddcb010257402a375a91d3ff1927d499c12f1d37cac78d66d7ca013416239b9ff5f45c2e80e08d84ddcb01023f252c430effe97a93d7f7c5a33078fc7e811fbf0a3fab37e9201c5cc6affe012101fef31e83dc8ba23c520ca4e105c9b6712d9ccebbc2849230356fe1bf6db41b92";

const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

//TODO This port will be used by the daemon to establish connections with p2p network
const int      P2P_DEFAULT_PORT                              = 42000;
//TODO This port will be used by the daemon to interact with simlewallet
const int      RPC_DEFAULT_PORT                              = 42001;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "8f80f9a5a434a9f1510d13336228debfee9c918ce505efe225d8c94d045fa115";

//TODO Add here your network seed nodes
const std::initializer_list<const char*> SEED_NODES = {
  "104.131.137.173:42000"
  //"your_seed_ip2.com:8080",
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
  { 1, "44605b385e6d3467d43a0b94e58861170e1d309020b27f829a85e4603cd7c9b8" },
  { 10, "39a55d993afbf23248d3f05d829c8efa49fa57e7dbd87ed44f535e902ebd677e" },
  { 42, "4322b517faeaee1b8318b2a02a486e479da2f4c13ea82c818cca02ca1e5ea6fa" },
  { 100, "c940bba48e493433ea7f553d5a1932d61a39f2566238639333cdf6f73a2cf35c" },
  { 420, "219c934c767b35fd025e5ca31de1596a4b73fcf5bb800267d16a5f5bb4d0c213" },
  { 810, "aedbaf54280cf3d4064452173fa77213ad2f64938b74ee170e6a7e52fc98df64" },
  { 1420, "c35b8c047d69b5942e42db23ec512105e78054bedbfffb128ee69305eb249c4c" },
  { 2500, "4c5c5b6be0a5c372381e7e9fa969a8f8693719be636840c130cc7ec99e9e96e2" },
  { 2585, "466e5ae5045a7b67934f99822a4175ad6241777373210c64b3922f1e8e1c21ca" },
  { 2700, "f7e72c2d78adad43a50028fd354f989747fb7cfb16e3ddafd441a2e9c6db3f8b" },
  { 3400, "3474f9c1af77024caa47563328422ab645d3ac9994f6a0366ada350bd48e4f76" },
  { 4000, "f3901e60472d5b17e09d3c25521f3cc236d7efe9284d583e62763a5392d1a1eb" },
  { 5000, "2bd06542971a8436118c721d2838dbc10e53f134f218787c51d1f05a7931fd5c" },
  { 5700, "001f2259a455068706172e608ee88bd3b06ca1583232d4d17ef2f15a95db20f7" },
  { 9000, "8a12df1e917c8d176fa3eada07dce845ff9fa0b9879425fa1d63e6849e8583a8" },
  { 13000, "487c7a142a314d91c435493dd5f437b6c20cccf0b3d91bdef9044070883a0e6e" },
  { 21420, "22d73571b9dc03fb46650e76e90a5c933b4f060fb61c575843457b9fdf89a665" },
  { 42000, "cf2d5fe0e5423201dbcec3eb26df4b63a307ae1c81b9a80e2536982d1df9de0f" },
};
} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
