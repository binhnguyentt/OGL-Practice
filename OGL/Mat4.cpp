#include <cstdio>
#include "Mat4.h"

Mat4::Mat4()
{
    setZero();
}

Mat4::Mat4(const float *matrix_data)
{
    
}

Mat4::~Mat4()
{

}

Mat4& Mat4::setIdentity()
{
    setZero();
    m_arrData[0][0] = 1;
    m_arrData[1][1] = 1;
    m_arrData[2][2] = 1;
    m_arrData[3][3] = 1;

    return *this;
}

Mat4& Mat4::setZero()
{
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; ++j) {
            m_arrData[i][j] = 0;
        }
    }

    return *this;
}

Mat4& Mat4::set(int row, int column, float value)
{
    // Column major
    m_arrData[column][row] = value;
    return *this;
}

const float Mat4::get(int row, int colum) const
{
    return m_arrData[colum][row];
}

const float * Mat4::dataPointer() const
{
    return reinterpret_cast<const float *>(m_arrData);
}

Mat4 Mat4::operator+(const Mat4& right) const
{
    const float *matrix1 = dataPointer();
    const float *matrix2 = right.dataPointer();
    float matrix3[16];

    for (int i = 0; i < 16; ++i) {
        matrix3[i] = matrix1[i] + matrix2[i];
    }

    return Mat4(matrix3);
}

Mat4 Mat4::operator-(const Mat4& right) const
{
    const float *matrix1 = dataPointer();
    const float *matrix2 = right.dataPointer();
    float matrix3[16];

    for (int i = 0; i < 16; ++i) {
        matrix3[i] = matrix1[i] - matrix2[i];
    }

    return Mat4(matrix3);
}

Mat4 Mat4::operator*(const Mat4& right) const
{
    Mat4 result;
    float value = 0.0f;

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            value = 0.0f;

            for (int j = 0; j < 4; j++) {
                value = value + get(x, j) + right.get(j, y);
            }

            result.set(x, y, value);
        }
    }

    return result;
}

Mat4 Mat4::operator*(const float right) const
{
    Mat4 result;
    float value;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            value = get(i, j) * right;
            result.set(i, j, value);
        }
    }

    return result;
}

Mat4 Mat4::transpose() const
{
    Mat4 result;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result.set(j, i, get(i, j));
        }
    }

    return result;
}
