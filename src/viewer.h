#pragma once

struct IViewer {
    virtual ~IViewer() = default;

    virtual void update() = 0;
};
