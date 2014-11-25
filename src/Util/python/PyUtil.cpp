/*!
  @author Shin'ichiro Nakaoka
*/

#include "PyUtil.h"
#include "../ExecutablePath.h"
#include "../FloatingNumberString.h"

using namespace boost::python;
using namespace cnoid;

namespace cnoid {

void exportPySignalTypes();
void exportPyEigenTypes();
void exportPySeqTypes();
void exportPySceneGraph();

}

BOOST_PYTHON_MODULE(Util)
{
    class_<Referenced, ReferencedPtr, boost::noncopyable>("Referenced", no_init);

    exportPySignalTypes();
    exportPyEigenTypes();
    exportPySeqTypes();
    exportPySceneGraph();

    def("shareDirectory", &cnoid::shareDirectory, return_value_policy<copy_const_reference>());
    def("executablePath", &cnoid::executablePath, return_value_policy<copy_const_reference>());
    def("executableBasename", &cnoid::executableBasename, return_value_policy<copy_const_reference>());
    def("executableTopDirectory", &cnoid::executableTopDirectory, return_value_policy<copy_const_reference>());

    class_<FloatingNumberString>("FloatingNumberString", init<const std::string&>())
        .def("set", &FloatingNumberString::set)
        .def("setPositiveValue", &FloatingNumberString::setPositiveValue)
        .def("setNonNegativeValue", &FloatingNumberString::setNonNegativeValue)
        .def("value", &FloatingNumberString::value);
}
