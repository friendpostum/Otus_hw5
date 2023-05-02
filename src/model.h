#pragma once

#include <string>
#include <map>
#include <vector>
#include "viewer.h"

struct Shape {
    virtual ~Shape() = default;

    void setName(const std::string &name_) {}

protected:
    explicit Shape(const std::string &name) {}
};

struct Ellipse : Shape {
    std::string name;

    Ellipse(const std::string &name) : Shape(name) {}

};

struct Rectangle : Shape {
    Rectangle(const std::string &name) : Shape(name) {}

};


struct IModel {
    virtual ~IModel() = default;

    virtual void subscribe(IViewer *obs) = 0;
};

struct Model : IModel {

    void subscribe(IViewer *viewer) override {
        viewers.push_back(viewer);
    }

    Model() : name("new doc") {}

    void setName(const std::string &name_) {
        name = name_;
    }

    void addShape(const std::shared_ptr<Shape> &shape) {
        shapes.insert({{0, 0}, std::make_unique<Rectangle>("New rectangle")});
        msg = "Add shape: ";
        notify();
    }

    void selectShape(int posX, int posY) {
        selectedShape = shapes.find({posX, posY});
        msg = "Selected shape: ";
      //  notify();
    };

    void removeShape() {
        if(selectedShape != shapes.end())
            shapes.erase(selectedShape);
        msg = "Removed shape: ";
       // notify();
    }

    void notify() {
        std::cout << "notify"<< std::endl;
        for (auto& s : viewers) {
            s->update();
            std::cout << "update"<< std::endl;
        }
    }

    std::string message() {
        return msg;
    }

private:
    using coord = std::pair<int, int>;
    std::string name;
    std::map<coord, std::shared_ptr<Shape>> shapes;
    std::map<coord, std::shared_ptr<Shape>>::iterator selectedShape;
    std::string msg;
    std::vector<IViewer *> viewers;
};


