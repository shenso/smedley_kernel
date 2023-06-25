#pragma once

namespace smedley
{

    class Event
    {
        bool _cancelable;
        bool _is_cancelled;
    public:
        Event(bool cancelable) : _cancelable(cancelable), _is_cancelled(false) {}
        virtual ~Event() {}

        void Cancel();
        inline bool can_cancel() { return _cancelable; }
        inline bool is_cancelled() { return _is_cancelled; }
    };

}