#include "CObject.h"

/*---------------------------------------------------------------------------*/
CObject::CObject()
{
    m_iId = 0;
    m_iIndex = -1;
}

/*---------------------------------------------------------------------------*/
CObject::CObject(int _iId)
{
    m_iId = _iId;
    m_iIndex = -1;
}

/*---------------------------------------------------------------------------*/
int CObject::iGetID()
{
    return m_iId;
}

/*---------------------------------------------------------------------------*/
void CObject::vSetPosition(CVector3* _oPos)
{
    m_oPosition.vSet(*_oPos);
}

/*---------------------------------------------------------------------------*/
void CObject::vGetPosition(CVector3* _poPos)
{
    _poPos->vSet(m_oPosition);
}

/*---------------------------------------------------------------------------*/
int CObject::iGetFaceSelectionne()
{
    return m_iIndex;
}

/*---------------------------------------------------------------------------*/
void CObject::vSetPicked(int _iPicked)
{
    m_iIndex = _iPicked;
}
