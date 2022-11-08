#include "Jogador1.h"

using namespace Jogadores;

Jogador1::Jogador1(GerenciadorGrafico *g) : Jogador(g) {
    velocidade = 700.f;
    corpoGrafico.inicializa(sf::Vector2f(100.f, 130.f), nullptr, sf::Vector2f(80.0f, 130.0f));
    corpoGrafico.setTextura("../assets//imagens//jogador1.png");

    hitbox->getCorpoGrafico()->setTextura("../assets//imagens//sunburn.png");
    hitbox->getCorpoGrafico()->inicializaAnimadora(sf::Vector2f(100.f, 130.f), sf::Vector2u(8, 8), sf::Vector2u(8, 8));

    posInicial = sf::Vector2f(corpoGrafico.getPosicao().x / 2.0f, 710.f);
    corpoGrafico = posInicial;

    id = 7;
}

Jogador1::~Jogador1() {}

void Jogador1::executar() {
    mover();
}

void Jogador1::mover() {
    sf::Vector2u animacao(0, 0);
    float tempoTrocaAnimacao = 0.3f;
    float DT = gerenciadorGrafico->getDT();
    movimentacao.x = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movimentacao.x -= velocidade;
        lado = -1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movimentacao.x += velocidade;
        lado = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && noChao) {
        movimentacao.y = -sqrtf(2.0f * 981.0f * pulo);
        noChao = false;
    }

    movimentacao.y += 981.0f * DT * 2.5f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        movimentacao.y -= 20.0f;
    }

    corpoGrafico.mover(movimentacao * DT);
    animar(movimentacao);
}