/**
 * @serialization.hpp
 * @author Ryan Curtin
 *
 * Simple utilities for boost::serialization.
 */
#ifndef MLPACK_BINDINGS_PYTHON_MLPACK_SERIALIZATION_HPP
#define MLPACK_BINDINGS_PYTHON_MLPACK_SERIALIZATION_HPP

#include <mlpack/core.hpp>

namespace mlpack {
namespace bindings {
namespace python {

template<typename T>
std::string SerializeOut(T* t, const std::string& name)
{
  std::ostringstream oss;
  {
    boost::archive::binary_oarchive b(oss);

    b << boost::serialization::make_nvp(name.c_str(), *t);
  }
  return oss.str();
}

template<typename T>
void SerializeIn(T* t, const std::string& str, const std::string& name)
{
  std::istringstream iss(str);
  boost::archive::binary_iarchive b(iss);

  b >> boost::serialization::make_nvp(name.c_str(), *t);
}

} // namespace python
} // namespace bindings
} // namespace mlpack

#endif
