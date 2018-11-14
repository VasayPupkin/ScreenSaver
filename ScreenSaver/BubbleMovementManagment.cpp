#include "BubbleMovementManagment.h"

BubbleMovementManagment::BubbleMovementManagment(const int movement_interval,
                                                 QObject *parent):
    _movement_interval(movement_interval)
{
    CreateMovementTimer(_movement_interval);
}

void BubbleMovementManagment::CreateMovementTimer(const int movement_interval)
{
    _movement_timer.reset(new QTimer());
    _movement_timer.get()->setInterval(movement_interval*MSEC_FACTOR);

    connect(_movement_timer.get(),SIGNAL(timeout()),SLOT(RecalculateBubblesPositions));
}

void BubbleMovementManagment::Start()
{
    //start movement timer
    _movement_timer.get()->start();
}

void BubbleMovementManagment::RecalculateBubblesPositions()
{

}
