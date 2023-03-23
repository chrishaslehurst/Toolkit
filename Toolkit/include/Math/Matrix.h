#pragma once
#include "Defines.h"
#include <type_traits>

namespace tk
{
	template<typename Type, s32 Rows, s32 Cols>
	class Matrix 
	{
	public:

		using MatrixType = Matrix<Type, Rows, Cols>;
		//Returns an identity matrix of the required dimensions..
		constexpr static Matrix<Type, Rows, Cols> Identity()
		{
			MatrixType result;
			// #todo-ch 31/12/2022: parallel for?
			for (s32 rowIndex = 0; rowIndex < Rows; ++rowIndex)
			{
				for (s32 colIndex = 0; colIndex < Cols; ++colIndex)
				{
					if (rowIndex == colIndex)
					{
						result.data[rowIndex][colIndex] = 1;
					}
					else
					{
						result.data[rowIndex][colIndex] = 0;
					}
				}
			}

			return result;
		}

		template<typename RHSValueType, s32 RHSRows, s32 RHSCols>
		Matrix<Type, RHSRows, Cols> operator*(Matrix<RHSValueType, RHSRows, RHSCols> rhs)
		{
			static_assert(Rows == RHSCols);
			static_assert(std::is_same_v<RHSValueType, Type>);

			using ResultType = Matrix<Type, RHSRows, Cols>;

			ResultType res;
			// #todo-ch 31/12/2022: parallel for?
			for (s32 resultRow = 0; resultRow < RHSRows; ++resultRow)
			{
				for (s32 resultCol = 0; resultCol < Cols; ++resultCol)
				{
					Type value = 0;
					for (s32 lhsRowIndex = 0; lhsRowIndex < Rows; ++lhsRowIndex)
					{
						value += data[lhsRowIndex][resultCol] * rhs.data[resultRow][lhsRowIndex];
					}
					res.data[resultRow][resultCol] = value;
				}
			}
			return res;
		}

		bool operator ==(const MatrixType& rhs) const
		{
			for (s32 rowIndex = 0; rowIndex < Rows; ++rowIndex)
			{
				for (s32 colIndex = 0; colIndex < Cols; ++colIndex)
				{
					if (data[rowIndex][colIndex] != rhs.data[rowIndex][colIndex])
					{
						return false;
					}
				}
			}
			return true;
		}
	
		Type data[Rows][Cols];
	};

	using Matrix4 = Matrix<float, 4, 4>;
	using Matrix3 = Matrix<float, 3, 3>;
	using Matrix2 = Matrix<float, 2, 2>;
	
	

}