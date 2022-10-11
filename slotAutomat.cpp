#include <SFML/Graphics.hpp>
#include <iostream>
#include "States/StateMachine/StateMachine.h"
#include "States/StartState/StartState.h"
#include "States/SpinState/SpinState.h"
#include "States/StopState/StopState.h"
#include "RenderHelper/RenderHelper.h"

int main() 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Window");
    RenderHelper renderHelper(&window);

    renderHelper.RenderSlots();
    renderHelper.RenderRedLine();
    renderHelper.RenderScore();

    StartState startState;
    SpinState spinState(sf::seconds(5), 0.1);
    StopState stopState;

    StateMachine stateMachine;
    stateMachine.AddState(&startState);
    stateMachine.AddState(&spinState);
    stateMachine.AddState(&stopState);

    while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        window.draw(renderHelper.GetScore());
        window.draw(renderHelper.GetStartButton().first);
        window.draw(renderHelper.GetStartButton().second);
        window.draw(renderHelper.GetStopButton().first);
        window.draw(renderHelper.GetStopButton().second);
        window.draw(renderHelper.GetRedLine());

        stateMachine.Loop();

        window.display();
    }
}