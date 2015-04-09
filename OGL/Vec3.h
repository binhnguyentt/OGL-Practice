#ifndef __Vec3_h_included__
#define __Vec3_h_included__

class Vec3
{
protected:
    float m_fX;
    float m_fY;
    float m_fZ;

public:
    Vec3();
    ~Vec3();

    Vec3(float x, float y, float z);

    float x() const;
    float y() const;
    float z() const;

    Vec3& x(float x);
    Vec3& y(float y);
    Vec3& z(float z);

    Vec3 operator +(const Vec3& right) const;
    Vec3 operator -(const Vec3& right) const;
    Vec3 operator *(const float right) const;
    Vec3 operator /(const float right) const;

    float length() const;

    float dot(const Vec3& right) const;
    Vec3 cross(const Vec3& right) const;
    Vec3 normalized() const;
};

#endif // __Vec3_h_included__