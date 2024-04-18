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
        context.rectangle(0, 0, 400, 400)
        context.fill()

        context.set_source_rgb(255,0,0)
        context.arc(width/6, height/6, 66.5-5, 0, 2*math.pi)
        context.fill()

        self.display(context)

        context.set_source_rgb(0.5, 0.5, 0.5)
        context.set_line_width(3)
        context.move_to(width/3, 0)
        context.line_to(width/3, height)

        context.move_to(2*width/3, 0)
        context.line_to(2*width/3, height)

        context.move_to(0, height/3)
        context.line_to(width, height/3)

        context.move_to(0, 2*height/3)
        context.line_to(width, 2*height/3)

        context.move_to(width/3, 0)
        context.line_to(width/3, height)
        context.stroke()


    def display(self, context):
        width = self.drawingarea.get_allocated_width()
        height = self.drawingarea.get_allocated_height()
        for y in range(3):
            for x in range(3):
                etat = self.jeu.getCell(x,y)
                if etat.name == "Vert":
                    context.set_source_rgb(0,255,0)
                    context.arc(x*width/3 + width/6, y*height/3 + height/6, 66.5-5, 0, 2*math.pi)
                    context.fill()
                elif etat.name == "Rouge":
                    context.set_source_rgb(255,0,0)
                    context.arc(x*width/3 + width/6, y*height/3 + height/6, 66.5-5, 0, 2*math.pi)
                    context.fill()

    def on_area_button_press(self, widget, event):
        if event.button == 1:
            width = self.drawingarea.get_allocated_width()
            height = self.drawingarea.get_allocated_height()

            x = int(int(event.x) // (width/3))
            y = int(int(event.y) // (height/3))
            self.jeu.jouer(x,y)
            self.drawingarea.queue_draw()
            print(x,y)
           

    def on_button1_clicked(self, widget):
        print('TODO on_button1_clicked')
        self.jeu.raz()
        self.drawingarea.queue_draw()

    def on_button2_clicked(self, widget):
        Gtk.main_quit()

    

if __name__ == '__main__':
    gui = Gui()
    gui.connect("destroy", Gtk.main_quit)
    gui.show_all()
    Gtk.main()
