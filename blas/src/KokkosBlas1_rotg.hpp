/*
//@HEADER
// ************************************************************************
//
//                        Kokkos v. 3.0
//       Copyright (2020) National Technology & Engineering
//               Solutions of Sandia, LLC (NTESS).
//
// Under the terms of Contract DE-NA0003525 with NTESS,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY NTESS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NTESS OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact Siva Rajamanickam (srajama@sandia.gov)
//
// ************************************************************************
//@HEADER
*/

#ifndef KOKKOSBLAS1_ROTG_HPP_
#define KOKKOSBLAS1_ROTG_HPP_

#include <Kokkos_Core.hpp>
#include <KokkosBlas1_rotg_spec.hpp>

namespace KokkosBlas {

/// \brief Compute the coefficients to apply a Givens rotation.
///
/// \tparam Scalar data type of inputs and outputs
///
/// \param a [in/out] on input one of the values to rotate, on output the
/// rotated value \param b [in/out] on input one of the values to rotate, on
/// output the rotated value \param c [out] cosine value associated with the
/// rotation \param s [out] sine value associated with the rotation
template <class Scalar, class ExecutionSpace = Kokkos::DefaultExecutionSpace>
void rotg(Scalar& a, Scalar& b,
          typename Kokkos::ArithTraits<Scalar>::mag_type& c, Scalar& s) {
  Kokkos::Profiling::pushRegion("KokkosBlas::rotg");
  Impl::Rotg<Scalar, ExecutionSpace,
             typename ExecutionSpace::memory_space>::rotg(a, b, c, s);
  Kokkos::Profiling::popRegion();
}

}  // namespace KokkosBlas

#endif  // KOKKOSBLAS1_ROTG_HPP_