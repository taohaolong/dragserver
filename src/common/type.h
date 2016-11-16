//
// Created by tao Jacky on 11/16/16.
//

#ifndef DRAGONAVS_TYPE_H
#define DRAGONAVS_TYPE_H



#include <sys/types.h>

/* Even in pure C, we still need a standard boolean typedef */
#ifndef __cplusplus
typedef     unsigned char bool;
	#define     true    1
	#define     false   0
#endif //__cplusplus

#ifdef __GNUC__
#ifndef	_STDINT_H
#ifndef _SYS_TYPES_H
typedef     signed char 		int8_t;
typedef     signed short		int16_t;
typedef     signed int			int32_t;
typedef     signed long long	int64_t;
typedef     unsigned char		uint8_t;
typedef     unsigned short		uint16_t;
typedef     unsigned int		uint32_t;
typedef     unsigned long long	uint64_t;
#else
typedef     u_int8_t        uint8_t;
			typedef     u_int16_t       uint16_t;
			typedef     u_int32_t       uint32_t;
			typedef     u_int64_t       uint64_t;
#endif //_SYS_TYPES_H
#endif //_STDINT_H
#elif defined(_MSC_VER)
typedef     signed char 		int8_t;
	typedef     signed short		int16_t;
	typedef     signed int			int32_t;
	typedef     signed __int64		int64_t;
	typedef     unsigned char		uint8_t;
	typedef     unsigned short		uint16_t;
	typedef     unsigned int		uint32_t;
	typedef     unsigned __int64	uint64_t;
#endif //_MSC_VER

#ifdef   WIN32
#define UNSIGNED_INT32_FORMAT_PARAM "%I32u"
	#define UNSIGNED_INT64_FORMAT_PARAM "%I64u"
	#define SIGNED_INT32_FORMAT_PARAM "%I32d"
	#define SIGNED_INT64_FORMAT_PARAM "%I64d"
#else  //WIN32
#define UNSIGNED_INT32_FORMAT_PARAM "%u"
#define SIGNED_INT32_FORMAT_PARAM	"%d"
#if      __WORDSIZE==64
#define UNSIGNED_INT64_FORMAT_PARAM "%lu"
		#define SIGNED_INT64_FORMAT_PARAM  "%ld"
#else  //__WORDSIZE==64
#define UNSIGNED_INT64_FORMAT_PARAM "%llu"
#define SIGNED_INT64_FORMAT_PARAM "%lld"
#endif //__WORDSIZE==64
#define interface struct
#endif //WIN32



#endif //DRAGONAVS_TYPE_H
