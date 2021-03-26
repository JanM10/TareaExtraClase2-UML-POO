#include <iostream>
#include <vector>

using namespace std;


class Handler {
public:
    virtual Handler *SetNext(Handler *handler) = 0;
    virtual string Handle(string request) = 0;
};

class AbstractHandler : public Handler {
private:
    Handler *next_handler_;

public:
    AbstractHandler() : next_handler_(nullptr) {
    }
    Handler *SetNext(Handler *handler) override {
        this->next_handler_ = handler;
        return handler;
    }
    string Handle(string request) override {
        if (this->next_handler_) {
            return this->next_handler_->Handle(request);
        }
        return {};
    }
};

class Ganador1Handler : public AbstractHandler {
public:
    string Handle(string request) override {
        if (request == "Tablet") {
            return "Ganador1: Yo quiero la " + request + ".\n";
        } else {
            return AbstractHandler::Handle(request);
        }
    }
};
class Ganador2Handler : public AbstractHandler {
public:
    string Handle(string request) override {
        if (request == "Computadora") {
            return "Ganador2: Yo quiero la " + request + ".\n";
        } else {
            return AbstractHandler::Handle(request);
        }
    }
};
class Ganador3Handler : public AbstractHandler {
public:
    std::string Handle(std::string request) override {
        if (request == "Celular") {
            return "Ganador3: Yo quiero el " + request + ".\n";
        } else {
            return AbstractHandler::Handle(request);
        }
    }
};

void ClientCode(Handler &handler) {
    vector<string> premios = {"Tablet", "Computadora", "Celular"};
    for (const string &f : premios) {
        cout << "Presentador: Quien quiere una " << f << "?\n";
        const string result = handler.Handle(f);
        if (!result.empty()) {
            cout << "  " << result;
        } else {
            cout << "  La " << f << " nadie la quiso.\n";
        }
    }
}

int main() {
    Ganador1Handler *primerG = new Ganador1Handler;
    Ganador2Handler *segundoG = new Ganador2Handler;
    Ganador3Handler *tercerG = new Ganador3Handler;
    primerG->SetNext(segundoG)->SetNext(tercerG);

    cout << "Primera cadena: Ganador1 --> Ganador2 --> Ganador3"<<endl;
    ClientCode(*primerG);

    cout << "------------------------------------------------\n";
    cout << "Segunda Cadena: Ganador2 --> Ganador3"<<endl;
    ClientCode(*segundoG);

    cout << "------------------------------------------------\n";
    cout << "Tercera Cadena: Ganador3"<<endl;
    ClientCode(*tercerG);

    delete primerG;
    delete segundoG;
    delete tercerG;

    return 0;
}
