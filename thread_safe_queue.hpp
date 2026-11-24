#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include <optional>

template <typename T>
class ThreadSafeQueue {
public:
    void push(T value) {
        std::lock_guard<std::mutex> lock(mu_);
        queue_.push(std::move(value));
        cv_.notify_one();
    }

    std::optional<T> pop() {
        std::unique_lock<std::mutex> lock(mu_);
        cv_.wait(lock, [this] { return !queue_.empty() || done_; });
        if (queue_.empty()) return std::nullopt;
        T value = std::move(queue_.front());
        queue_.pop();
        return value;
    }

    void stop() {
        std::lock_guard<std::mutex> lock(mu_);
        done_ = true;
        cv_.notify_all();
    }

private:
    std::queue<T> queue_;
    std::mutex mu_;
    std::condition_variable cv_;
    bool done_ = false;
};
