#pragma once
#ifndef TESTWORK_TYPE_H
#define TESTWORK_TYPE_H


typedef unsigned char uint8;
typedef signed char int8;

#if defined( _WIN32 ) && !defined( __GNUC__ )

typedef __int16 int16;
typedef unsigned __int16 uint16;
typedef __int32 int32;
typedef unsigned __int32 uint32;
typedef __int64 int64;
typedef unsigned __int64 uint64;

typedef int64 lint64;
typedef uint64 ulint64;

#ifdef X64BITS
typedef __int64 intp;				// intp is an integer that can accomodate a pointer
typedef unsigned __int64 uintp;		// (ie, sizeof(intp) >= sizeof(int) && sizeof(intp) >= sizeof(void *)
#else
typedef __int32 intp;
typedef unsigned __int32 uintp;
#endif

#else // _WIN32

typedef short int16;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;

// [u]int64 are actually defined as 'long long' and gcc 64-bit
// doesn't automatically consider them the same as 'long int'.
// Changing the types for [u]int64 is complicated by
// there being many definitions, so we just
// define a 'long int' here and use it in places that would
// otherwise confuse the compiler.
typedef long int lint64;
typedef unsigned long int ulint64;

#ifdef X64BITS
typedef long long intp;
typedef unsigned long long uintp;
#else
typedef int intp;
typedef unsigned int uintp;
#endif

#endif // else _WIN32
#endif // TESTWORK_TYPE_H
