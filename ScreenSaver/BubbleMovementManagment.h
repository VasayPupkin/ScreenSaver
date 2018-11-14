#ifndef BUBBLEMOVEMENTMANAGMENT_H
#define BUBBLEMOVEMENTMANAGMENT_H

#include <list>
#include <memory>

#include "BubbleShape.h"

//TODO: replace to boost steady_timer
#include <QTimer>
#include <QDateTime>

#define MSEC_FACTOR 1000

using BubblePtr = std::unique_ptr<BubbleShape>;
using BubblePtrList = std::list<BubblePtr>;

class BubbleMovementManagment : public QObject
{
    Q_OBJECT
public:
    explicit BubbleMovementManagment(const int movement_interval, QObject* parent = nullptr);

private:
    void CreateMovementTimer(const int movement_interval);
    void Start();

public slots:
    void RecalculateBubblesPositions();

private:
    int _movement_interval;

    BubblePtrList _bubble_ptr_list;
    std::unique_ptr<QTimer> _movement_timer;
};

#endif // BUBBLEMOVEMENTMANAGMENT_H
