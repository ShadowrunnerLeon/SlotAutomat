#include <SFML/Graphics.hpp>
#include <iostream>
#include "States/StateMachine/StateMachine.h"
#include "States/StartState/StartState.h"
#include "States/SpinState/SpinState.h"
#include "States/StopState/StopState.h"
#include "RenderHelper/RenderHelper.h"

int main() 
{
    RenderHelper renderHelper;

    renderHelper.RenderSlots();
    renderHelper.RenderRedLine();
    renderHelper.RenderScore();

    StartState startState(&renderHelper);
    SpinState spinState(&renderHelper, sf::seconds(5), 0.1);
    StopState stopState(&renderHelper);

    StateMachine stateMachine;
    stateMachine.AddState(&startState);
    stateMachine.AddState(&spinState);
    stateMachine.AddState(&stopState);

    while (renderHelper.GetWindow().isOpen())
    {
        renderHelper.GetWindow().clear(sf::Color::Black);
        renderHelper.GetWindow().draw(renderHelper.GetScore());
        renderHelper.GetWindow().draw(renderHelper.GetStartButton().text);
        renderHelper.GetWindow().draw(renderHelper.GetStartButton().vertexArray);
        renderHelper.GetWindow().draw(renderHelper.GetStopButton().text);
        renderHelper.GetWindow().draw(renderHelper.GetStopButton().vertexArray);
        renderHelper.GetWindow().draw(renderHelper.GetRedLine());

        stateMachine.Update();

        renderHelper.GetWindow().display();
    }
}