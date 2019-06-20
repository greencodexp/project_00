#include "cplatlong.h"

CPLatLong::CPLatLong()
{
    m_lat =0;
    m_long =0;
}

void CPLatLong::f_setLat(double a)
{
    m_lat =a;
}

void CPLatLong::f_setLong(double a)
{
    m_long =a;
}

double CPLatLong::f_getLat()
{
    return m_lat;
}

double CPLatLong::f_getLong()
{
    return m_long;
}
