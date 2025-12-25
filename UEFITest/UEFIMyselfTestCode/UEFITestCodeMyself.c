#include "UEFITest.h"

EFI_STATUS EfiApplicationEntryPoint(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable){
    (void)ImageHandle;
    EFI_STATUS textout_status = SystemTable->ConOut->OutputString(SystemTable->ConOut,L"Hello,World!\n\r");
    return 0;
}