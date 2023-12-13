#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "integrator.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
    py::class_<IntegratorBase, std::shared_ptr<IntegratorBase>>(m, "IntegratorBase")
        .def(py::init<>())
        .def("compute_step", &IntegratorBase::compute_step)
        .def("integrate", &IntegratorBase::integrate);

    py::class_<EulerIntegrator, IntegratorBase, std::shared_ptr<EulerIntegrator>>(m, "EulerIntegrator")
        .def(py::init<>())
        .def("compute_step", &EulerIntegrator::compute_step);

    py::class_<HarmonicOscillator, EulerIntegrator, std::shared_ptr<HarmonicOscillator>>(m, "HarmonicOscillator")
        .def(py::init<>())
        .def("f", &HarmonicOscillator::f);
}
