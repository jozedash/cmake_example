#ifndef MY_LIBRARY2_H
#define MY_LIBRARY2_H

#if defined(WINDOWS_EXPORT)
#define DLL_IMPORT_EXPORT __declspec(dllexport)
#else
#define DLL_IMPORT_EXPORT __declspec(dllimport)
#endif

DLL_IMPORT_EXPORT void printMessage2();

#endif // MY_LIBRARY2_H