#include "BOOTX64.h"

EFI_STATUS BootloaderEntryPoint(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable){
    EFI_LOADED_IMAGE_PROTOCOL *image_protocol;
    EFI_STATUS load_image_protocol = SystemTable->BootServices->OpenProtocol(ImageHandle,&(EFI_GUID)EFI_LOADED_IMAGE_PROTOCOL_GUID,(void**)&image_protocol,ImageHandle,NULL,EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL);
    EFI_HANDLE device_handle = image_protocol->DeviceHandle
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *simple_file_protocol;
    EFI_STATUS get_simple_file_protocol = SystemTable->BootServices->OpenProtocol(device_handle,&(EFI_GUID)EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID,(void**)&simple_file_protocol,ImageHandle,NULL,EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL);
    EFI_FILE_PROTOCOL *volume;
    EFI_STATUS get_volume = simple_file_protocol->OpenVolume(simple_file_protocol,(void**)&volume);
    EFI_FILE_PROTOCOL *OS_image;
    char os_file_name[] = L""; 
    EFI_STATUS get_file = volume->Open(volume,(void**)&OS_image,os_file_name,EFI_FILE_MODE_READ,EFI_FILE_READ_ONLY);
    
}