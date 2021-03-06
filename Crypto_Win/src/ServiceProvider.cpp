//
// ServiceProvider.cpp
//
// $Id$
//
// Library: Crypto_Win
// Package: CryptoCore
// Module:  ServiceProvider
//
// Copyright (c) 2006-2014, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/Crypto/ServiceProvider.h"
#include "Poco/Exception.h"


namespace Poco {
namespace Crypto {


ServiceProvider::ServiceProvider()
{
	if(!CryptAcquireContext(&_handle,
		NULL,
		MS_ENH_RSA_AES_PROV,
		PROV_RSA_AES,
		CRYPT_VERIFYCONTEXT | CRYPT_SILENT))
	{
		error("Cannot acquire crypt context");
	}
}

		
ServiceProvider::~ServiceProvider()
{
	CryptReleaseContext(_handle, 0);
}


void initializeCrypto()
{
}


void uninitializeCrypto()
{
}


} } // namespace Poco::Crypto
