#ifndef __UEFITest_H__
#define __UEFITest_H__

#define IN
#define OUT
#define EFIAPI
typedef struct{
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];
}EFI_GUID;
typedef void VOID;
typedef __int32 INT32;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned __int32 UINT32;
typedef unsigned __int64 UINT64;
typedef UINT64 UINTN;
typedef unsigned short CHAR16;
typedef unsigned char BOOLEAN;
typedef VOID *EFI_HANDLE;
typedef VOID *EFI_EVENT;
typedef UINTN EFI_STATUS;
typedef struct{
    UINT16 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
}EFI_TABLE_HEADER;
typedef struct{
    EFI_TABLE_HEADER Hdr;
    // 本来ここ以下に色々続くが、使わない為に割愛
}EFI_RUNTIME_SERVICES;
typedef struct{
    EFI_TABLE_HEADER Hdr;
    // 本来ここ以下に色々続くが、使わない為に割愛
}EFI_BOOT_SERVICES;
typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL{
    EFI_INPUT_RESET Reset;
    EFI_INPUT_READ_KEY ReadKeyStroke;
    EFI_EVENT WaitForKey;
}EFI_SIMPLE_TEXT_INPUT_PROTOCOL;
typedef EFI_STATUS (EFIAPI *EFI_INPUT_RESET)(
    IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This,
    IN BOOLEAN ExtendedVerification
);
typedef struct{
    UINT16 ScanCode;
    CHAR16 UnicodeChar;
}EFI_INPUT_KEY;
typedef EFI_STATUS (EFIAPI *EFI_INPUT_READ_KEY)(
    IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This,
    OUT EFI_INPUT_KEY *Key
);
typedef struct{
    INT32 MaxMode;
    INT32 Mode;
    INT32 Attribute;
    INT32 CursorColumm;
    INT32 CursorRow;
    BOOLEAN CursorVisible;
}EFI_SIMPLE_TEXT_OUTPUT_MODE;
typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL{
    EFI_TEXT_RESET Reset;
    EFI_TEXT_STRING OutputString;
    EFI_TEXT_TEST_STRING TestString;
    EFI_TEXT_QUERY_MODE QueryMode;
    EFI_TEXT_SET_MODE SetMode;
    EFI_TEXT_SET_ATTRIBUTE SetAttribute;
    EFI_TEXT_CLEAR_SCREEN ClearScreen;
    EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
    EFI_TEXT_ENABLE_CURSOR EnableCursor;
    EFI_SIMPLE_TEXT_OUTPUT_MODE *Mode;
};
typedef EFI_STATUS(EFIAPI *EFI_TEXT_ENABLE_CURSOR)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN BOOLEAN Visible
);
typedef EFI_STATUS(EFIAPI *EFI_TEXT_SET_CURSOR_POSITION)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN UINTN Columm,
    IN UINTN Row
);
typedef EFI_STATUS(EFIAPI *EFI_TEXT_CLEAR_SCREEN)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This
);
typedef EFI_STATUS(EFIAPI *EFI_TEXT_SET_ATTRIBUTE)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN UINTN Attribute
);
typedef EFI_STATUS(EFIAPI *EFI_TEXT_SET_MODE)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN UINTN ModeNumber
);
//ここにEFI_TEXT_QUERY_MODE以降のそれ以上にあるコードを書く事
//コードの所在地(Include/Protocol/SimpleTextOut.h内の242行目まで実装し、それ以上を実装する事)
typedef EFI_STATUS(EFIAPI *EFI_TEXT_QUERY_MODE)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN UINTN ModeNumber,
    OUT UINTN *Columns,
    OUT UINTN *Rows
);
typedef EFI_STATUS(EFIAPI *EFI_TEXT_TEST_STRING)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN CHAR16 *String
);
typedef EFI_STATUS(EFIAPI *EFI_TEXT_STRING)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN CHAR16 *String
);
typedef EFI_STATUS(EFIAPI *EFI_TEXT_RESET)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    IN BOOLEAN ExtendedVerification
);
typedef struct {
    EFI_GUID VendorGuid;
    VOID    *VendorTable;
} EFI_CONFIGURATION_TABLE;
typedef struct{
    EFI_TABLE_HEADER Hdr;
    CHAR16 *FirmwareVendor;
    UINT32 FirmwareRevision;
    EFI_HANDLE ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
    EFI_RUNTIME_SERVICES *RuntimeServices;
    EFI_BOOT_SERVICES *BootServices;
    UINTN NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE *ConfigurationTable;
}EFI_SYSTEM_TABLE;
typedef EFI_STATUS
(EFIAPI *EFI_IMAGE_ENTRY_POINT)(
    IN EFI_HANDLE ImageHandle,
    IN EFI_SYSTEM_TABLE *SystemTable 
);

#endif