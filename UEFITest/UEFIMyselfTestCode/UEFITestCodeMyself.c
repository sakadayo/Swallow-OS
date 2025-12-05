typedef unsigned char BOOLEAN;
typedef signed char INT8;
typedef struct {
unsigned long long Low;
unsigned long long High;
} UINT128;
#define VOID void
typedef struct {
unsigned long Data1;
unsigned short Data2;
unsigned short Data3;
unsigned char Data4[8];
} EFI_GUID;
typedef unsigned long long EFI_STATUS;
typedef void* EFI_HANDLE;
#define EFIAPI
#define IN
#define OUT
