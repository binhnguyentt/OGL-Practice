#ifndef __Mat4_h_included__
#define __Mat4_h_included__

/**
 * Note: OpenGL uses column major matrix
 */
class Mat4
{
protected:
    float m_arrData[4][4];

public:
    Mat4();
    Mat4(const float *matrix_data);

    ~Mat4();

    Mat4& setZero();
    Mat4& setIdentity();

    /**
     * Note: OpenGL uses column major matrix
     */
    Mat4& set(int row, int column, float value);
    const float get(int row, int colum) const;

    const float * dataPointer() const;

    Mat4 operator +(const Mat4& right) const;
    Mat4 operator -(const Mat4& right) const;
    Mat4 operator *(const Mat4& right) const;
    Mat4 operator *(const float right) const;

    Mat4 inverse() const;
    Mat4 transpose() const;
};

#endif // __Mat4_h_included__
