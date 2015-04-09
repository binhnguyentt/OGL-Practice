#include <cmath>
#include "Common.h"
#include "Vec3.h"

Vec3::Vec3()
    : m_fX(0.0f), m_fY(0.0f), m_fZ(0.0f)
{
}

Vec3::Vec3(float x, float y, float z)
    : m_fX(x), m_fY(y), m_fZ(z)
{
}

Vec3::~Vec3()
{

}

Vec3 Vec3::operator+(const Vec3& right) const
{
    return Vec3(
        m_fX + right.x(), 
        m_fY + right.y(), 
        m_fZ + right.z()
    );
}

Vec3 Vec3::operator-(const Vec3& right) const
{
    return Vec3(
        m_fX - right.x(), 
        m_fY - right.y(), 
        m_fZ - right.z()
    );
}

Vec3 Vec3::operator*(const float right) const
{
    return Vec3(
        m_fX * right,
        m_fY * right, 
        m_fZ * right
    );
}

Vec3 Vec3::operator/(const float right) const
{
    return Vec3(
        m_fX / right,
        m_fY / right,
        m_fZ / right
    );
}

float Vec3::x() const
{
    return m_fX;

}

Vec3& Vec3::x(float x)
{
    m_fX = x;

    return *this;
}

float Vec3::y() const
{
    return m_fY;
}

Vec3& Vec3::y(float y)
{
    m_fY = y;

    return *this;
}

float Vec3::z() const
{
    return m_fZ;
}

Vec3& Vec3::z(float z)
{
    m_fZ = z;

    return *this;
}

float Vec3::dot(const Vec3& right) const
{
    return m_fX * right.x()
        + m_fY * right.y()
        + m_fZ * right.z();
}

Vec3 Vec3::cross(const Vec3& right) const
{
    return Vec3(
        m_fY * right.z() + m_fZ * right.y(),
        m_fZ * right.x() + m_fX * right.z(),
        m_fX * right.y() + m_fY * right.x()
    );
}

Vec3 Vec3::normalized() const
{
    float len = length();

    return Vec3(
        m_fX / len,
        m_fY / len,
        m_fZ / len
    );
}

float Vec3::length() const
{
    return std::sqrt(SQR(m_fX) + SQR(m_fY) + SQR(m_fZ));
}
