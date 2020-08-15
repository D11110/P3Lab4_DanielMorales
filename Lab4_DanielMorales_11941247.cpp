#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Jugador
{
    friend class Juego;

private:
    string nombre;
    vector<string> baraja;
    int sumaCartas = 0;

public:
    Jugador();
    Jugador(string _nombre)
    {
        nombre = _nombre;
    };

    void agregarCarta(string carta)
    {
        baraja.push_back(carta);
    };
};

class Juego
{

private:
public:
    Juego();
    void Jugar();
    static void JugarJugador(Jugador &, string);
    static void mostrarCartas(Jugador &);
    static void mostrarPuntuacion(Jugador &);
    static int retornaPuntuacion(Jugador &);
};

Juego::Juego()
{
}

int Juego::retornaPuntuacion(Jugador &j)
{
    return j.sumaCartas;
}

void Juego::JugarJugador(Jugador &j, string cartaRecibida)
{
    j.agregarCarta(cartaRecibida);
    string valorCartaEnString = cartaRecibida.substr(0, 2);
    int valorCarta = 0;
    if (valorCartaEnString == "A ")
    {
        valorCarta = 1;
    }
    else if (valorCartaEnString == "J ")
    {
        valorCarta = 11;
    }
    else if (valorCartaEnString == "Q ")
    {
        valorCarta = 12;
    }
    else if (valorCartaEnString == "K ")
    {
        valorCarta = 13;
    }
    else if (valorCartaEnString == "10")
    {
        valorCarta = 10;
    }
    else
    {
        valorCartaEnString.substr(0, 1);
        valorCarta = stoi(valorCartaEnString);
    }
    j.sumaCartas = j.sumaCartas + valorCarta;
}

void Juego::mostrarCartas(Jugador &j)
{
    std::cout << j.nombre << ": ";
    int size = j.baraja.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << j.baraja.at(i);
    }
}

void Juego::mostrarPuntuacion(Jugador &j)
{
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "La puntuacion de " << j.nombre << " es: " << j.sumaCartas << std::endl;
}

vector<string> llenarBarajaParaJugadores(vector<string> baraja)
{
    for (int i = 0; i < 13; i++)
    {
        string cartaDiamante = "";
        if (i == 10)
        {
            cartaDiamante = "J  <> ,";
            baraja.push_back(cartaDiamante);
        }
        else if (i == 11)
        {
            cartaDiamante = "Q  <> ,";
            baraja.push_back(cartaDiamante);
        }
        else if (i == 12)
        {
            cartaDiamante = "K  <> ,";
            baraja.push_back(cartaDiamante);
        }
        else if (i == 0)
        {
            cartaDiamante = "A  <> ,";
            baraja.push_back(cartaDiamante);
        }
        else
        {
            cartaDiamante = to_string(i + 1) + "  <> ,";
            baraja.push_back(cartaDiamante);
        }
    }

    for (int i = 0; i < 13; i++)
    {
        string cartaCorazon = "";
        if (i == 10)
        {
            cartaCorazon = "J  <3 ,";
            baraja.push_back(cartaCorazon);
        }
        else if (i == 11)
        {
            cartaCorazon = "Q  <3 ,";
            baraja.push_back(cartaCorazon);
        }
        else if (i == 12)
        {
            cartaCorazon = "K  <3 ,";
            baraja.push_back(cartaCorazon);
        }
        else if (i == 0)
        {
            cartaCorazon = "A  <3 ,";
            baraja.push_back(cartaCorazon);
        }
        else
        {
            cartaCorazon = to_string(i + 1) + "  <3 ,";
            baraja.push_back(cartaCorazon);
        }
    }

    for (int i = 0; i < 13; i++)
    {
        string cartaEspada = "";
        if (i == 10)
        {
            cartaEspada = "J  O? ,";
            baraja.push_back(cartaEspada);
        }
        else if (i == 11)
        {
            cartaEspada = "Q  O? ,";
            baraja.push_back(cartaEspada);
        }
        else if (i == 12)
        {
            cartaEspada = "K  O? ,";
            baraja.push_back(cartaEspada);
        }
        else if (i == 0)
        {
            cartaEspada = "A  O? ,";
            baraja.push_back(cartaEspada);
        }
        else
        {
            cartaEspada = to_string(i + 1) + "  O? ,";
            baraja.push_back(cartaEspada);
        }
    }

    for (int i = 0; i < 13; i++)
    {
        string cartaTrebol = "";
        if (i == 10)
        {
            cartaTrebol = "J  -# ,";
            baraja.push_back(cartaTrebol);
        }
        else if (i == 11)
        {
            cartaTrebol = "Q  -# ,";
            baraja.push_back(cartaTrebol);
        }
        else if (i == 12)
        {
            cartaTrebol = "K  -# ,";
            baraja.push_back(cartaTrebol);
        }
        else if (i == 0)
        {
            cartaTrebol = "A  -# ,";
            baraja.push_back(cartaTrebol);
        }
        else
        {
            cartaTrebol = to_string(i + 1) + "  -# ,";
            baraja.push_back(cartaTrebol);
        }
    }

    return baraja;
};

int main()
{
    std::cout << "Bienvenido a 31 \n"
              << "Cuantos jugadores van a jugar? " << std::endl;
    int numJugadores;
    cin >> numJugadores;

    while (numJugadores < 2 || numJugadores > 10)
    {
        std::cout << "Escoga entre 2 a 10 jugadores." << std::endl;
        std::cout << "Cuantos jugadores van a jugar? " << std::endl;
        cin >> numJugadores;
    }

    std::cout << "Ingrese su nombre:" << std::endl;
    string nombreJugador;
    cin >> nombreJugador;

    vector<string> baraja;
    baraja = llenarBarajaParaJugadores(baraja);

    vector<Jugador> jugadoresJugando;

    Jugador jugador1(nombreJugador);

    for (int i = 0; i < numJugadores - 1; i++)
    {
        string nombreBot = "bot-" + to_string(i + 1) + " ";
        Jugador temp(nombreBot);
        jugadoresJugando.push_back(temp);
    }

    srand((unsigned int)time(NULL));
    int limiteRandom = 51;

    for (int i = 0; i < 3; i++)
    {
        int indCartaGenerada = (1 + rand() % (limiteRandom)) - 1;
        string cartaObtenida = baraja.at(indCartaGenerada);

        Juego::JugarJugador(jugador1, cartaObtenida);

        baraja.erase(baraja.begin() + indCartaGenerada);
        limiteRandom--;
    }
    bool primerIntento = true;

    while (primerIntento)
    {
        Juego::mostrarCartas(jugador1);
        std::cout << "" << std::endl;
        std::cout << "Desea tomar otra carta? (1-si 2-no)" << std::endl;
        int confirmacionUsuario;
        cin >> confirmacionUsuario;

        bool sigueVivo = false;
        if (confirmacionUsuario == 1)
        {
            sigueVivo = true;
        }
        else
        {
            break;
        }

        while (confirmacionUsuario > 2 || confirmacionUsuario < 0)
        {
            std::cout << "Ingrese una opcion valida" << std::endl;
            std::cout << "Desea tomar otra carta? (1-si 2-no)" << std::endl;
            cin >> confirmacionUsuario;
        }

        while (sigueVivo)
        {
            int indCartaGenerada = (1 + rand() % (limiteRandom)) - 1;
            string cartaObtenida = baraja.at(indCartaGenerada);

            Juego::JugarJugador(jugador1, cartaObtenida);

            baraja.erase(baraja.begin() + indCartaGenerada);
            limiteRandom--;

            Juego::mostrarCartas(jugador1);
            std::cout << "" << std::endl;
            std::cout << "Desea tomar otra carta? (1-si 2-no)" << std::endl;
            int confirmacionUsuario;
            cin >> confirmacionUsuario;

            if (confirmacionUsuario == 2)
            {
                sigueVivo = false;
                primerIntento = false;
            }

            while (confirmacionUsuario > 2 || confirmacionUsuario < 0)
            {
                std::cout << "Ingrese una opcion valida" << std::endl;
                std::cout << "Desea tomar otra carta? (1-si 2-no)" << std::endl;
                cin >> confirmacionUsuario;
            }
        }

        if (sigueVivo == false)
        {
            for (int i = 0; i < jugadoresJugando.size(); i++)
            {
                bool botVivo = true;
                while (botVivo)
                {
                    int indCartaGeneradaBot = (1 + rand() % (limiteRandom)) - 1;
                    string cartaObtenidaBot = baraja.at(indCartaGeneradaBot);
                    Juego::JugarJugador(jugadoresJugando.at(i), cartaObtenidaBot);

                    baraja.erase(baraja.begin() + indCartaGeneradaBot);
                    limiteRandom--;
                    int posibilidad = 0;

                    if (Juego::retornaPuntuacion(jugadoresJugando.at(i)) > 0 || Juego::retornaPuntuacion(jugadoresJugando.at(i)) < 10)
                    {
                        posibilidad = 1 + rand() % 100;
                    }
                    else if (Juego::retornaPuntuacion(jugadoresJugando.at(i)) > 10 || Juego::retornaPuntuacion(jugadoresJugando.at(i)) < 20)
                    {
                        posibilidad = 1 + rand() % 80;
                    }else if (Juego::retornaPuntuacion(jugadoresJugando.at(i)) > 20 || Juego::retornaPuntuacion(jugadoresJugando.at(i)) < 30)
                    {
                        posibilidad = 1 + rand() % 40;
                    }else if (Juego::retornaPuntuacion(jugadoresJugando.at(i)) > 30 || Juego::retornaPuntuacion(jugadoresJugando.at(i)) < 31)
                    {
                        posibilidad = 1 + rand() % 10;
                    }
                }
            }
        }
    }
}