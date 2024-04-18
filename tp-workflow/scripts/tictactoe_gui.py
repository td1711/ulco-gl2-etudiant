import gi
import math
import tictactoe

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk, Gdk

class Gui(Gtk.Window):
    
    def __init__(self):
        super().__init__(title="Tictactoe")
        self.set_size_request (400, 400)

        # main vertical box : drawing area + hbox (label, button1, button2)
        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
        self.add(vbox)

        self.jeu = tictactoe.Jeu()

        # drawing area
        self.drawingarea = Gtk.DrawingArea()
        self.drawingarea.add_events(Gdk.EventMask.BUTTON_PRESS_MASK)
        self.drawingarea.connect("draw", self.on_draw)
        self.drawingarea.connect("button-press-event", self.on_area_button_press)
        vbox.pack_start(self.drawingarea, True, True, 0)

        # horizontal box
        hbox = Gtk.Box()
        vbox.pack_end(hbox, False, False, 0)
        # label
        self.label = Gtk.Label(label=self.jeu.displayStatus())
        hbox.pack_start(self.label, True, True, 0)
        # button1
        button1 = Gtk.Button(label="rejouer")
        button1.connect("clicked", self.on_button1_clicked)
        hbox.pack_start(button1, True, True, 0)

        # button2
        button2 = Gtk.Button(label="quitter")
        button2.connect("clicked", self.on_button2_clicked)
        hbox.pack_start(button2, True, True, 0)

        #  ODO create game (from the C++ module)

    def on_draw(self, widget, context):

        # TODO on_draw
        
        width = widget.get_allocated_width()
        height = widget.get_allocated_height()

        context.set_source_rgb(0, 0, 0)
        context.rectangle(0, 0, 100, 100)
        context.fill()

        context.set_source_rgb(0.5, 0.5, 0.5)
        context.set_line_width(3)
        context.move_to(width, 0)
        context.line_to(0, height)
        context.stroke()


    def on_area_button_press(self, widget, event):
        # TODO on_area_button_press
        if event.button == 1:
            print('TODO on_area_button_press')
            

    def on_button1_clicked(self, widget):
        # TODO on_button1_clicked
        print('TODO on_button1_clicked')
        self.drawingarea.queue_draw()

    def on_button2_clicked(self, widget):
        Gtk.main_quit()

    def on_button2_clicked(self, widget):
        self.jeu.raz()
    

if __name__ == '__main__':
    gui = Gui()
    gui.connect("destroy", Gtk.main_quit)
    gui.show_all()
    Gtk.main()
