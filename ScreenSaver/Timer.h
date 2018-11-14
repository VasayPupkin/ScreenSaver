#ifndef MOVEMENTTIMER_H
#define MOVEMENTTIMER_H
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/chrono/chrono.hpp>
#include <memory>

using SteadyTimer = boost::asio::steady_timer;
using IOService = boost::asio::io_service;
using TimerPtr = std::unique_ptr<SteadyTimer>;
using IOServicePtr = std::unique_ptr<IOService>;

class Timer
{
public:
    explicit Timer(const int interval);

    static void Notify(const boost::system::error_code& /*e*/);
    void Run();
private:
    int _interval;
    IOServicePtr _io;
    TimerPtr _timer;
};

#endif // MOVEMENTTIMER_H
