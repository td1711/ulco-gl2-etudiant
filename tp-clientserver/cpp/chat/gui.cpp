#include <gtkmm.h>
#include <hv/WebSocketClient.h>

class MyWindow : public Gtk::Window {

    private:
        Gtk::TextView _textView;
        Gtk::Entry _entry;
    
    public:
        MyWindow() {

            auto ptrVPaned = Gtk::make_managed<Gtk::VPaned>();
            auto ptrScroll = Gtk::make_managed<Gtk::ScrolledWindow>();
            auto ptrHPaned = Gtk::make_managed<Gtk::HPaned>();
            auto ptrButton = Gtk::make_managed<Gtk::Button>("Send");

            add(*ptrVPaned);
            ptrVPaned->pack1(*ptrScroll, Gtk::EXPAND);
            ptrVPaned->pack2(*ptrHPaned, Gtk::SHRINK);

            ptrScroll->add(_textView);

            ptrHPaned->pack1(_entry, Gtk::EXPAND);
            ptrHPaned->pack2(*ptrButton, Gtk::SHRINK);

            _textView.set_editable(false);
            set_default_size(400, 300);
            show_all();

            ptrButton->signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::send));
        }

        void displayMsg(const std::string & msg) {
            auto buffer = _textView.get_buffer();
            auto text = buffer->get_text();
            buffer->set_text(text + msg + "\n");
        }

    private:
        void send() {
            
        }
};

int main(int argc, char ** argv) {

    Gtk::Main kit(argc, argv);
    
    MyWindow window;

    kit.run(window);

    return 0;
}

