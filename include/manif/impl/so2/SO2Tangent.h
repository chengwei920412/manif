#ifndef _MANIF_MANIF_SO2TANGENT_H_
#define _MANIF_MANIF_SO2TANGENT_H_

#include "manif/impl/so2/SO2Tangent_base.h"

#include <Eigen/Core>

namespace manif
{
namespace internal
{

// Traits specialization

template <typename _Scalar>
struct traits<SO2Tangent<_Scalar>>
{
  template <typename T>
  using TangentTemplate = SO2Tangent<T>;

  using Scalar = _Scalar;

  using Manifold = SO2<_Scalar>;
  using Tangent  = SO2Tangent<_Scalar>;

  using Base = SO2TangentBase<_Scalar>;

  static constexpr int Dim     = ManifoldProperties<Base>::Dim;
  static constexpr int DoF     = ManifoldProperties<Base>::DoF;
  static constexpr int RepSize = DoF;

  using DataType  = Eigen::Matrix<Scalar, RepSize, 1>;

  using Jacobian = Eigen::Matrix<Scalar, DoF, DoF>;

  using LieType = Eigen::Matrix<Scalar, 2, 2>;
};

} /* namespace internal */
} /* namespace manif */

namespace manif
{

///////////////
///         ///
/// Tangent ///
///         ///
///////////////

template <typename _Scalar>
struct SO2Tangent : SO2TangentBase<SO2Tangent<_Scalar>>
{
private:

  using Base = SO2TangentBase<SO2Tangent<_Scalar>>;
  using Type = SO2Tangent<_Scalar>;

public:

  MANIF_TANGENT_TYPEDEF

  SO2Tangent() = default;

  SO2Tangent(const Scalar theta);
  SO2Tangent(const DataType& theta);

  /// Tangent common API

  const DataType& coeffs() const;

  MANIF_INHERIT_TANGENT_API
  MANIF_INHERIT_TANGENT_OPERATOR

  /// SO2Tangent specific API

  using Base::angle;

  /// @todo consider using a
  /// Eigen::Matrix<std::complex<Scalar>, 1, 1>
  /// as DataType
//  Scalar angle2()
//  {
//    using std::atan2;
//    Eigen::Matrix<std::complex<Scalar>, 1, 1> test;
//    return atan2(test.imag()(0), test.real()(0));
//  }

protected:

  friend class TangentBase<SO2Tangent<Scalar>>;
  DataType& coeffs_nonconst();

  DataType data_;
};

MANIF_EXTRA_TANGENT_TYPEDEF(SO2Tangent);

template <typename _Scalar>
SO2Tangent<_Scalar>::SO2Tangent(const Scalar theta)
  : data_(theta)
{
  //
}

template <typename _Scalar>
SO2Tangent<_Scalar>::SO2Tangent(const DataType& theta)
  : data_(theta)
{
  //
}

template <typename _Scalar>
typename SO2Tangent<_Scalar>::DataType&
SO2Tangent<_Scalar>::coeffs_nonconst()
{
  return data_;
}

template <typename _Scalar>
const typename SO2Tangent<_Scalar>::DataType&
SO2Tangent<_Scalar>::coeffs() const
{
  return data_;
}

} /* namespace manif */

#endif /* _MANIF_MANIF_SO2TANGENT_H_ */