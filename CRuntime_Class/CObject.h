#include "stdafx.h"

#ifndef _CObject_
#define _CObject_

class CObject {
public:
	virtual CRuntimeClass *GetRuntimeClass() const; // virtual void Serialize(CArchive &ar);
	virtual ~CObject() {}

protected:
	CObject() {}
};
#endif