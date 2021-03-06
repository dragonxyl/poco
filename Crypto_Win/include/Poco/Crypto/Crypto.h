//
// Crypto.h
//
// $Id$
//
// Library: Crypto_Win
// Package: CryptoCore
// Module:  Crypto
//
// Basic definitions for the Poco Crypto library.
// This file must be the first file included by every other Crypto
// header file.
//
// Copyright (c) 2006-2014, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Crypto_Crypto_INCLUDED
#define Crypto_Crypto_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Error.h"
#include "Poco/Format.h"


namespace Poco {
namespace Crypto {


enum RSAPaddingMode
	/// The padding mode used for RSA public key encryption.
{
	RSA_PADDING_PKCS1,
		/// PKCS #1 v1.5 padding. This currently is the most widely used mode. 

	RSA_PADDING_PKCS1_OAEP,
		/// EME-OAEP as defined in PKCS #1 v2.0 with SHA-1, MGF1 and an empty 
		/// encoding parameter. This mode is recommended for all new applications.

	RSA_PADDING_SSLV23,
		/// PKCS #1 v1.5 padding with an SSL-specific modification that denotes 
		/// that the server is SSL3 capable. 

	RSA_PADDING_NONE
		/// Raw RSA encryption. This mode should only be used to implement cryptographically 
		/// sound padding modes in the application code. Encrypting user data directly with RSA 
		/// is insecure. 
};


inline void error(const char* msg)
	/// Formats the error message and throws SystemException.
{
	DWORD err = Poco::Error::last();
	throw Poco::SystemException(Poco::format("%s: [%s]", std::string(msg), Error::getMessage(err)));
}


} }


//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the Crypto_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// Crypto_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(POCO_DLL)
	#if defined(Crypto_Win_EXPORTS)
		#define Crypto_Win_API __declspec(dllexport)
	#else
		#define Crypto_Win_API __declspec(dllimport)
	#endif
#endif


#if !defined(Crypto_Win_API)
	#define Crypto_Win_API
#endif


//
// Automatically link Crypto library.
//
#if defined(_MSC_VER)
	#if !defined(POCO_NO_AUTOMATIC_LIBS) && !defined(Crypto_Win_EXPORTS)
		#pragma comment(lib, "PocoCryptoWin" POCO_LIB_SUFFIX)
	#endif
#endif


namespace Poco {
namespace Crypto {


void Crypto_Win_API initializeCrypto();
	/// Initialize the Crypto library.
	///
	/// Should be called before using any class from the Crypto library.
	/// The Crypto library will be initialized automatically, through  
	/// OpenSSLInitializer instances held by various Crypto classes
	/// (Cipher, CipherKey, RSAKey, X509Certificate).
	/// However, it is recommended to call initializeCrypto()
	/// in any case at application startup.
	///
	/// Can be called multiple times; however, for every call to
	/// initializeCrypto(), a matching call to uninitializeCrypto()
	/// must be performed.
	

void Crypto_Win_API uninitializeCrypto();
	/// Uninitializes the Crypto library.


} } // namespace Poco::Crypto


#endif // Crypto_Crypto_INCLUDED
