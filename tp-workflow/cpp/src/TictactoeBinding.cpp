#include "Tictactoe.hpp"

#include <pybind11/pybind11.h>

PYBIND11_MODULE(tictactoe, m) {
        
    pybind11::enum_<Cell>(m, "Cell")
        .value("Vide", Cell::Vide)
        .value("Rouge", Cell::Rouge)
        .value("Vert", Cell::Vert)
        ;

    // TODO Status

    pybind11::class_<Jeu>(m, "Jeu")
        .def(pybind11::init<>())
        .def("getStatus", &Jeu::getStatus)
        .def("jouer", &Jeu::jouer)
        .def("isFinished", &Jeu::isFinished)
        .def("displayStatus", &Jeu::displayStatus)
        .def("raz", &Jeu::raz)
        ;

}

