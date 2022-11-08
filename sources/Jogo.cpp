#include "Jogo.h"
#include "MenuPrincipal.h"

using namespace Controladoras;

Jogo *Jogo::CriarJogo() {
    if (not jogoUnico) { jogoUnico = new Jogo(); }
    return jogoUnico;
}

Jogo::Jogo() {
    srand((unsigned) time(NULL));
    pilha.colocarEstado(reinterpret_cast<Estado *>(new MenuPrincipal(this)));
}

Jogo::~Jogo() { delete jogoUnico; }

void Jogo::executar() {

    float dT;
    sf::Clock clock;

    while (GG.getAberto()) {
        dT = clock.restart().asSeconds();
        if (dT > 1.0f / 20.0f) { dT = 1.0f / 20.0f; }

        GG.setDT(dT);
        GG.limpar();
        GG.leEventos();

        if (not pilha.executar()) { GG.getJanela()->close(); }

        GG.getJanela()->display();
    }
}

Jogo *Jogo::jogoUnico = nullptr;