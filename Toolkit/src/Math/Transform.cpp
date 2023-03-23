#include "Transform.h"

namespace tk
{
    Transform::Transform() 
    { 
       data = Matrix4::Identity();
    }

    void Transform::SetTranslation(const Vector3 &translation) 
    {
    }

    void Transform::SetRotation(const Rotation &rotation) 
    {
    }

    void Transform::SetScale(const Vector3 &scale) {}

} // namespace tk
