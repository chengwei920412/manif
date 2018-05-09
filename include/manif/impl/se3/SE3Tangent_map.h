#ifndef _MANIF_MANIF_SE3TANGENT_MAP_H_
#define _MANIF_MANIF_SE3TANGENT_MAP_H_

#include "manif/impl/se3/SE3Tangent.h"

namespace manif {
namespace internal {

template <>
template <typename _Scalar>
struct traits< Eigen::Map<SE3Tangent<_Scalar>,0> >
    : public traits<SE3Tangent<_Scalar>>
{
  using typename traits<SE3Tangent<_Scalar>>::Scalar;
  using traits<SE3Tangent<_Scalar>>::RepSize;
  using DataType = Eigen::Map<Eigen::Matrix<Scalar, RepSize, 1>, 0>;
};

template <>
template <typename _Scalar>
struct traits< Eigen::Map<const SE3Tangent<_Scalar>,0> >
    : public traits<const SE3Tangent<_Scalar>>
{
  using typename traits<const SE3Tangent<_Scalar>>::Scalar;
  using traits<const SE3Tangent<_Scalar>>::RepSize;
  using DataType = Eigen::Map<const Eigen::Matrix<Scalar, RepSize, 1>, 0>;
};

} /* namespace internal */
} /* namespace manif */

namespace Eigen
{

template <class _Scalar>
class Map<manif::SE3Tangent<_Scalar>, 0>
    : public manif::SE3TangentBase<Map<manif::SE3Tangent<_Scalar>, 0> >
{
  using Base = manif::SE3TangentBase<Map<manif::SE3Tangent<_Scalar>, 0> >;

public:

  MANIF_TANGENT_TYPEDEF
  MANIF_INHERIT_TANGENT_API
  MANIF_INHERIT_TANGENT_OPERATOR

  Map(Scalar* coeffs) : data_(coeffs) { }

  const DataType& coeffs() const { return data_; }

protected:

  friend class manif::TangentBase<Map<manif::SE3Tangent<_Scalar>, 0>>;
  DataType& coeffs_nonconst() { return data_; }

  DataType data_;
};

template <class _Scalar>
class Map<const manif::SE3Tangent<_Scalar>, 0>
    : public manif::SE3TangentBase<Map<const manif::SE3Tangent<_Scalar>, 0> >
{
  using Base = manif::SE3TangentBase<Map<const manif::SE3Tangent<_Scalar>, 0> >;

public:

  MANIF_TANGENT_TYPEDEF
  MANIF_INHERIT_TANGENT_API
  MANIF_INHERIT_TANGENT_OPERATOR

  Map(Scalar* coeffs) : data_(coeffs) { }

  const DataType& coeffs() const { return data_; }

protected:

  friend class manif::TangentBase<Map<const manif::SE3Tangent<_Scalar>, 0>>;
  DataType& coeffs_nonconst() { return data_; }

  DataType data_;
};

} /* namespace Eigen */

#endif /* _MANIF_MANIF_SE3TANGENT_MAP_H_ */
