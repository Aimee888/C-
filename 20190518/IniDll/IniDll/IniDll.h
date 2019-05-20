#pragma once
#ifdef __cplusplus               // if used by C++ code
extern "C" {                     // we need to export the C interface
#endif

#ifndef INIDLL_H
#define INIDLL_H

#include "export.h"
EXPORT_API int GetSections_num(char* path_str);
EXPORT_API char* GetSections(char* path_str, int tag);
EXPORT_API void Ini_Write(char* sec_str, char* key_str, char* value_str, char* path_str);
EXPORT_API char* Ini_Read(char* sec_str, char* key_str, char* path_str);
EXPORT_API void Ini_Del_Key(char* sec_str, char* key_str, char* path_str);
EXPORT_API void Ini_Del_Sec(char* sec_str, char* path_str);
//EXPORT_API int Ini_Read(char* sec_str, char* key_str, char* path_str, int int_true);
#endif //!INIDLL_H

#ifdef __cplusplus
}
#endif