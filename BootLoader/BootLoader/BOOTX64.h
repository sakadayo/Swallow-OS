#ifndef __BOOTX64_H__
#define __BOOTX64_H__
#include <stdint.h>

//二章三部一節に記載せらるデータ型の定義
//余分な<Enumerated Type>及びsizeof(VOID *)(コンパイラに依りサイズは規定される)、Bitfields(AIに拠れば抑々非推奨と云う)は定義しない
//<Enumerated Type>(ANSI C内のenum)はサイズが不安定な為、構造体内で使用しない様にすべきだが、関数引数としての利用は許容される
typedef unsigned char BOOLEAN;
typedef intptr_t INTN;
typedef uintptr_t UINTN;
typedef char INT8;
typedef unsigned char UINT8;
typedef short int INT16;
typedef unsigned short int UINT16;
typedef long int INT32;
typedef unsigned long int UINT32;
typedef long long int INT64;
typedef unsigned long long int UINT64;
typedef struct{ intptr_t high; intptr_t low ; }INT128; //計算や比較演算は不可能
typedef struct{ uintptr_t high; uintptr_t low ; }UINT128; //上記と同じ
typedef char CHAR8;
typedef short CHAR16;
typedef void VOID;
typedef struct{ UINT32 Data1; UINT16 Data2; UINT16 Data3; UINT8 Data4[8]; }EFI_GUID;
typedef UINTN EFI_STATUS;
typedef VOID *EFI_HANDLE;
typedef VOID *EFI_EVENT;
typedef UINT64 EFI_LBA;
typedef UINTN EFI_TPL;
typedef struct{ UINT8 Addr[32]; }EFI_MAC_ADDRESS;
typedef struct{ UINT8 Addr[4]; }EFI_IPv4_ADDRESS;
typedef struct{ UINT8 Addr[16]; }EFI_IPv6_ADDRESS;
typedef struct{ UINT32 Addr[4]; EFI_IPv4_ADDRESS v4; EFI_IPv6_ADDRESS v6;}EFI_IP_ADDRESS;

//上記と同じ章に記載せらるニーモニックの定義・読解上の手助けであり、特に意味は無い
#define IN
#define OUT
#define OPTIONAL
#define CONST
#define EFIAPI

//四章一部一節に記載せらるEFI_IMAGE_ENTRY_POINTの定義
typedef EFI_SYSTEM_TABLE EFI_SYSTEM_TABLE;
typedef EFI_STATUS (EFIAPI *EFI_IMAGE_ENTRY_POINT) (IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable);
#define EFI_SUCCESS

//四章二部一節に記載せらるEFI_TABLE_HEADERの定義
typedef struct { UINT64 Signature; UINT32 Revision; UINT32 HeaderSize; UINT32 CRC32; UINT32 Reserved; }EFI_TABLE_HEADER;

//四章三部一節に記載せらるEFI_SYSTEM_TABLEの定義
#define EFI_SYSTEM_TABLE_SIGNATURE 0x5453595320494249
#define EFI_2_100_SYSTEM_TABLE_REVISION ((2<<16) | (100))
#define EFI_2_90_SYSTEM_TABLE_REVISION ((2<<16) | (90))
#define EFI_2_80_SYSTEM_TABLE_REVISION ((2<<16) | (80))
#define EFI_2_70_SYSTEM_TABLE_REVISION ((2<<16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION ((2<<16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION ((2<<16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION ((2<<16) | (40))
#define EFI_2_30_SYSTEM_TABLE_REVISION ((2<<16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION ((2<<16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION ((2<<16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION ((2<<16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION ((1<<16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION ((1<<16) | (02))
#define EFI_SPECIFICATION_VERSION EFI_SYSTEM_TABLE_REVISION
#define EFI_SYSTEM_TABLE_REVISION EFI_2_100_SYSTEM_TABLE_REVISION

typedef EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;
typedef EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;
typedef EFI_RUNTIME_SERVICES EFI_RUNTIME_SERVICES;
typedef EFI_BOOT_SERVICES EFI_BOOT_SERVICES;
typedef EFI_CONFIGURATION_TABLE EFI_CONFIGURATION_TABLE;
typedef struct { EFI_TABLE_HEADER Hdr; CHAR16 *FirmwareVendor; UINT32 FirmwareRevision; EFI_HANDLE ConsoleInHandle; EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn; EFI_HANDLE ConsoleOutHandle; EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut; EFI_HANDLE StandardErrorHandle; EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr; EFI_RUNTIME_SERVICES *RuntimeServices; EFI_BOOT_SERVICES *BootServices; UINTN NumberOfTableEntries; EFI_CONFIGURATION_TABLE *ConfigurationTable; }EFI_SYSTEM_TABLE;

//四章四部一節に記載せらるEFI_BOOT_SERVICESの定義

#endif