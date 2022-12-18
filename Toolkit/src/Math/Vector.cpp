#include "Vector.h"
namespace tk
{
	namespace vector
    {
        constexpr float DotProduct(const Vector3 &lhs, const Vector3 &rhs)
        {
            return (lhs.X * rhs.X) + (lhs.Y * rhs.Y) + (lhs.Z * rhs.Z);
        }

        constexpr Vector3 CrossProduct(const Vector3 &lhs, const Vector3 &rhs)
        {
            return Vector3(((lhs.Y * rhs.Z) - (lhs.Z * rhs.Y)), ((lhs.Z * rhs.X) - (lhs.X * rhs.Z)),
                           ((lhs.X * rhs.Y) - (lhs.Y * rhs.X)));
        }

        constexpr float DistSquared(const Vector3 &a, const Vector3 &b)
        {
            Vector3 between = a - b;
            return (between.X * between.X) + (between.Y * between.Y) + (between.Z * between.Z);
        }

        float Dist(const Vector3 &a, const Vector3 &b) { return sqrt(DistSquared(a, b)); }

        constexpr float LengthSquared(const Vector3 &vec)
        {
            return (vec.X * vec.X) + (vec.Y * vec.Y) + (vec.Z * vec.Z);
        }

        float Length(const Vector3 &vec) { return sqrtf(LengthSquared(vec)); }

    } // namespace vector
}//namespace tk


