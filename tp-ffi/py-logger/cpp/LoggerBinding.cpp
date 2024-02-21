#include "Logger.hpp"

#include <pybind11/pybind11.h>

PYBIND11_MODULE(Logger, m) {

    pybind11::enum_<Level>(m, "Level")
        .value("Info", Level::Info)
        .value("Warning", Level::Warning)
        .value("Error", Level::Error)
        ;
        

    pybind11::class_<Logger>(m, "Logger")
        .def(pybind11::init<>())
        .def("add_item", &Logger::addItem)
        .def("report_by_added", &Logger::reportByAdded)
        .def("report_by_level", &Logger::reportByLevel);
    


}

