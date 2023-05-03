#pragma once

struct IViewer {
    virtual ~IViewer() = default;

    virtual void update(std::string msg) = 0;
};
