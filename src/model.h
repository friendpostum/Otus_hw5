#pragma once

#include <string>
#include <map>

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

struct Viewer;
struct Model{
    virtual ~Model() = default;

    virtual void subscribe(const std::shared_ptr<Viewer>& obs) = 0;
};

struct Document {

    Document() : name("new doc") {}

    void setName(const std::string &name_) {
        name = name_;
    }

    void addShape(const std::shared_ptr<Shape> &shape) {
        shapes.insert({{0, 0}, std::make_unique<Rectangle>("New rectangle")});
    }

    void selectShape(int posX, int posY) {
        selectedShape = shapes.find({posX, posY});
    };

    void removeShape() {
        if (selectedShape != shapes.end())
            shapes.erase(selectedShape);
    }

    using coord = std::pair<int, int>;
private:
    std::string name;
    std::map<coord, std::shared_ptr<Shape>> shapes;
    std::map<coord, std::shared_ptr<Shape>>::iterator selectedShape;
};


