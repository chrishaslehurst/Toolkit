#include "Matrix.h"
#include "Vector.h"

namespace tk
{
	struct Rotation
	{
		float pitch;
		float yaw;
		float roll;
	};

	class Transform
	{
	public:
		Transform();

		void SetTranslation(const Vector3& translation);
		void SetRotation(const Rotation& rotation);
		void SetScale(const Vector3& scale);

	private:
		Matrix4 data;
	};
}