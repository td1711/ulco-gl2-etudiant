import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk

from matplotlib.backends.backend_gtk3agg import (
    FigureCanvasGTK3Agg as FigureCanvas)
from matplotlib.figure import Figure
import numpy as np
import myfibo


class Gui(Gtk.Window):
    
    def __init__(self):
        super().__init__(title="Fibo")

        # init some data
        initial_n = 11
        max_n = 30

        # main vertical box : canvas + hbox (spin1, button1)
        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
        self.add(vbox)

        # canvas
        fig = Figure(figsize=(5, 4), dpi=100)
        self.canvas = FigureCanvas(fig)
        self.canvas.set_size_request(800, 600)
        self.ax = fig.add_subplot()
        self.update_canvas(initial_n)
        vbox.add(self.canvas)

        # horizontal box
        hbox = Gtk.Box()
        vbox.pack_end(hbox, False, False, 0)
        # spin1
        adjustment = Gtk.Adjustment(value=initial_n,
                                    lower=2,
                                    upper=max_n,
                                    step_increment=1)
        self.spin1 = Gtk.SpinButton(adjustment=adjustment)
        self.spin1.connect("value-changed", self.on_spin1_changed)
        hbox.pack_start(self.spin1, True, True, 0)
        # button1
        button1 = Gtk.Button(label="quitter")
        button1.connect("clicked", self.on_button1_clicked)
        hbox.pack_start(button1, True, True, 0)

    def on_spin1_changed(self, widget):
        self.update_canvas(self.spin1.get_value_as_int())

    def on_button1_clicked(self, widget):
        Gtk.main_quit()

    def update_canvas(self, n):
        self.ax.clear()
        xs = np.arange(0, n+1, 1)
        ys = np.vectorize(myfibo.fibo_naive)(xs)
        self.ax.plot(xs, ys)
        self.canvas.draw()


if __name__ == '__main__':
    gui = Gui()
    gui.connect("destroy", Gtk.main_quit)
    gui.show_all()
    Gtk.main()

