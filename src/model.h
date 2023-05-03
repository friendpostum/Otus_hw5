#pragma once

#include <string>
#include <map>
#include <utility>
#include <vector>
#include "viewer.h"

struct Shape {
    virtual ~Shape() = default;

    std::string name;
protected:
    explicit Shape(std::string name):name(std::move(name)) {}
};

struct Ellipse : Shape {
    explicit Ellipse(const std::string &name) : Shape(name) {}

};

struct Rectangle : Shape {
    explicit Rectangle(const std::string &name) : Shape(name) {}

};


struct IModel {
    virtual ~IModel() = default;

    virtual void subscribe(IViewer *obs) = 0;
};

struct Model : IModel {

    void subscribe(IViewer *viewer) override {
        ui.push_back(viewer);
    }

    explicit Model(std::string name) : name(std::move(name)) {}

    void setName(const std::string &name_) {
        name = name_;
    }

    void addShape(const std::shared_ptr<Shape> &shape) {
        shapes.insert({{0, 0}, shape});
        msg = "Add shape: " + shape->name;
        notify();
    }

    void selectShape(int posX, int posY) {
        selectedShape = shapes.find({posX, posY});
        msg = "Selected shape: ";
        notify();
    };

    void removeShape() {
        if(selectedShape != shapes.end()) {
            msg = "Removed " + selectedShape->second->name;
            shapes.erase(selectedShape);
        } else
            msg = "The deletion didn't happen. Shape not selected";

        notify();
    }

    void notify() {
        for (auto& s : ui) {
            s->update(msg);
        }
    }

    std::string message() {
        return msg;
    }

private:
    using coord = std::pair<int, int>;
    std::string name;
    std::multimap<coord, std::shared_ptr<Shape>> shapes;
    std::multimap<coord, std::shared_ptr<Shape>>::iterator selectedShape;
    std::string msg;
    std::vector<IViewer *> ui;
};


