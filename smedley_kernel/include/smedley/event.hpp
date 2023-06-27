#pragma once

namespace smedley
{

    /**
     * Represents a snapshot of some in-game event/action/change in
     * state. Some events are cancellable.
     */
    class Event
    {
        bool _cancelable;
        bool _is_cancelled;
    public:
        Event(bool cancelable) : _cancelable(cancelable), _is_cancelled(false) {}
        virtual ~Event() {}

        /// @brief Cancels the event if possible.
        void Cancel();
        /// @brief Returns if the event is cancellable.
        inline bool can_cancel() { return _cancelable; }
        /// @brief Returns if the event has been cancelled.
        inline bool is_cancelled() { return _is_cancelled; }
    };

}