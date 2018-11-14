#include "Timer.h"

Timer::Timer(const int interval):
    _interval(interval)
{
    _io.reset(new IOService());
    _timer.reset(new SteadyTimer(*_io, std::chrono::seconds(_interval)));
    _timer.get()->async_wait(boost::bind(Notify, boost::asio::placeholders::error));
}

void Timer::Notify(const boost::system::error_code &)
{

}

void Timer::Run()
{
    _io.get()->run();
}
